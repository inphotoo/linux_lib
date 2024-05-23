#pragma once

#include "kvstore_api.h"
#include "MurmurHash3.h"
#include <string>
#include <unordered_set>
#include <vector>
#include "utils.h"

//跳表
struct QuadlistNode
{
    std::string entry;
    uint64_t key;
    QuadlistNode *prev ;
    QuadlistNode *succ ;
    QuadlistNode *above;
    QuadlistNode *below;
    QuadlistNode(uint64_t k , std::string e = "" , QuadlistNode *p = NULL, QuadlistNode *s = nullptr, QuadlistNode *a = nullptr, QuadlistNode *b = nullptr):
            key(k),entry(e),prev(p),succ(s),above(a),below(b){
        key = k;
    }
    QuadlistNode* insertAsSuccAbove(uint64_t k ,std::string e , QuadlistNode *b =nullptr)
    {
        QuadlistNode *x = new QuadlistNode(k , e , this , this->succ , nullptr , b);
        this->succ->prev = x;
        this->succ = x;
        if(b != nullptr) b->above = x;
        return x;
    }
};


struct MemTable
{
    struct Quadlist
    {
        Quadlist()
        {
            header = new QuadlistNode(0);
            header->entry = "@header";
            trailer = new QuadlistNode(922337203685477580);
            trailer->prev = header;
            trailer->entry = "@trailer";
            header->succ = trailer;
            header->prev = header->above = header->below = NULL;
            trailer->above = trailer->below = trailer->succ = NULL;
            size = 0;
        }
        QuadlistNode *frist(){return header->succ ;}
        QuadlistNode *last(){return trailer->prev ;}
        bool isEmpty(){if(size <= 0) return true; }
        QuadlistNode *insertAfterAbove(uint64_t k , std::string e , QuadlistNode *p , QuadlistNode * b){
            return p->insertAsSuccAbove(k , e, b);
        };
        QuadlistNode *header;
        QuadlistNode *trailer;
        int size;
        // add something here
    };
public:
    std::vector<Quadlist *> list;
    double p = 0.1;
    void put(uint64_t key, const std::string &val);
    void clear();
    std::string get(uint64_t key , bool &isFind );
    int getSize();
    int getMinKey();
    int getMaxKey();

    Quadlist * frist()
    {
        if(list.size() == 0)
            list.push_back(new Quadlist) ;
        return list[0];
    };
    Quadlist * last(){
        if(list.size() == 0)
            list.push_back(new Quadlist) ;
        return list[list.size() - 1];
    };
    MemTable(){};



};

class KVStore : public KVStoreAPI
{
    // You can add your implementation here
private:

    std::string ssTable;
    std::string dataDir;
    std::string vlogDir;
    long Head = 0;
    long Tail = 0;
    struct ssNode
    {
        uint64_t max;
        uint64_t min;
        uint64_t timestamp;
        int value;
        std::string filename;
        std::string str;
        ssNode(uint64_t max , uint64_t min):max(max),min(min){};
    };

    struct ssLevel
    {
        int currentNum;
        int level;
        std::vector<ssNode> ssNodes;
    };

    struct sstable
    {
        uint64_t timestamp;
        uint64_t key;
        uint32_t valueLen;
        uint64_t offset;
    };
public:
    MemTable memTable;

    std::vector<ssLevel> sslevel;

    void buildSSTable();

    void appendVLog();

    KVStore(const std::string &dir, const std::string &vlog);

    ~KVStore();

    void put(uint64_t key, const std::string &s) override;

    std::string get(uint64_t key) override;

    bool del(uint64_t key) override;

    void reset() override;

    void scan(uint64_t key1, uint64_t key2, std::list<std::pair<uint64_t, std::string>> &list) override;

    void compactLevel(int level);

    void selfCompaction(int level);

    void gc(uint64_t chunk_size) override;

    void SSTableCompaction() ;

    std::tuple<uint64_t, uint32_t> findInssTable(const std::string &str,uint64_t key, bool *isExist , bool *isFound);

    std::string readFromVLog(uint64_t dataOffset, uint32_t valueLen);

    std::list<std::tuple<uint64_t, uint64_t  ,uint32_t>>
    findInSsTableByRange(const std::string& str, uint64_t max_key, uint64_t min_key);

    ssNode writeSSTableToFile(const std::string &str , int level);

    std::list<std::string> compaction(std::list<ssNode> ssNodeList);

    void removeCompactedNodes(ssLevel &level, const std::list<ssNode> &selectedNodes);

    std::list<ssNode> selectNodesForCompaction(int level);

    off_t seekDataBlock(const std::string& path);

    void initialize();
};
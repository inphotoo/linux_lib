#pragma once

#include "kvstore_api.h"
#include "MurmurHash3.h"
#include <string>
#include <vector>
#include "utils.h"

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
            trailer = new QuadlistNode(922337203685477580);
            trailer->prev = header;
            header->succ = trailer;
            header->prev = header->above = header->below = NULL;
            trailer->above = trailer->below = trailer->succ = NULL;
            size = 0;
        }
        QuadlistNode *frist(){return header->succ ;}
        QuadlistNode *last(){return trailer->prev ;}
        bool isEmpty(){if(size <= 0) return true; }
        QuadlistNode *insertAfterAbove(uint64_t k , std::string e , QuadlistNode *p , QuadlistNode * b){
            size ++;
            return p->insertAsSuccAbove(k , e, b);
        };
        QuadlistNode *header;
        QuadlistNode *trailer;
        int size;
        // add something here
    };
public:
    std::vector<Quadlist *> list;
    double p = 0.5;
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
    Quadlist * last(){return list[list.size() - 1];};
    MemTable(){};



};

class KVStore : public KVStoreAPI
{
	// You can add your implementation here
private:

    std::string ssTable;
    std::string dataDir;
    std::string vlogDir;
    struct ssNode
    {
        uint64_t max;
        uint64_t min;
        ssNode(uint64_t max , uint64_t min):max(max),min(min){};
    };

    struct ssLevel
    {
        int currentNum;
        int level;
        std::vector<ssNode> ssNodes;
    };
public:
    MemTable memTable;
    std::pmr::vector<ssLevel> sslevel;
    void buildSSTable();

	KVStore(const std::string &dir, const std::string &vlog);

	~KVStore();

	void put(uint64_t key, const std::string &s) override;

	std::string get(uint64_t key) override;

	bool del(uint64_t key) override;

	void reset() override;

	void scan(uint64_t key1, uint64_t key2, std::list<std::pair<uint64_t, std::string>> &list) override;

	void gc(uint64_t chunk_size) override;

    void SSTableCompaction() ;

};
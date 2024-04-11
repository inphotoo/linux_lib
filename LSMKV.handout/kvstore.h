#pragma once

#include "kvstore_api.h"

struct QuadlistNode
{
    value_type entry;
    key_type key;
    QuadlistNode *prev ;
    QuadlistNode *succ ;
    QuadlistNode *above;
    QuadlistNode *below;
    QuadlistNode(key_type k = key_type() , value_type e = value_type(), QuadlistNode *p = NULL, QuadlistNode *s = nullptr, QuadlistNode *a = nullptr, QuadlistNode *b = nullptr):
    key(k),entry(e),prev(p),succ(s),above(a),below(b){
        key = k;
    }
    QuadlistNode* insertAsSuccAbove(key_type k ,value_type e , QuadlistNode *b =nullptr)
    {
        QuadlistNode *x = new QuadlistNode(k , e , this , this->succ , nullptr , b);
        this->succ->prev = x;
        this->succ = x;
        if(b != nullptr) b->above = x;
        return x;
    }
};
struct Quadlist
{		
    Quadlist()
    {
        header = new QuadlistNode(0);
        trailer = new QuadlistNode(2 * 9223372036854775807);
        trailer->prev = header;
        header->succ = trailer;
        header->prev = header->above = header->below = NULL;
        trailer->above = trailer->below = trailer->succ = NULL;
        size = 0;
    }
    QuadlistNode *frist(){return header->succ ;}
    QuadlistNode *last(){return trailer->prev ;}
    bool isEmpty(){if(size <= 0) return true; }
    QuadlistNode *insertAfterAbove(key_type k , value_type e , QuadlistNode *p , QuadlistNode * b){
        size ++;
        return p->insertAsSuccAbove(k , e, b);
    };
    QuadlistNode *header;
    QuadlistNode *trailer;
    int size;
// add something here
};

struct MemTable
{
public:
    void put(uint64_t key, const std::string &val);
    std::string get(uint64_t key , bool &isFind );
    int getSize(){return this->frist()->frist()->key;}
    int getMinKey(){return this->last()->frist()->key;}
    int getMaxKey(){return this->last()->last()->key;}
}

class KVStore : public KVStoreAPI
{
	// You can add your implementation here
private:
    MemTable MemTable;
public:
	KVStore(const std::string &dir, const std::string &vlog);

	~KVStore();

	void put(uint64_t key, const std::string &s) override;

	std::string get(uint64_t key) override;

	bool del(uint64_t key) override;

	void reset() override;

	void scan(uint64_t key1, uint64_t key2, std::list<std::pair<uint64_t, std::string>> &list) override;

	void gc(uint64_t chunk_size) override;
};
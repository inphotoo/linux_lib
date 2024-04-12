#include "kvstore.h"
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <iostream>




/**
 * Insert/Update the key-value pair.
 * No return values for simplicity.
 */
void MemTable::put(uint64_t key, const std::string &val)
{
	Quadlist *f = frist();
        QuadlistNode *p = f->frist();
        while(p != nullptr)
        {
            //go to the next
            while(p->succ && (key >= p->key) )
                p = p->succ;
            //come back
            p = p->prev;
            if(p->key == key && p != f->frist()->prev)
            {
                //find bottom
                while(p->below != nullptr)
                    p = p->below;
                //change the value
                while(p != nullptr)
                    {
                        p->entry = val;
                         p = p->above;
                    }
                return;
            }
            else
            {
                if(p->below == nullptr) break;
                else p = p->below;
            }
        }// find the place of insert
        

        Quadlist *listlast = this->last();
        listlast->insertAfterAbove(key , val ,p , nullptr);

        // 创建随机数
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(0.0, 1.0);
        int height = 0;
        p = p->succ;
        while(true)
        {
            double randNum = dis(gen);
            if(randNum >= this->p) return;
            if(list.size() <= height + 1)            
            if(list.size() <= height + 1)
            {
                Quadlist *qlist = new Quadlist();
                qlist->header->below = list[height]->header;
                qlist->trailer->below = list[height]->trailer;
                qlist->insertAfterAbove(key , val , qlist->header , p);
                p = p->above;
                list.push_back(qlist);
                height ++;
                continue;
            }
            Quadlist *qlist = list[height + 1];
            QuadlistNode *pre = qlist->header;
            while(pre->succ != qlist->trailer && key > pre->succ->key )
                pre = pre->succ;
            qlist->insertAfterAbove(key , val , pre , p);
            p = p->above;
            height ++;
        }
}

/**
 * Returns the (string) value of the given key.
 * An empty string indicates not found.
 */
std::string MemTable::get(uint64_t key , bool &isFind )
{

	Quadlist *li = frist();
    QuadlistNode * p = li->frist();
    if(p == nullptr) return "";
    while(true)
    {
        while(p->succ && (p->key <= key))
            p = p->succ;
        p = p->prev;
        if(p && p->key == key)
        {
            if(p->entry != "~DELETED~")
                isFind = true;
            return p->entry;
        }
        else
        {
            if(p->below == nullptr) return "";
            else p = p->below;
        }
    }
}

int MemTable::getSize()
{
    return this->list.size();
}
void MemTable::clear()
{
    list.clear();
}
KVStore::KVStore(const std::string &dir, const std::string &vlog) : KVStoreAPI(dir, vlog)
{
    this->dataDir = dir;
    this->vlogDir = vlog;
    utils::_mkdir("./data/vlog");
}

KVStore::~KVStore()
{
}

int MemTable::getMinKey()
{
    return this->frist()->frist()->key;
}
int MemTable::getMaxKey()
{
    return this->frist()->last()->key;
}
/**
 * Insert/Update the key-value pair.
 * No return values for simplicity.
 */
void KVStore::put(uint64_t key, const std::string &val)
{
    //we get the val frist
    //isFind is to know is the value exist
    bool isFind = false;
    std::string v = memTable.get(key , isFind);

    //if not out of range, we insert a key.
    if(memTable.getSize() < 408)
    {
        memTable.put(key , val);
        return;
    }

    //if out of range ,we build ssTable frist; 
    buildSSTable();

    //then we input again
    memTable.put(key , val);

}
/**
 * Returns the (string) value of the given key.
 * An empty string indicates not found.
 */
std::string KVStore::get(uint64_t key)
{
    //Frist , we get data from memTable
    bool isFind = false;
    std::string v = memTable.get(key , isFind);

    if(isFind)
        return v;
    else
    {
        for(int i = 0 ; i < this->sslevel.size() ; i++)
        {
            for(int j = 0 ; j < this->sslevel[i].currentNum ; j++)
            {
                if(key <= this->sslevel[i].ssNodes[j].max && key >= this->sslevel[i].ssNodes[j].min)
                {
                    std::string filename = this->vlogDir + std::to_string(i)+ "/ssTable/" + std::to_string(j);
                    std::ifstream file(filename);
                    std::cout << "find in ssTable";
                    bool isExist = true;
                    if(isExist)
                        return "";
                }
            }
        }
    }
    return "";
}

/**
 * Delete the given key-value pair if it exists.
 * Returns false iff the key is not found.
 */
bool KVStore::del(uint64_t key)
{
    bool isFind = false;
    // frist , we find in memTable
    std::string v = memTable.get(key , isFind);

    //Then , we find it in ssTable
    if(isFind)
	{
        memTable.put(key , "~DELETED~");
        return true;
    }
    else
        for(int i = 0 ; i < this->sslevel.size() ; i++)
        {
            for(int j = 0 ; j < this->sslevel[i].currentNum ; j++)
            {
                if(key <= this->sslevel[i].ssNodes[j].max && key >= this->sslevel[i].ssNodes[j].min)
                {
                    std::string filename = this->vlogDir + std::to_string(i)+ "/ssTable/" + std::to_string(j);
                    std::ifstream file(filename);
                    std::cout << "delt in ssTable";
                    bool isExist = true;
                    if(isExist)
                        return true;
                }
            }
        }
    return false;
}

/**
 * This resets the kvstore. All key-value pairs should be removed,
 * including memtable and all sstables files.
 */
void KVStore::reset()
{
    for(int i = 0 ; i <= this->sslevel.size() ; i++)
    {
        std::string dirName = "./data/vlog/Level" + std::to_string(i);
        if(this->sslevel.size() == 0) return;
        for(int j = 0 ; j <= this->sslevel[i].currentNum ; j++)
        {
            std::string fileName =  dirName + "/ssTable" + std::to_string(j + 1) ;
            utils::rmfile(fileName);
        }
        utils::rmdir(dirName);
    }
}

/**
 * Return a list including all the key-value pair between key1 and key2.
 * keys in the list should be in an ascending order.
 * An empty string indicates not found.
 */
void KVStore::scan(uint64_t key1, uint64_t key2, std::list<std::pair<uint64_t, std::string>> &list)
{

    //get menTable frist
    QuadlistNode * node = this->memTable.frist()->frist();
    while(node->succ != nullptr)
    {
        //if it is between the size , add it into list
        if(node->key <= key2 && node->key >= key1)
        {
            std::pair<uint64_t, std::string> cur_pair;
            cur_pair.first = node->key ;
            cur_pair.second = node->entry;
            list.push_back(cur_pair);
        }
        node= node->succ;
    }

    //Find in ssTable
    for(int i = 0 ; i < this->sslevel.size() ; i++)
    {
        for(int j = 0 ; j < this->sslevel[i].currentNum ; j++)
        {
            if(key1 <= this->sslevel[i].ssNodes[j].max && key1 >= this->sslevel[i].ssNodes[j].min ||
                key2 <= this->sslevel[i].ssNodes[j].max && key2 >= this->sslevel[i].ssNodes[j].min)
            {
                std::string filename = this->vlogDir + std::to_string(i)+ "/ssTable/" + std::to_string(j);
                std::ifstream file(filename);
                // std::cout << "data may in ssTable";
                bool isExist = true;
                if(isExist)
                {
                    std::pair<uint64_t, std::string> cur_pair;
                    cur_pair.first = 0 ;
                    cur_pair.second = "";
                    list.push_back(cur_pair);
                }

            }
        }
    }
}

/**
 * This reclaims space from vLog by moving valid value and discarding invalid value.
 * chunk_size is the size in byte you should AT LEAST recycle.
 */
void KVStore::gc(uint64_t chunk_size)
{
}

std::string to8Bits(uint64_t value)
{
    std::string binaryString;
    binaryString.reserve(64);

    for (int i = 0; i < 8; i++) {
        char byte = (value % 256);
        value >>= 3;
        binaryString.push_back(byte);
    }

    return binaryString;
}

std::string to4Bits(unsigned int  value)
{
    std::string binaryString;
    binaryString.reserve(32);

    for (int i = 0; i < 4; i++) {
        char byte = (value % 256);
        value >>= 3;
        binaryString.push_back(byte);
    }

    return binaryString;
}

void KVStore::buildSSTable()
{
    // bool isExist = utils::dirExists("");
    //build ssTable

    // 获取当前时间戳
    auto now = std::chrono::system_clock::now();
    uint64_t timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
    uint64_t num_of_key = memTable.getSize();
    uint64_t min_key = memTable.getMinKey();
    uint64_t max_key = memTable.getMaxKey();

    ssTable += to8Bits(timestamp) + to8Bits(num_of_key) + to8Bits(min_key) + to8Bits(max_key);

    auto node = this->memTable.list[0]->frist();
    unsigned int vec[2048] = {0};
    while(node != nullptr)
    {
        long long key = 103122;
        unsigned int hash[4] = {0};
        MurmurHash3_x64_128(&key, sizeof(key), 1, hash);
        for(int i = 0 ; i < 4 ; i++)
        {
            int val = hash[i] % 65536 ;
            int k = val / 32;
            int j = val % 32;
            vec[k] |= (1 << j);
        }
        node = node->succ;
    }
    for(int i = 0 ; i < 2048 ; i++)
        ssTable += to4Bits(vec[i]);
    

    uint64_t current_key = 0;
    uint64_t offset = 0;
    unsigned int vlen = 0;
    while( ssTable.length() + 20 <= 16 * 1024)
    {
        ssTable += to8Bits(current_key) + to8Bits(offset) + to4Bits(vlen);
        current_key++;
    }
    std::cout << ssTable.length() << std::endl;
    std::cout << current_key;

    //把文件添加到Level0中,并设置每个文件ssTable范围
    std::string fileName ;
    if(this->sslevel.size() == 0)
    {
        ssLevel s0;
        s0.currentNum = 0;
        s0.level = 0;
        sslevel.push_back(s0);
        std::cout << utils::_mkdir( vlogDir + "/Level0" );
    }
    //
    sslevel[0].currentNum ++;
    ssNode s(max_key , min_key);
    sslevel[0].ssNodes.push_back( s);
    fileName = vlogDir + "/Level0/ssTable" + std::to_string(sslevel[0].currentNum );

    std::ofstream file(fileName);
    std::cout << file.is_open();
    file << ssTable;
    file.close();
    // TODO: Your code here
    if(sslevel[0].currentNum >= 3)
    {
        //compaction
        SSTableCompaction();
    }
    this->memTable.clear();
}

void KVStore::SSTableCompaction()
{
    
}
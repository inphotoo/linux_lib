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

	Quadlist *f = last();
    QuadlistNode *p = f->frist();
    while(p != nullptr)
    {
        //寻找合适插入的位置
        while(p->succ && (key >= p->key) )
            p = p->succ;
        //向后退一步
        p = p->prev;
        //当P的key是目标插入的key且不为表头，全部替换
        if(p->key == key &&  p->entry != f->frist()->prev->entry)
        {
            //找到底部
            while(p->below != nullptr)
                p = p->below;
            //改变当前数值
            //向上全部修改
            if(p->entry == "~DELETED~")
                list[0]->size ++;
            while(p != nullptr)
                {
                    p->entry = val;
                    p = p->above;
                }
            return;
        }
        else
        {
            //如果到达最底层返回，否则继续向下寻找
            if(p->below == nullptr) break;
            else p = p->below;
        }
    }// find the place of insert

    Quadlist *listlast = this->frist();
    //最底层先插入
    listlast->insertAfterAbove(key , val ,p , nullptr);
    listlast->size ++;
    // 创建随机数
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    int height = 0;
    p = p->succ;
    while(true)
    {
        //如果随机数大于预定概率，则新增一层
        double randNum = dis(gen);
        if(randNum >= this->p) return;
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
	Quadlist *li = last();
    QuadlistNode * p = li->frist();
    if(p == nullptr) return "";
    while(true)
    {
        while(p->succ && (p->key <= key))
            p = p->succ;
        p = p->prev;
        if(p && p->key == key && p->entry != li->frist()->prev->entry)
        {
//            if(p->entry != "~DELETED~" )
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
    return this->list[0]->size;
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
    //首先在跳表中插入
    bool isFind = false;
    std::string v = memTable.get(key , isFind);

    std::cerr << memTable.getSize();
    //如果最底层那一层
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
    if(v == "~DELETED~") return"";
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
                    std::string filename = this->vlogDir + "/Level" + std::to_string(i )+ "/ssTable" + std::to_string(j + 1);
//                    std::ifstream file(filename);
//                    std::cout << "find in ssTable";
                    bool isExist = false;
                    std::ifstream file(filename, std::ios::binary);
                    std::stringstream buffer;
                    buffer << file.rdbuf();
                    std::string str = buffer.str();
                    auto [dataOffset, valueLen] = findInssTable(str ,key , &isExist);
                    if(isExist)
                    {
                        return KVStore::readFromVLog(dataOffset , valueLen);
                    }
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
    // 首先，在memTable中寻找
    std::string v = memTable.get(key , isFind);
    // 然后，在ssTable中寻找
    if(v == "~DELETED~") return false;
    if(isFind)
	{
        memTable.put(key , "~DELETED~");
        memTable.list[0]->size --;
        return true;
    }
    else
        for(int i = 0 ; i < this->sslevel.size() ; i++)
        {
            std::string dirName = "./data/vlog/Level" + std::to_string(i);
            for(int j = 0 ; j < this->sslevel[i].currentNum ; j++)
            {
                if(key <= this->sslevel[i].ssNodes[j].max && key >= this->sslevel[i].ssNodes[j].min)
                {
                    std::string fileName =  dirName + "/ssTable" + std::to_string(j + 1) ;
//                    std::cout << "delt in ssTable";
                    bool isExist = true;
                    std::ifstream file(fileName, std::ios::binary);
                    std::stringstream buffer;
                    buffer << file.rdbuf();
                    std::string str = buffer.str();
                    auto [dataOffset, valueLen] = findInssTable(str ,key , &isExist);
                    if(isExist)
                    {
                        memTable.put(key , "~DELETED~");
                        return true;
                    }
                    return false;
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
    util::rmfile("./data/vlog/vLog")
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
        //如果在列表之间，加入列表
        if(node->key <= key2 && node->key >= key1)
        {
            std::pair<uint64_t, std::string> cur_pair;
            cur_pair.first = node->key ;
            cur_pair.second = node->entry;
            list.push_back(cur_pair);
        }
        node= node->succ;
    }

    //在ssTable中寻找
    //对于其中的每一个节点
    for(int i = 0 ; i < this->sslevel.size() ; i++)
    {
        for(int j = 0 ; j < this->sslevel[i].currentNum ; j++)
        {
            if( this->sslevel[i].ssNodes[j].max  >= key1 &&
                key2 >= this->sslevel[i].ssNodes[j].min)
            {
                std::string filename = vlogDir + "/Level0/ssTable" + std::to_string(j + 1);
//                std::ifstream file(filename);
                // std::cout << "data may in ssTable";
                // 后续补
                std::ifstream file(filename, std::ios::binary);
                std::stringstream buffer;
                buffer << file.rdbuf();
                std::string str = buffer.str();
                auto list_find= findInSsTableByRange(str , key2 , key1);
                for(auto item : list_find)
                {
                    auto [key ,dataOffset,vLen] = item;
                    std::string entry = readFromVLog(dataOffset , vLen);
                    std::pair<uint64_t, std::string> cur_pair;
                    cur_pair.first = key ;
                    cur_pair.second = entry;
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

std::string to8Bytes(uint64_t value) {
    std::string binaryString;
    binaryString.reserve(8);

    for (int i = 0; i < 8; ++i) {
        char byte = static_cast<char>(value & 0xFF);
        value >>= 8;
        binaryString.push_back(byte);
    }

    return binaryString;
}

std::string to4Bytes(uint64_t value) {
    std::string binaryString;
    binaryString.reserve(4);

    for (int i = 0; i < 4; ++i) {
        char byte = static_cast<char>(value & 0xFF);
        value >>= 8;
        binaryString.push_back(byte);
    }

    return binaryString;
}

std::string to2Bytes(uint64_t value) {
    std::string binaryString;
    binaryString.reserve(8);

    for (int i = 0; i < 2; ++i) {
        char byte = static_cast<char>(value & 0xFF);
        value >>= 8;
        binaryString.push_back(byte);
    }

    return binaryString;
}

std::string toByte(uint64_t value) {
    std::string binaryString;
    binaryString.reserve(1);

    char byte = static_cast<char>(value & 0xFF);
    value >>= 8;
    binaryString.push_back(byte);

    return binaryString;
}

void KVStore::buildSSTable()
{
    //先把内容追加到vLog里面
    appendVLog();
    // bool isExist = utils::dirExists("");
    //build ssTable

    // 获取当前时间戳
    auto now = std::chrono::system_clock::now();
    uint64_t timestamp = std::chrono::time_point_cast<std::chrono::milliseconds>(now).time_since_epoch().count();
    uint64_t num_of_key = memTable.getSize();
    uint64_t min_key = memTable.getMinKey();
    uint64_t max_key = memTable.getMaxKey();

    //ssTable前32位，分别是：时间戳，最小的key，key数量,最大的key值是多少
    ssTable += to8Bytes(timestamp) + to8Bytes(num_of_key) + to8Bytes(min_key) + to8Bytes(max_key);

    auto node = this->memTable.list[0]->frist();
    unsigned int vec[2048] = {0};
    while(node->succ != nullptr)
    {
        uint64_t key = node->key;
        unsigned int hash[4] = {0};
        MurmurHash3_x64_128(&key, sizeof(key), 1, hash);
        //布隆过滤器，8192个bit分别设置，如果存在设置为1
        for(int i = 0 ; i < 4 ; i++)
        {
            int val = hash[i] % 65536 ;
            int k = val / 32;
            int j = val % 32;
            vec[k] |= (1 << j);
        }
        node = node->succ;
        key++;
    }
    for(int i = 0 ; i < 2048 ; i++)
        ssTable += to4Bytes(vec[i]);

    uint64_t current_key = 0;

    uint64_t offset = Head ;
    auto cur_node = this->memTable.list[0]->frist();
//    while( ssTable.length() + 20 <= 16 * 1024 && cur_node)
    while(cur_node->succ != nullptr)
    {
        //开始位置：当前头位置
        unsigned int vlen = 0;
        if(cur_node->entry == "~DELETED~")
        {
            cur_node = cur_node->succ;
            continue;
        }
        vlen = cur_node->entry.size();
        ssTable += to8Bytes(cur_node->key) + to8Bytes(Head) + to4Bytes(vlen);
        // 头位置向后偏移
        Head +=  1 + 2 + 8 + 4 + vlen ; //Magic + checksum + key + entryLen + entry;
        current_key++;
        cur_node = cur_node->succ;
    }
    std::cerr << ssTable.length() << std::endl;
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
    //ssLevel里面缓存了所有的ssTable
    sslevel[0].currentNum ++;
    ssNode s(max_key , min_key);
    sslevel[0].ssNodes.push_back( s);
    fileName = vlogDir + "/Level0/ssTable" + std::to_string(sslevel[0].currentNum );

    std::ofstream file(fileName);
    std::cout << file.is_open();
    file << ssTable;
    file.close();
    // 如果0层大于3个，就要开始合并
    if(sslevel[0].currentNum >= 3)
    {
        //compaction
        SSTableCompaction();
    }
    //不留缓存
    this->memTable.clear();
}

void KVStore::appendVLog()
{
    std::string append_vlog ;
    auto node = this->memTable.list[0]->frist();
    while(node->succ != nullptr)
    {
        //如果是被删除的，就不用写到vlog里面
        if(node->entry == "~DELETED~")
        {
            node = node->succ;
            continue;
        }
        //data: 校验和数据 key , vlen , entry合并而成。
        std::string data = to8Bytes(node->key) + to4Bytes(node->entry.length()) + node->entry;
        std::vector<unsigned char> data_vector(data.begin() , data.end());
        //vlog = Magic + checksum + key + vlen + value
        std::string vLog = toByte(INT8_MAX) + to2Bytes(utils::crc16(data_vector)) +
                to8Bytes(node->key) + to4Bytes(node->entry.length()) + node->entry;
        node = node->succ;
        append_vlog += vLog;
//        std::cerr << append_vlog.size();
    }
    std::string vLogName = vlogDir + "/vLog";
    std::ofstream file(vLogName , std::ios::app);
    if(!file.is_open())
    {
        std::cout << "Failed to open the file: " << vLogName << std::endl;
    }
    else
    {
        std::cerr << append_vlog.size();
        file << append_vlog;
    }
    file.flush();
    file.close();

}
void KVStore::SSTableCompaction()
{
    //将要被归并的nodes
    std::list<ssNode> selectedNodes;
    // Level 0 层中所有 SSTable 所覆盖的键的区间
    uint64_t ss_min = UINT64_MAX;
    uint64_t ss_max = 0;
    for(auto ssNode:  sslevel[0].ssNodes)
    {
        if(ssNode.min < ss_min) ss_min = ssNode.min;
        if(ssNode.max > ss_max) ss_max = ssNode.max;
        selectedNodes.push_back(ssNode);
    }

    // 在level1层中找到所有有交集的文件

    if(sslevel.size() <= 1) return ;//不level1
    for(auto ssnode : sslevel[1].ssNodes)
    {
        //两个区间有交集
        if(ssnode.max >= ss_min && ss_max > ssnode.min)
        {
            selectedNodes.push_back(ssnode);
        }
    }

}

// 将 8 字节的字符串转换为 uint64_t
uint64_t from8Bytes(const std::string& str) {
    if (str.size() < 8) throw std::runtime_error("Insufficient data for uint64_t conversion");
    uint64_t value;
    std::memcpy(&value, str.data(), 8);
    return value;
}

// 将 4 字节的字符串转换为 uint32_t
uint32_t from4Bytes(const std::string& str) {
    if (str.size() < 4) throw std::runtime_error("Insufficient data for uint32_t conversion");
    uint32_t value;
    std::memcpy(&value, str.data(), 4);
    return value;
}

bool checkBloomFilter(const std::vector<unsigned int>& vec, uint64_t key) {
    unsigned int hash[4] = {0};
    MurmurHash3_x64_128(&key, sizeof(key), 1, hash);
    for (int i = 0; i < 4; ++i) {
        int val = hash[i] % 65536;
        int k = val / 32;
        int j = val % 32;
        if (!(vec[k] & (1 << j))) {
            return false;
        }
    }
    return true;
}

std::tuple<uint64_t, uint32_t> KVStore::findInssTable(std::string str, uint64_t key ,  bool *isExist) {
    uint64_t timestamp = from8Bytes(str.substr(0, 8));
    uint64_t num_of_key = from8Bytes(str.substr(8, 8));
    uint64_t min_key = from8Bytes(str.substr(16, 8));
    uint64_t max_key = from8Bytes(str.substr(24, 8));
    // 解析布隆过滤器
    std::vector<uint32_t> bloomFilter(2048);
    size_t offset = 32;
    for (size_t i = 0; i < 2048; ++i) {
        bloomFilter[i] = from4Bytes(str.substr(offset, 4));
        offset += 4;
    }
    *isExist = checkBloomFilter(bloomFilter, key);
    if (*isExist) {
        for (uint64_t i = 0; i < num_of_key; ++i) {
            uint64_t ss_key = from8Bytes(str.substr(offset, 8));
            offset += 8;
            uint64_t dataOffset = from8Bytes(str.substr(offset, 8));
            offset += 8;
            uint32_t valueLen = from4Bytes(str.substr(offset, 4));
            offset += 4;
            if (key == ss_key)
                return std::make_tuple(dataOffset, valueLen);
        }
        *isExist = false;
        return std::make_tuple(0, 0);
    }
}

std::list<std::tuple<uint64_t  ,uint64_t, uint32_t>> KVStore::findInSsTableByRange(std::string str , uint64_t max_key , uint64_t min_key)
{
    std::list<std::tuple<uint64_t,uint64_t  , uint32_t>> list;
    uint64_t timestamp = from8Bytes(str.substr(0, 8));
    uint64_t num_of_key = from8Bytes(str.substr(8, 8));
//    uint64_t min_key = from8Bytes(str.substr(16, 8));
//    uint64_t max_key = from8Bytes(str.substr(24, 8));
    // 解析布隆过滤器
    std::vector<uint32_t> bloomFilter(2048);
    size_t offset = 32;
    for (size_t i = 0; i < 2048; ++i) {
        bloomFilter[i] = from4Bytes(str.substr(offset, 4));
        offset += 4;
    }
    for (uint64_t i = 0; i < num_of_key; ++i) {
        uint64_t ss_key = from8Bytes(str.substr(offset, 8));
        offset += 8;
        uint64_t dataOffset = from8Bytes(str.substr(offset, 8));
        offset += 8;
        uint32_t valueLen = from4Bytes(str.substr(offset, 4));
        offset += 4;
        if ( ss_key <= max_key && ss_key >= min_key)
            list.push_back(std::make_tuple(ss_key,dataOffset , valueLen));
    }
    return list;

}
std::string KVStore::readFromVLog(uint64_t dataOffset, uint32_t valueLen) {
    std::string vLogName = vlogDir + "/vLog";
    std::ifstream file(vLogName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << vLogName << std::endl;
        return "";
    }
    //seekg 方法将文件指针移动到指定的 dataOffset 位置
    file.seekg(dataOffset, std::ios::beg);

    // 读取完整的vLog条目: Magic + checksum + key + vlen + value
    const int headerSize = 1 + 2 + 8 + 4; // Magic (1 byte) + checksum (2 bytes) + key (8 bytes) + vlen (4 bytes)
    std::vector<char> buffer(headerSize + valueLen);
    file.read(buffer.data(), buffer.size());

    if (!file) {
        std::cerr << "Failed to read the data from the file: " << vLogName << std::endl;
        file.close();
        return "";
    }

    std::string entry(buffer.begin() + headerSize, buffer.end());
    file.close();
    return entry;
}

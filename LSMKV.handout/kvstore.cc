#include "kvstore.h"
#include <string>
#include <random>
#include <fstream>
#include <chrono>
#include <iostream>
#include <unordered_map>
#include <filesystem>
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
//            if(p->entry == "~DELETED~")
//                list[0]->size ++;
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
    utils::_mkdir(dataDir);

    // 如果数据目录中存在文件，则进行初始化
    if (std::filesystem::exists(vlogDir) && std::filesystem::file_size(vlogDir) > 0) {
        KVStore::initialize();
    }

    // 恢复 head 的正确值
    Head = std::filesystem::exists(vlogDir) ? std::filesystem::file_size(vlogDir) : 0;

    // 恢复 tail 的正确值
    Tail = std::filesystem::exists(vlogDir) ? seekDataBlock(vlogDir) : 0;

}

void KVStore::initialize()
{
// 检查并加载 SSTable 文件
    ssLevel newLevel;
    newLevel.level = 0;
    newLevel.currentNum = 0;
    sslevel.push_back(newLevel);
    for (int i = 0; ; ++i) {
        std::string dirName = dataDir + "/Level" + std::to_string(i);
        if (!utils::dirExists(dirName)) break;

        for (const auto& entry : std::filesystem::directory_iterator(dirName)) {
            std::string filename = entry.path().string();
            // 读取 SSTable 文件并更新缓存
            std::ifstream file(filename, std::ios::binary);
            if (!file.is_open()) continue;
            std::stringstream buffer;
            buffer << file.rdbuf();
            std::string str = buffer.str();
            uint64_t timestamp = from8Bytes(str.substr(0 , 8));
            uint64_t keyNum = from8Bytes(str.substr(8,8));
            uint64_t minKey = from8Bytes(str.substr(16, 8));
            uint64_t maxKey = from8Bytes(str.substr(24, 8));
            ssNode node(maxKey, minKey);
            node.filename = filename;
            node.str = str;
            node.timestamp = timestamp;
            if (i >= sslevel.size()) {
                ssLevel newLevel;
                newLevel.level = i;
                newLevel.currentNum = 0;
                sslevel.push_back(newLevel);
            }
            sslevel[i].currentNum = keyNum;
            sslevel[i].ssNodes.push_back(node);
        }
    }
}
KVStore::~KVStore()
{
    this;
    // 在析构函数中将 MemTable 中的所有数据写入 SSTable 和 vLog
    if (memTable.getSize() > 0) {
        buildSSTable();
    }
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

    //std::cerr << memTable.getSize();
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
            for(int j = 0 ; j < this->sslevel[i].ssNodes.size() ; j++)
            {
                if(key <= this->sslevel[i].ssNodes[j].max && key >= this->sslevel[i].ssNodes[j].min)
                {
                    std::string  filename = this->sslevel[i].ssNodes[j].filename;
//                    std::string filename = this->vlogDir + "/Level" + std::to_string(i )+ "/ssTable" + std::to_string(j + 1);
//                    std::ifstream file(filename);
//                    std::cout << "find in ssTable";
                    bool isExist = false;
                    bool isFound = false;
                    std::ifstream file(filename, std::ios::binary);
                    std::stringstream buffer;
                    buffer << file.rdbuf();
                    std::string str = buffer.str();
                    auto [dataOffset, valueLen] = findInssTable(str ,key , &isExist , &isFound);
                    if(isFound )
                    {
                        if(isExist)
                            return KVStore::readFromVLog(dataOffset , valueLen);
                        return "";
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
    std::string v = memTable.get(key, isFind);
    // 如果在memTable中找到并且不是被删除标记
    if (isFind) {
        if (v != "~DELETED~") {
            memTable.put(key, "~DELETED~");
            return true;
        }
        return false; // 已经是删除标记
    }

    // 然后，在ssTable中寻找
    for (int i = 0; i < this->sslevel.size(); i++) {
        for (int j = 0; j < this->sslevel[i].ssNodes.size(); j++) {
            if (key <= this->sslevel[i].ssNodes[j].max && key >= this->sslevel[i].ssNodes[j].min) {
                std::string fileName = this->sslevel[i].ssNodes[j].filename;
                bool isExist = false;
                bool isFound = false;
                std::ifstream file(fileName, std::ios::binary);
                std::stringstream buffer;
                buffer << file.rdbuf();
                std::string str = buffer.str();
                auto [dataOffset, valueLen] = findInssTable(str, key, &isExist , &isFound);
                // 如果找到，就插入一条被删除的记录
                if (isFound) {
                    if(isExist)
                    {
                        memTable.put(key, "~DELETED~");
                        return true;
                    }
                    return false;
                }
            }
        }
    }

    // 在所有层次中都未找到该key
    return false;
}

/**
 * This resets the kvstore. All key-value pairs should be removed,
 * including memtable and all sstables files.
 */
void KVStore::reset()
{
    // 删除所有 SSTable 文件和表示层的目录
    for (int i = 0; i < sslevel.size(); ++i) {
        std::string dirName = dataDir + "/Level" + std::to_string(i);
        for (const auto& ssNode : sslevel[i].ssNodes) {
            utils::rmfile(ssNode.filename);
        }
        utils::rmdir(dirName);
    }

    // 删除 vLog 文件
    utils::rmfile(vlogDir);

    // 清除内存中 MemTable 和缓存数据
    memTable.clear();
    sslevel.clear();
    ssTable.clear();

    // 将 tail 和 head 的值置 0
    Tail = 0;
    Head = 0;
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
        for(int j = 0 ; j < this->sslevel[i].ssNodes.size(); j++)
        {
            if( this->sslevel[i].ssNodes[j].max  >= key1 &&
                key2 >= this->sslevel[i].ssNodes[j].min)
            {
                std::string filename = this->sslevel[i].ssNodes[j].filename;
//                std::string filename = vlogDir + "/Level0/ssTable" + std::to_string(j + 1);
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
    list.sort([](const std::pair<uint64_t, std::string> &a, const std::pair<uint64_t, std::string> &b) {
        return a.first < b.first;
    });
}

/**
 * This reclaims space from vLog by moving valid value and discarding invalid value.
 * chunk_size is the size in byte you should AT LEAST recycle.
 */
void KVStore::gc(uint64_t chunk_size) {
    std::string vLogName = vlogDir;
    std::ifstream file(vLogName, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << vLogName << std::endl;
        return;
    }

    file.seekg(Tail, std::ios::beg);

    uint64_t totalProcessedSize = 0;
    std::vector<char> leftoverBuffer;  // 缓存上次读取不足的数据

    uint64_t lastLen = 0;
    while (totalProcessedSize < chunk_size) {
        // 批量读取数据，减少文件 I/O 操作次数
        std::vector<char> buffer(chunk_size);
        uint64_t readSize = std::max(lastLen , chunk_size);
        file.read(buffer.data(), readSize);
        size_t bufferSize = file.gcount();
        if (bufferSize == 0) break;  // 已经到达文件末尾

        if (!leftoverBuffer.empty()) {
            // 将缓存的数据与新读取的数据合并
            buffer.insert(buffer.begin(), leftoverBuffer.begin(), leftoverBuffer.end());
            bufferSize += leftoverBuffer.size();
            leftoverBuffer.clear();
        }

        const char* ptr = buffer.data();
        size_t processedSize = 0;

        while (processedSize < bufferSize && totalProcessedSize < chunk_size) {
            // 读取头部：Magic (1字节) + 校验和 (2字节) + key (8字节) + vlen (4字)
            const int headerSize = 1 + 2 + 8 + 4;
            if (bufferSize - processedSize < headerSize) {
                leftoverBuffer.insert(leftoverBuffer.end(), ptr, ptr + (bufferSize - processedSize));
                break; // 剩余数据不足以读取头部，缓存并跳出循环
            }

            uint64_t key = from8Bytes(std::string(ptr + 3, 8));
            uint32_t valueLen = from4Bytes(std::string(ptr + 11, 4));

            if (bufferSize - processedSize < headerSize + valueLen) {
                leftoverBuffer.insert(leftoverBuffer.end(), ptr, ptr + (bufferSize - processedSize));
                break; // 剩余数据不足以读取完整条目，缓存并跳出循环
            }

            std::string valueStr(ptr + headerSize, valueLen);

            // 验证当前条目是否是 LSM Tree 中的最新值
            bool isLatest = false;
            bool isMemFind = false;
            std::string memValue = memTable.get(key, isMemFind);

            if (isMemFind && memValue == valueStr) {
                isLatest = true;
            } else if (!isMemFind) {
                std::string storeValue = get(key);
                if (storeValue == valueStr) {
                    isLatest = true;
                }
            }

            if (isLatest) {
                // 如果是最新值，重新插入到 MemTable 中
                memTable.put(key, valueStr);
            }

            processedSize += headerSize + valueLen;
            totalProcessedSize += headerSize + valueLen;
            ptr += headerSize + valueLen;
            Tail += headerSize + valueLen; // 更新tail的位置
        }

        // 如果到达文件末尾
        if (file.eof()) {
            break;
        }
    }

    file.close();

    // 如果 MemTable 中有任何条目，写入到 SSTable 中
    if (memTable.getSize() > 0) {
        buildSSTable();
    }

    // 对处理过的 vLog 文件区域打洞
    utils::de_alloc_file(vLogName, 0, Tail);
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
    ssTable.clear();
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
//        if(cur_node->entry == "~DELETED~")
//        {
//            cur_node = cur_node->succ;
//            continue;
//        }
        if(cur_node->entry == "~DELETED~")
            vlen = 0;
        else vlen = cur_node->entry.size();
        ssTable += to8Bytes(cur_node->key) + to8Bytes(Head) + to4Bytes(vlen);
        // 头位置向后偏移
        Head +=  1 + 2 + 8 + 4 + vlen ; //Magic + checksum + key + entryLen + entry;
        current_key++;
        cur_node = cur_node->succ;
    }
//    std::cerr << ssTable.length() << std::endl;
//    std::cout << current_key;

    //把文件添加到Level0中,并设置每个文件ssTable范围
    std::string fileName ;
    if(this->sslevel.size() == 0)
    {
        ssLevel s0;
        s0.currentNum = 0;
        s0.level = 0;
        sslevel.push_back(s0);
        //std::cout <<
        utils::_mkdir( dataDir + "/Level0" );
    }
    //ssLevel里面缓存了所有的ssTable
    sslevel[0].currentNum ++;
    ssNode s(max_key , min_key);
    fileName = dataDir + "/Level0/ssTable" + std::to_string(sslevel[0].currentNum + 1);
    s.filename = fileName;
    s.str = ssTable;
    s.value = sslevel[0].ssNodes.size();
    sslevel[0].ssNodes.push_back(s);


    std::ofstream file(fileName);
//    std::cout << file.is_open();
    file << ssTable;
    file.close();
    // 如果0层大于3个，就要开始合并
    if(sslevel[0].ssNodes.size() >= 3)
    {
        sslevel;
        //compaction
        SSTableCompaction();
    }
    //不留缓存
    this->memTable.clear();
}

void KVStore::appendVLog() {
    std::ostringstream append_vlog;
    auto node = this->memTable.list[0]->frist();

    while (node->succ != nullptr) {
        // 构建 vLog 条目
        std::string value;
        uint32_t vlen;
        if (node->entry == "~DELETED~") {
            value = "";
            vlen = 0;
        } else {
            value = node->entry;
            vlen = node->entry.length();
        }

        std::string data = to8Bytes(node->key) + to4Bytes(vlen) + value;
        std::vector<unsigned char> data_vector(data.begin(), data.end());

        // vLog = Magic + checksum + key + vlen + value
        append_vlog << toByte(INT8_MAX)
                    << to2Bytes(utils::crc16(data_vector))
                    << to8Bytes(node->key)
                    << to4Bytes(vlen)
                    << value;

        node = node->succ;
    }

    std::string vLogName = vlogDir;
    std::ofstream file(vLogName, std::ios::app | std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << vLogName << std::endl;
        return;
    }

    std::string vlogData = append_vlog.str();
    file.write(vlogData.data(), vlogData.size());

    if (!file) {
        std::cerr << "Failed to write to the file: " << vLogName << std::endl;
    }

    file.close();
}
void KVStore::SSTableCompaction() {
    // 将要被归并的nodes
    std::list<ssNode> selectedNodes;
    std::unordered_set<std::string> selectedFilenames;
    // Level 0 层中所有 SSTable 所覆盖的键的区间
    uint64_t ss_min = UINT64_MAX;
    uint64_t ss_max = 0;
    for (auto ssNode : sslevel[0].ssNodes) {
        if (ssNode.min < ss_min) ss_min = ssNode.min;
        if (ssNode.max > ss_max) ss_max = ssNode.max;
        selectedNodes.push_back(ssNode);
    }

    for (const auto& node : selectedNodes) {
        selectedFilenames.insert(node.filename);
    }

    if (sslevel.size() > 1)  // 不存在level1
        // 在下一层中找到所有有交集的文件
        for (const auto& node : sslevel[ 1].ssNodes) {
            for (const auto& selectedNode : selectedNodes) {
                if (node.min <= selectedNode.max && node.max >= selectedNode.min) {
                    if (selectedFilenames.find(node.filename) == selectedFilenames.end()) {
                        selectedNodes.push_back(node);
                        selectedFilenames.insert(node.filename);
                    }
                    break;
                }
            }
        }

//    // 在level1层中找到所有有交集的文件
//    if (sslevel.size() > 1)  // 不存在level1
//        for (auto ssnode : sslevel[1].ssNodes) {
//            // 两个区间有交集
//            if (ssnode.max >= ss_min && ss_max > ssnode.min) {
//                selectedNodes.push_back(ssnode);
//            }
//        }

    // 合并选中的SSTables
    auto strLists = compaction(selectedNodes);

    // 将合并结果写入Level 1层
    for (const auto &str : strLists) {
        ssNode newNode = writeSSTableToFile(str , 1);
        sslevel[1].ssNodes.push_back(newNode);
    }

    // 检查Level 1层文件数量是否超出限制
    if (sslevel[1].ssNodes.size() > 4) {
        compactLevel(1);
    }

    // 清空Level 0层已合并的文件
    for(auto ssnode : sslevel[0].ssNodes)
    {
        utils::rmfile(ssnode.filename);
    }
    sslevel[0].ssNodes.clear();

}
//自我检查，这一层如果有范围重叠的，则合并
void KVStore::selfCompaction(int level)
{
    // 将要被归并的nodes
    std::list<ssNode> selectedNodes;
    std::vector<bool> merged(sslevel[level].ssNodes.size(), false);

    //首先检查范围有无重合
    for (size_t i = 0; i < sslevel[level].ssNodes.size(); ++i) {
        if (merged[i]) continue;

        ssNode& nodeA = sslevel[level].ssNodes[i];
        for (size_t j = i + 1; j < sslevel[level].ssNodes.size(); ++j) {
            if (merged[j]) continue;

            ssNode& nodeB = sslevel[level].ssNodes[j];
            // 检查两个区间是否有重叠
            if (nodeA.min <= nodeB.max && nodeA.max >= nodeB.min) {
                selectedNodes.push_back(nodeA);
                selectedNodes.push_back(nodeB);
                merged[i] = true;
                merged[j] = true;
                break;
            }
        }
        if (!merged[i]) {
            selectedNodes.push_back(nodeA);
            merged[i] = true;
        }
    }
    //去重
    selectedNodes.sort([](const ssNode& a, const ssNode& b) { return a.filename < b.filename; });
    selectedNodes.unique([](const ssNode& a, const ssNode& b) { return a.filename == b.filename; });

    auto strLists = compaction(selectedNodes);

    // 将合并结果写入本层
    for (const auto &str : strLists) {
        ssNode newNode = writeSSTableToFile(str , level );
        sslevel[level].ssNodes.push_back(newNode);
    }

    // 从当前层移除已合并的文件
    removeCompactedNodes(sslevel[level], selectedNodes);
}

void KVStore::compactLevel(int level) {
    if (level >= sslevel.size() - 1) {
        utils::mkdir(this->dataDir + "/Level" + std::to_string(level + 1));
        ssLevel ss;
        ss.currentNum = 0;
        ss.level = level + 1;
        sslevel.push_back(ss);
    }

    // 找出需要合并的文件，假设我们需要优先选择时间戳最小的若干个文件
    std::list<ssNode> selectedNodes = selectNodesForCompaction(level);
    std::unordered_set<std::string> selectedFilenames;

    // 将选中的节点文件名加入集合
    for (const auto& node : selectedNodes) {
        selectedFilenames.insert(node.filename);
    }

    if (sslevel.size() > level + 1)  // 不存在level1
        // 在下一层中找到所有有交集的文件
        for (const auto& node : sslevel[level + 1].ssNodes) {
            for (const auto& selectedNode : selectedNodes) {
                if (node.min <= selectedNode.max && node.max >= selectedNode.min) {
                    if (selectedFilenames.find(node.filename) == selectedFilenames.end()) {
                        selectedNodes.push_back(node);
                        selectedFilenames.insert(node.filename);
                    }
                    break;
                }
            }
        }

    // 合并选中的SSTables
    auto strLists = compaction(selectedNodes);

    // 将合并结果写入下一层
    for (const auto &str : strLists) {
        ssNode newNode = writeSSTableToFile(str, level + 1);
        sslevel[level + 1].ssNodes.push_back(newNode);
    }

    // 从当前层移除已合并的文件
    removeCompactedNodes(sslevel[level], selectedNodes);

    // 对下一层进行自我合并
    selfCompaction(level + 1);

    // 检查下一层文件数量是否超出限制
    if (sslevel[level + 1].ssNodes.size() > static_cast<size_t>(pow(2, level + 1))) {
        compactLevel(level + 1);
    }
}

void KVStore::removeCompactedNodes(ssLevel &level, const std::list<ssNode> &selectedNodes) {
    for (const auto &node : selectedNodes) {
        auto it = std::remove_if(level.ssNodes.begin(), level.ssNodes.end(),
                                 [&node](const ssNode &n) {
                                     return n.filename == node.filename;
                                 });
        level.ssNodes.erase(it, level.ssNodes.end());

        // 删除文件
        utils::rmfile(node.filename);
    }
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

uint64_t from8Bytes2(const char* data) {
    uint64_t value;
    std::memcpy(&value, data, 8);
    return value;
}

uint32_t from4Bytes2(const char* data) {
    uint32_t value;
    std::memcpy(&value, data, 4);
    return value;
}

std::tuple<uint64_t, uint32_t> KVStore::findInssTable(const std::string& str, uint64_t key, bool *isExist , bool *isFound) {
    const char* ptr = str.data();

    // 读取前32字节的元数据
    uint64_t timestamp = from8Bytes2(ptr);
    ptr += 8;
    uint64_t num_of_key = from8Bytes2(ptr);
    ptr += 8;
    uint64_t min_key = from8Bytes2(ptr);
    ptr += 8;
    uint64_t max_key = from8Bytes2(ptr);
    ptr += 8;

    // 解析布隆过滤器
    std::vector<uint32_t> bloomFilter(2048);
    for (size_t i = 0; i < 2048; ++i) {
        bloomFilter[i] = from4Bytes2(ptr);
        ptr += 4;
    }

    // 检查布隆过滤器
    *isExist = checkBloomFilter(bloomFilter, key);
    if (!*isExist) {
        return std::make_tuple(0, 0);
    }


    //二分查找
    // 使用二分查找在键区间中搜索
    uint64_t left = 0;
    uint64_t right = num_of_key - 1;

    while (left <= right) {
        uint64_t mid = left + (right - left) / 2;
        const char *cur_ptr = ptr + 20 * mid;
        uint64_t ss_key = from8Bytes2(cur_ptr);

        if (key == ss_key) {
            *isFound = true;
            uint64_t dataOffset = from8Bytes2(cur_ptr + 8);
            uint32_t valueLen = from4Bytes2(cur_ptr + 16);
            return std::make_tuple(dataOffset, valueLen);
        }

        if (ss_key < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    *isFound = false;
    *isExist = false;
    return std::make_tuple(0, 0);
}

std::list<std::tuple<uint64_t, uint64_t, uint32_t>> KVStore::findInSsTableByRange(const std::string& str, uint64_t max_key, uint64_t min_key) {
    std::list<std::tuple<uint64_t, uint64_t, uint32_t>> list;
    const char* ptr = str.data();

    uint64_t timestamp = from8Bytes2(ptr);
    ptr += 8;
    uint64_t num_of_key = from8Bytes2(ptr);
    ptr += 24;
//    ptr += 8;
//    ptr += 8; // skip min_key in metadata
//    ptr += 8; // skip max_key in metadata

    // 解析布隆过滤器
    std::vector<uint32_t> bloomFilter(2048);
    for (size_t i = 0; i < 2048; ++i) {
        bloomFilter[i] = from4Bytes2(ptr);
        ptr += 4;
    }

    // 使用二分查找找到范围的起始位置
    uint64_t left = 0;
    uint64_t right = num_of_key;
    uint64_t start = num_of_key;
    while (left < right) {
        uint64_t mid = left + (right - left) / 2;
        const char *cur_ptr = ptr + 20 * mid;
        uint64_t ss_key = from8Bytes2(cur_ptr);

        if (ss_key >= min_key) {
            start = mid;
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    // 使用二分查找找到范围的结束位置
    left = 0;
    right = num_of_key - 1;
    uint64_t end = num_of_key;
    while (left <= right) {
        uint64_t mid = left + (right - left) / 2;
        const char *cur_ptr = ptr + 20 * mid;
        uint64_t ss_key = from8Bytes2(cur_ptr);

        if (ss_key <= max_key) {
            end = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // 遍历找到的范围内的键值对
    for (uint64_t i = start; i <= end && i < num_of_key; ++i) {
        const char *cur_ptr = ptr + 20 * i;
        uint64_t ss_key = from8Bytes2(cur_ptr);
        uint64_t dataOffset = from8Bytes2(cur_ptr + 8);
        uint32_t valueLen = from4Bytes2(cur_ptr + 16);

        if (ss_key <= max_key && ss_key >= min_key && valueLen != 0) {
            list.push_back(std::make_tuple(ss_key, dataOffset, valueLen));
        }
    }

    return list;
}
std::string KVStore::readFromVLog(uint64_t dataOffset, uint32_t valueLen) {
    // 打开文件
    std::ifstream file(vlogDir, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << vlogDir << std::endl;
        return "";
    }

    // 将文件指针移动到指定的 dataOffset 位置
    file.seekg(dataOffset, std::ios::beg);

    // 读取完整的vLog条目: Magic + checksum + key + vlen + value
    const int headerSize = 1 + 2 + 8 + 4; // Magic (1 byte) + checksum (2 bytes) + key (8 bytes) + vlen (4 bytes)
    std::vector<char> buffer(headerSize + valueLen);

    // 读取数据
    if (!file.read(buffer.data(), buffer.size())) {
        std::cerr << "Failed to read the data from the file: " << vlogDir << std::endl;
        return "";
    }

    // 直接从buffer中构建entry字符串
    return std::string(buffer.data() + headerSize, valueLen);
}

//根据ssNodeList队列，返回ssTable纯字符串。
std::list<std::string> KVStore::compaction(std::list<ssNode> ssNodeList) {
    std::list<std::string> strs;
    std::unordered_map<uint64_t, sstable> sstable_map;
    uint64_t latest_timestamp = 0;

    for (const auto &ssnode : ssNodeList) {
        // 读取文件
        std::ifstream file(ssnode.filename, std::ios::binary);
        if (!file.is_open()) continue;

        // 读取文件内容到字符串
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string str = buffer.str();

        // 使用指针解析文件内容
        const char* ptr = str.data();
        uint64_t timestamp = from8Bytes2(ptr);
        ptr += 8;
        uint64_t num_of_key = from8Bytes2(ptr);
        ptr += 8;
        uint64_t min_key = from8Bytes2(ptr);
        ptr += 8;
        uint64_t max_key = from8Bytes2(ptr);
        ptr += 8;

        // 保留最大时间戳
        latest_timestamp = std::max(latest_timestamp, timestamp);

        // 跳过布隆过滤器
        ptr += 2048 * 4;

        for (uint64_t i = 0; i < num_of_key; ++i) {
            uint64_t ss_key = from8Bytes2(ptr);
            ptr += 8;
            uint64_t dataOffset = from8Bytes2(ptr);
            ptr += 8;
            uint32_t valueLen = from4Bytes2(ptr);
            ptr += 4;

//            // 为0表示该数据已被删除
//            if (valueLen == 0) continue;

            // 如果键已存在且新的时间戳更大，则覆盖
            auto it = sstable_map.find(ss_key);
            if (it == sstable_map.end() || it->second.timestamp < timestamp) {
                sstable_map[ss_key] = {timestamp, ss_key, valueLen, dataOffset};
            }
        }
    }

    // 将unordered_map中的值转换为vector，并按照key从小到大排序
    std::vector<sstable> s;
    for (const auto &pair : sstable_map) {
        s.push_back(pair.second);
    }
    std::sort(s.begin(), s.end(), [](const sstable &a, const sstable &b) {
        return a.key < b.key;
    });

    // 每408个合并成一个
    for (size_t i = 0; i < s.size(); i += 408) {
        std::string str;
        uint64_t num_of_key = std::min<size_t>(408, s.size() - i);
        uint64_t min_key = s[i].key;
        uint64_t max_key = s[i + num_of_key - 1].key;

        str += to8Bytes(latest_timestamp) + to8Bytes(num_of_key) + to8Bytes(min_key) + to8Bytes(max_key);

        unsigned int vec[2048] = {0};
        for (size_t j = 0; j < num_of_key; ++j) {
            uint64_t key = s[i + j].key;
            uint32_t hash[4] = {0};
            MurmurHash3_x64_128(&key, sizeof(key), 1, hash);
            for (int index = 0; index < 4; ++index) {
                int val = hash[index] % 65536;
                int k = val / 32;
                int l = val % 32;
                vec[k] |= (1 << l);
            }
        }
        for (int j = 0; j < 2048; ++j) {
            str += to4Bytes(vec[j]);
        }
        for (size_t j = 0; j < num_of_key; ++j) {
            str += to8Bytes(s[i + j].key) + to8Bytes(s[i + j].offset) + to4Bytes(s[i + j].valueLen);
        }
        strs.push_back(str);
    }

    return strs;
}

// 保持辅助函数不变
uint64_t from8Bytes(const char* data) {
    uint64_t value;
    std::memcpy(&value, data, 8);
    return value;
}

uint32_t from4Bytes(const char* data) {
    uint32_t value;
    std::memcpy(&value, data, 4);
    return value;
}

KVStore::ssNode KVStore::writeSSTableToFile(const std::string &str, int level) {

    if(level >= this->sslevel.size())
    {
        utils::mkdir(this->dataDir + "/Level" + std::to_string(level ));
        ssLevel ss;
        ss.level = level;
        ss.currentNum = 0;
        sslevel.push_back(ss);
    }
    // 时间戳
    uint64_t timestamp = std::chrono::system_clock::now().time_since_epoch().count();
    std::string filename =  this->dataDir + "/Level" + std::to_string(level )+ "/ssTable" + std::to_string(this->sslevel[level].currentNum + 1);

    // 将SSTable数据写入文件
    std::ofstream outFile(filename, std::ios::binary);
    outFile.write(str.data(), str.size());
    outFile.close();

    // 从SSTable数据中解析元数据
    uint64_t num_of_key = from8Bytes(str.substr(8, 8));
    uint64_t min_key = from8Bytes(str.substr(16, 8));
    uint64_t max_key = from8Bytes(str.substr(24, 8));

    // 创建并返回新的ssNode
    ssNode newNode(max_key,min_key);
    newNode.filename = filename;
    newNode.timestamp = timestamp;

    // 更新内存中的层次元数据
//    sslevel[level].ssNodes.push_back(newNode);
    sslevel[level].currentNum ++;
    return newNode;
}

//返回时间戳最小的和范围冲突的
std::list<KVStore::ssNode> KVStore::selectNodesForCompaction(int level) {
    std::list<ssNode> nodesToCompact(this->sslevel[level].ssNodes.begin(), this->sslevel[level].ssNodes.end());

    // 排序：首先按时间戳排序，然后按最小键值排序
    nodesToCompact.sort([](const ssNode &a, const ssNode &b) {
        if (a.timestamp == b.timestamp) {
            return a.min < b.min;
        }
        return a.timestamp < b.timestamp;
    });

    std::list<ssNode> ssnodes;
    size_t maxNodes = std::pow(2, level + 1);


    // 移动超出限制的节点到ssnodes
    while (nodesToCompact.size() > maxNodes) {
        ssnodes.push_back(nodesToCompact.front());
        nodesToCompact.pop_front();
    }

    return ssnodes;
}
off_t KVStore::seekDataBlock(const std::string& path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << path << std::endl;
        return 0;
    }

    off_t tail = 0;
    char byte;
    while (file.read(&byte, 1)) {
        if (byte != char(0)) {
            file.seekg(-1, std::ios::cur); // 移动文件指针到该字节的位置
            break;
        }
        ++tail;
    }

    file.close();
    return tail;
}
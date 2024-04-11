#include "kvstore.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    std::string dir = "./data", vlog = "./data/vlog";
    KVStore k(dir , vlog);
    k.put(114 , "114514");
    // std::cout << k.memTable.getSize();
    k.buildSSTable();
}
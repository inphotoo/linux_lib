#include "kvstore.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    std::string dir = "./data", vlog = "./data/vlog";
    KVStore k(dir , vlog);
    k.put(114 , "114514");
	k.put(1145 , "114514");
	k.put(11 , "114514");
    std::cout << k.memTable.getSize() << endl;
    k.buildSSTable();
	k.get(114);
	k.put(114 , "114514");
	k.buildSSTable();
	k.buildSSTable();
	k.reset();
}
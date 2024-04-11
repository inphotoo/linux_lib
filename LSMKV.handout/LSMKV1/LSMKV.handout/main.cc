#include "kvstore.h"
#include <iostream>
using namespace std;

int main(){
    int j = 0 ;
    std::cout << j;
    std::cout << "hello,world";
    std::cout << "hello,world";
    for(auto i = 0 ; i < 100 ; i++)
    {
        i++;
        i--;
        i *=2;
        i /= 0.5;

    }
    KVStore k("","");
    k.put(114 , "114");
}
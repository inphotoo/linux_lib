#include "cachelab.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

typedef struct chcheline
{
    int vaild;
    int tag;
    int time_last;
}Chcheline;

typedef struct cache
{
    int S;
    int E;
    int B;
    Chcheline **block;
} Cache;

static Cache *cache;

void init_chche(int s , int E , int b)
{
    cache = (Cache *)malloc(sizeof(Cache));
    cache->S = 1 << s;
    cache->E = E;
    cache->B = 1 << b;
    cache->block = (Chcheline **)malloc(sizeof(Chcheline) * cache->S);

    for(int i = 0 ; i < cache->S ; i ++)
    {
        cache->block[i] = (Chcheline *)malloc(sizeof(Chcheline) * cache->E);
        for(int j = 0 ; j < cache->E ; j++)
        {
            cache->block[i][j].vaild = 0;
            cache->block[i][j].tag = -1;
            cache->block[i][j].time_last = 0;
        }

    }
}

int cacheIndex(int set , int tag)
{
    for(int i = 0 ; i < cache->E ; i++)
    {
        if(cache->block[set][i].vaild && cache->block[set][i].tag == tag)
            return i;
    }
    return -1;
}

int cacheNotUsedIndex(int set)
{
    for(int i = 0 ;i < cache->E ; i++)
    {
        if(cache->block[set][i].vaild == 0)
            return i;
    }
    return -1;
}

//if not used
void setNotUsed(int block_num , int set , int tag)
{
    cache->block[set][block_num].vaild = 1;
    cache->block[set][block_num].tag = tag;
    for(int i = 0 ; i < cache->E ; i ++)
    {
        //others time_last ++
        if(cache->block[set][i].vaild == 1)
        {
            cache->block[set][i].time_last++;
        }
    } 
    cache->block[set][block_num].time_last = 0;
}

void setFullUsed(int set , int tag)
{
    int max_index = 0;
    int max_time_last = 0;
    for(int i = 0 ; i < cache->E ; i++)
    {
        if(cache->block[set][i].time_last > max_time_last)
        {
            max_time_last = cache->block[set][i].time_last;
            max_index = i;
        }
    }

    cache->block[set][max_index].vaild = 1;
    cache->block[set][max_index].tag = tag;
    for(int i = 0 ; i < cache->E ; i ++)
    {
        //others time_last ++
        if(cache->block[set][i].vaild == 1)
        {
            cache->block[set][i].time_last++;
        }
    } 
    cache->block[set][max_index].time_last = 0;
}

int hit_count;
int miss_count;
int eviction_count;

void update(int set , int tag)
{
    int cache_index = cacheIndex(set , tag);
    if(cache_index == -1)
    {
        miss_count += 1;
        int index = cacheNotUsedIndex(set);
        if(index == -1)
        {
            eviction_count++;
            setFullUsed(set , tag);
        }
        setNotUsed(index , set , tag);
        return;
    }
    hit_count++;
    setNotUsed(cache_index , set , tag);
}

char filename[50];

void getTrace(int s, int E, int b) {
    FILE *p_file;
    p_file = fopen(filename, "r");
    if (p_file == NULL)
    {
        exit(-1);
    }
    char identifier;
    unsigned address;
    int size;

    while (fscanf(p_file, " %c %x,%d", &identifier, &address, &size) > 0)
    {
        int tag = address >> (s + b);
        int set = (address >> b) & ((unsigned)(-1) >> (8 * sizeof(unsigned) - s));
        switch (identifier)
        {
            case 'M':
                update(set, tag);
            case 'S':
                update(set, tag);
                break;    
            case 'L':
                update(set, tag);
                break;

        }
    }
    fclose(p_file);
}


int main(int argc , char **argv)
{
    char op;
    int s , E , b;
    while((op=getopt(argc, argv, "hvs:E:b:t:"))!=-1 )
    {
        switch (op)
        {
        case 's':
            s = atoi(optarg);
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            break;
        case 't':
            strcpy(filename, optarg);
            break;
        default:
            printf("Cannot read the flag %c\n", op);
            exit(1);
        }
    }
    init_chche(s , E , b);
    getTrace(s , E , b);
    printSummary(hit_count, miss_count,eviction_count );
    return 0;

}

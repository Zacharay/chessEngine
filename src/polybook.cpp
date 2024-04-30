#include "polybook.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Entry {
    uint64_t hash_pos;
    uint16_t move;
    uint16_t weight;
    uint32_t learn;
};

void swapOrder16(uint16_t &number)
{
   number= ((number&0xFF)<<8)|((number&0xFF00)>>8);
}

void swapOrder64(uint64_t &number) {
    number= ((number & 0x00000000000000FF) << 56) |
           ((number & 0x000000000000FF00) << 40) |
           ((number & 0x0000000000FF0000) << 24) |
           ((number & 0x00000000FF000000) << 8) |
           ((number & 0x000000FF00000000) >> 8) |
           ((number & 0x0000FF0000000000) >> 24) |
           ((number & 0x00FF000000000000) >> 40) |
           ((number & 0xFF00000000000000) >> 56);
}
int binarySearch(int left,int right,uint64_t targetPos)
{
    while(left<right)
    {
        int mid = (left+right)/2;
        Entry currentEntry;
        ifstream inFile("book.bin",ios::binary);

        streampos entrySize = sizeof(currentEntry);
        streampos entryPos = mid*entrySize;
        inFile.seekg(entryPos,ios::beg);

        inFile.read(reinterpret_cast<char*>(&currentEntry),sizeof(currentEntry));
        swapOrder64(currentEntry.hash_pos);
        if(currentEntry.hash_pos==targetPos)
        {
            return mid;
        }
        else if(currentEntry.hash_pos >targetPos)
        {
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    return -1;
}
int getBookMove(uint64_t position)
{
    ifstream inFile("book.bin",ios::binary);
    inFile.seekg(0, ios::end);
    streampos numberOfPos = inFile.tellg()/16;
    inFile.seekg(0, ios::beg);

    Entry entry;
    int idx = binarySearch(0,int(numberOfPos),position);
    streampos entrySize = sizeof(entry);
    inFile.seekg(entrySize*idx,ios::beg);

    inFile.read(reinterpret_cast<char*>(&entry),sizeof(entry));
    swapOrder64(entry.hash_pos);
    swapOrder16(entry.move);
    swapOrder16(entry.weight);

    return entry.move;
}

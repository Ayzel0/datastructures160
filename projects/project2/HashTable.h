#include <iostream>

class HashTable
{
    private:
        int hashTableSize;
    public:
        int getHashTableSize(){return hashTableSize;}
        void setHashTableSize(int newHashTableSize){hashTableSize = newHashTableSize;}
        int* table;
        HashTable();
        HashTable(static int initialTableSize);
};
#include <iostream>
#include <string>

using namespace std;
class HashTable
{
    private:
        int hashTableSize;
        HashTableEntry hashEntry;
    public:
        // getter and setter        
        int getHashTableSize(){return hashTableSize;}
        void setHashTableSize(int newHashTableSize){hashTableSize = newHashTableSize;}

        // hash table functions
        void insertValue(int position, int value);
        void deleteValue(int position);
        void searchValue(int key);

        // constructors
        HashTable();
        HashTable(int initialTableSize);

        // hash function
        int hashFunction(string hashString);
};
#include "QuadProbingHashTable.h"

QuadProbingHashTable::QuadProbingHashTable()
{
    // create a new table with the size of tableSize
    hashTable = new string[quadProbingHashTableSize];
}

QuadProbingHashTable::~QuadProbingHashTable()
{
    delete[] hashTable;
}

// hash function implementation
int QuadProbingHashTable::hashFunction(string value){
    long long int hash = 0;
    for(long unsigned int i = 0; i<value.length(); i++)
    {
        if(i < 10)
            hash += value.at(i)*pow(primeConstant, i);
        else
            hash += value.at(i)*pow(primeConstant, 10);
    }

    return hash%quadProbingHashTableSize;
}

void QuadProbingHashTable::insertValue(string value, int index, int k)
{
    int insertIndex = (index+(k^2))%quadProbingHashTableSize;
    if(hashTable[insertIndex].compare("") == 0)
    {
        // if the array at index is empty, insert the string at the index
        hashTable[insertIndex] = value;
    }
    else
    {
        // if not empty, quadratically probe
        insertValue(value, index, k+1);
    }
}

// parameter K is for recursion so that we can keep track of how many times we've probed
int QuadProbingHashTable::searchValue(string value, int index, int k)
{
    // first check whether the index is empty
    int searchIndex = (index + (k^2))%quadProbingHashTableSize;
    if(hashTable[searchIndex].compare("") == 0)
    {
        // no value at index, return -1
        return -1;
    }
    else
    {
        if(hashTable[searchIndex].compare(value) == 0)
        {
            // string at index is equal to the string we're searching for
            return searchIndex;
        }
        else
        {
            // quadratically probe
            return searchValue(value, index, k+1);
        }
    }
}

void QuadProbingHashTable::printTable()
{
    for(int i = 0; i<quadProbingHashTableSize; i++)
    {
        cout << "[";
        if(hashTable[i].compare("") == 0)
        {
            cout << "NULL" << ", ";
        }
        else
        {
            cout << hashTable[i] << ", ";
        }
    }
}
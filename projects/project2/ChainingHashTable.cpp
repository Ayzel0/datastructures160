#include "ChainingHashTable.h"

// constructor
ChainingHashTable::ChainingHashTable()
{
    // create a new table with the size of tableSize
    hashTable = new ChainingHashTableEntry*[chainingHashTableSize];
    for(int i = 0; i<chainingHashTableSize; i++)
    {
        hashTable[i] = nullptr;
    }
}

// destructor
ChainingHashTable::~ChainingHashTable()
{
    // delete the nodes in hash table
    for(int i = 0; i<chainingHashTableSize; i++)
    {
        // check if the head is null, if not then go through LL and delete
        if(hashTable[i] != nullptr)
        {
            if(hashTable[i]->next == nullptr)
            {
                delete hashTable[i];
            }
            else
            {
                // basically a linked list destructor
                ChainingHashTableEntry* current = hashTable[i];
                while(current->next != nullptr)
                {
                    ChainingHashTableEntry* nextEntry = current->next;
                    delete current;
                    current = nextEntry;
                }
            }
        }
    }

    // delete hash table
    delete[] hashTable;
}

// hash function implementation
int ChainingHashTable::hashFunction(string value){
    long long int hash = 0;
    for(long unsigned int i = 0; i<value.length(); i++)
    {
        if(i < 10)
            hash += value.at(i)*pow(chainingPrimeConstant, i);
        else
            hash += value.at(i)*pow(chainingPrimeConstant, 10);
    }

    return hash%chainingHashTableSize;
}

void ChainingHashTable::insertValue(string value)
{
    // find the index
    int index = hashFunction(value);
    // check whether index is free
    if(hashTable[index] == nullptr)
    {
        // create a new entry and put it in the array
        hashTable[index] = new ChainingHashTableEntry(value);
    }

    // if index isn't free, chain the value
    else
    {
        ChainingHashTableEntry* temp = hashTable[index];
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new ChainingHashTableEntry(value);
    }
}

// hash table insert function
int ChainingHashTable::searchValue(string value)
{
    // find the index
    int index = hashFunction(value);

    // first check whether the index is empty
    if(hashTable[index] == nullptr)
    {
        // no value at index, return -1
        return -1;
    }
    else
    {
        // check whether or not the entry at the index is equal to the value we're searching for
        if(hashTable[index]->value == value)
        {
            return index;
        }
        // check all chained values
        else if(hashTable[index]->next != nullptr)
        {
            ChainingHashTableEntry* temp = hashTable[index];
            while(temp->next != nullptr)
            {
                if(temp->next->value == value)
                {
                    return index;
                }
                else
                {
                    temp = temp->next;
                }
            }
            return -1;
        }
        else
        {
            return -1;
        }
    }
}

// hash table insert function for recursion

// print the entire table, debug purposes
void ChainingHashTable::printTable()
{
    cout << "[";

    for(int i = 0; i<chainingHashTableSize; i++)
    {
        if(hashTable[i] == nullptr)
            cout << "NULL" << ", ";
        else
            cout << hashTable[i] << ", ";
    }
}
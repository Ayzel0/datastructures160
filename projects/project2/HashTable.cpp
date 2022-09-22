#include "HashTable.h"

HashTable::HashTable()
{
    int newTable[1];
    table = newTable;
}

HashTable::HashTable(int initialTableSize)
{
    int newTable[initialTableSize];
}
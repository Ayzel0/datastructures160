#include "ChainingHashTableEntry.h"

ChainingHashTableEntry::ChainingHashTableEntry()
{
    next = nullptr;
    value = "";
}

ChainingHashTableEntry::ChainingHashTableEntry(string newValue)
{
    next = nullptr;
    value = newValue;
}
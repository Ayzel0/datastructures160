#include "ChainingHashTableEntry.h"

ChainingHashTableEntry::ChainingHashTableEntry()
{
    this->next = nullptr;
    this->value = "";
}

ChainingHashTableEntry::ChainingHashTableEntry(string newValue)
{
    this->next = nullptr;
    this->value = newValue;
}
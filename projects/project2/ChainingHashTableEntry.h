#include <iostream>
#include <string>

using namespace std;

class ChainingHashTableEntry
{
    public:
        string value;
        ChainingHashTableEntry* next;
        ChainingHashTableEntry(string v);
        ChainingHashTableEntry();
};
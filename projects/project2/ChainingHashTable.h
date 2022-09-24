#include "ChainingHashTableEntry.h"
#include <cmath>

using namespace std;

const int chainingHashTableSize = 2000000;
const int chainingPrimeConstant = 17;

class ChainingHashTable
{
    private:
        ChainingHashTableEntry** hashTable;
    public:
        // hash table functions
        void insertValue(string);
        int searchValue(string);

        // constructor and destructor
        ChainingHashTable();
        ~ChainingHashTable();

        // hash function
        int hashFunction(string);

        // debug stuff
        void printTable();
};
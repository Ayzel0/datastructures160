#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int quadProbingHashTableSize = 2000000;
const int primeConstant = 17;

class QuadProbingHashTable
{
    private:
        string* hashTable;
    public:
        // hash table functions
        void insertValue(string, int, int);
        int searchValue(string, int, int);

        // constructor and destructor
        QuadProbingHashTable();
        ~QuadProbingHashTable();

        // hash function
        int hashFunction(string);

        // hash tools
        char decapitalize(char c);

        // debug stuff
        void printTable();
};
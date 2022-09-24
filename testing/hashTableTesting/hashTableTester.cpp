#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

const int hashTableSize = 2000000;
const int primeConstant = 11;

class HashTable
{
    private:
        string* hashTable;
    public:
        // hash table functions
        void insertValue(string, int, int);
        int searchValue(string, int, int);

        // constructor and destructor
        HashTable();
        ~HashTable();

        // hash function
        int hashFunction(string);

        // hash tools
        char decapitalize(char c);
};

HashTable::HashTable()
{
    // create a new table with the size of tableSize
    hashTable = new string[hashTableSize];
}

HashTable::~HashTable()
{
    delete hashTable;
}

// hash function implementation
int HashTable::hashFunction(string value){
    long long int hash = 0;
    for(int i = 0; i<value.length(); i++)
    {
        if(i < 10)
            hash += value.at(i)*pow(primeConstant, i);
        else
            hash += value.at(i)*pow(primeConstant, 10);
    }

    return hash%hashTableSize;
}

void HashTable::insertValue(string value, int index, int k)
{
    int insertIndex = (index + k)%hashTableSize;
    if(hashTable[insertIndex].compare("") == 0)
    {
        // if the array at index is empty, insert the string at the index
        hashTable[insertIndex] = value;
        cout << "inserted string " << value << " at index " << insertIndex << endl;
    }
    else
    {
        // if not empty, linear probe
        insertValue(value, index, k+1);
    }
}

// parameter K is for recursion so that we can keep track of how many times we've probed
int HashTable::searchValue(string value, int index, int k)
{
    // first check whether the index is empty
    int searchIndex = (index + k)%hashTableSize;
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

string cleanWord(string);

int main(int argc, char* argv[])
{
    HashTable hashTable;

    
    // read words from the dictionary file and insert into hash table, clean the words too
    ifstream inputFileStream;
    inputFileStream.open(argv[1]);
    string word = "";
    int count = 0;
    while(inputFileStream >> word)
    {
        string cleaned = cleanWord(word);
        hashTable.insertValue(cleaned, hashTable.hashFunction(cleaned), 0);
        
        count++;
    }

    cout << count << endl;

    /*    
    cout << hashTable.hashFunction("tan") << endl;
    cout << hashTable.hashFunction("tang") << endl;
    cout << hashTable.hashFunction("tani") << endl;
    cout << hashTable.hashFunction("tania") << endl;
    */
}

// remove punctuation and decapitalize word
string cleanWord(string s)
{
    string returnString; 
    for(int i = 0; i<s.length(); i++)
    {
        // check for lowercase letters
        if(s.at(i) >= 97 && s.at(i) <= 122)
        {
            returnString.push_back(s.at(i));
        }
        
        // check for capital letters
        else if(s.at(i) >= 65 && s.at(i) <= 90)
        {
            returnString.push_back(s.at(i)+32);
        }

        // check for dash
        else if(s.at(i) == '-')
        {
            returnString.push_back(s.at(i));
        }

        // anything that doesn't fall into one of these two categories doesn't get pushed
    }

    return returnString;
}
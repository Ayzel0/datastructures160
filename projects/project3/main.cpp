#include "main.h"
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

void readDataIntoBST(binarySearchTree&, string);
void readDataIntoSplayTree(splayTree&, string);

int main(int argc, char* argv[])
{
    // chrono setup
    chrono::time_point<chrono::system_clock> bstStart, bstEnd, splayStart, splayEnd;
    chrono::duration<double> bstTimeElapsed, splayTimeElapsed;

    string fileName = argv[1];
    binarySearchTree BST;
    splayTree mySplayTree;

    bstStart = chrono::system_clock::now();
    readDataIntoBST(BST, fileName);
    bstEnd = chrono::system_clock::now();
    bstTimeElapsed = bstEnd-bstStart;

    cout << "BST Final tree structure: ";
    BST.display();
    cout << endl;
    
    cout << "BST traversal count: " << BST.traversalCount << endl;
    cout << "BST chrono count: " << bstTimeElapsed.count()*1000000000 << endl;

    splayStart = chrono::system_clock::now();
    readDataIntoSplayTree(mySplayTree, fileName);
    splayEnd = chrono::system_clock::now();
    splayTimeElapsed = splayEnd-splayStart;

    cout << "Final tree structure: ";
    mySplayTree.display();
    cout << endl;

    cout << "splay traversal count: " << mySplayTree.traversalCount << endl;
    cout << "splay chrono count: " << splayTimeElapsed.count()*1000000000 << endl;
}

void readDataIntoBST(binarySearchTree& bst, string fileName)
{
    ifstream inputFileStream;
    inputFileStream.open(fileName);
    int stage = 0;
    
    if(!inputFileStream.is_open())
    {
        throw invalid_argument("invalid file name passed");
    }
    
    string readValue;
    while(inputFileStream >> readValue)
    {
        if(readValue == "$")
            stage++;
        
        else
        {
            if(stage == 0)
            {
                bst.insert(stoi(readValue));
            }
            else if(stage == 1)
            {
                bst.search(stoi(readValue));
            }
            else
            {
                bst.remove(stoi(readValue));
            }
        }
    }
    inputFileStream.close();
}

void readDataIntoSplayTree(splayTree& splayTree, string fileName)
{
    ifstream inputFileStream;
    inputFileStream.open(fileName);
    int stage = 0;
    
    if(!inputFileStream.is_open())
    {
        throw invalid_argument("invalid file name passed");
    }
    
    string readValue;
    while(inputFileStream >> readValue)
    {
        if(readValue == "$")
            stage++;
        
        else
        {
            if(stage == 0)
            {
                splayTree.insert(stoi(readValue));
            }
            else if(stage == 1)
            {
                splayTree.search(stoi(readValue));
            }
            else
            {
                splayTree.treeRoot = splayTree.remove(stoi(readValue));
            }
        }
    }
    inputFileStream.close();
}

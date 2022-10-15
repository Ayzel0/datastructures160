#include "main.h"
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

void readDataIntoBST(binarySearchTree&, string);

int main(int argc, char* argv[])
{
    // chrono setup
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> timeElapsed;

    string fileName = argv[1];
    binarySearchTree BST;

    start = chrono::system_clock::now();
    readDataIntoBST(BST, fileName);
    end = chrono::system_clock::now();
    timeElapsed = end-start;

    cout << "Final tree structure: ";
    BST.display();
    cout << endl;
    
    cout << "traversal count: " << BST.traversalCount << endl;
    cout << "chrono count: " << timeElapsed.count()*1000000000;
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
}
#include <iostream>

using namespace std;

class BSTnode
{
    public:
        BSTnode();
        BSTnode(int);
        int value;
        BSTnode* leftChild;
        BSTnode* rightChild;
};
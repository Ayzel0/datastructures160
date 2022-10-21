#include <iostream>

using namespace std;

class splayNode
{
    public:
        splayNode();
        splayNode(int);
        int value;
        splayNode* leftChild;
        splayNode* rightChild;
};
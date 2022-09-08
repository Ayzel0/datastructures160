#include <iostream>

using namespace std;

class Node
{
    int data;
    Node* next;

    // default constructor
    Node()
    {
        data = 0;
        next = nullptr;
    }

    // not a default constructor L + Ratio
    Node(int dataVal)
    {
        this->data = dataVal;
        this->next = nullptr;
    }

    // not a default constructor L + Ratio + you fell off + maidenless
    Node(int dataVal, Node* nextNode)
    {
        this->data = dataVal;
        this->next = nextNode;
    }
};

class linkedList // idk what im doing here
{
    Node* headNode;
};


#include <iostream>

using namespace std;

#ifndef LIST_H
#define LIST_H

class Node
{
    public:
        int data;
        Node* next;
        Node();
        Node(int val);
};

class List
{
    public:
        List();
        Node* head;
        Node* tail;
        void pushValue(int value);
        void removeValue(int index);
        int length;
};

class mtfList: public List
{
    int searchAndMoveToFront(int value);
    void insertValueAtFront(int value);
};

class orderedList: public List
{
    int searchForValue(int value);
};

#endif
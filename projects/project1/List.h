#include <iostream>
#include <fstream>
#include <string>

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
        void readInFile(string fileName);
        void pushValue(int value);
        void removeValue(int index);
        void printList();
        int length;
};

class MTFlist: public List
{
    public:
        void readInFileAndQuery(string fileName);
        int searchAndMoveToFront(int value);
        void insertValueAtFront(int value);
};

class orderedList: public List
{
    int searchForValue(int value);
};

#endif
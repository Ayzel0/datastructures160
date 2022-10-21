#include <iostream>
#include "BSTnode.h"

using namespace std;

class binarySearchTree
{
    public:
        BSTnode* treeRoot;
        int traversalCount;
        binarySearchTree();
        ~binarySearchTree();
        void insert(BSTnode*, int);
        void remove(BSTnode*, int);
        void search(BSTnode*, int);
        void searchNum(BSTnode*&, BSTnode*&, int);
        BSTnode* searchMinValue(BSTnode*);
        void insert(int);
        void remove(int);
        void search(int);
        void display(BSTnode*);
        void display();
        void destroyTree(BSTnode*);
        BSTnode* splayNode(BSTnode*, int);
        BSTnode* rightRotate(BSTnode*);
        BSTnode* leftRotate(BSTnode*);
};
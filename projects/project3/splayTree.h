#include "splayTreeNode.h"

class splayTree
{
    public:
        splayTree();
        ~splayTree();
        splayNode* treeRoot;
        int traversalCount;
        void insert(splayNode*, int);
        splayNode* remove(splayNode*, int);
        void search(splayNode*, int);
        void insert(int);
        splayNode* remove(int);
        void search(int);
        void display(splayNode*);
        void display();
        void destroyTree(splayNode*);
        splayNode* splay(splayNode*, int);
        splayNode* rightRotate(splayNode*);
        splayNode* leftRotate(splayNode*);
};
#include "Node.h"

class mtfList
{
    public:
        // basics
        mtfList();
        Node* head;
        Node* tail;
        int length;

        // add and remove
        void pushValueAtBack(int value);
        void pushValueAtFront(int value);
        void removeValue(int index);
        void printList();
        
        // sort stuff
        int readInFileAndQuery(string);
        int searchAndMoveToFront(int);
        void insertValueAtFront(int);
};
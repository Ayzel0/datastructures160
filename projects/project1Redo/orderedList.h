#include "Node.h"

class orderedList
{
    public:
        // basics
        orderedList();
        Node* head;
        Node* tail;
        int length;

        // add and remove values
        void pushValueAtBack(int value);
        void pushValueAtFront(int value);
        void removeValue(int index);
        void printList();
};
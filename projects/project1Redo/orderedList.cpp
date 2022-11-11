#include "orderedList.h"

orderedList::orderedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void orderedList::pushValueAtFront(int value)
{
    length++;
    Node* newNode = new Node(value);

    // check if list is empty
    // if list is empty, set head and tail to newNode
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    // if it's not empty:
    // set new node's next pointer to current head, set head to new node
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void orderedList::pushValueAtBack(int value)
{
    length++;
    Node* newNode = new Node(value);
    
    // check if list is empty
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void orderedList::removeValue(int index)
{
    if(index > length-1)
    {
        throw out_of_range("index passed to removeValue in orderedList out of range");
    }

    Node* current = head;
    Node* trailer = nullptr;

    for(int i = 0; i<index; i++)
    {
        trailer = current;
        current = current->next;
    }

    if(index == 0)
    {
        head = head->next;
        length--;
        delete current;
    }

    if(index == length-1)
    {
        // go to the second to last element and set tail equal to it
        for(int i = 0; i<length-1; i++)
        {
            current = current->next;
        }

        // set tail equal to the second to last element, then move temp by one and delete it
        tail = current;
        tail->next = nullptr;
        current = current->next;
        length--;
        delete current;
    }
    
    // if it's not the first or last value, loop through until you find the index of the value
    for(int i = 0; i<index; i++)
    {
        trailer = current;
        current = current->next;
    }

    // once the index is reached, point the previous value to the next value, and delete node
    temp2->next = temp->next;
    length--;
    delete temp;
}
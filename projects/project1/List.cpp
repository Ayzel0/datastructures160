#include "List.h"

Node::Node()
{
    data = 0;
    next = nullptr;
}

Node::Node(int val)
{
    this->data = val;
    this->next = nullptr;
}

List::List()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

void List::pushValue(int value)
{
    length++;
    Node* newNode = new Node(value);

    // check if the list is empty
    // if list is empty, set head and tail to newNode
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }

    // if it's not empty:
    // set the tail node's next pointer to newNode
    // set tail pointer to newNode
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void List::removeValue(int index)
{
    if(index > length-1)
        throw out_of_range("index passed to removeValue function out of range");

    // temp pointer to keep track of 
    Node* temp = head;
    Node* temp2 = nullptr;

    // if index is the first element, shift head and delete the node
    if(index == 0)
    {
        head = head->next;
        delete temp;
    }

    // if index is the last element, move the tail pointer and delete the node
    if(index == length-1)
    {
        // go to the second to last element and set tail equal to it
        for(int i = 0; i<length-1; i++)
        {
            temp = temp->next;
        }

        // set tail equal to the second to last element, then move temp by one and delete it
        tail = temp;
        temp = temp->next;
        delete temp;
    }
    
    // if it's not the first or last value, loop through until you find the index of the value
    for(int i = 0; i<index; i++)
    {
        temp2 = temp;
        temp = temp->next;
    }

    // once the index is reached, point the previous value to the next value, and delete node
    temp2->next = temp->next;
    delete temp;
}

int mtfList::searchAndMoveToFront()
{

}

int orderedList::searchForValue()
{
    
}
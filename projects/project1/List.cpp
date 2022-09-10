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
        length--;
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
        length--;
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
    length--;
    delete temp;
}

void List::printList()
{
    // temp pointer notde
    Node* temp = head;

    // loop through all nodes and print out the numbers with a space
    while(temp->next != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void MTFlist::readInFileAndQuery(string fileName)
{
    ifstream inputFileStream;
    inputFileStream.open(fileName);
    if(inputFileStream.is_open())
    {
        cout << "file is open" << endl;
    }

    // read in the number of values to be stored in the list - first number in file
    int numberOfInts;
    string numOfIntsString;
    inputFileStream >> numOfIntsString;
    cout << "there are " << numOfIntsString << " to be read into the linked list" << endl;
    numberOfInts = stoi(numOfIntsString);

    // read in the next n numbers into the list
    int nextValue = 0;
    string nextValueString;
    for(int i = 0; i<numberOfInts; i++)
    {
        inputFileStream >> nextValueString;
        nextValue = stoi(nextValueString);
        cout << "read in " << nextValueString << " to the linked list" << endl;
        pushValue(nextValue);
    }

    // get the number of queries
    int numberOfQueries = 0;
    string numberOfQueriesString;
    inputFileStream >> numberOfQueriesString;
    numberOfQueries = stoi(numberOfQueriesString);

    // read in all the numbers to be queried
    int nextQuery = 0;
    string nextQueryString;
    for(int i = 0; i<numberOfQueries; i++)
    {
        inputFileStream >> nextQueryString;
        nextQuery = stoi(nextQueryString);
        searchAndMoveToFront(nextQuery);
    }
}

void MTFlist::insertValueAtFront(int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    length++;
}

int MTFlist::searchAndMoveToFront(int value)
{
    // bool to keep track of whether value is found
    bool found = false;
    
    // integer to return
    int returnVal = 0;

    // loop through the linked list, searching for value
    Node* temp1 = head;
    Node* temp2 = nullptr;

    while(temp1->next != nullptr)
    {
        // check if temp1 is equal to the value
        if(temp1->data == value)
        {
            // set returnVal to the value at pointer
            returnVal = temp1->data;

            // set found to true
            found = true;

            // insert the value at front
            insertValueAtFront(temp1->data);

            // delete temp1 node, set temp2 next pointer to temp1 next
            temp2->next = temp1->next;
            delete temp1;

            // return value
            return returnVal;
        }

        // if temp1 not at this value, move to the next node
        temp2 = temp1;
        temp1 = temp1->next;
    }

    // if not found
    if(found == false)
    {
        returnVal = -1;
        return returnVal;
    }
}

int orderedList::searchForValue(int value)
{
    Node* temp = head;
    int index = 0;

    while(temp->next != nullptr)
    {
        if(temp->data == value)
        {
            // temp is pointing to node with data, so return index
            return index;
        }
        else
        {
            // shift temp by one, add one to index
            temp = temp->next;
            index++;
        }
    }

    return -1;
}
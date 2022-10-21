#include "binarySearchTree.h"

void searchNum(BSTnode*&, BSTnode*&, int);
BSTnode* searchMinValue(BSTnode*);

binarySearchTree::binarySearchTree()
{
    treeRoot = nullptr;
    traversalCount = 0;
}

binarySearchTree::~binarySearchTree()
{
    destroyTree(treeRoot);
}

// recursive solution
void binarySearchTree::insert(BSTnode* root, int insertNum)
{
    traversalCount++;
    // check if root is empty
    if(root == nullptr)
    {
        root = new BSTnode(insertNum);
        treeRoot = root;
    }
    else
    {
        // else root is not empty, check recursively
        if(insertNum < root->value)
        {
            // should go into the left subtree
            if(root->leftChild == nullptr)
            {
                root->leftChild = new BSTnode(insertNum);
            }
            else
            {
                insert(root->leftChild, insertNum);
            }
        }
        else
        {
            // should go into the right subtree
            if(root->rightChild == nullptr)
            {
                root->rightChild = new BSTnode(insertNum);
            }
            else
            {
                insert(root->rightChild, insertNum);
            }
        }
    }
}

void binarySearchTree::insert(int insertNum)
{
    insert(treeRoot, insertNum);
}

void binarySearchTree::remove(BSTnode* root, int removeNum)
{
    traversalCount++;
    // in order to remove a value we need parent node
    BSTnode* parentNode = nullptr;
    BSTnode* currentNode = root;

    // search the BST to set current to the node we're searching for and find parent
    searchNum(parentNode, currentNode, removeNum);

    if(currentNode == nullptr)
    {
        // the value does not exist
        return;
    }

    // case one: the current node has zero children, so just remove it and point parent to null
    if(currentNode->leftChild == nullptr && currentNode->rightChild == nullptr)
    {
        if(parentNode->leftChild == currentNode)
        {
            parentNode->leftChild = nullptr;
        }
        else
        {
            parentNode->rightChild = nullptr;
        }

        delete currentNode;
    }
    
    // case two: current node has two children, so:
    // find the minimum value in subtree with root of currentNode
    // copy found node value to the current node
    // delete the found node 
    else if(currentNode->leftChild != nullptr && currentNode->rightChild != nullptr)
    {
        BSTnode* minNode = searchMinValue(currentNode->rightChild);
        int val = minNode->value;
        remove(root, minNode->value);
        currentNode->value = val;
    }

    // case 3: current node has one child
    else
    {
        // find whether the left or right node is the child that isn't null
        BSTnode* child;
        if(currentNode->leftChild == nullptr)
        {
            child = currentNode->rightChild;
            traversalCount++;
        }
        else
        {
            child = currentNode->leftChild;
            traversalCount++;
        }

        // point the parent to the child node if the current isn't root
        if(currentNode != root)
        {
            if(currentNode == parentNode->leftChild)
            {
                traversalCount++;
                parentNode->leftChild = child;
            }
            else
            {
                traversalCount++;
                parentNode->rightChild = child;
            }
        }

        // else, parent is root, meaning that you just set root to child
        else
        {
            root = child;
        }

        // delete the memory for current node
        delete currentNode;
    }
}

void binarySearchTree::remove(int removeNum)
{
    remove(treeRoot, removeNum);
}

// searches the BST for a key
void binarySearchTree::search(BSTnode* root, int searchNum)
{
    traversalCount++;

    if(root->value == searchNum)
    {
        return; // value has been found
    }
    else
    {
        if(searchNum < root->value)
            search(root->leftChild, searchNum);
        else if(searchNum > root->value)
            search(root->rightChild, searchNum);
    }
}

void binarySearchTree::search(int searchNum)
{
    search(treeRoot, searchNum);
}

void binarySearchTree::display(BSTnode* current)
{
    if(current != nullptr && (current->leftChild != nullptr || current->rightChild != nullptr))
    {
        cout << "[";
        cout << current->value;
        display(current->leftChild);
        display(current->rightChild);
        cout << "]";
    }
    else if(current != nullptr)
    {
        cout << "[";
        cout << current->value;
        cout << "]";
    }
    else
    {
        cout << "[]";
    }
}

void binarySearchTree::display()
{
    display(treeRoot);
}

void binarySearchTree::destroyTree(BSTnode* current)
{
    if(current == nullptr)
    {
        return;
    }

    BSTnode* currentNode = current;
    BSTnode* leftNode = current->leftChild;
    BSTnode* rightNode = current->rightChild;

    delete currentNode;
    destroyTree(leftNode);
    destroyTree(rightNode);
}

// searches the BST for both parent node and current num
void binarySearchTree::searchNum(BSTnode*& parent, BSTnode*& current, int num)
{
    // go through tree to search for key as long as 
    // you haven't reached nullptr and haven't found the value
    while(current != nullptr && current->value != num)
    {
        traversalCount++;
        // shift parent
        parent = current;

        // move current to one of its children
        if(current->value > num)
        {
            current = current->leftChild;
        }
        else
        {
            current = current->rightChild;
        }
    }
}

// searches for the minimum value in subtree with root currentNode
BSTnode* binarySearchTree::searchMinValue(BSTnode* currentNode)
{
    // using while loop to reduce function calls
    while(currentNode->leftChild != nullptr)
    {
        traversalCount++;
        currentNode = currentNode->leftChild;
    }

    return currentNode;
}
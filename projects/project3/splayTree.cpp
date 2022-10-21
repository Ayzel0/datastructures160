#include "splayTree.h"

splayNode* splayTree::rightRotate(splayNode* root)
{
    splayNode* leftNode = root->leftChild;
    root->leftChild = leftNode->rightChild;
    leftNode->rightChild = root;
    return leftNode;
}

splayNode* splayTree::leftRotate(splayNode* root)
{
    splayNode* rightNode = root->rightChild;
    root->rightChild = rightNode->leftChild;
    rightNode->leftChild = root;
    return rightNode;
}

splayNode* splayTree::splay(splayNode* root, int value)
{
    // cout << "splaying value " << value << " to root" << endl;
    traversalCount++;
    // base case - root is null or root is the value we're looking for
    if(root == nullptr || root->value == value)
    {
        return root;
    }

    // first case: value is in the left subtree
    if(value < root->value)
    {
        // cout << "case 1: key in left subtree" << endl;
        if(root->leftChild == nullptr)
        {
            // value doesn't exist
            return root;
        }

        if(value < root->leftChild->value)
        {
            root->leftChild->leftChild = splay(root->leftChild->leftChild, value);
            traversalCount++;
            // zig zig rotate step 1
            root = rightRotate(root);
        }
        else if(value > root->leftChild->value)
        {
            root->leftChild->rightChild = splay(root->leftChild->rightChild, value);

            // zig zag rotation step 1
            if(root->leftChild->rightChild != nullptr)
            {
                traversalCount++;
                root->leftChild = leftRotate(root->leftChild);
            }
        }

        if(root->leftChild == nullptr)
        {
            return root;
        }
        else
        {
            return rightRotate(root);
        }
    }

    // second case: value is in right subtree
    else
    {
        // cout << "case 2: key in right subtree" << endl;
        if(root->rightChild == nullptr)
        {
            // value isn't in the tree, we can just return root
            // cout << "value not in tree" << endl;
            return root;
        }

        if(value > root->rightChild->value)
        {
            // zig zig rotation
            root->rightChild->rightChild = splay(root->rightChild->rightChild, value);
            root = leftRotate(root);
            traversalCount++;
        }
        else if(value < root->rightChild->value)
        {
            // zig zag rotation
            root->rightChild->leftChild = splay(root->rightChild->leftChild, value);
            if(root->rightChild->leftChild != nullptr)
            {
                traversalCount++;
                root->rightChild = rightRotate(root->rightChild);
            }
        }
        

        if(root->rightChild == nullptr)
        {
            return root;
        }
        else
        {
            return leftRotate(root);
        }
    }
}

splayTree::splayTree()
{
    treeRoot = nullptr;
    traversalCount = 0;
}

splayTree::~splayTree()
{
    destroyTree(treeRoot);
}

// recursive solution
void splayTree::insert(splayNode* root, int insertNum)
{
    traversalCount++;
    // check if root is empty
    if(root == nullptr)
    {
        root = new splayNode(insertNum);
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
                root->leftChild = new splayNode(insertNum);
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
                root->rightChild = new splayNode(insertNum);
            }
            else
            {
                insert(root->rightChild, insertNum);
            }
        }
    }
}

void splayTree::insert(int insertNum)
{
    insert(treeRoot, insertNum);
    treeRoot = splay(treeRoot, insertNum);
}

splayNode* splayTree::remove(splayNode* root, int removeNum)
{
    splayNode* tempNode;
    if(root == nullptr)
    {
        return nullptr;
    }

    root = splay(root, removeNum);

    if(removeNum != root->value)
    {
        return root;
    }

    if(root->leftChild == nullptr)
    {
        tempNode = root;
        root = root->rightChild;
    }

    else
    {
        tempNode = root;
        root = splay(root->leftChild, removeNum);
        root->rightChild = tempNode->rightChild;
    }

    delete tempNode;

    return root;
}

splayNode* splayTree::remove(int removeNum)
{
    return remove(treeRoot, removeNum);
}

// searches the BST for a key
void splayTree::search(splayNode* root, int searchNum)
{
    treeRoot = splay(root, searchNum);
}

void splayTree::search(int searchNum)
{
    search(treeRoot, searchNum);
}

void splayTree::display(splayNode* current)
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

void splayTree::display()
{
    display(treeRoot);
}

void splayTree::destroyTree(splayNode* current)
{
    if(current == nullptr)
    {
        return;
    }

    splayNode* currentNode = current;
    splayNode* leftNode = current->leftChild;
    splayNode* rightNode = current->rightChild;

    delete currentNode;
    destroyTree(leftNode);
    destroyTree(rightNode);
}
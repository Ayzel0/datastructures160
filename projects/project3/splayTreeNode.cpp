#include "splayTreeNode.h"

splayNode::splayNode()
{
    value = 0;
    leftChild = nullptr;
    rightChild = nullptr;
}

splayNode::splayNode(int val)
{
    value = val;
    leftChild = nullptr;
    rightChild = nullptr;
}
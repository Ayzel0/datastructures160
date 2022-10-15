#include "BSTnode.h"

BSTnode::BSTnode()
{
    value = 0;
    leftChild = nullptr;
    rightChild = nullptr;
}

BSTnode::BSTnode(int val)
{
    value = val;
    leftChild = nullptr;
    rightChild = nullptr;
}
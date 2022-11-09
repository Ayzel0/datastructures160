#include "radixSortNode.h"

radixSortNode::radixSortNode()
{
    data = 0;
    next = nullptr;
}

radixSortNode::radixSortNode(char charData)
{
    data = charData;
    next = nullptr;
}


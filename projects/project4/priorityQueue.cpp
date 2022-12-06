#include "priorityQueue.h"

// default, sets size to zero
template <class T>
priorityQueue<T>::priorityQueue()
{
    T unused;
    size = 0;
}

// returns index of parent
template <class T>
int priorityQueue<T>::parentIndex(int i)
{
    return (i-1)/2;
}

// returns index of left child
template <class T>
int priorityQueue<T>::leftChildIndex(int i)
{
    return 2*i+1;
}

// returns index of right child
template <class T>
int priorityQueue<T>::rightChildIndex(int i)
{
    return 2*i+2;
}

// swaps two items in the priority queue
template <class T>
void priorityQueue<T>::swap(T* x, T* y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
}

// adds value to heap, satisfying min queue property
template <class T>
void priorityQueue<T>::enqueue(T data)
{
    // first check to make sure that the heap size isn't larger than max size
    if(size >= maxHeapSize)
    {
        // throw an exception
        throw std::out_of_range("queue is full, can't insert any more values");
    }

    // else, add one to the size and enqueue
    // insert at end of array
    heap[size] = data;

    // add one to size
    size++;

    // now move the number so that it satisfies the min heap property

    // use int index to represent the position of the value we're trying to move
    int index = size-1;

    // loop through and swap until we reach a point where int at index not smaller than parent
    while(index >= 0 && heap[priorityQueue::parentIndex(index)] > heap[index])
    {
        priorityQueue::swap(&heap[priorityQueue::parentIndex(index)], &heap[index]);
        index = priorityQueue::parentIndex(index);
    }
}

// shifts the item at index to the correct position
template <class T>
void priorityQueue<T>::minHeapify(int index)
{
    // check the children nodes
    int left = priorityQueue::leftChildIndex(index);
    int right = priorityQueue::rightChildIndex(index);

    // temp int to keep track for recursion
    int smallestIndex = index;

    // check whether the left child is smaller than the current node
    if(left <= size && heap[left] < heap[smallestIndex])
    {
        smallestIndex = left;
    }

    // check whether right child is smaller than both the current and the left node
    if(right <= size && heap[right] < heap[smallestIndex])
    {
        smallestIndex = right;
    }

    // check if smallestIndex is index of current node; if not swap
    if(smallestIndex != index)
    {
        int temp = heap[index];
        heap[index] = heap[smallestIndex];
        heap[smallestIndex] = temp;
        minHeapify(smallestIndex);
    }
}

// return the smallest item
template <class T>
T priorityQueue<T>::peek()
{
    return heap[0];
}

// remove the smallest item and return it
template <class T>
T priorityQueue<T>::dequeue()
{
    // grab the smallest item
    T minItem = heap[0];

    // set the head of the heap to the last item in the heap
    heap[0] = heap[size-1];

    // maintain heap property
    minHeapify(0);
    
    return minItem;
}

// debug purposes, prints the queue
template <class T>
void priorityQueue<T>::printQueue()
{
    for(int i = 0; i<size; i++)
    {
        cout << heap[i] << " ";
    }
}
#include <iostream>
#include "pQueueEntry.h"

using namespace std;

// implementing priority queue with a heap structure to preserve time complexity
class priorityQueue
{
    private:
        const static int maxHeapSize = 50;
        pQueueEntry* heap[maxHeapSize];
        int size;

    public:
        priorityQueue();
        static int parentIndex(int);
        static int leftChildIndex(int);
        static int rightChildIndex(int);
        static void swap(pQueueEntry**, pQueueEntry**);
        void enqueue(pQueueEntry*);
        void minHeapify(int);
        pQueueEntry* peek();
        pQueueEntry* dequeue();
        void printQueue();
};
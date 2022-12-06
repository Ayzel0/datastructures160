#include <iostream>
#include "graph.h"

using namespace std;

// implementing priority queue with a heap structure to preserve time complexity
class priorityQueue
{
    private:
        const static int maxHeapSize = 50;
        vertex heap[maxHeapSize];
        int size;

    public:
        priorityQueue();
        static int parentIndex(int);
        static int leftChildIndex(int);
        static int rightChildIndex(int);
        static void swap(vertex*, vertex*);
        void enqueue(vertex);
        void minHeapify(int);
        vertex peek();
        vertex dequeue();
        void printQueue();
};
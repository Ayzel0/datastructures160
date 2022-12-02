#include <iostream>

using namespace std;

// implementing priority queue with a heap structure to preserve time complexity
class priorityQueue
{
    private:
        const static int maxHeapSize = 50;
        int heap[maxHeapSize];
        int size;

    public:
        priorityQueue();
        static int parentIndex(int);
        static int leftChildIndex(int);
        static int rightChildIndex(int);
        static void swap(int*, int*);
        void enqueue(int);
        void minHeapify(int);
        int peek();
        int dequeue();
        void printQueue();
};
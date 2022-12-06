#include <iostream>

using namespace std;

// implementing priority queue with a heap structure to preserve time complexity
template <class T>
class priorityQueue
{
    private:
        const static int maxHeapSize = 50;
        T heap[maxHeapSize];
        int size;

    public:
        priorityQueue();
        static int parentIndex(int);
        static int leftChildIndex(int);
        static int rightChildIndex(int);
        static void swap(T*, T*);
        void enqueue(T);
        void minHeapify(int);
        T peek();
        T dequeue();
        void printQueue();
};
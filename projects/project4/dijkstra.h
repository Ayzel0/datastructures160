#include "priorityQueueDijkstra.h"

struct dijkstraEntry
{
    vertex* v;
    int shortestDistance = 2147483647;
    vertex* previousVertex;
    bool done = false;
};

class dijkstra
{
    private:
        priorityQueue pQueue;
        vector<dijkstraEntry*> dVector;
        dijkstraEntry* findDEntry(vertex*);

    public:
        dijkstra();
        ~dijkstra();
        void deleteDijkstraVector();
        void printDijkstra();
        void printPQueue();
        int findShortestDistance(string, string, graph);
};
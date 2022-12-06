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
        int findShortestDistance(string, string, graph);
};
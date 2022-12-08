#include "priorityQueueDijkstra.h"

struct dijkstraEntry
{
    vertex* v;
    int shortestDistance = 2147483647;
    vertex* previousVertex;
    bool done = false;
};

class dijkstraList
{
    private:
        const static int maxListSize = 50;
        dijkstraEntry* list[maxListSize];
        int dijkstraListSize;
    
    public:
        dijkstraList();
        void deleteDijkstraList();
        int size();
        dijkstraEntry* at(int);
        void push_back(dijkstraEntry*);
};

class vertexList
{
    private:
        const static int maxListSize = 50;
        string vList[maxListSize];
        int vertexListSize;

    public:
        void push_back(vertex*);
        void push_back(string);
        void remove(int);
        int size();
        string at(int);
        vertexList();
        void printVertexList();
};

class dijkstra
{
    private:
        priorityQueue pQueue;
        dijkstraList dList;
        dijkstraEntry* findDEntry(vertex*);

    public:
        dijkstra();
        ~dijkstra();
        void printDijkstra();
        void printPQueue();
        int findShortestDistance(string, string, graph);
};
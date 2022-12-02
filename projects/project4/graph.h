#include <iostream>
#include <vector>

using namespace std;

// edge implementation
class vertex
{
    public:
        vertex();
        vertex(string, int);
        string name;
        vertex* next;
        int weight;
};

// graph implementation
class graph
{
    public:
        graph();
        int vertices;
        vector<vertex*> graphVector;
        void addEdge(string, string, int);
        void shortestDistance(string, string);
        void printGraph();
};
#include <iostream>
#include <vector>
#include <string>

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
        bool operator<(const vertex& v);
        bool operator>(const vertex& v);
        bool operator<=(const vertex& v);
        bool operator>=(const vertex& v);
        bool operator==(const vertex& v);
        friend ostream &operator<<(ostream& output, const vertex& v);
};

// graph list implementation
class graphList
{
    private:
        const static int maxGraphSize = 50;
        int graphSize;
        vertex* graph[maxGraphSize];

    public:
        graphList();
        void push_back(vertex* v);
        int size();
};

// graph implementation
class graph
{
    public:
        graph();
        int vertices;
        graphList graphList;
        void addEdge(string, string, int);
        vertex getClosestUnvisitedNeighbor(vertex*);
        vertex getClosestUnvisitedNeighbor(string);
        void printGraph();
};
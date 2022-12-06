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

// graph implementation
class graph
{
    public:
        graph();
        int vertices;
        vector<vertex*> graphVector;
        void addEdge(string, string, int);
        vertex getClosestUnvisitedNeighbor(vertex*);
        vertex getClosestUnvisitedNeighbor(string);
        void printGraph();
};
#include "main.h"

int main(int argc, char* argv[])
{
    graph myGraph;
    myGraph.addEdge("ATL", "DFW", 500);
    myGraph.addEdge("ATL", "LAX", 1000);
    myGraph.addEdge("DFW", "LGA", 750);
    myGraph.addEdge("DFW", "AUS", 50);
    myGraph.addEdge("ATL", "JFK", 400);
    myGraph.addEdge("LGA", "REA", 200);

    myGraph.printGraph();
}


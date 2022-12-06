#include "main.h"

using namespace std;

void readIntoGraph(graph&, vector<string>&, string);

int main(int argc, char* argv[])
{
    graph myGraph;
    vector<string> destinations;
    string fileName = argv[1];

    readIntoGraph(myGraph, destinations, fileName);
    dijkstra d;
    int dist = d.findShortestDistance(destinations.at(0), destinations.at(1), myGraph);
    cout << "the distance between the vertices we want to find is " << dist << endl;
}

void readIntoGraph(graph &graph, vector<string> &destinations, string fileName)
{
    // open the filestream
    ifstream inputFileStream;
    inputFileStream.open(fileName);

    // read into the graph
    string tempString;

    getline(inputFileStream, tempString);
    stringstream ss(tempString);
    string destination1;
    string destination2;
    ss >> destination1;
    ss >> destination2;
    destinations.push_back(destination1);
    destinations.push_back(destination2);

    getline(inputFileStream, tempString);

    while(getline(inputFileStream, tempString))
    {
        stringstream s(tempString);
        string vertex1;
        string vertex2;
        int weight;
        s >> vertex1;
        s >> vertex2;
        s >> weight;

        graph.addEdge(vertex1, vertex2, weight);
    }
}
#include "graph.h"

// struct to store things for dijkstra
struct dijkstraEntry
{
    vertex* v;
    int shortestDistance = 2147483647;
    vertex* previousVertex;
};

// edge default constructor
vertex::vertex()
{
    next = nullptr;
    weight = 0;
    name = " ";
}

vertex::vertex(string name, int weight)
{
    next = nullptr;
    this->name = name;
    this->weight = weight;
}

// overloaded comparison operator
bool vertex::operator<=(const vertex& v)
{
    if(this->weight <= v.weight)
    {
        return true;
    }
    return false;
}

// overloaded comparison operator
bool vertex::operator>=(const vertex& v)
{
    if(this->weight >= v.weight)
    {
        return true;
    }
    return false;
}

// overloaded comparison operator
bool vertex::operator<(const vertex& v)
{
    if(this->weight < v.weight)
    {
        return true;
    }
    return false;
}

// overloaded comparison operator
bool vertex::operator>(const vertex& v)
{
    if(this->weight > v.weight)
    {
        return true;
    }
    return false;
}

// overloaded comparison operator
bool vertex::operator==(const vertex& v)
{
    if(this->weight == v.weight)
    {
        return true;
    }
    return false;
}

std::ostream &operator<<(ostream& output, const vertex& v)
{
    output << v.name << " with weight " << to_string(v.weight);
    return output;
}

graph::graph()
{
    vertices = 0;
}

void graph::addEdge(string origin, string terminus, int weight)
{
    // check if we already have a node with the given origin
    bool found = false;

    //debug
    // cout << "attempting to add vertex with origin " << origin << ", terminus " << terminus << ", and weight " << weight << endl;
    
    for(int i = 0; i<vertices; i++)
    {
        if(graphVector.at(i)->name == origin)
        {
            // debug
            // cout << "existing vertex found, attemping to add" << endl;
            found = true;

            // we know that this already exists in the vector
            // create a new node with the name of terminus
            vertex* newVertex = new vertex(terminus, weight);

            vertex* current = graphVector.at(i);
            while(current->next != nullptr)
            {
                current = current->next;
            }

            // set the next vertex of whatever we're at to the new vertex
            current->next = newVertex;
        }
    }

    if(found == false)
    {
        // make two new vertices
        // vertex that holds the origin, has weight of 0
        vertex* newVertexOrigin = new vertex(origin, 0);

        // vertex that holds the terminus, weight given
        vertex* newVertexTerminus = new vertex(terminus, weight);

        // add the origin vertex to the vector
        graphVector.push_back(newVertexOrigin);

        // set the origin vertex's next pointer to the new vertex
        graphVector.at(graphVector.size()-1)->next = newVertexTerminus;

        // increase number of vertices by 1
        vertices++;
    }
}

vertex graph::getClosestUnvisitedNeighbor(string vertexName)
{
    vertex returnVertex;
    for(int i = 0; i<graphVector.size(); i++)
    {
        if(graphVector.at(i)->name == vertexName)
        {
            returnVertex = getClosestUnvisitedNeighbor(graphVector.at(i));
        }
    }

    return returnVertex;
}

vertex graph::getClosestUnvisitedNeighbor(vertex* v)
{
    // int to keep track of shortest distance
    int smallestDistance = 2147483647;

    // vertex pointer to keep track of what the smallest vertex is
    vertex tempVertex;

    // int to keep track of where in the vector the vertex we're comparing against is
    int index = -1;

    // find the vertex in the vector
    for(int i = 0; i<vertices; i++)
    {
        if(v == graphVector.at(i))
        {
            index = i;
            break;
        }
    }

    // check if something was actually found
    if(index == -1)
    {
        return *v;
    }

    // loop through the vertices of the vertex at index i
    // current pointer for traversing the linked list
    vertex* current = graphVector.at(index);
    while(current->next != nullptr)
    {
        current = current->next;
        cout << "comparing " << v->name << " against vertex " << current->name << endl; 
        if(current->weight < smallestDistance)
        {
            smallestDistance = current->weight;
            tempVertex = *current;
        }
    }

    return tempVertex;
}

int graph::shortestDistance(string v1, string v2)
{
    // check that v1 and v2 are valid vertices and assign to pointers
    vertex* vertex1;
    vertex* vertex2;
    for(int i = 0; i<vertices; i++)
    {
        if(graphVector.at(i)->name == v1)
        {
            vertex1 = graphVector.at(i);
        }
        
        if(graphVector.at(i)->name == v2)
        {
            vertex2 = graphVector.at(i);
        }
    }

    // create the list of visited and unvisited vertices
    vector<vertex*> visitedVector;
    vector<vertex*> unvisitedVector;

    // fill the unvisited list
    for(int i = 0; i<graphVector.size(); i++)
    {
        unvisitedVector.push_back(graphVector.at(i));
    }

    // dijkstra vector - stores vertex, its shortest distance, and the previous vertex
    vector<dijkstraEntry*> dijkstraVector;

    // construct the dijkstra vector - start at vector1
    dijkstraEntry *sourceVertex = new dijkstraEntry;
    sourceVertex->shortestDistance = 0;
    sourceVertex->v = vertex1;
    sourceVertex->previousVertex = nullptr;

    dijkstraVector.push_back(sourceVertex);

    // loop through every other vertex and add it to the dijkstra vector with infinite distance
    for(int i = 0; i<graphVector.size(); i++)
    {
        if(graphVector.at(i) != vertex1)
        {
            dijkstraEntry *entry = new dijkstraEntry;
            entry->shortestDistance = 2147483647;
            entry->previousVertex = nullptr;
            entry->v = graphVector.at(i);
            dijkstraVector.push_back(entry);
        }
    }

    // start at dijkstra entry at position 0, and loop through and do dijkstra's algo
    for(int i = 0; i<dijkstraVector.size(); i++)
    {
        
    }
}

void graph::printGraph()
{
    for(int i = 0; i<graphVector.size(); i++)
    {
        // print the origin
        cout << "origin node: " << graphVector.at(i)->name << " is connected to the following:" << endl;
        
        vertex* current = graphVector.at(i);
        while(current->next != nullptr)
        {
            current = current->next;
            cout << current->name << " with weight " << current->weight << endl;
        }
    }
}
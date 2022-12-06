#include "graph.h"

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

// graphList implementation
graphList::graphList()
{
    graphSize = 0;
}

void graphList::push_back(vertex* v)
{
    if(graphSize < maxGraphSize)
    {
        graph[graphSize] = v;
        graphSize++;
    }
}

int graphList::size()
{
    return graphSize;
}

vertex* graphList::at(int index)
{
    return graph[index];
}

// graph implementation
graph::graph()
{
    vertices = 0;
}

void graph::addEdge(string origin, string terminus, int weight)
{
    // bool to check if we already have a node with the given origin
    bool originFound = false;
    bool terminusFound = false;

    //debug
    // cout << "attempting to add vertex with origin " << origin << ", terminus " << terminus << ", and weight " << weight << endl;
    
    for(int i = 0; i<vertices; i++)
    {
        if(graphList.at(i)->name == origin)
        {
            // debug
            // cout << "existing vertex found, attemping to add" << endl;
            originFound = true;

            // we know that this already exists in the vector
            // create a new node with the name of terminus
            vertex* newVertex = new vertex(terminus, weight);

            vertex* current = graphList.at(i);
            while(current->next != nullptr)
            {
                current = current->next;
            }

            // set the next vertex of whatever we're at to the new vertex
            current->next = newVertex;
        }

        if(graphList.at(i)->name == terminus)
        {
            terminusFound = true;
        }
    }

    if(originFound == false)
    {
        // make two new vertices
        // vertex that holds the origin, has weight of 0
        vertex* newVertexOrigin = new vertex(origin, 0);

        // vertex that holds the terminus, weight given
        vertex* newVertexTerminus = new vertex(terminus, weight);

        // add the origin vertex to the vector
        graphList.push_back(newVertexOrigin);

        // set the origin vertex's next pointer to the new vertex
        graphList.at(graphList.size()-1)->next = newVertexTerminus;

        // increase number of vertices by 1
        vertices++;
    }

    if(terminusFound == false)
    {
        // create a new vertex for terminus
        vertex* newVertex = new vertex(terminus, 0);

        // add the vertex to the vector
        graphList.push_back(newVertex);

        // increase vertices
        vertices++;
    }
}

vertex graph::getClosestUnvisitedNeighbor(string vertexName)
{
    vertex returnVertex;
    for(int i = 0; i<graphList.size(); i++)
    {
        if(graphList.at(i)->name == vertexName)
        {
            returnVertex = getClosestUnvisitedNeighbor(graphList.at(i));
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
        if(v == graphList.at(i))
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
    vertex* current = graphList.at(index);
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

void graph::printGraph()
{
    for(int i = 0; i<graphList.size(); i++)
    {
        // print the origin
        cout << "origin node: " << graphList.at(i)->name << " is connected to the following:" << endl;
        
        vertex* current = graphList.at(i);
        while(current->next != nullptr)
        {
            current = current->next;
            cout << current->name << " with weight " << current->weight << endl;
        }
    }
}
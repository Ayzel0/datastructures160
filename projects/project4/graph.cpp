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

graph::graph()
{
    vertices = 0;
}

void graph::addEdge(string origin, string terminus, int weight)
{
    // check if we already have a node with the given origin
    bool found = false;

    //debug
    cout << "attempting to add vertex with origin " << origin << ", terminus " << terminus << ", and weight " << weight << endl;
    
    for(int i = 0; i<graphVector.size(); i++)
    {
        if(graphVector.at(i)->name == origin)
        {
            // debug
            cout << "existing vertex found, attemping to add" << endl;
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
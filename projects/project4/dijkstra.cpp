#include "dijkstra.h"

dijkstra::dijkstra()
{
    priorityQueue pQueue;
    vector<dijkstraEntry*> dVector;
}

dijkstra::~dijkstra()
{
    deleteDijkstraVector();
    // cout << "done deleting dijkstra vector" << endl;
}

dijkstraEntry* dijkstra::findDEntry(vertex* vert)
{
    for(int i = 0; i<dVector.size(); i++)
    {
        if(dVector.at(i)->v->name == vert->name)
        {
            return dVector.at(i);
        }
    }
    return nullptr;
}

void dijkstra::deleteDijkstraVector()
{
    for(int i = 0; i<dVector.size(); i++)
    {
        dijkstraEntry *d = dVector.at(i);
        delete d;
    }
    dVector.clear();
}

bool isInVector(vector<vertex*> vec, vertex* v)
{
    for(int i = 0; i<vec.size(); i++)
    {
        if(vec.at(i)->name == v->name)
            return true;
    }

    return false;
}

void addToPriorityQueue(priorityQueue &p, vertex* fromVertex, vertex* toVertex, int weight)
{
    pQueueEntry *newEntry = new pQueueEntry;
    newEntry->from = fromVertex;
    newEntry->to = toVertex;
    newEntry->weight = weight;
    p.enqueue(newEntry);
}

// debug
void printVector(vector<vertex*> v)
{
    for(int i = 0; i<v.size(); i++)
    {
        cout << v.at(i)->name << endl;
    }
}

// debug
void dijkstra::printDijkstra()
{
    cout << "vertex name " << " : " << " previous vertex " << " : " << " shortest distance" << endl;
    for(int i = 0; i<dVector.size(); i++)
    {
        if(dVector.at(i)->previousVertex == nullptr)
            cout << dVector.at(i)->v->name << " : " << "null" << " : " << dVector.at(i)->shortestDistance << endl; 
        else
            cout << dVector.at(i)->v->name << " : " << dVector.at(i)->previousVertex->name << " : " << dVector.at(i)->shortestDistance << endl; 
    }
}

void dijkstra::printPQueue()
{
    pQueue.printQueue();
}

pQueueEntry* dequeueUntilUnvisited(priorityQueue &p, vector<vertex*> unvisited)
{
    bool visited = true;
    while(visited)
    {
        pQueueEntry *entry = p.dequeue();
        if(isInVector(unvisited, entry->to))
        {
            visited = false;
            return entry;
        }
        delete entry;
    }
}

int dijkstra::findShortestDistance(string v1, string v2, graph g)
{
    // do dijkstra's algorithm
    // find where we're starting
    int start = 0, end = 0;
    for(int i = 0; i<g.graphVector.size(); i++)
    {
        if(g.graphVector.at(i)->name == v1)
        {
            start = i;
        }
    }

    // start by making the path and cost arrays - should have three columns and row equivalent to entries
    for(int i = 0; i<g.graphVector.size(); i++)
    {
        dijkstraEntry *newEntry = new dijkstraEntry;
        newEntry->v = g.graphVector.at(i);
        newEntry->previousVertex = nullptr;
        dVector.push_back(newEntry);
    }

    // make the visited and unvisited arrays
    vector<vertex*> visited;
    vector<vertex*> unvisited;

    // fill the unvisited array
    for(int i = 0; i<g.graphVector.size(); i++)
    {
        unvisited.push_back(g.graphVector.at(i));
    }

    // now, start traversing
    // create a priority queue for this stuff
    priorityQueue pQueue;

    // keep track of which vertex we're looking at
    int vertexNum = start;

    // set the distance between the start and itself to 0
    findDEntry(g.graphVector.at(vertexNum))->shortestDistance = 0;

    // loop while we've still got entries in the unvisited vector - there are still vertices we haven't visited
    while(unvisited.size() != 0)
    {
        // pointer for the vertex we are currently "at"
        vertex* currentVertex = g.graphVector.at(vertexNum);

        // dijkstra entry for the vertex we're currently at
        dijkstraEntry *d = findDEntry(currentVertex);

        // loop to enqueue all vertices for a specific vertex - current variable to loop
        vertex* current = currentVertex;
        while(current->next != nullptr)
        {
            current = current->next;

            // check whether current has been visited before
            if(!isInVector(visited, current))
            {
                // create a priority queue entry
                addToPriorityQueue(pQueue, currentVertex, current, current->weight+d->shortestDistance);
            }
        }

        // dequeue until we find something we haven't visited
        pQueueEntry* tempEntry = dequeueUntilUnvisited(pQueue, unvisited);
        dijkstraEntry* nextVertex = findDEntry(tempEntry->to);

        if(nextVertex->shortestDistance > tempEntry->weight)
        {
            nextVertex->shortestDistance = tempEntry->weight;
            nextVertex->previousVertex = tempEntry->from;
        }
        
        // remove the vertex we're currently looking at from the unvisited vector and add it to visited
        // find the index of the current vertex in the unvisited vector
        for(int i = 0; i<unvisited.size(); i++)
        {
            // check whether the name of unvisited at index i is equal to the name of currentVertex
            if(unvisited.at(i)->name == currentVertex->name)
            {
                // add the vertex to visited
                visited.push_back(unvisited.at(i));

                // remove the vertex from unvisited
                unvisited.erase(unvisited.begin()+i);
            }
        }

        // update vertexNum to be the correct index for the next vertex
        for(int i = 0; i<g.graphVector.size(); i++)
        {
            if(g.graphVector.at(i)->name == tempEntry->to->name)
            {
                vertexNum = i;
            }
        }

        // delete tempEntry
        delete tempEntry;
    }

    // after the while loop is over, you now have a complete dijkstra vector, so look for the path you want
    for(int i = 0; i<dVector.size(); i++)
    {
        if(dVector.at(i)->v->name == v2)
        {
            return dVector.at(i)->shortestDistance;
        }
    }

    return -1;
}
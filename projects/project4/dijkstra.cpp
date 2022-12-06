#include "dijkstra.h"

dijkstra::dijkstra()
{
    priorityQueue pQueue;
    vector<dijkstraEntry*> dVector;
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
    }
}

int dijkstra::findShortestDistance(string v1, string v2, graph g)
{
    cout << "starting dijkstra's algorithm" << endl;
    // do dijkstra's algorithm
    // find where we're starting
    int start = 0, end = 0;
    for(int i = 0; i<g.graphVector.size(); i++)
    {
        if(g.graphVector.at(i)->name == v1)
        {
            start = i;
            cout << "starting at index " << start << endl;
        }
    }

    // start by making the path and cost arrays - should have three columns and row equivalent to entries
    for(int i = 0; i<g.graphVector.size(); i++)
    {
        dijkstraEntry *newEntry = new dijkstraEntry;
        newEntry->v = g.graphVector.at(i);
        newEntry->previousVertex = nullptr;
        
        // debug
        cout << "adding entry with vertex " << newEntry->v->name << " and weight " << newEntry->shortestDistance << endl; 

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

    cout << "done adding dijkstra entries to the dijkstra vector" << endl;

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
        dequeueUntilUnvisited(pQueue, unvisited);

        bool hasBeenVisited = true;
        while(hasBeenVisited == true)
        {
            pQueueEntry* tempEntry = pQueue.dequeue();

            // check whether the "to" element of the pQueue (which is what we're moving to) hasn't been visited
            for(int i = 0; i<unvisited.size(); i++)
            {
                if(tempEntry->to->name == unvisited.at(i)->name)
                    hasBeenVisited = false;
            }

            // if hasBeenVisited is still true here, then we know that we need to just dequeue again
            // else, if it's false, we want to update the dijkstra vector
            if(hasBeenVisited == false)
            {
                // this is where we're moving to next
                cout << "the shortest path from " << v1 << " to " << tempEntry->to->name << " is " << tempEntry->weight << endl;

                // find the vertex corresponding to the smallest value
                vertex* tempV = tempEntry->to;

                // find the dijkstra entry for that vertex and set its distance to what we got from the pQueueEntry
                dijkstraEntry *nextSmallest = findDEntry(tempV);
                nextSmallest->shortestDistance = tempEntry->weight;
                nextSmallest->previousVertex = tempEntry->from;

                // update the vertex we're looking at by searching through the graphVector
                for(int i = 0; i<g.graphVector.size(); i++)
                {
                    if(g.graphVector.at(i)->name == tempV->name)
                    {
                        vertexNum = i;
                    }
                }

                // remove the vertex we're currently looking at from the unvisited vector and add it to visited
                for(int i = 0; i<unvisited.size(); i++)
                {
                    if(unvisited.at(i)->name == g.graphVector.at(vertexNum)->name)
                    {
                        cout << "removing vertex " << g.graphVector.at(vertexNum)->name << endl;
                        unvisited.erase(unvisited.begin()+(i-1));
                        visited.push_back(g.graphVector.at(vertexNum));
                    }
                }

                // delete the temp entry
                delete tempEntry;
            }
            else
            {
                delete tempEntry;
            }
        }
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
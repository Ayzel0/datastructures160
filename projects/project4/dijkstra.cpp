#include "dijkstra.h"

dijkstra::dijkstra()
{
    priorityQueue pQueue;
}

dijkstra::~dijkstra()
{
    dList.deleteDijkstraList();
}

dijkstraEntry* dijkstra::findDEntry(vertex* vert)
{
    for(int i = 0; i<dList.size(); i++)
    {
        if(dList.at(i)->v->name == vert->name)
        {
            return dList.at(i);
        }
    }
    return nullptr;
}

// dijkstraList implementation
dijkstraList::dijkstraList()
{
    dijkstraListSize = 0;
}

int dijkstraList::size()
{
    return dijkstraListSize;
}

void dijkstraList::push_back(dijkstraEntry* e)
{
    if(dijkstraListSize < maxListSize)
    {
        list[dijkstraListSize] = e;
        dijkstraListSize++;
    }
}

dijkstraEntry* dijkstraList::at(int index)
{
    return list[index];
}

void dijkstraList::deleteDijkstraList()
{
    for(int i = 0; i<dijkstraListSize; i++)
    {
        delete list[i];
    }
}

// vertexList implementation
vertexList::vertexList()
{
    vertexListSize = 0;
}

void vertexList::push_back(vertex* v)
{
    if(vertexListSize < maxListSize)
    {
        vList[vertexListSize] = v->name;
        vertexListSize++;
    }
}

void vertexList::push_back(string v)
{
    if(vertexListSize < maxListSize)
    {
        vList[vertexListSize] = v;
        vertexListSize++;
    }
}

string vertexList::at(int index)
{
    return vList[index];
}

int vertexList::size()
{
    return vertexListSize;
}

void vertexList::remove(int index)
{
    for(int i = index; i<vertexListSize-1; i++)
    {
        vList[i] = vList[i+1];
    }
    vertexListSize--;
}

void vertexList::printVertexList()
{
    for(int i = 0; i<vertexListSize; i++)
    {
        cout << vList[i] << endl;
    }
}

// helper functions
bool isInList(vertexList list, vertex* v)
{
    for(int i = 0; i<list.size(); i++)
    {
        if(list.at(i) == v->name)
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
void dijkstra::printDijkstra()
{
    cout << "vertex name " << " : " << " previous vertex " << " : " << " shortest distance" << endl;
    for(int i = 0; i<dList.size(); i++)
    {
        if(dList.at(i)->previousVertex == nullptr)
            cout << dList.at(i)->v->name << " : " << "null" << " : " << dList.at(i)->shortestDistance << endl; 
        else
            cout << dList.at(i)->v->name << " : " << dList.at(i)->previousVertex->name << " : " << dList.at(i)->shortestDistance << endl; 
    }
}

// debug
void dijkstra::printPQueue()
{
    pQueue.printQueue();
}

pQueueEntry* dequeueUntilUnvisited(priorityQueue &p, vertexList unvisited)
{
    bool visited = true;
    while(visited)
    {
        pQueueEntry *entry = p.dequeue();
        if(isInList(unvisited, entry->to))
        {
            visited = false;
            return entry;
        }
        delete entry;
    }
    return nullptr;
}

int dijkstra::findShortestDistance(string v1, string v2, graph g)
{
    // do dijkstra's algorithm
    // find where we're starting
    int start = 0;
    for(int i = 0; i<g.gList.size(); i++)
    {
        if(g.gList.at(i)->name == v1)
        {
            start = i;
        }
    }

    // start by making the path and cost arrays - should have three columns and row equivalent to entries
    for(int i = 0; i<g.gList.size(); i++)
    {
        dijkstraEntry *newEntry = new dijkstraEntry;
        newEntry->v = g.gList.at(i);
        newEntry->previousVertex = nullptr;
        dList.push_back(newEntry);
    }

    // make the visited and unvisited arrays
    vertexList visited;
    vertexList unvisited;

    // fill the unvisited array
    for(int i = 0; i<g.gList.size(); i++)
    {
        unvisited.push_back(g.gList.at(i));
    }

    // now, start traversing
    // create a priority queue for this stuff
    priorityQueue pQueue;

    // keep track of which vertex we're looking at
    int vertexNum = start;

    // set the distance between the start and itself to 0
    findDEntry(g.gList.at(vertexNum))->shortestDistance = 0;

    // loop while we've still got entries in the unvisited vector - there are still vertices we haven't visited
    int loopNumber = 0;
    while(unvisited.size() != 0)
    {
        // pointer for the vertex we are currently "at"
        vertex* currentVertex = g.gList.at(vertexNum);

        // dijkstra entry for the vertex we're currently at
        dijkstraEntry *d = findDEntry(currentVertex);

        // loop to enqueue all vertices for a specific vertex - current variable to loop
        vertex* current = currentVertex;
        while(current->next != nullptr)
        {
            current = current->next;

            // check whether current has been visited before
            if(!isInList(visited, current))
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
            if(unvisited.at(i) == currentVertex->name)
            {
                // add the vertex to visited
                visited.push_back(unvisited.at(i));

                // remove the vertex from unvisited
                unvisited.remove(i);

                break;
            }
        }

        // update vertexNum to be the correct index for the next vertex
        for(int i = 0; i<g.gList.size(); i++)
        {
            if(g.gList.at(i)->name == tempEntry->to->name)
            {
                vertexNum = i;
            }
        }

        // delete tempEntry
        delete tempEntry;
        loopNumber++;
    }

    // after the while loop is over, you now have a complete dijkstra vector, so look for the path you want
    for(int i = 0; i<dList.size(); i++)
    {
        if(dList.at(i)->v->name == v2)
        {
            return dList.at(i)->shortestDistance;
        }
    }

    return -1;
}
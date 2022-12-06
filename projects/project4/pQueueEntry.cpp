#include "pQueueEntry.h"

pQueueEntry::pQueueEntry()
{
    from = nullptr;
    to = nullptr;
    weight = 0;
}

bool pQueueEntry::operator>=(const pQueueEntry& e)
{
    if(this->weight >= e.weight)
    {
        return true;
    }

    return false;
}

bool pQueueEntry::operator<=(const pQueueEntry& e)
{
    if(this->weight <= e.weight)
    {
        return true;
    }

    return false;
}

bool pQueueEntry::operator>(const pQueueEntry& e)
{
    if(this->weight > e.weight)
    {
        return true;
    }

    return false;
}

bool pQueueEntry::operator<(const pQueueEntry& e)
{
    if(this->weight < e.weight)
    {
        return true;
    }

    return false;
}

bool pQueueEntry::operator==(const pQueueEntry& e)
{
    if(this->weight == e.weight)
    {
        return true;
    }

    return false;
}

std::ostream &operator<<(ostream& output, const pQueueEntry& e)
{
    output << "priority queue entry starting at " << e.from->name << " to " << e.to->name << " with weight " << e.weight << endl;
    return output;
}
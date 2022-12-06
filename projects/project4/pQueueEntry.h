#include "graph.h"

class pQueueEntry
{
    public:
        vertex* from;
        vertex* to;
        int weight;
        pQueueEntry();

        // overloaded operators
        bool operator<(const pQueueEntry& v);
        bool operator>(const pQueueEntry& v);
        bool operator<=(const pQueueEntry& v);
        bool operator>=(const pQueueEntry& v);
        bool operator==(const pQueueEntry& v);
        friend ostream &operator<<(ostream& output, const pQueueEntry& e);
};
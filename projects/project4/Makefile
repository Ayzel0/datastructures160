CPP = g++
CFLAGS = -pg -Wall -std=c++11
SRCS = main.cpp dijkstra.cpp graph.cpp pQueueEntry.cpp priorityQueueDijkstra.cpp
SRCS = ${wildcard *.cpp}
OBJS = ${SRCS:.cpp=.o}
INCLS = ${SRCS:.cpp=.h}

p4: $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o p4

$(OBJS):
	$(CPP) $(CFLAGS) -c $*.cpp

depend: Makefile.dep
	$(CPP) -MM $(SRCS) > Makefile.dep

Makefile.dep:
	touch Makefile.dep

.PHONY: submit clean

submit:
	rm -f submit.zip
	zip submit.zip $(SRCS) $(INCLS) Makefile Makefile.dep

clean:
	rm -f *.o a.out core

include Makefile.dep
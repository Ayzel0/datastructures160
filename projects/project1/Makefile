# makefile for project 1

DRIVER_NAME = main
SUBMIT_NAME = submit

a.out: $(DRIVER_NAME).o List.o
	g++ $(Driver_NAME).o List.o

$(DRIVER_NAME).o: $(DRIVER_NAME).cpp $(DRIVER_NAME).h List.h
	g++ -c $(DRIVER_NAME).cpp

List.o: List.cpp List.h
	g++ -c List.cpp

.PHONY: submit clean

submit:
	rm -f $(SUBMIT_NAME).zip
	zip $(SUBMIT_NAME).zip Makefile $(DRIVER_NAME).cpp $(DRIVER_NAME).h List.cpp List.h

clean:
	rm -f *.o core a.out

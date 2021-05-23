CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage
all: graph rm

graph: graph.o test.o
	g++ graph.o test.o -o graph ${CFLAGS}

graph.o: graph.cpp
	g++ -c graph.cpp

test.o: test.cpp
	g++ -c test.cpp

rm:
	rm *.o
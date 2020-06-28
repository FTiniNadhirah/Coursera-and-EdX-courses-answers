CC=g++
CFLAGS=-g -c -Wall -std=c++0x

Main: Main.o ShortestPath.o PriorityQueue.o Graph.o Data.o
	$(CC) Data.o Graph.o PriorityQueue.o ShortestPath.o Main.o -o Main

Main.o: Data.h Graph.h ShortestPath.h Main.cpp
	$(CC) $(CFLAGS) Main.cpp

ShortestPath.o: Data.h Graph.h PriorityQueue.h ShortestPath.h ShortestPath.cpp
	$(CC) $(CFLAGS) ShortestPath.cpp

PriorityQueue.o: Data.h PriorityQueue.h PriorityQueue.cpp
	$(CC) $(CFLAGS) PriorityQueue.cpp

Graph.o: Graph.h Graph.cpp
	$(CC) $(CFLAGS) Graph.cpp

Data.o: Data.h Data.cpp
	$(CC) $(CFLAGS) Data.cpp

clean:
	rm -rf *.o Main

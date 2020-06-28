CC=g++
CFLAGS=-g -c -Wall -std=c++0x

Main: Main.o PrimMST.o KruskalMST.o DisjointSet.o PriorityQueue.o Graph.o
	$(CC) Graph.o PriorityQueue.o DisjointSet.o KruskalMST.o PrimMST.o Main.o -o Main

Main.o: Graph.h KruskalMST.h PrimMST.h MinSpanTree.h Main.cpp
	$(CC) $(CFLAGS) Main.cpp

PrimMST.o: PrimMST.cpp PrimMST.h MinSpanTree.h
	$(CC) $(CFLAGS) PrimMST.cpp

KruskalMST.o: KruskalMST.cpp KruskalMST.h MinSpanTree.h DisjointSet.h
	$(CC) $(CFLAGS) KruskalMST.cpp

DisjointSet.o: DisjointSet.cpp DisjointSet.h
	$(CC) $(CFLAGS) DisjointSet.cpp

PriorityQueue.o: Data.h PriorityQueue.h PriorityQueue.cpp
	$(CC) $(CFLAGS) PriorityQueue.cpp

Graph.o: Graph.h Graph.cpp
	$(CC) $(CFLAGS) Graph.cpp

clean:
	rm -rf *.o Main

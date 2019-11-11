#pragma once
#include <iostream>
using namespace std;

template<class T>
class Edge;

template <class T>
class LinkedNode
{
public:
	T node;
	Edge<T> * adj;
	LinkedNode<T>* next;

	int status; //0-neobrajden,1-obradjen(radni cvor)
	int rastojanje;
	LinkedNode<T>* prev;

	inline LinkedNode() { adj = NULL;next = NULL;status = 0;rastojanje=0;prev = NULL; }
	inline LinkedNode(T nodeN) { node = nodeN;adj = NULL;next = NULL;status = 0;prev = NULL;rastojanje = 0; }
	inline LinkedNode(T nodeN, Edge<T>* adjN, LinkedNode<T>* nextN, int statusN)
	{
		node = nodeN;
		adj = adjN;
		next = nextN;
		status = statusN;

		prev = NULL;
		rastojanje = 0;
	}
	void visit() { cout << node << endl; }
};

template<class T>
class Edge
{
public:
	LinkedNode<T>* dest;
	Edge<T>* link;
	int weight;
	Edge() { dest = NUll;link = NULL; }
	Edge(LinkedNode<T>* destN, Edge<T>* linkN)
	{
		dest = destN;
		link = linkN;
	}
};

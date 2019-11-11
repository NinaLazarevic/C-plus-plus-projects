#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

class QueueAsArray
{
protected:
	int n;
	Node **a;
	int head;
	int tail;
	int brel;
public:
	QueueAsArray(int t);
	~QueueAsArray(void);
	void enqueue(Node* el);
	Node* dequeue();
	bool isEmpty() { return brel == 0; }
};

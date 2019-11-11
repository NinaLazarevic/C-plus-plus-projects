#include "Red.h"

#include<iostream>
using namespace std;
QueueAsArray::QueueAsArray(int t)
{
	n = t;
	a = new Node*[n];
	head = -1;
	tail = -1;
	brel = 0;
}
QueueAsArray::~QueueAsArray(void)
{
	delete[] a;
}
void QueueAsArray::enqueue(Node* el)
{
	if (brel == n)
		throw "nema mesta u redu";
	tail++;
	a[tail] = el;
	brel++;
}
Node* QueueAsArray::dequeue()
{
	if (brel == 0)
		throw "red je prazan nema citanja";
	if (head == -1)
		head++;
	Node* pom = a[head];
	head++;
	if (head == n)
		head = 0;
	brel--;
	if (brel == 0)
		head = tail = -1;
	return pom;
}


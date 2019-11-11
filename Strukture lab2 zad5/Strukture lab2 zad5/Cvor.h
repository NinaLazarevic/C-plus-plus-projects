#pragma once
#include <iostream>
using namespace std;

template <class Tip>
class Cvor
{
public:
	Tip info;
	Cvor* next; //pokazivac na sledeci cvor
public:
	Cvor() { next = NULL; }
	Cvor(Tip i) { info = i;next = NULL; }
	Cvor(Tip i, Cvor* n)
	{
		info = i;
		next = n;
	}
	~Cvor(){}
	Tip Print() { return info; }
};

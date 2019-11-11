#pragma once
#include <iostream>
using namespace std;

class StackAsArray
{
	char* niz;
	int velicina;
	int top;
public:
	StackAsArray(int n)
	{
		velicina = n;
		niz = new char[n];
		top = -1;
	}
	~StackAsArray()
	{
		delete niz;
	}
	void Push(char el)
	{
		if (top == (velicina - 1))
			throw "Stek je pun";
		top++;
		niz[top] = el;
		
	}
	void Pop()
	{
		if (top == -1)
			throw "Stek je prazan";
		top--;
	}
	char getTop()
	{
		if (top == -1)
			throw "Stek je prazan";
		return niz[top];
	}
	bool isEmpty()
	{
		return (top == -1);
	}
};

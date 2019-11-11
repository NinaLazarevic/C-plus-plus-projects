#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	int info;
	Node* left, *right;
public:
	Node() { left = right = NULL; }
	Node(int el) { info = el;left = right = NULL; }
	Node(int el, Node* l, Node* r) { info = el;left = l;right = r; }

	bool isLS(int el)
	{
		if (info < el)
			return true;
		else
			return false;
	}
	bool isGR(int el)
	{
		if (info>el)
			return true;
		else
			return false;
	}
	bool isEQ(int el)
	{
		if (info == el)
			return true;
		else
			return false;
	}
	void setInfo(int i) { info = i; }
	int getInfo() { return info; }
	void visit()
	{
		cout << info << " ";
	}

};

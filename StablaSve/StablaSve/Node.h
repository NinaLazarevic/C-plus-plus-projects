#pragma once
#include <iostream>
using namespace std;

template<class T>
class Node
{
public:
	T key;
	Node<T>*left, *right;

	Node() { left = right = NULL; }
	Node(T el) { key = el;left = right = NULL;}
	Node(T el, Node<T>*l, Node<T>*r) { key = el;left = l;right = r; }

	bool isLT(T el)
	{
		if (key < el) return true;
		else return false;
	}
	bool isGT(T el)
	{
		if (key > el) return true;
		else return false;
	}
	bool isEQ()
	{
		if (key == el) return true;
		else return false;
	}
	void setKey(T el) { key = el; }
	T getKey()
	{
		return key;
	}

	void visit()
	{
		cout << key << " ";
	}
};

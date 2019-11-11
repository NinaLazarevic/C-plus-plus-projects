#pragma once
#include "Node.h"
#include "Red.h"

class Tree
{
	Node* root;
	int brel;
public:
	Tree() { root = NULL;brel = 0; }
	~Tree() { deleteTree(root); }
	void deleteTree(Node* p);
	void Insert(int el);
	void Print();
	int ElAtLevel(int lvl);
	void Preorder(Node* p);
	void breadthFirst();
	
};

#pragma once
#include "Node.h"

template<class T>
class Tree
{
private:
	Node<T>* root;
	int num;
public:
	
	Tree()
	{
		root = NULL;
		num = 0;
	}
	~Tree()
	{
		deleteTree(root);
	}
	void deleteTree(Node<T>* p);
	bool isEmpty()
	{
		return root == NULL;
	}
	void Insert(T el);
	Node<T>* search(T el)
	{
		return search(root, el);
	}
	Node<T>* search(Node<T>* p, T el);
	/*int brRazlCv();*/
	int height(Node<T>* p);
	int leafsCount(Node<T> *p);

	int max(int a, int b)
	{
		if (a > b) return a;
		else return b;
	}
	
	int getDeepest(Node<T>* node, Node<T>** deepest);
	void getDeepest()
	{
		Node<T>** pom= &root;
		getDeepest(root, pom);

		(*pom)->visit();

	}
	int getDepth(Node<T>*p);

	/*Node<T>* getRoot() { return root; }*/
	
};

template<class T>
inline void Tree<T>::deleteTree(Node<T>* p)
{
	if (p != NULL)
	{
		deleteTree(p->left);
		deleteTree(p->right);
		delete p;
	}
}

template<class T>
inline void Tree<T>::Insert(T el)
{
	Node<T>* p = root, *prev = NULL;
	while (p != NULL)
	{
		prev = p;
		if (p->isLT(el))
			p = p->right;
		else
			p = p->left;
	}
	if (root == NULL)
		root = new Node<T>(el);
	else if(prev->isLT(el))
		prev->right= new Node<T>(el);
	else
		prev->left = new Node<T>(el);
	num++;
}

template<class T>
inline Node<T>* Tree<T>::search(Node<T>* p, T el)
{
	while (p != NULL)
	{
		if (p->isEQ(el))
			return p;
		else if (p->isGT(el))
			p = p->left;
		else p = p->right;
		return NULL;
	}
}

template<class T>
inline int Tree<T>::height(Node<T>* p)
{
	if (p == NULL) return 0;

	if (p->left == NULL && p->right == NULL) return 1;
	else return max(height(p->left), height(p->right)) + 1;
}

template<class T>
inline int Tree<T>::leafsCount(Node<T>* p)
{
		int n = 0;
		if (p->left == NULL && p->right == NULL)
			return 1;
		else {
			n += leafsCount(p->left);
			n += leafsCount(p->right);
		}
		return n;
}

template<class T>
inline int Tree<T>::getDeepest(Node<T>* node, Node<T>** deepest)
{
	Node<T>** dpl = deepest;
	Node<T>** dpr = deepest;
	if (node == NULL)
	{
		return 0;
	}
	if (node->left == NULL && node->right == NULL)
	{
		deepest = &node;
		dpr = dpl = &node;
		return 1;
	}
	else
		if (getDeepest(node->left, dpl) > getDeepest(node->right, dpr))
			deepest = dpl;
		else
			deepest = dpr;
			
}

template<class T>
inline int Tree<T>::getDepth(Node<T>* p)
{
	int pkey = p->getKey();
	bool nadjen = false;
	Node<T>*pom = root;
	int dp = 0;

	while (pom != NULL || nadjen != true)
	{
		if (pom->getKey() != pkey)
			dp++;
		else
			nadjen = true;
		if (pom->getKey() > p->getKey())
			pom = pom->left;
		else
			pom = pom->right;
	}
	if(nadjen)
		return dp;
	else return -1;
}






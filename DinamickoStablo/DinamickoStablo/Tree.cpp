#include "Tree.h"
#include <math.h>

void Tree::deleteTree(Node * p)
{
	if (p != NULL)
	{
		deleteTree(p->left);
		deleteTree(p->right);
		delete p;
	}
}

void Tree::Insert(int el)
{
	Node* p=root, *prev=NULL;
	while (p != NULL)
	{
		prev = p;
		if (p->isLS(el))
			p = p->right;
		else
			p = p->left;
	}
	if (root == NULL)
		root = new Node(el);
	else
		if (prev->isLS(el))
			prev->right = new Node(el);
		else
			prev->left = new Node(el);
	brel++;
}

void Tree::Print()
{ //kao preorder
	this->Preorder(root);
}

int Tree::ElAtLevel(int lvl)
{
	Node* pom = new Node(0); //pomocni cvor za inicijalizaciju niza
	Node * p = root;
	Node** niz=new Node*[40];
	QueueAsArray Red(50);
	for (int i = 0;i < 40;i++)
		niz[i] = pom; //elementi niza ne smeju da budu NULL zbog f-je koja sledi
	int i = 0;
	if (p != NULL) //smestamo stablo u niz kao staticku reprezentaciju
		{
			Red.enqueue(p);
	
			while (!Red.isEmpty())
			{
				p = Red.dequeue();
				while(niz[i]==NULL)
					{
						niz[2 * i + 1] = NULL;
						niz[2 * i + 2] = NULL;
						i++;
					}
				niz[i] = p;
				if (p->left != NULL)
					Red.enqueue(p->left);
				else
					niz[2 * i + 1] = NULL;
				if (p->right != NULL)
					Red.enqueue(p->right);
				else
					niz[2 * i + 2] = NULL;
				i++;
			}
		}
	int brel = 0;
	int granica = 1;
	for (int i = 0;i < lvl;i++)
		granica = granica * 2;//brpj elemenata na nivou i index prvog na tom nivou 
	int j = (granica-1);//indexi pocinju od 0
	int granica2 = j + granica - 1;
	while (j <= granica2 /*&& brel <= granica*/)
	{
		if (niz[j] != NULL)
			brel++;
		j++;
	}
	return brel;

	delete p;
	delete pom;
	for (int i = 0;i < 40;i++)
		delete niz[i];
	delete niz;
	
}

void Tree::Preorder(Node * p)
{
	if (p != NULL)
	{
		p->visit();
		Preorder(p->left);
		Preorder(p->right);
	}
}

void Tree::breadthFirst()
{
	Node * p = root;
	QueueAsArray Red(50);
	if (p != NULL)
	{
		Red.enqueue(p);

		while (!Red.isEmpty())
		{
			p = Red.dequeue();
			p->visit();
			if (p->left != NULL)
				Red.enqueue(p->left);
			if (p->right != NULL)
				Red.enqueue(p->right);
		}
	}
}





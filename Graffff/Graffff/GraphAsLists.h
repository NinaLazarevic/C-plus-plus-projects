#pragma once
#include "LinkedNode.h"

template<class T>
class GraphAsLists
{
protected:
	LinkedNode<T>* start;
	int nodeNum;
public:
	GraphAsLists() { start = NULL;nodeNum = 0; }
	~GraphAsLists();
	LinkedNode<T>* findNode(T pod);
	Edge<T>* findEdge(T a, T b);
	bool insertNode(T pod);
	bool insertEdge(T a, T b);
	bool deleteNode(T pod);
	bool deleteEdge(T a, T b);
	void print();
	void deleteEdgeToNode(LinkedNode<T>* ptr);
	bool IsThereAPath(T a, T b);
	bool findShortestPath(T a, T b);
};

template<class T>
inline GraphAsLists<T>::~GraphAsLists()
{
	LinkedNode<T>* ptr = start;
	while (ptr != NULL)
	{
		LinkedNode<T>* ptr2 = ptr->next;
		deleteNode(ptr->node);
		ptr = ptr2;
	}
	start = NULL;
}

template<class T>
inline LinkedNode<T>* GraphAsLists<T>::findNode(T pod)
{
	LinkedNode<T>* ptr = start;
	while (ptr != NULL && ptr->node != pod)
		ptr = ptr->next;
	return ptr;

}

template<class T>
inline Edge<T>* GraphAsLists<T>::findEdge(T a, T b)
{
	LinkedNode<T>* pa = findNode(a);
	LinkedNode<T>* pb = findNode(b);
	if (pa == NULL || pb == NULL) return NULL;
	Edge<T>* ptr = pa->adj;
	while (ptr != NULL && ptr->dest != pb)
		ptr = ptr->link;
	return ptr;
}

template<class T>
inline bool GraphAsLists<T>::insertNode(T pod)
{
	LinkedNode<T>* novi = new LinkedNode<T>(pod, NULL, start, 0);
	if (novi == NULL) return false;
	start = novi;
	nodeNum++;
	return true;
}

template<class T>
inline bool GraphAsLists<T>::insertEdge(T a, T b)
{
	LinkedNode<T>* pa = findNode(a);
	LinkedNode<T>* pb = findNode(b);
	if (pa == NULL || pb == NULL) return false;
	Edge<T>* ptr = new Edge<T>(pb, pa->adj);
	if (ptr == NULL) return false;
	pa->adj = ptr;
	return true;
}

template<class T>
inline bool GraphAsLists<T>::deleteNode(T pod)
{
	LinkedNode<T> *ptr;
	if (start == NULL) return false;
	if (start->node == pod)
	{
		ptr = start;
		Edge<T> *pot = start->adj;
		while (pot != NULL)
		{
			Edge<T> *tpot = pot->link;
			delete pot;
			pot = tpot;
		}
		start->adj = NULL;
		deleteEdgeToNode(start);
		ptr = start;
		start = start->next;
		delete ptr;
		nodeNum--;
		return true;
	}
	else
	{
		ptr = start->next;
		LinkedNode<T> *par = start;
		while (ptr != NULL && ptr->node != pod)
		{
			par = ptr;
			ptr = ptr->next;
		}
		if (ptr == NULL) return false;
		par->next = ptr->next;
		Edge<T> *pot = ptr->adj;
		while (pot != NULL)
		{
			Edge<T> *tpot = pot->link;
			delete pot;
			pot = tpot;
		}
		ptr->adj = NULL;
		deleteEdgeToNode(ptr);
		delete ptr;
		nodeNum--;
		return true;
	}
}

template<class T>
inline bool GraphAsLists<T>::deleteEdge(T a, T b)
{
	Edge<T>* pot = findEdge(a, b);
	if (pot == NULL) return false;
	LinkedNode<T>* pa = findNode(a);
	if (pot == pa->adj)
	{
		pa->adj = pot->link;
		delete pot;
		return true;
	}
	Edge<T>* tpot = pa->adj;
	while (tpot->link != pot)
		tpot = tpot->link;
	tpot->link = pot->link;
	delete pot;
	return true;
}

template<class T>
inline void GraphAsLists<T>::print()
{
	LinkedNode<T>* ptr = start;
	while (ptr != NULL)
	{
		cout << ptr->node << "->";
		Edge<T>* pa = ptr->adj;
		while (pa != NULL)
		{
			cout << pa->dest->node << "|";
			pa = pa->link;
		}
		cout << "\r\n";
		ptr = ptr->next;
	}
}

template<class T>
inline void GraphAsLists<T>::deleteEdgeToNode(LinkedNode<T>* ptr)
{
	LinkedNode<T> *pa = start;
	while (pa != NULL)
	{
		Edge<T> *prev, *pot = pa->adj;
		prev = pot;
		while (pot != NULL)
		{
			if (pot->dest == ptr)
			{
				if (pa->adj == pot)
				{
					pa->adj = pot->link;
					delete pot;
					pot = pa->adj;
				}
				else
				{
					prev->link = pot->link;
					delete pot;
					pot = prev->link;
				}
			}
			else
			{
				prev = pot;
				pot = pot->link;
			}
		}
		pa = pa->next;
	}
}

template<class T>
inline bool GraphAsLists<T>::IsThereAPath(T a, T b)
{
	LinkedNode<T>* pa = findNode(a);
	LinkedNode<T>* pb = findNode(b);
	if (pa == NULL || pb == NULL) return false;
	if (findEdge(a, b) != NULL) return true;//ako postoji grana,to je put
	else {
		LinkedNode<T>*pom = pa;
		Edge<T>* pomeg = pa->adj;
		while (pom != NULL) 
		{
			Edge<T>* ptr = pom->adj;
			while (ptr != NULL)
			{
				if (findEdge(ptr->dest->node, b))return true;
				ptr = ptr->link;
			}
			pom = pomeg->dest;
			pomeg = pomeg->link;
		}
	}
	

}

template<class T>
inline bool GraphAsLists<T>::findShortestPath(T a, T b)
{
	LinkedNode<T>* ptr = start;
	Edge<T>* grana = start->adj;
	while (ptr != NULL)
	{
		ptr->rastojanje = 999999; //svakom cvoru stavimo rastojanje na veliki br
		int i = 1;
		while (grana != NULL)
		{
			grana->weight = i;//stavljamo tezine granama
			grana = grana->link;
			i++; 
		}
		ptr = ptr->next;
		if(ptr!=NULL)
			grana = ptr->adj;
	}

	LinkedNode<T>* odredisni = findNode(b);
	if (odredisni == NULL) { cout << "Ne postoji cvor " << b << " u grafu.";return false; }

	ptr = findNode(a); //biramo cvor a za prvi radni cvor
	if (ptr == NULL) { cout << "Ne postoji cvor " << a << " u grafu.";return false; }

	ptr->rastojanje = 0; //prvi radni cvor ima rastojanje 0
	ptr->status = 1; //ako je radni cvor,status mu je 1
	grana = ptr->adj;
	while (grana != NULL)
	{
		grana->dest->rastojanje = ptr->rastojanje + grana->weight;
		grana->dest->prev = ptr;
		grana = grana->link;
	}
	
	int i = 0;
	while (ptr != odredisni && i <= nodeNum)
	{
		int minras = 999999;
		grana = ptr->adj;
		while (grana != NULL)
		{
			if (grana->dest->rastojanje < minras) {
				minras = grana->dest->rastojanje;
				ptr = grana->dest; //sledeci radni cvor
			}
			grana = grana->link;
		}
		
		if (ptr->status == 0)
		{
			ptr->status = 1;
			i++;
		}
		else //nalazimo sledeci radni cvor
		{
			LinkedNode<T>* pom = start;
			while (pom != NULL) {
				grana = pom->adj;
				while (grana != NULL)
				{
					if (grana->dest->status == 0 && grana->dest->rastojanje < minras)
						ptr = grana->dest;
				}
				pom = pom->next;
			}
		}
			grana = ptr->adj;
			while (grana != NULL) //ponovo susedima odredjujemo rastojanje
			{
				grana->dest->rastojanje = ptr->rastojanje + grana->weight;
				grana->dest->prev = ptr;
				grana = grana->link;
			}

		}
	
		if (ptr == odredisni)
		{
			cout << "\nNajkrace rastojanje od cvora " << a << " do cvora " << b << " je: " <<ptr->rastojanje ;
			cout << "\nI prolazi kroz cvorove: ";
			LinkedNode<T>* pom = ptr;
			pom->prev = ptr->prev;
			cout << ptr->node<<" ";
			while (pom->prev != NULL)
			{
				cout << pom->prev->node << " ";
				pom = pom->prev;
			}
			
			return true;
		}
	
	else
	{
		cout << "Ne postoji put.";
		return false;
	}
}

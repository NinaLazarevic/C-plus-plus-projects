#pragma once
#include "Cvor.h"

template<class Tip>
class CSortList
{
	Cvor<Tip>* head, *tail; //pokazivaci na prvi i zadnji cvor
public:
	CSortList() { head = tail = NULL; }
	~CSortList();
	bool IsEmpty() { return head == NULL; }
	void deleteFromHead();
	void AddToHead(Tip el);
	void Sort();  //Selection Sort
	void SwapNode(Cvor<Tip>* prvi, Cvor<Tip> *drugi);
	void PrintAll();
};

template<class Tip>
inline CSortList<Tip>::~CSortList()
{
	while (!IsEmpty())
		deleteFromHead();
}

template<class Tip>
inline void CSortList<Tip>::deleteFromHead()
{
	if (IsEmpty())
		throw "Lista je prazna";
	else
	{
		Cvor<Tip> *pom = head;
		if (head == tail)
			head = tail = NULL;
		else
			head = head->next;
		delete pom;
	}
}

template<class Tip>
inline void CSortList<Tip>::AddToHead(Tip el)
{
	head = new Cvor<Tip>(el, head);
	if (tail == NULL)
		tail = head;
}

template<class Tip>
inline void CSortList<Tip>::Sort()
{
	Cvor<Tip>* pom, *minindex;
	for (Cvor<Tip>* tmp = head;tmp->next != NULL;tmp = tmp->next)
	{
		minindex = tmp;
		for (Cvor<Tip>* tmp2 = tmp->next;tmp2 != NULL;tmp2 = tmp2->next)
			if (minindex->info > tmp2->info)
				minindex = tmp2;

		pom = tmp;
		SwapNode(pom, minindex);

	}
}

template<class Tip>
inline void CSortList<Tip>::SwapNode(Cvor<Tip>* prvi, Cvor<Tip>* drugi)
{
	Cvor<Tip>* pom1,*pom2;
	pom1 = prvi;
	pom2 = prvi->next;

	prvi = drugi;
	prvi->next = drugi->next;

	drugi = pom1;
	drugi->next = pom2;

}

template<class Tip>
inline void CSortList<Tip>::PrintAll()
{
	for (Cvor<Tip>* tmp = head;tmp != NULL;tmp = tmp->next)
		cout << tmp->Print() << " ";
	cout << endl;
}
//template< class Tip >
//void CSortList<Tip>::Sort()
//{
//	Cvor<Tip> *tmp1, *tmp2, *prev, *prev_max;
//	for (tmp1 = NULL; tmp1 != tail; )
//	{
//		prev_max = NULL;
//		if (tmp1 == NULL) tmp2 = head;
//		else tmp2 = tmp1->next;
//
//		Tip max = tmp2->info;
//		for (; tmp2 != NULL; prev = tmp2, tmp2 = tmp2->next)
//			if (max < tmp2->info)
//			{
//				prev_max = prev;
//				max = tmp2->info;
//			}
//
//		if (prev_max != NULL) SwapNode(tmp1, prev_max);
//
//		if (tmp1 == NULL) tmp1 = head;
//		else tmp1 = tmp1->next;
//	}
//};

//template< class Tip >
//void CSortList<Tip>::SwapNode(Cvor<Tip>* tmp, Cvor<Tip>* prev_max)
//{
//	if (prev_max->next == tail)
//		if (tmp != NULL) tail = tmp->next;
//		else tail = head;
//
//		if (tmp == NULL)
//		{
//			Cvor<Tip>* pom1 = prev_max->next->next;
//			Cvor<Tip>* pom2 = head;
//
//			head = prev_max->next;
//			head->next = pom2->next;
//			prev_max->next = pom2;
//			prev_max->next->next = pom1;
//		}
//		else
//		{
//			Cvor<Tip>* pom3 = prev_max->next;
//			Cvor<Tip>* pom4 = tmp->next;
//			Cvor<Tip>* pom1 = prev_max->next->next;
//			Cvor<Tip>* pom2 = tmp->next->next;
//
//			tmp->next = pom3;
//			if (pom2 == pom3) tmp->next->next = pom4;
//			else tmp->next->next = pom2;
//
//			if (pom2 != pom3)
//			{
//				prev_max->next = pom4;
//				prev_max->next->next = pom1;
//			}
//			else prev_max->next = pom1;
//		}
//};


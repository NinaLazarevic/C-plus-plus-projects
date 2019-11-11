#pragma once
#include "HashObject.h"

class HashTable 
{
	unsigned int length;
	unsigned int brel;
	HashObject* niz;
public:
	HashTable(int vel)
	{
		length = vel+ 0.2*vel;
		niz = new HashObject[length];
		brel = 0;
	}
	~HashTable()
	{
		while (brel != 0)
			for (int i = 0;i < length;i++)
			{
				if (!niz[i].free)
					brel--;
				niz[i].deleteHashObject();
			}
		delete[] niz;
	}
	unsigned int getlength() { return length; }
	unsigned int h(char* a);
	void Insert(HashObject O);
	void Print();
	HashObject* Find(char* key);
	unsigned int c(unsigned int i);
};

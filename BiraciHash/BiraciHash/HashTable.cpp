#include "HashTable.h"

unsigned int HashTable::h(char * s)
{
	unsigned int res = 0;
	unsigned int a = 7;
	for (int i = 0;s[i] != 0;i++)
		res = res << a^s[i];
	res = res%length;
	return res;
}

void HashTable::Insert(HashObject O)
{
	unsigned int k = h(O.Jmbg);
	if (niz[k].IsFree())
		niz[k] = O;
	else {
		while (!niz[k].free)
		{
			k = c(k);
			k %= length;
		}
		niz[k] = O;
	}
	brel++;
}

void HashTable::Print()
{
	for (int i = 0;i < length;i++)
		if (!niz[i].free)
			niz[i].Print();
}

HashObject* HashTable::Find(char * key)
{
	unsigned int k = h(key);
	unsigned int probe = k;
	if (!niz[k].IsFree() && strcmp(niz[k].Jmbg,key)==0)
		return &niz[k];
	else
	{
		do
		{
			unsigned int m = c(k);
			k = m;
			k %= length;
			if (niz[k].IsFree()) { cout << "Glasac nije nadjen\n"; return NULL; }
		} while (strcmp(niz[k].Jmbg, key) != 0 || k != probe);
		if (k != probe && strcmp(niz[k].Jmbg, key) == 0)
		{
			return &niz[k];
		}
		else //ponovo je dosao do pocetne hash f-je
		{
			cout << "Glasac nije nadjen"; return NULL;
		}
	}
}

unsigned int HashTable::c(unsigned int i)
{
	return (i+1)%length;
}

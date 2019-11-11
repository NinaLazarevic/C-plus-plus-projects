#pragma once
#include "Radnik.h"
#include <string.h>
#include <iostream>

using namespace std;

class Preduzece
{
	char* naziv;
	int budzet;
	Radnik** niz;
	int maxbr;
	int br;
public:
	Preduzece(char* n, int m,int b) :maxbr(m),budzet(b)
	{
		naziv = new char[10];
		strcpy(naziv, n);
		br = 0;
		niz = new Radnik*[m];
	}
	~Preduzece()
	{
		delete[] niz;
		delete[] naziv;
	}
	void Dodaj(Radnik& R);
	void Obrisi(int J);
	double Novac();

	friend ostream& operator<<(ostream& out, Preduzece& P);
	int VratibrRadnika() { return this->br; }

};

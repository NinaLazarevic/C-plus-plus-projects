#include "Preduzece.h"
#include "Radnik.h"
#include <iostream>

void Preduzece::Dodaj(Radnik & R)
{
	if (this->br < this->maxbr)
		this->niz[br] = &R;
	br++;
}

void Preduzece::Obrisi(int J)
{
	for (int i = 0;i < this->br;i++)
	{
		if ((this->niz[i])->VratiJMBG() == J)
		{
			for (int j = i; j < br-1;j++)
				this->niz[j] = this->niz[j + 1];
			this->br -= 1;
		}
		(this->niz[i])->PostaviGodzap(0);

		}
}

double Preduzece::Novac()
{
	double n=0;
	for (int i = 0;i < this->br;i++)
		n += (this->niz[i])->OdrPlatu();
	return n;
}


ostream& operator<<(ostream& out, Preduzece& P)
{
	for (int j = 0;j < P.br - 2;j++)
	{
		int imin = j;
		for (int i = j + 1;i < P.br;i++)
			if (*P.niz[imin] > (*P.niz[i]))
				imin = i;
		Radnik* pom = P.niz[j];
		P.niz[j] = P.niz[imin];
		(P.niz[imin]) = pom;

	}
	out << "\nRadnici su: " << endl;
	for (int i = 0;i < P.br;i++)
		P.niz[i]->out();
	return out;

}


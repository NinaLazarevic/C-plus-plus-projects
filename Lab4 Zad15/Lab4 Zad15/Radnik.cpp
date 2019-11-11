#include "Radnik.h"

Radnik::Radnik(int J, char * i, int gz, int gs, double osn)
{
	int n = 20;
	JMBG = J;
	imeprez = new char[n];
	strcpy(imeprez, i);
	godstar = gs;
	godzap = gz;
	osnovica = osn;
}

char * Radnik::VratiImePrez()
{
	return  this->imeprez;
}

int Radnik::operator>(Radnik & R)
{
	if (this->godstar > R.godstar)
		return 1;
	else
		return 0;
}

void Radnik::PostaviGodzap(int g)
{
	this->godzap = g;
}


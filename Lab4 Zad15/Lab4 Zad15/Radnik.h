#pragma once
#include <string.h>


using namespace std;

class Radnik
{
protected:
	int JMBG;
	char* imeprez;
	int godzap;
	int godstar;
	double osnovica;
public:
	Radnik()
	{
		JMBG = 0;
		godzap = 0;
		godstar = 0;
		osnovica = 0;
		imeprez = 0;
	}
	Radnik(int J, char* i, int gz, int gs, double osn);
	virtual~Radnik()
	{
		delete[] imeprez;
	}
	int VratiJMBG() { return this->JMBG; }
	char* VratiImePrez();
	int VratiGodzap() { return this->godzap; }
	virtual double OdrPlatu() = 0;
	int operator>(Radnik& R);
	virtual void out() = 0;
	void PostaviGodzap(int g);
	

};

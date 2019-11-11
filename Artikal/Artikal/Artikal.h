#pragma once
#include <string.h>

using namespace std;

class Artikal
{
	char* naziv=new char[10];
	double cena;
public:
	Artikal(char n[10], double c) :cena(c)
	{
		strcpy(naziv, n);
	}
	
	virtual ~Artikal()
	{
		delete[] naziv;
	}
	
	virtual void ShowDescription();
	double GetPrice()
	{
		return this->cena;

	}
};

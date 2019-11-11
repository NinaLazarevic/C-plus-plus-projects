#pragma once
#include "Artikal.h"
#include <string.h>

using namespace std;

class Laptop :public Artikal
{
	char* opis=new char[20];
	int stanje;
public:
	Laptop(char naziv[10], double cena, char op[20], int s) :Artikal(naziv, cena)
	{
		strcpy(opis, op);
		stanje = s;
	}
	~Laptop()
	{
		delete[] opis;
	}
	void ShowDescription();
	void TurnOn();
	void TurnOff();


};

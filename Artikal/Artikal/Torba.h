#pragma once
#include "Artikal.h"
#include <iostream>
#include <string.h>

using namespace std;

class Torba :public Artikal
{
	int puna;
	Artikal* sadrzaj;
public:
	Torba(char naziv[10], double c, int p) :Artikal(naziv, c)
	{
		puna = p;
	}
	
	
	
	void ShowDescription();
	void Put(Artikal& a);
	void remove();
};

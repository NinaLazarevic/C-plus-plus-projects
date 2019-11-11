#pragma once
#include "Radnik.h"
#include <string.h>
#include <iostream>

using namespace std;

class Developer :public Radnik
{
	char* tip;
	int prekSati;
public:
	Developer(char* p,char* i):Radnik(0,i,0,0,0)
	{
		int n = 15;
		tip = new char[n];
		prekSati = 0;
		strcpy(tip, p);
	}
	Developer(int J, char* i, int gz, int gs, double osn, char* t, int sati) :Radnik(J, i, gz, gs, osn)
	{
		int n = 15;
		tip = new char[n];
		strcpy(tip, t);
		prekSati = sati;
	}
	~Developer() {
		delete[] tip;
	}
	double OdrPlatu();
	friend istream& operator>>(istream& in, Developer& D);
	void out();
};

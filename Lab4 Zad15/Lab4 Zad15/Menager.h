#pragma once
#include "Radnik.h"
#include <string.h>
#include <iostream>

using namespace std;

class Menager :public Radnik
{
	char* tip;
public:
	Menager(char* p, char* i) :Radnik(0, i, 0, 0, 0)
	{
		int n = 15;
		tip = new char[n];
		strcpy(tip, p);
	}
	Menager(int J, char* i, int gz, int gs, double osn, char* t) :Radnik(J, i, gz, gs, osn)
	{
		int n = 15;
		tip = new char[n];
		strcpy(tip, t);
	}
	~Menager()
	{
		delete[] tip;
	}
	double OdrPlatu();
	friend istream& operator>>(istream& in, Menager& M);
	void out();
};

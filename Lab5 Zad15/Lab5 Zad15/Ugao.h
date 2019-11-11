#pragma once
#include <iostream>

using namespace std;

class Ugao
{
	int stepen;
	int minut;
	int sekund;
public:
	Ugao()
	{
		stepen = 0;
		minut = 0;
		sekund = 0;

	}
	~Ugao(){}
	Ugao(const Ugao& U);
	Ugao operator+(Ugao& U);
	Ugao& operator=(const Ugao& U);
	friend istream& operator >> (istream& in, Ugao& U);
	friend ostream& operator<< (ostream& out, Ugao& U);


};

#include "Preduzece.h"
#include "Developer.h"
#include "Menager.h"
#include <iostream>

void main()
{
	Preduzece P("Firma", 20, 80000);
	Developer D1(123, "Radnik1", 3, 32, 2000, "tester", 2);
	Developer D2(124, "Radnik2", 4, 43, 15000, "programer", 5);
	Menager M(125, "Menadzer", 2, 27, 1200, "finansijski");
	Developer D3("programer","Radnik3");
	cin >> D3;
	P.Dodaj(D3);
	P.Dodaj(D1);
	P.Dodaj(D2);
	P.Dodaj(M);

	cout << P;

	P.Obrisi(123);
	cout << P;

	cout << "\nUkupan novac: " << P.Novac();

}
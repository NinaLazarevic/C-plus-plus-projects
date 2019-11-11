#include "Ugao.h"
#include "Vektor.h"
#include <iostream>

void main()
{
	Vektor<int> V1(4);
	Vektor<int> V2(2);
	Vektor <Ugao> V3(1);
	Vektor <Ugao> V4(1);
	Vektor <int> V5;

	V1.Unesi();
	V2.Unesi();
	V3.Unesi();
	V4.Unesi();

	V1.Ispisi();
	
	
}
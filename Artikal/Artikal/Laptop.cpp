#include "Laptop.h"
#include <string.h>
#include <iostream>






void Laptop::ShowDescription()
{
	cout << "\nOpis laptopa: \n" << this->opis << endl;;
	this->Artikal::ShowDescription();
}

void Laptop::TurnOn()
{
	if (this->stanje != 1)
		this->stanje = 1;
}

void Laptop::TurnOff()
{
	if (this->stanje != 0)
		this->stanje = 0;
}

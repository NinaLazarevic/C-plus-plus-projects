#include "Artikal.h"
#include "Laptop.h"
#include <iostream>
#include <string.h>
#include "Torba.h"

void Torba::ShowDescription()
{
	cout << "\nTorba za laptop.\n";
	if (puna != 0)
		sadrzaj->ShowDescription();
	else
		cout << "\nTorba je prazna.\n";

}

void Torba::Put(Artikal & a)
{
	this->sadrzaj = &a;
	this->puna = 1;
}

void Torba::remove()
{
	if (this->puna!= 0)
		sadrzaj = 0;
}


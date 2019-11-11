#include "Torba.h"
#include "Laptop.h"
#include "Artikal.h"
#include <string.h>
#include <iostream>

void main()
{
	Laptop L("ASUS",30000,"Kvalitetan",0);
	Torba T("nema",0,0);
	T.ShowDescription();
	T.Put(L);
	T.ShowDescription();
}
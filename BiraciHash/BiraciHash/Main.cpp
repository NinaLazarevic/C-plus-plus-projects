#include "HashObject.h"
#include "HashTable.h"
#include <string.h>

void main()
{
	try {

		HashTable T(1000);

		HashObject B1("Srdjan Antic", "43527");
		HashObject B2("Milena Dimitrijevic", "64382");
		HashObject B3("Stefan Kolic", "76232");
		HashObject B4("Andjela Jovic", "65309");
		HashObject B5("Jovan Tomic", "86231");
		T.Insert(B1);
		T.Insert(B2);
		T.Insert(B3);
		T.Insert(B4);
		T.Insert(B5);

		cout << "Svi trenutno prijavljani glasaci: " << endl;
		T.Print();

		cout << "\nProvera za glasaca sa Jmbg-om 86231: " << endl;
		if (T.Find("86231") != NULL)
		{
			T.Find("86231")->Print();
			cout << endl;
		}
		cout << "Provera za glasaca sa Jmbg-om 86238: " << endl;
		if (T.Find("86238") != NULL)
		{
			T.Find("86238")->Print();
			cout << endl;
		}
		cout << "\nProvera za glasaca sa Jmbg-om 26298: " << endl;
		if (T.Find("26298") != NULL)
		{
			T.Find("26298")->Print();
			cout << endl;
		}
		
	}

	catch (char* iz)
	{
		cout << iz;
	}
}
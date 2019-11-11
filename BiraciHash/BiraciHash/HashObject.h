#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class HashObject
{
public:
	char* Jmbg; //kljuc
	char* ImePrezime; //Informacija koja se pamti
	bool free;
public:
	HashObject()
	{
		Jmbg = NULL;
		ImePrezime =NULL;
		free = true;
	}
	HashObject(char* info, char* key)
	{
		Jmbg = new char[strlen(key)+1];
		ImePrezime = new char[strlen(info)+1];
		strcpy(Jmbg, key);
		strcpy(ImePrezime, info);
		free = false;
	}
	void deleteHashObject()
	{
		delete[] Jmbg;
		delete[] ImePrezime;
	}
	HashObject& operator=(HashObject const& obj)
	{
		/*delete[] Jmbg;
		delete[] ImePrezime;*/
		this->Jmbg = new char[strlen(obj.Jmbg)+1];
		this->ImePrezime = new char[strlen(obj.ImePrezime)+1];
		strcpy(Jmbg, obj.Jmbg);
		strcpy(ImePrezime, obj.ImePrezime);
		free = obj.free;
		return *this;
	}
	void Print()
	{
		cout << "Glasac: " << ImePrezime<<endl;
	}
	bool IsFree() { return free; }
	
};
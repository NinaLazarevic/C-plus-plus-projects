#include "Developer.h"
#include <iostream>

double Developer::OdrPlatu()
{
	double plata = 0;
	plata = 25 * this->osnovica + 1500 * this->godzap + 1000 * this->prekSati;
	return plata;
}
void Developer::out()
{
	cout << "\nPodaci o radniku:" << endl;
	cout << "\nJMBG " << this->JMBG;
	cout << "\nIme i prezime: " << this->imeprez;
	cout << "\nGodina starosti i god zaposljenja: " << this->godstar << " " << this->godzap;
	cout << "\nPlata: " << this->OdrPlatu();
	cout << "\nTip i prekovremeni sati: " << this->tip << " " << this->prekSati << endl;
}
istream& operator>>(istream& in, Developer& D)
{
	cout << "\nUnesi podatke o radniku:\n" << endl;
	cout << "\nJMBG: "; in >> D.JMBG;
	cout << "\nGodina starosti i god zaposljenja: ";in >> D.godstar; in >> D.godzap;
	cout << "\nOsnovica: ";in >> D.osnovica;
	cout << "\nPrekovremeni sati: ";in >> D.prekSati;
	return in;
	
}

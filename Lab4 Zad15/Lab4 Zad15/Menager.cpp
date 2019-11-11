#include "Menager.h"

double Menager::OdrPlatu()
{
	double plata = 0;
	plata = 30 * this->osnovica + 1000 * this->godzap;
	return plata;
}
void Menager::out()
{
	cout << "\nPodaci o radniku:" << endl;
	cout << "\nJMBG " << this->JMBG;
	cout << "\nIme i prezime: " << this->imeprez;
	cout << "\nGodina starosti i god zaposljenja: " << this->godstar << " " << this->godzap;
	cout << "\nPlata: " << this->OdrPlatu();
	cout << "\nTip: " << this->tip << endl;
}
istream& operator>>(istream& in, Menager& M)
{
	cout << "\nUnesi podatke o radniku:\n" << endl;
	cout << "\nJMBG: "; in >> M.JMBG;
	cout << "\nGodina starosti i god zaposljenja: ";in >> M.godstar; in >> M.godzap;
	cout << "\nOsnovica: ";in >> M.osnovica;
	return in;

}

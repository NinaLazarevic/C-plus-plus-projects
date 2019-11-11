#include "Ugao.h"



Ugao::Ugao(const Ugao & U)
{
	if (this != &U)
	{
		this->stepen = U.stepen;
		this->minut = U.minut;
		this->sekund = U.sekund;
	}
}

Ugao Ugao::operator+(Ugao & U)
{
	Ugao Ug;
	int st;
	st = this->stepen + U.stepen;
	if (st < 355 && st>0)
		Ug.stepen = st;
	else {
		cout << "\nZbir stepena nije u opsegu 0-355" << endl;
		Ug.stepen = 0;
	}
	int se=this->sekund+U.sekund;
	if (se > 0 && se < 60)
		Ug.sekund = se;
	else
	{
		cout << "\nZbir sekundi nije u opsegu 0-60" << endl;
		Ug.sekund = 0;
	}
	int m = this->minut + U.minut;
	if (m > 0 && m < 60)
		Ug.minut = m;
	else
	{
		cout << "Zbir minuta nije u opsegu 0-60" << endl;
		Ug.minut = 0;
	}

	return Ug;
}

Ugao & Ugao::operator=(const Ugao & U)
{
	if (this != &U)
	{
		this->stepen = U.stepen;
		this->minut = U.minut;
		this->sekund = U.sekund;
	}
	return *this;
}
istream& operator >> (istream& in, Ugao& U)
{
	cout << "\nUnesi stepen:"; in >> U.stepen;
	cout << "\nUnesi minut:"; in >> U.minut;
	cout << "\nUnesi sekund:";in >> U.sekund;
	return in;
}
ostream& operator<< (ostream& out, Ugao& U)
{
	out << "\Stepen: " << U.stepen;
	out << "\nMinut: " << U.minut;
	out << "\nSekund: " << U.sekund;
	return out;
}

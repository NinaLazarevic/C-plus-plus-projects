#pragma once
#include <iostream>

using namespace std;

template <class Type>
class Vektor
{
	int n;
	Type* V;
public:
	Vektor()
	{
		n = 0;
		V = new Type[n];
	}
	Vektor(int br)
	{
		n = br;
		V = new Type[br];
	}
	~Vektor()
	{
		delete[] V;
	}
	Vektor(const Vektor& R);
	Vektor<Type>  operator+(Vektor<Type>& Vek);
	void Unesi();
	void Ispisi();
	int VratiBrEl()
	{
		return this->n;
	}
};

template<class Type>
inline Vektor<Type>::Vektor(const Vektor & R)
{
	this->V = new Type[R.n];
	this->n = R.n;
	for (int i = 0;i < this->n;i++)
		this->V[i] = R.V[i];
}

template<class Type>
inline Vektor<Type> Vektor<Type>::operator+(Vektor<Type>& Vek)
{
	int j;
	if (this->n > Vek.n)
		j = Vek.n;
	else
		j = this->n;
	Vektor<Type> R(j);
	for (int i = 0;i < j;i++)
		R.V[i] = this->V[i] + Vek.V[i];
	return R;
}

template<class Type>
inline void Vektor<Type>::Unesi()
{
	cout << "\nUnesi elemente vektora:" << endl;
	for (int i = 0;i < n;i++)
		cin >> this->V[i];
}

template<class Type>
inline void Vektor<Type>::Ispisi()
{
	cout << "\nElementi vektora su:" << endl;
	for (int i = 0;i < n;i++)
		cout << this->V[i] << " ";
}

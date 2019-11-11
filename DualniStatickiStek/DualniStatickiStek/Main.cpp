#include "Stek.h"
#include <string.h>

void main()
{
	try
	{
		char izraz[15];
		cout << "Unesi izraz:" << endl;
		cin >> izraz;
		int n = strlen(izraz);

		char postfixizraz[15];
		

		int j = 0; //index za postfixizraz

		StackAsArray S(15);

		for (int i = 0;i < n;i++)
		{

			if (izraz[i] == '(')
				S.Push(izraz[i]);

			if (izraz[i] == ')')
			{
				while (S.getTop() != '(')
				{
					postfixizraz[j] = S.getTop();
					S.Pop();
					j++;
				}
				if (S.getTop() == '(')
				{
					S.Pop();
				}
			}
			if (izraz[i] == '*' || izraz[i] == '/')
			{
				if (S.isEmpty())
					S.Push(izraz[i]);
				else
				{
					if (S.getTop() == '*' || S.getTop() == '/') //ako je istog prioriteta
					{
						postfixizraz[j] = S.getTop();
						S.Pop();
						S.Push(izraz[i]);
						j++;
					}
					else //tekuci operator je najviseg prioriteta,samo se ubaci na stek
						S.Push(izraz[i]);
				}
			}
			else
				if (izraz[i] == '+' || izraz[i] == '-')
				{
					if (S.isEmpty())
						S.Push(izraz[i]);
					else
					{
						if (S.getTop() == '+' || S.getTop() == '-' || S.getTop() == '*' || S.getTop() == '/')
						{
							postfixizraz[j] = S.getTop();
							S.Pop();
							S.Push(izraz[i]);
							j++;
						}
						else //tekuci operators e ubaci na stek
							S.Push(izraz[i]);
					}
				}
				else //skenirani element je operand,direktno se smesta u izlazni izraz
					if(izraz[i]!='(' && izraz[i]!=')')
					{
						postfixizraz[j] = izraz[i];
						j++;
					}

		}
		postfixizraz[j] = S.getTop();
		for (int i = 0;i <j+1;i++)
		cout << postfixizraz[i];
		cout << endl;
		
	}
	catch (char* iz)
	{
		cout << "Greska: " << iz << endl;
	}
	}
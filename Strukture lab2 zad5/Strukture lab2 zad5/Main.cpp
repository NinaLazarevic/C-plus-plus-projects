#include "CSortList.h"
#include "Cvor.h"
void main()
{
	try
	{
		CSortList<int> list;
		list.AddToHead(0);
		list.AddToHead(3);
		list.AddToHead(10);
		list.AddToHead(1);
		list.AddToHead(7);
		list.AddToHead(2);

		list.PrintAll();

		list.Sort();

		list.PrintAll();
	}
	catch (char* iz)
	{
		cout << iz << endl;
	}
}
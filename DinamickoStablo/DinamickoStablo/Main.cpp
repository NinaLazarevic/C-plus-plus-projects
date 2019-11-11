#include "Node.h"
#include "Tree.h"
#include <iostream>
using namespace std;

void main()
{
	try {
		Tree T;
		T.Insert(20);
		T.Insert(5);
		T.Insert(93);
		T.Insert(6);
		T.Insert(50);
		T.Insert(8);
		T.Insert(1);
		T.Insert(3);
		T.Insert(39);
		T.Insert(7);

		/*T.breadthFirst();*/
		T.Print();

		/*cout << "Na 1. nivou ima " << T.ElAtLevel(1) << " elemenata" << endl;*/
		/*cout<<"Na 2. nivou ima "<<T.ElAtLevel(2)<<" elemenata"<<endl;*/
		cout << "Na 3. nivou ima " << T.ElAtLevel(3) << " elemenata" << endl;
		/*cout << "Na 4. nivou ima " << T.ElAtLevel(4) << " elemenata" << endl;*/
	}
	catch (char* iz)
	{
		cout << iz<<endl;
	}
}
#include "Tree.h"
#include "Node.h"
#include <iostream>
using namespace std;

void main()
{
	Tree<int> t;

	t.Insert(7);
	t.Insert(3);
	t.Insert(8);
	t.Insert(2);
	t.Insert(5);
	t.Insert(1);

	/*t.getDeepest();*/

	Node<int>* pp = new Node<int>(1);
	cout<< t.getDepth(pp);
	
}
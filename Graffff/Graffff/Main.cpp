#include "GraphAsLists.h"

void main()
{
	GraphAsLists<int> graph;

	graph.insertNode(4);
	graph.insertNode(3);
	graph.insertNode(2);
	graph.insertNode(1);

	graph.insertEdge(1, 3);
	graph.insertEdge(2, 4);
	/*graph.insertEdge(2, 1);*/
	/*graph.insertEdge(1, 2);*/
	graph.insertEdge(3, 2);
	/*graph.insertEdge(1, 4);*/
	//graph.insertEdge(4, 2);
	graph.insertEdge(4, 1);

	graph.print();
	if (graph.IsThereAPath(4, 3)) cout << "\nPostoji put izmedju cvora 4 i cvora 3.\n";
	else cout << "\nNe postoji put izmedju cvora 4 i cvora 3.\n";

	graph.findShortestPath(4, 3);
}
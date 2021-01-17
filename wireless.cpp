#include"myGraph.h"
#include<iostream>

using namespace std;
wireless::wireless()
{
	cout << "wireless created";
}

wireless::wireless(int area, int num_of_nodes) :myGraph_class(area, num_of_nodes)
{
	cout << endl << "The size of area entered is " << area << "X" << area << endl;
	cout << endl << "The number of nodes entered is " << num_of_nodes << endl;
}
void wireless::shortest_path()
{
	int vert1, vert2, dist;
	cout << endl << "Enter vertex 1" << endl;
	cin >> vert1;
	cout << endl << "Enter vertex 1" << endl;
	cin >> vert2;
	dist = calculate_1(vert1, vert2);
	cout << endl << "The distance between starting(" << vert1 << ")and ending point(" << vert2 << ")is" << dist << endl;
}

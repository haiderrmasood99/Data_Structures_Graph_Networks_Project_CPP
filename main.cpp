#include <iostream>
#include "myGraph.h"
using namespace std;
int main() {
	cout << "WELCOME TO THE NETWORK SIMULATOR";
	int input_var1, input_var2;
	float input_var_f1;
	string input_var1s, input_var2s;

	myGraph_class a;
	char choice;
GorN:
	int ahg_1 = 0;
	cout << "\nPress *      G       * to access functinalities of Graph   class:\n";
	cout << endl;
	cout << "\nPress *      N       * to access functinalities of Network class:\n";
	cout << "!!!!!!!!!     CASE SENSITIVE    !!!!!!!!!\n";
	cout << endl;
	cin >> choice;
	switch (choice)
	{
	case 'G':
	{
		while (ahg_1 == 0)
		{
			int opt;
			cout << "Press 1: to Add Vertex\n";
			cout << "Press 2: to Add Edge\n";
			cout << "Press 3: to Remove Vertex\n";
			cout << "Press 4: to Remove Edge\n";
			cout << "Press 5: to Show Gra ph\n";
			cout << "Press 6: to Get NUmberof Vertices\n";
			cout << "Press 7: to Get Number of Links\n";
			cout << "Press 8: to Check if graph is empty\n";
			cout << "Press 9: to access network class\n";

			cin >> opt;
			switch (opt)
			{
			case 1:
			{
				cout << "Enter String of your choice as vertex name" << endl;
				cin >> input_var1s;
				a.addVertex(input_var1s);
				break;
			}
			case 2:
			{
				cout << "Enter Edge1 of your choice" << endl;
				cin >> input_var1s;
				cout << "Enter Edge2 of your choice" << endl;
				cin >> input_var2s;
				cout << "Enter weight of your choice" << endl;
				cin >> input_var_f1;
				a.addEdge(input_var1s, input_var2s, input_var_f1);
				break;
			}
			case 3:
			{
				cout << "Enter vertex of your choice to remove" << endl;
				cin >> input_var1s;
				a.deleteVertex(input_var1s);
				break;
			}
			case 4:
			{
				cout << "Enter Edge1 of your choice" << endl;
				cin >> input_var1s;
				cout << "Enter Edge2 of your choice" << endl;
				cin >> input_var2s;
				a.deleteEdge(input_var1s, input_var2s);
				break;
			}
			case 5:
			{
				a.showData();
				break;
			}
			case 6:
			{
				cout << a.getNumVertices() << endl;

				break;
			}
			case 7:
			{
				cout << a.getNumLinks() << endl;
				break;
			}
			case 8:
			{
				if (a.isEmpty())
					cout << "EMPTY" << endl;
				else
					cout << "Not empty" << endl;

				break;
			}
			case 9:
			{
				goto GorN;
				break;
			}
			default:
				cout << "WRONG OPTION SELECTED" << endl;
				goto GorN;
				break;
			}
			cout << "ENTER 1 to STOP AND 0 TO PERFORM MORE OPERATIONS" << endl;
			cin >> ahg_1;
		}

	case 'N':
	{

		int ahg = 0;
		cout << "calculating the unit disk areas and establishing links" << endl;
		cout << "ENTER THE AREA OF YOUR CHOICE" << endl;
		cin >> input_var1;
		cout << "ENTER THE NUMBER OF NODES OF YOUR CHOICE" << endl;
		cin >> input_var2;
		wireless wireless_1(input_var1, input_var2);
		cout << endl;
		while (ahg == 0)
		{
			int opt2;
			cout << endl;
			cout << "Press 1: To show graph \n";
			cout << "Press 2: To Make network \n";
			cout << "Press 3: For shortest path \n";
			cout << "Press 4: For BFS \n";
			cout << "Press 5: For DFS \n";
			cout << "Press 6: to access graph class \n";

			cin >> opt2;
			switch (opt2)
			{
			case 1:
			{
				wireless_1.showDatas();
				cout << endl;
				break;
			}
			case 2:
			{
				wireless_1.networkmaker();
				cout << endl;
				break;
			}
			case 3:
			{
				wireless_1.shortest_path();
				cout << endl;
				break;
			}
			case 4:
			{
				cout << "Enter node of your choice" << endl;
				cin >> input_var1;
				wireless_1.BFS(input_var1);
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "Enter node of your choice" << endl;
				cin >> input_var1;
				wireless_1.DFS(input_var1);
				cout << endl;
				break;
			}
			case 6:
			{
				goto GorN;
				break;
			}
			default:
				cout << "WRONG OPTION SELECTED" << endl;
				goto GorN;
				break;
			}
			cout << "ENTER 1 to STOP AND 0 TO PERFORM MORE OPERATIONS" << endl;
			cin >> ahg;
		}
	}

	}

	}
	system("pause");
}

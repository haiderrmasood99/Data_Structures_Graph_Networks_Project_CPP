#include"myGraph.h"
#include<cmath>
#include<iostream>
#include<stack>
#include<queue>

using namespace std;

template<class T>
int ADJLIST<T>::size() {
	return numLinks;

}
template<class T>
void ADJLIST<T>::incNum() {
	numLinks++;
}

template<class T>
ADJLIST<T>::ADJLIST() {
	numLinks = 0;

}
template<class T>
void ADJLIST<T>::decNum() {
	numLinks--;
}
void myGraph_class::addVertex(int a)
{
	if (!isVertex(a)) {
		ADJLIST<str_list_nw> temp;
		str_list_nw temp2;
		temp2.vertexName_i = a;
		temp2.Weight = -1;
		temp.push_back(temp2);
		adjacencylist.push_back(temp);

	}
	else
		cout << "vertex with this name already exists\n";
}
void myGraph_class::addVertex(string a)
{
	if (!isVertex(a)) {
		ADJLIST<str_list_nw> temp;
		str_list_nw temp2;
		temp2.vertexName = a;
		temp2.Weight = -1;
		temp.push_back(temp2);
		adjacencylist.push_back(temp);

	}
	else
		cout << "vertex with this name already exists\n";
}
void myGraph_class::addEdge(string a, string b, float w) {
	if (isVertex(a) && isVertex(b)) {
		if (!isEdge(a, b))
		{
			vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
			for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
			{
				if (it->front().vertexName == a)
				{
					str_list_nw temp;
					temp.vertexName = b;
					temp.Weight = w;
					it->push_back(temp);
					it->incNum();
				}
				if (it->front().vertexName == b) {
					str_list_nw temp;
					temp.vertexName = a;
					temp.Weight = w;
					it->push_back(temp);
					it->incNum();
				}
			}
		}
		else
			cout << "edge already exists\n";
	}
	else
		cout << "one of the vertex doesnot exist\n";

}
void myGraph_class::addEdge(int a, int b, float w) {
	if (isVertex(a) && isVertex(b)) {
		if (!isEdge(a, b))
		{
			vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
			for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
			{
				if (it->front().vertexName_i == a)
				{
					str_list_nw temp;
					temp.vertexName_i = b;
					temp.Weight = w;
					it->push_back(temp);
					it->incNum();
				}
				if (it->front().vertexName_i == b) {
					str_list_nw temp;
					temp.vertexName_i = a;
					temp.Weight = w;
					it->push_back(temp);
					it->incNum();
				}
			}
		}
		else
			cout << "";
	}
	else
		cout << "one of the vertex doesnot exist\n";

}
bool myGraph_class::isEdge(string a, string b) {
	vector<ADJLIST<str_list_nw>>::iterator it;
	for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
	{
		if (it->front().vertexName == a)
		{

			ADJLIST<str_list_nw>::iterator i = it->begin();
			for (i = it->begin(); i != it->end(); i++)
				if (i->vertexName == b)
					return true;
		}
		if (it->front().vertexName == b)
		{
			ADJLIST<str_list_nw>::iterator i;
			for (i = it->begin(); i != it->end(); i++)
				if (i->vertexName == a)
					return true;
		}

	}
	return false;
}
bool myGraph_class::isEdge(int a, int b) {
	vector<ADJLIST<str_list_nw>>::iterator it;
	for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
	{
		if (it->front().vertexName_i == a)
		{

			ADJLIST<str_list_nw>::iterator i = it->begin();
			for (i = it->begin(); i != it->end(); i++)
				if (i->vertexName_i == b)
					return true;
		}
		if (it->front().vertexName_i == b)
		{
			ADJLIST<str_list_nw>::iterator i;
			for (i = it->begin(); i != it->end(); i++)
				if (i->vertexName_i == a)
					return true;
		}

	}
	return false;
}
bool myGraph_class::isVertex(string a) {
	vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
	for (it = adjacencylist.begin(); it < adjacencylist.end(); it++) {
		if (it->front().vertexName == a)
			return true;
	}
	return false;
}
bool myGraph_class::isVertex(int a) {
	vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
	for (it = adjacencylist.begin(); it < adjacencylist.end(); it++) {
		if (it->front().vertexName_i == a)
			return true;
	}
	return false;
}
myGraph_class::myGraph_class() {
}
myGraph_class::myGraph_class(int area, int nodes) {

	for (int ver = 0; ver < nodes; ver++)
	{
		addVertex(ver, area);
	}
}
void myGraph_class::showData() {
	vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
	for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
	{
		cout << "NODE: " << it->front().vertexName << "\nNetwork Member:\n";
		ADJLIST<str_list_nw>::iterator i = it->begin();
		i++;
		for (i; i != it->end(); i++)
			cout << "node:" << i->vertexName << " , weight :" << i->Weight << endl;
		cout << endl;
	}

}
void myGraph_class::showDatas() {
	vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
	for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
	{
		cout << "NODE: " << it->front().vertexName_i << "\nLINKED NODES:\n";
		//cout << "   " << it->front().posx << "   " << it->front().posy << endl;
		ADJLIST<str_list_nw>::iterator i = it->begin();
		i++;
		for (i; i != it->end(); i++)
			cout << "node:" << i->vertexName_i << " , weight :" << i->Weight << endl;
		cout << endl;
		cout << endl;

	}

}
bool myGraph_class::isEmpty() {
	return adjacencylist.empty();
}

void myGraph_class::deleteVertex(string a) {
	if (isVertex(a))
	{
		vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
		for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
		{

			if (it->front().vertexName == a) {
				it = adjacencylist.erase(it);
				break;
			}

		}
		for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
		{

			for (ADJLIST<str_list_nw>::iterator i = it->begin(); i != it->end(); i++)
				if (i->vertexName == a) {
					i = it->erase(i);
					break;
				}


		}
	}
	else
		cout << "no vertex with this name\n";
}
void myGraph_class::deleteEdge(string a, string b) {
	if (isVertex(a) && isVertex(b)) {
		if (isEdge(a, b))
		{
			vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
			for (it; it != adjacencylist.end(); it++)
			{
				if (it->front().vertexName == a) {
					for (ADJLIST<str_list_nw>::iterator i = it->begin(); i != it->end(); i++)
						if (i->vertexName == b)
						{
							i = it->erase(i);
							break;
						}
					it->decNum();
				}
				if (it->front().vertexName == b)
				{
					for (ADJLIST<str_list_nw>::iterator i = it->begin(); i != it->end(); i++)
						if (i->vertexName == a)
						{
							i = it->erase(i);
							break;
						}
					it->decNum();
				}
			}

		}
		else
			cout << "edge doesn't exist\n";

	}
	else
		cout << "one of the vertex doesn't exist\n";
}
int myGraph_class::getNumVertices() {
	return adjacencylist.size();
}

int myGraph_class::getNumLinks() {
	int links = 0;
	for (vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin(); it != adjacencylist.end(); it++)
	{
		links += it->size();
	}return links / 2;
}
int myGraph_class::randomx(int area)
{
	int rtrn_value;
again_val:rtrn_value = rand() % area;
	if (rtrn_value < area && rtrn_value > 0)
	{
		return rtrn_value;
	}
	else
		goto again_val;
}
int myGraph_class::randomy(int area)
{
	int rtrn_value;
again_val:rtrn_value = rand() % area;
	if (rtrn_value < area && rtrn_value > 0)
	{
		return rtrn_value;
	}
	else
		goto again_val;
}

void myGraph_class::addVertex(int name, int area) {
	if (!isVertex(name)) {
		ADJLIST<str_list_nw> temp;
		str_list_nw temp2;
		temp2.vertexName_i = name;
	random_again:
		temp2.posx = randomx(area);
		temp2.posy = randomy(area);
		temp2.Weight = -1;
		if (position_occupied(temp2.posx, temp2.posy, temp2.vertexName_i))
		{
			temp.push_back(temp2);
			adjacencylist.push_back(temp);
		}
		else
		{
			goto random_again;
		}
	}
	else
		cout << "vertex with this name already exists\n";
}
void myGraph_class::networkmaker()
{
	float unit_displacement;
	vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
	vector<ADJLIST<str_list_nw>>::iterator it_1 = adjacencylist.begin();

	for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
	{
		int pos_x1 = it->front().posx;
		int pos_y1 = it->front().posy;
		//cout << it->front().vertexName_i;
		for (it_1 = adjacencylist.begin(); it_1 < adjacencylist.end(); it_1++)
		{
			int pos_x2 = it_1->front().posx;
			int pos_y2 = it_1->front().posy;
			unit_displacement = sqrt(pow(pos_x1 - pos_x2, 2) + pow(pos_y1 - pos_y2, 2) * 1.0);
			if (unit_displacement > 0 && unit_displacement <= 1)
			{
				addEdge((it_1->front().vertexName_i), (it->front().vertexName_i), unit_displacement);
			}
		}
	}
}


bool myGraph_class::position_occupied(int x, int y, int name)
{
	vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
	if (name != 0) {
		if ((it->front().vertexName_i) != name) {
			for (it = adjacencylist.begin(); it < adjacencylist.end(); it++)
			{

				int pos_y1 = it->front().posy;
				int pos_x1 = it->front().posx;
				if (pos_y1 == y && pos_x1 == x)
				{
					return false;
				}
			}
			return true;
		}
		else if ((it->front().vertexName_i) = name)
		{
			return true;
		}
		else
			cout << "Blah blah blah";
	}
	else
	{
		return true;
	}
}
int myGraph_class::calculate_1(int vertex1, int vertex2)
{

	int counter = 0;
	vector<ADJLIST<str_list_nw>>::iterator it_outer = adjacencylist.begin();
	for (it_outer = adjacencylist.begin(); it_outer < adjacencylist.end(); it_outer++)
		if ((it_outer->front().vertexName_i) == vertex1)
		{
			cout << "The starting vertex entered was" << vertex1 << endl;
			cout << "The ending vertex entered was" << vertex2 << endl;
			ADJLIST<str_list_nw>::iterator i = it_outer->begin();
			i++;
			for (i; i != it_outer->end(); i++)
			{
				counter++;
				if ((i->vertexName_i) == vertex2)
				{
					return counter;
				}

			}
			cout << endl << "The specified vertex is disconnected" << endl;
		}
}
void myGraph_class::BFS(int node)
{
	bool* visited = new bool[adjacencylist.size()];
	for (int i = 0; i < adjacencylist.size(); i++)
	{
		visited[i] = false;
	}
	queue<int> q;
	visited[node] = true;
	q.push(node);
	while (!q.empty())
	{

		cout << q.front() << "  ";

		vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
		for (it; it != adjacencylist.end(); it++)
			//for(each unvisited vertix u adjacent to node )
		{
			ADJLIST<str_list_nw>::iterator itlist = it->begin();
			for (itlist; itlist != it->end(); itlist++)
			{
				str_list_nw objst = *itlist;
				//mark u as visited
				if (!visited[objst.vertexName_i])
				{
					visited[objst.vertexName_i] = true;
					q.push(objst.vertexName_i);
				}

			}

		}
		q.pop();
	}

}
void myGraph_class::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and 
	// print it 
	visited[v] = true;
	cout << v << " ";

	vector<ADJLIST<str_list_nw>>::iterator it = adjacencylist.begin();
	for (it; it != adjacencylist.end(); it++)

	{
		ADJLIST<str_list_nw>::iterator i = it->begin();
		for (i; i != it->end(); i++)
		{
			str_list_nw objst = *i;
			if (!visited[objst.vertexName_i])
			{
				DFSUtil(objst.vertexName_i, visited);
			}
		}
	}
}
void myGraph_class::DFS(int node)
{
	bool* visited = new bool[adjacencylist.size()];
	for (int i = 0; i < adjacencylist.size(); i++)
	{
		visited[i] = false;
	}

	// Call the recursive helper function 
	// to print DFS traversal 
	DFSUtil(node, visited);

}

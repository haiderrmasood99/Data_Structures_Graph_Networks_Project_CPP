#pragma once
#include<string>
#include<vector>
#include<list>
#include <stack>
#include<queue>
using namespace std;
struct str_list_nw {
	string vertexName;
	int vertexName_i;
	float Weight;
	int posx;
	int posy;

};
template<class T>
class ADJLIST :public list<T> {

public:
	int numLinks;

	ADJLIST();
	void incNum();
	void decNum();
	int size();
};
class myGraph_class {
	vector<ADJLIST<str_list_nw>> adjacencylist;
	bool isVertex(int);
	bool isVertex(string);
	bool isEdge(string, string);
	bool isEdge(int, int);
public:
	myGraph_class();
	myGraph_class(int a, int b);
	void addVertex(int a);
	void addVertex(string a);
	void addVertex(int, int);
	void addEdge(string, string, float);
	void addEdge(int, int, float);
	void showData();
	void showDatas();
	bool isEmpty();
	void deleteVertex(string);
	void deleteEdge(string, string);
	int  getNumVertices();
	int  getNumLinks();
	int randomx(int a);
	int randomy(int a);
	void networkmaker();
	bool position_occupied(int a, int b, int name);
	int calculate_1(int vertex1, int vertex2);
	void DFS(int vertex);
	void BFS(int node);
	void DFSUtil(int node, bool visited[]);

};
class wireless :public myGraph_class
{
	myGraph_class n_graph;
public:
	wireless();
	wireless(int area, int num_of_nodes);
	void shortest_path();


};

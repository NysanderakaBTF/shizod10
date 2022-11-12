#pragma once
#include <list>
#include <vector>
using namespace std;
class graph
{
	vector<vector< pair<int, int> > > nodelist;
	list<int> findpath(int end, int start, vector<int>& we);
public:
	graph(int size);
	void add_edge(int a, int b, int w);
	void set_size(int s);
	void get_gamilton_path(list<int> pa, int cur, int dest);
	list<int> dijkstra(int a, int b);
	void construct();
	void print();

};

#include "graph.h"
#include <thread>
#include <mutex>
#include <algorithm>
#include <iostream>

graph::graph(int size=0)
{
	nodelist.resize(size);
	for (int i = 0; i < size; i++)
		nodelist[i].resize(0);
}

void graph::add_edge(int a, int b, int w)
{
	nodelist[a].push_back(make_pair(b, w));
}

void graph::set_size(int s)
{
	nodelist.resize(s);
}
mutex mx;

void graph::get_gamilton_path(list<int> pa, int cur, int dest)
{
	pa.push_back(cur);
	for(size_t i=0;i<nodelist[cur].size();i++)
	{
		if(cur == dest && pa.size()==nodelist.size()+1){
			for_each(pa.begin(), pa.end(), [](int a) {cout << " " << a+1; });
			cout << endl;
			return;
		}
		if(find((++pa.begin()), pa.end(), nodelist[cur][i].first) == pa.end())
		{
			get_gamilton_path(pa, nodelist[cur][i].first, dest);
		}
	}
}

list<int> graph::dijkstra(int a, int b)
{
	vector<int> dist(nodelist.size());
	vector<bool> visited(nodelist.size());

	fill(dist.begin(), dist.end(), INT_FAST32_MAX);
	fill(visited.begin(), visited.end(), false);
	dist[a] = 0;

	for (int i = 0; i < nodelist.size(); ++i)
	{
		int minv = INT_MAX;
		int mini = 0;
		for (int n = 0; n < nodelist.size(); ++n)
		{
			if (!visited[n] && dist[n] < minv) { minv = dist[n]; mini = n; }
		}
		visited[mini] = true;
		for (auto j: nodelist[mini])
		{
			if (!visited[j.first] && dist[mini] + j.second< dist[j.first])
			{
				dist[j.first] = dist[mini] + j.second;
			}
				
		}
	}
	list<int> pp = findpath(b, a, dist);
	pp.push_front(dist[b]);
	return pp;
}


void graph::construct()
{
	cout << "Enter num of tops" << endl;
	int n; cin >> n;
	this->nodelist.resize(n);
	cout << "Enter sourse destination and weight; To end: -1" << endl;
	for (;;)
	{
		int a, b, c;
		cin >> a;
		if (a != -1)
		{
			cin >> b >> c;
			this->add_edge(a-1, b-1, c);
		}
		else return;
	}

}

void graph::print()
{
	cout << "Vertex\tNeightbors(weight)"<<endl;
	for (int i = 0; i < nodelist.size(); ++i)
	{
		cout << i+1 << '\t';
		for_each(nodelist[i].begin(), nodelist[i].end(), [](const pair<int, int> & q){
				cout << q.first+1 << "(" << q.second << ")" << " ";
		});
		cout << endl;
	}
}

list<int> graph::findpath(int end, int start, vector<int> &we)
{
	list<int> path;
	path.push_back(end + 1);
	int weight = we[end];
	while (end!=start)
	{
		for (auto value : nodelist[end])
		{
			int temp = weight - value.second;
			if(temp == we[value.first])
			{
				weight = temp;
				end = value.first;
				path.push_back(value.first+1);
			}
		}
	}
	ranges::reverse(path.begin(), path.end());
	return path;
}

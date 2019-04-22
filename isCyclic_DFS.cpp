#include <iostream>
#include <list>
#include <stack>

using namespace std;
class Graph
{
	int V;
	bool ans;
	list<int> *adj;
	void DFSUtil(int v, bool visited[]);

public:
	Graph(int V);
	void addEdge(int v, int w);
	void DFS(int v);
	void isCyclic(int ans);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	ans = false;
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::isCyclic(int ans)
{
	if(ans == true)
		cout<<"Cyclic!\n";
	else
		cout<<"Non Cyclic!\n";
}

void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	stack<int> Stack;

	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
	}

	DFSUtil(v, visited);

	isCyclic(ans);
}

void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	list<int>::iterator i;

	for (i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if(visited[*i] == true)
		{
			ans = true;
			break;
		}
		else 
		{
			DFSUtil(*i, visited);
		}
	}
}

int main(void)
{
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.DFS(0);
	return 0;
}
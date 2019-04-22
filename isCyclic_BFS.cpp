#include <iostream>
#include <list>
#include <queue>

using namespace std;
class Graph
{
	int V;
	bool ans;
	list<int> *adj;

public:
	Graph(int V);
	void addEdge(int v, int w);
	void BFS(int v);
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

void Graph::BFS(int v)
{
	bool *visited = new bool[V];
	list<int> q;

	list<int>::iterator i;

	for (int j = 0; j < V; j++)
	{
		visited[j] = false;
	}

	visited[v] = true;
	q.push_back(v);

	while(q.empty() == false)
	{
		int src = q.front();
		q.pop_front();

		for( i = adj[src].begin(); i != adj[src].end(); i++)
		{
			if(visited[*i] == false)
			{
				visited[*i] = true;
				q.push_back(*i);
			}
			else
			{
				ans = true;
				break;
			}
		}
	}
	isCyclic(ans);
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

	g.BFS(0);
	return 0;
}
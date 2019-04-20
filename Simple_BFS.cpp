#include <iostream>
#include <queue>
using namespace std;

int adj[9][9]={{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                 {4, 0, 0, 0, 0, 0, 0, 11, 0}, 
                 {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                 {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                 {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                 {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                 {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                 {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                 {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                }; 
bool visited[9];

void Bad_BFS(int v)
{
	queue<int> q;
	for (int i = 0; i < 9; i++)
	{
		visited[i]=false;
	}

	for(int i = 0; i < 9 ; i++)
	{
		if(visited[i] == false)
		{
			q.push(i);

			while(q.empty() == false)
			{
				int src = q.front();
				cout<<src<<" ";
				q.pop();

				if(visited[src] == false)
				{
					visited[src] = true;

					for(int j = 0; j < 9 ; j++)
					{
						if(adj[src][j] > 0 && visited[j]==false)
						{
							q.push(j);
						}
					}
				}
			}
		}
	}
}
void Better_BFS(int v)
{
	queue<int> q;

	for (int i = 0; i < 9; i++)
	{
		visited[i]=false;
	}
	for (int i = 0; i < 9; i++)
	{
		if(visited[i]==false)
		{
			visited[i]=true;
			q.push(i);

			while(!q.empty())
			{
				int src = q.front();
				q.pop();
				cout<<src<<" ";

				for(int j = 0; j < 9; j++)
				{
					if(adj[src][j] > 0 && visited[j]==false)
					{
						visited[j] = true;
						q.push(j);
					}
				}
			}
		}

	}
}
int main()
{
	Bad_BFS(0);
	cout<<"\n";
	Better_BFS(0);
	return 0;
}
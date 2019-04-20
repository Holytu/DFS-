#include <iostream>
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

void DFS(int v)
{
	visited[v]=true;
	cout<<v<<" ";
	for (int j = 0; j < 9 ; j++)
	{
		if( visited[j] == false && adj[v][j] > 0 )
		{
			//cout<<"\n";
			//cout<<" j = "<<j<<endl;
			DFS(j);
		}
	}
}
void Traversal()
{
	for (int i = 0; i < 9; i++)
	{
		visited[i] = false;
	}
	for (int i = 0; i < 9; i++)
	{
		if(visited[i]==false)
		{
			DFS(i);
		}
	}
}
int main()
{
	
	Traversal();


}
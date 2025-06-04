#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int adj[MAX][MAX];
int visited[MAX];
int n;
void DFS(int start)
{
  visited[start] = 1;
  printf("%d ", v);
  for (int i = 0; i < n; i++)
  {
    if (adj[start][i] == 1 && !visited[i])
    {
      DFS(i);
    }
  }
}
int main()
{
  int edges, v1, v2;
  printf("Enter number of vertices: ");
  scanf("%d", &n);
  printf("Enter number of edges: ");
  scanf("%d", &edges);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      adj[i][j] = 0;
    }
    visited[i] = 0;
  }
  printf("Enter the edges (v1 v2):\n");
  for (int i = 0; i < edges; i++)
  {
    scanf("%d %d", &v1, &v2);
    adj[v1][v2] = 1;
    adj[v2][v1] = 1;
  }
  int start;
  printf("Enter starting vertex for DFS: ");
  scanf("%d", &start);
  printf("DFS traversal starting from vertex %d: ", start);
  DFS(start);
  return 0;
}

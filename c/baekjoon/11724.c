#include <stdio.h>

#define MAX 1001

int n, m;
int u, v;
int map[MAX][MAX];
int visited[MAX];

void dfs(int v)
{
	visited[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (map[v][i] == 1 && visited[i] == 0) // map[v][i] == 1 간선이 있다는 의미, visited[i] == 0 아직 방문되지 않았다는 뜻
			dfs(i);
	}
}

int main(void)
{
	int result = 0;

	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &u, &v);
		map[u][v] = 1;
		map[v][u] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0)
		{
			dfs(i);
			result++;
		}
	}
	printf("%d\n", result);
	return (0);
}
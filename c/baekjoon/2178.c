#include <stdio.h>

#define MAX 100

typedef struct s_point
{
	int x;
	int y;
} t_point;

t_point queue[MAX * MAX];
int front = 0, rear = 0;

int n, m;
int map[MAX][MAX];
int visit[MAX][MAX];

void enqueue(int x, int y)
{
	queue[rear].x = x;
	queue[rear].y = y;
	rear++;
}

t_point dequeue()
{
	return (queue[front++]);
}

int bfs(int start_x, int start_y, int dest_x, int dest_y)
{
	int move_x[4] = { 0, 0, 1, -1 }; // 상하좌우
	int move_y[4] = { 1, -1, 0, 0 };
	enqueue(start_x, start_y);
	visit[start_x][start_y] = 1;

	while (front < rear)
	{
		t_point current = dequeue();
		int x = current.x;
		int y = current.y;

		if (x == dest_x && y == dest_y)
			return (visit[x][y]);
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + move_x[i];
			int next_y = y + move_y[i];

			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && map[next_x][next_y] == 1 && visit[next_x][next_y] == 0)
			{
				enqueue(next_x, next_y);
				visit[next_x][next_y] = visit[x][y] + 1;
			}
		}
	}
	return (-1);
}

int main()
{

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			scanf("%1d", &map[i][j]);
	}
	int result = bfs(0, 0, n - 1, m - 1);
	printf("%d\n", result);
	return (0);
}
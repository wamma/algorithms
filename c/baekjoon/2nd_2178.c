#include <stdio.h>

#define MAX 101

typedef struct s_point
{
	int x;
	int y;
}	t_point;

t_point queue[MAX * MAX];
int front = 0; rear = 0;

void enqueue(int x, int y)
{
	queue[rear].x = x;
	queue[rear].y = y;
	rear++;
}

t_point dequeue(void)
{
	return (queue[front++]);
}

int N, M;
int map[MAX][MAX];
int visited[MAX][MAX];

int bfs(int start_x, int start_y, int dest_x, int dest_y)
{
	int move_x[4] = {0, 0, -1, 1};
	int move_y[4] = {1, -1, 0, 0};
	enqueue(start_x, start_y);
	visited[start_x][start_y] = 1;

	while (front < rear)
	{
		
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	}
	int result = bfs(0, 0, N - 1, M - 1);
	if (result == -1)
		printf("Wrong Map\n");
	printf("%d\n", result);
}

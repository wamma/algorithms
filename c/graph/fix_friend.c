#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20

typedef struct Node {
	char name[MAX_NAME_LEN];
	struct Node *next;
} Node;

typedef struct Graph {
	int num_vertex;
	Node **list;
} Graph;

Graph *create_graph(int num_vertex) {
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	graph->num_vertex = num_vertex;
	graph->list = (Node **)malloc(num_vertex * sizeof(Node *));

	for (int i = 0; i < num_vertex; i++) {
		graph->list[i] = NULL;
	}

	return graph;
}

// src와 dest 사이에 간선 추가 (무방향 그래프)
void add_edge(Graph *graph, char *src, char *dest)
{
	int src_index = -1;
	int dest_index = -1;

	for (int i = 0; i < graph->num_vertex; i++) {
		if (strcmp(graph->list[i]->name, src) == 0) {
			src_index = i;
		}
		if (strcmp(graph->list[i]->name, dest) == 0) {
			dest_index = i;
		}
	}
	
	if (src_index == -1 || dest_index == -1) {
		printf("해당 이름의 노드가 없습니다.\n");
		return ;
	}

	Node *new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		return ;
	strncpy(new_node->name, dest, MAX_NAME_LEN);
	new_node->next = NULL;

	// src에서 dest로 가는 간선 추가
	if (graph->list[src_index]->next == NULL)
		graph->list[src_index]->next = new_node;
	else
	{
		Node *temp = graph->list[src_index]->next;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}

	// dest에서 src로 가는 간선 추가
	new_node = malloc(sizeof(Node));
	if (new_node == NULL)
		return ;
	strncpy(new_node->name, src, MAX_NAME_LEN);
	new_node->next = NULL;

	if (graph->list[dest_index]->next == NULL)
		graph->list[dest_index]->next = new_node;
	else
	{
		Node *temp = graph->list[dest_index]->next;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

// 친구 추천 함수
void	friend_recommend(Graph *graph, char *name)
{
	int index = -1;

	// 인자에 해당하는 이름의 노드가 몇번째 노드인지 찾습니다.
	for (int i = 0; i < graph->num_vertex; i++)
	{
		if (strcmp(graph->list[i]->name, name) == 0)
		{
			index = i;
			break ;
		}
	}

	if (index == -1)
	{
		printf("해당 이름의 노드가 없습니다.\n");
		return ;
	}

	Node *current = graph->list[index]->next; // 사용자의 인접한 목록 가져오기

	// 각 사용자의 공통 친구 수를 저장할 배열을 만듭니다.
	int *common_count = (int *)malloc(graph->num_vertex * sizeof(int));
	if (common_count == NULL)
		return ;
	for (int i = 0; i < graph->num_vertex; i++)
		common_count[i] = 0;

	// 사용자의 인접 리스트 순회
	while (current != NULL)
	{
		int near_index = -1;
		for (int i = 0; i < graph->num_vertex; i++)
		{
			if (strcmp(graph->list[i]->name, current->name) == 0)
			{
				near_index = i;
				break ;
			}
		}
		if (near_index != -1)
		{
			Node *new_current = graph->list[near_index]->next; // 사용자의 인접한 목록 가져오기
			while (new_current != NULL) // 인접한 각 노드에 공통 친구 수를 늘립니다.
			{
				if (strcmp(new_current->name, name) != 0)
					common_count[near_index]++;
				new_current = new_current->next;
			}
		}
		current = current->next;
	}

	// 공통 친구 수가 가장 많은 사용자를 찾습니다.
	int max = -1;
	int recommend_index = -1;
	for (int i = 0; i < graph->num_vertex; i++)
	{
		if (i != index && common_count[i] > max) // 자기 자신은 제외합니다.
		{
			max = common_count[i]; // 공통 친구 수가 더 많은 사용자를 찾습니다.
			recommend_index = i;
		}
	}
	if (recommend_index != -1)
		printf("%s의 추천 친구는 %s입니다.\n", name, graph->list[recommend_index]->name);
	else
		printf("추천 친구가 없습니다.\n");
	free(common_count);
}

int main()
{
	char *names[] = {"hyungjup", "shikim", "jaehejun", "eoh", "jungjkim"};
	int num_vertex = 5;
	Graph *graph = create_graph(num_vertex);

	for (int i = 0; i < num_vertex; i++)
	{
		Node *new_node = (Node *)malloc(sizeof(Node));
		strncpy(new_node->name, names[i], MAX_NAME_LEN); // 이름 복사
		new_node->next = NULL;
		graph->list[i] = new_node;
	}

	add_edge(graph, "hyungjup", "jaehejun");
	add_edge(graph, "shikim", "eoh");
	add_edge(graph, "shikim", "jungjkim");
	add_edge(graph, "eoh", "hyungjup");

	for (int i = 0; i < num_vertex; i++)
	{
		printf("%s와 인접한 노드: ", graph->list[i]->name);
		Node *temp = graph->list[i]->next;
		while (temp)
		{
			printf("%s ", temp->name);
			temp = temp->next;
		}
		printf("\n");
	}

	friend_recommend(graph, "jaehejun");

	return 0;
}

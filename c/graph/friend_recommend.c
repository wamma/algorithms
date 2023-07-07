#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char *name;
	struct Node *next;
} Node;

typedef struct Graph
{
	int num_vertex;
	Node **list;
} Graph;

Graph *create_graph(int num_vertex)
{
	Graph *graph = (Graph *)malloc(sizeof(Graph));
	if (!graph)
		return (NULL);
	graph->num_vertex = num_vertex;
	graph->list = (Node **)malloc(sizeof(Node *) * num_vertex);
	if (!graph->list)
		return (NULL);
	for (int i = 0; i < num_vertex; i++)
		graph->list[i] = NULL;
	return (graph);
}

Node *create_new_node(char *name)
{
	Node *new_node = malloc(sizeof(Node));
	if (!new_node)
		return (NULL);
	new_node->name = name;
	new_node->next = NULL;

	return (new_node);
}

int find_vertex_index(Graph *graph, char *name)
{
	for (int i = 0; i < graph->num_vertex; i++)
	{
		if (strcmp(graph->list[i]->name, name) == 0)
			return i;
	}
	return (-1);
}

void	add_node_to_list(Node **list, char *name)
{
	Node *new_node = create_new_node(name);
	if (!new_node)
		return ;
	new_node->next = *list;
	*list = new_node;
}

void addEdge(Graph *graph, char *src, char *dest)
{
	int src_index;
	int dest_index;

	src_index = find_vertex_index(graph, src);
	dest_index = find_vertex_index(graph, dest);
	if (src_index == -1 || dest_index == -1)
	{
		printf("정점을 찾을 수 없습니다.\n");
		return ;
	}
	add_node_to_list(&(graph->list[src_index]), dest);
	add_node_to_list(&(graph->list[dest_index]), src);
}

// int find_common_friends_count(Graph* graph, char* person, char* friend_candidate) {
// 	int commonCount = 0;

// 	Node* personNode = graph->list[find_vertex_index(graph, person)]->next;
// 	Node* friendNode = graph->list[find_vertex_index(graph, friend_candidate)]->next;

// 	while (personNode) {
// 		Node* tempFriend = friendNode;
// 		while (tempFriend) {
// 			if (strcmp(personNode->name, tempFriend->name) == 0) {
// 				commonCount++;
// 				break;
// 			}
// 			tempFriend = tempFriend->next;
// 		}
// 		personNode = personNode->next;
// 	}

// 	return commonCount;
// }

// void recommendFriends(Graph* graph, char* person) {
// 	int personIndex = find_vertex_index(graph, person);
// 	if (personIndex == -1) {
// 		printf("해당 이름을 가진 노드가 없습니다.\n");
// 		return;
// 	}

// 	int maxCommonCount = 0;
// 	int maxCommonIndex = -1;
// 	Node* friendList = graph->list[personIndex];

// 	Node* temp = friendList->next;
// 	while (temp) {
// 		int commonCount = find_common_friends_count(graph, person, temp->name);
// 		if (commonCount > maxCommonCount) {
// 			maxCommonCount = commonCount;
// 			maxCommonIndex = find_vertex_index(graph, temp->name);
// 		}
// 		temp = temp->next;
// 	}

// 	if (maxCommonIndex != -1) {
// 		printf("%s에게 추천하는 친구: %s\n", person, graph->list[maxCommonIndex]->name);
// 	} else {
// 		printf("%s에게 추천할 수 있는 친구가 없습니다.\n", person);
// 	}
// }


int main() {
	char *names[] = {"hyungjup", "shikim", "jaehejun", "eoh", "jungjkim"};
	int num_vertex = 5;
	Graph *graph = create_graph(num_vertex);

	// 그래프 정점들에 이름 할당
	for (int i = 0; i < num_vertex; i++) {
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->name = names[i];
		newNode->next = NULL;
		graph->list[i] = newNode;
	}

	addEdge(graph, "hyungjup", "jaehejun");
	addEdge(graph, "shikim", "eoh");
	addEdge(graph, "shikim", "jungjkim");
	addEdge(graph, "eoh", "hyungjup");

	for (int i = 0; i < num_vertex; i++) {
		printf("%s와 인접한 노드: ", graph->list[i]->name);
		Node *temp = graph->list[i]->next;
		while (temp) {
			printf("%s ", temp->name);
			temp = temp->next;
		}
		printf("\n");
	}

	return 0;
}
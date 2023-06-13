#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}	node;

node	*head = NULL;
node	*tail = NULL;

void	insert_data(int data)
{
	node	*new_node = malloc(sizeof(node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}
}

void	swap_nodes(node *node1, node *node2)
{
	node	*temp_next;
	node	*temp_prev;

	if (node1 == NULL || node2 == NULL || node1 == node2)
		return ;
	// node1의 이전 노드와 연결
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		head = node2;
	
	// node2의 이전 노드와 연결
	if (node2->prev != NULL)
		node2->prev->next = node1;
	else
		head = node1;
	
	// node1의 다음 노드와 연결
	if (node1->next != NULL)
		node1->next->prev = node2;
	else
		tail = node2;
	
	// node2의 다음 노드와 연결
	if (node2->next != NULL)
		node2->next->prev = node1;
	else
		tail = node1;
	
	// 두 노드의 이전 노드와 다음 노드 교환
	temp_next = node1->next;
	temp_prev = node1->prev;
	node1->next = node2->next;
	node1->prev = node2->prev;
	node2->next = temp_next;
	node2->prev = temp_prev;
}

void	display_list(void)
{
	node	*current = head;

	if (head == NULL)
	{
		printf("리스트가 비어 있습니다\n");
		return ;
	}
	printf("리스트 : ");
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main(void)
{
	insert_data(5);
	insert_data(10);
	insert_data(15);
	display_list();

	node *node1 = tail;
	node *node2 = tail->prev;
	swap_nodes(node1, node2);
	display_list();

	return 0;
}

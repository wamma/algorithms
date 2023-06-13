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
	return 0;
}

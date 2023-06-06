#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}	node;

node	*head = NULL;

void	insert_node(int data)
{
	node	*new_node;
	node	*temp;

	new_node = malloc(sizeof(node));
	if (!new_node)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	if (head == NULL)
		head = new_node;
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}

	printf("\"%d\" inserted\n", data);
}

void	delete_node(int data)
{
	node	*temp = head;
	node	*prev = NULL;

	while (temp != NULL && temp->data != data)
	{
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("%d data not found\n", data);
		return ;
	}
	if (prev == NULL)
		head = temp->next;
	else
		prev->next = temp->next;
	free(temp);
	printf("%d deleted\n", data);
}

void	display_node(void)
{
	node	*temp;
	if (head == NULL)
		printf("List is empty\n");
	else
	{
		temp = head;
		printf("List elements: ");
		while (temp != NULL)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(void)
{
	insert_node(5);
	insert_node(10);
	insert_node(15);

	display_node();

	delete_node(10);

	display_node();

	return 0;
}

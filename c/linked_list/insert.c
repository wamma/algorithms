#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}	node;

node	*head = NULL;

void	insert_node(int argc, char **argv)
{
	node	*new_node;
	node	*temp;
	int		data;

	for (int i = 1; i < argc; i++)
	{
		data = atoi(argv[i]);
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
		printf("New node with data \"%d\" inserted\n", data);
	}
}

void	delete_node(int argc, char **argv)
{
	node	*temp;
	node	*prev;
	int		data;

	temp = head;
	prev = NULL;
	for (int i = 1; i < argc; i++)
	{
		data = atoi(argv[i]);
		while (temp != NULL && temp->data != data)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
		{
			printf("%d Node with data not found\n", data);
			return ;
		}
		else if (prev == NULL)
		{
			prev->next = temp->next;
			free(temp);
			printf("%d node with data deleted\n", data);
		}
	}
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

int main(int argc, char **argv)
{
	insert_node(argc, argv);
	display_node();
	return 0;
}

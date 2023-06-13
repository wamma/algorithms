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

void	delete_node(int data)
{
	node *current = head;

	while (current != NULL)
	{
		if (current->data == data)
		{
			if (current == head)
			{
				head = current->next;
				if (head != NULL)
					head->prev = NULL;
				else
					tail = NULL;
			}
			else if (current == tail)
			{
				tail = current->prev;
				if (tail != NULL)
					tail->next = NULL;
				else
					head = NULL;
			}
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}

			free(current);
			return ;
		}

		current = current->next;
	}

	printf("해당 데이터를 가진 노드를 찾을 수 없습니다.\n");
}


void	display_list(void)
{
	node	*current = head;

	if (head == NULL)
	{
		printf("리스트가 비어 있습니다\n");
		return ;
	}
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

	printf("삽입 후의 리스트 : ");
	display_list();

	delete_node(10);
	printf("삭제 후의 리스트 : ");
	display_list();
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
} node;

node *head = NULL;

void insert_node(int data)
{
	node *new_node = malloc(sizeof(node));
	if (!new_node)
		return;

	new_node->data = data;
	new_node->next = NULL;

	if (head == NULL)
		head = new_node;
	else
	{
		node *temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}

	printf("\"%d\" inserted\n", data);
}

void delete_duplicates(void)
{
	if (head == NULL)
		return;

	int has_duplicates = 0; // 중복 여부를 확인하는 변수

	node *current = head;
	while (current != NULL)
	{
		node *temp = current;
		while (temp->next != NULL)
		{
			if (temp->next->data == current->data)
			{
				has_duplicates = 1; // 중복이 발견되면 변수 값을 1로 설정
				node *duplicate = temp->next;
				temp->next = temp->next->next;
				free(duplicate);
			}
			else
			{
				temp = temp->next;
			}
		}
		current = current->next;
	}

	if (has_duplicates)
		printf("Duplicates deleted\n");
	else
		printf("No duplicates found\n");
}

void display_node(void)
{
	node *temp;
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
	for (int i = 1; i < argc; i++)
	{
		int data = atoi(argv[i]);
		insert_node(data);
	}
	display_node();
	delete_duplicates();
	display_node();
	return 0;
}

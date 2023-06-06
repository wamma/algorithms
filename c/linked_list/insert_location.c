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

	printf("New node with data \"%d\" inserted\n", data);
}

void insert_node_at(int data, int position)
{
	node *new_node = malloc(sizeof(node));
	if (!new_node)
		return;

	new_node->data = data;

	if (position <= 0)
	{
		// 리스트의 첫 번째에 삽입
		new_node->next = head;
		head = new_node;
	}
	else
	{
		node *temp = head;
		int count = 0;

		// 삽입 위치의 이전 노드를 찾음
		while (temp != NULL && count < position - 1)
		{
			temp = temp->next;
			count++;
		}

		if (temp == NULL)
		{
			// 삽입 위치가 리스트의 길이보다 큰 경우, 리스트의 끝에 삽입
			new_node->next = NULL;
			temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new_node;
		}
		else
		{
			// 삽입 위치에 노드를 삽입
			new_node->next = temp->next;
			temp->next = new_node;
		}
	}

	printf("New node with data \"%d\" inserted at position %d\n", data, position);
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

int main(void)
{
	insert_node(5);
	insert_node(10);
	insert_node(15);

	display_node();
	insert_node_at(100, 3);
	insert_node_at(0, 1);

	display_node();

	return 0;
}

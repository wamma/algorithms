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
		{
			printf("Failed memory allocated for new node\n");
			return ;
		}
		new_node->data = data;
		new_node->next = NULL;
		if (head == NULL)
		{
			head = new_node;
			head->next = head; // 첫 번째 노드의 다음 노드를 자기 자신으로 설정하여 원형 형태로 만듬
		}
		else
		{
			temp = head;
			while (temp->next != head) // 원형 연결 리스트는 NULL이 아니고 head일때 까지로 조건문을 해야한다.
				temp = temp->next;
			temp->next = new_node;
			new_node->next = head; // 마지막 노드의 다음 노드를 첫 번째 노드로 설정 
		}
		printf("New node with data \"%d\" inserted\n", data);
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
		while (1)
		{
			printf("%d ", temp->data);
			temp = temp->next;
			if (temp == head)
				break ;
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
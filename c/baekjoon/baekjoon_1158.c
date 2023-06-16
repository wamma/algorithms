#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} Node;

typedef struct _list
{
	Node *head;
	Node *tail;
	Node *cur;
} List;

void ListInit(List *plist)
{
	plist->head = NULL;
	plist->tail = NULL;
}

int main(void)
{
	int n, k;
	List *list;

	scanf("%d %d", &n, &k);
	list = (List *)malloc(sizeof(List) * n);
	ListInit(list);

	for (int i = 1; i <= n; i++)
	{
		Node *newnode = (Node *)malloc(sizeof(Node));
		if (!newnode)
			return (-1);
		newnode->data = i;
		newnode->next = NULL;
		if (list->tail == NULL)
		{
			list->head = newnode;
			list->tail = newnode; 
		}
		else
		{
			list->tail->next = newnode;
			list->tail = newnode;
		}
	}
	list->tail->next = list->head; // 원형 연결 리스트로 만들기
	list->cur = list->head;

	printf("<");
	while (list->head != NULL)
	{
		for (int i = 0; i < k; i++)
			list->cur = list->cur->next;
		Node *newnode = list->cur;
		list->cur = list->cur->next;

		if (newnode == list->head) // 리스트의 마지막 노드인 경우
			list->head = list->head->next;
		printf("%d", newnode->data);
		free(newnode);

		if (list->head != NULL)
			printf(", ");
	}
	printf("%d>", list->cur->data);
	return (0);
}
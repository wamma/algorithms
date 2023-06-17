#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

typedef struct
{
	Node* tail;
} CircularLinkedList;

void push_back(CircularLinkedList* cll, int k)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->value = k;
	new_node->next = NULL;

	if (cll->tail == NULL) // 비어 있는경우
	{
		cll->tail = new_node;
		new_node->next = new_node;
	} else 
	{
		new_node->next = cll->tail->next;
		cll->tail->next = new_node;
		cll->tail = new_node;
	}
}

void erase(CircularLinkedList* cll, int k, int z)
{
	Node* dest = cll->tail;
	for (int i = 0; i < k; i++)
	{
		if (i == k - 1)
			cll->tail = dest;
		dest = dest->next;
	}

	if (z == 0)
		printf("%d", dest->value);
	else
		printf(", %d", dest->value);

	cll->tail->next = dest->next;
	free(dest);
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	CircularLinkedList cll;
	cll.tail = NULL;

	for (int i = 0; i < n; i++)
		push_back(&cll, i + 1);

	printf("<");
	for (int i = 0; i < n; i++)
		erase(&cll, k, i);
	printf(">\n");

	return 0;
}

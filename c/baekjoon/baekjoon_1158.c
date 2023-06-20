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

void push_back(CircularLinkedList* cll, int i)
{
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->value = i;
	new_node->next = NULL;

	if (cll->tail == NULL) // 비어 있는경우
	{
		cll->tail = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->next = cll->tail->next; // new_node->next를 cll->tail->next로 설정함으로써 새로운 노드의 next 포인터를 첫 번째 노드를 가리키도록 합니다.
		cll->tail->next = new_node; // tail의 next가 새로운 노드를 가리키게 한다.
		cll->tail = new_node;
	}
}

void erase(CircularLinkedList* cll, int k, int first) // first는 출력을 위한 변수
{
	Node* dest = cll->tail;
	for (int i = 0; i < k; i++)
	{
		if (i == k - 1) // k번째 노드를 찾은 경우
			cll->tail = dest;
		dest = dest->next;
	}

	if (first == 0)
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

	for (int i = 1; i <= n; i++)
		push_back(&cll, i);

	printf("<");
	for (int i = 0; i < n; i++)
		erase(&cll, k, i);
	printf(">\n");

	return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct {
	int data[MAX_SIZE];
	int size;
} priority_queue;

void init(priority_queue *pq) {
	pq->size = 0;
}

bool is_full(priority_queue *pq) {
	return (pq->size == MAX_SIZE);
}

bool is_empty(priority_queue *pq) {
	return (pq->size == 0);
}

void enqueue(priority_queue *pq, int data) {
	if (is_full(pq)) {
		printf("Queue is full!\n");
		return;
	}
	int i = pq->size;
	pq->data[i] = data; // 마지막 노드에 데이터 삽입
	pq->size++;
	while (i > 0 && pq->data[i] < pq->data[(i - 1) / 2]) // pq->data[(i - 1) / 2] = 부모노드
	{
		int temp = pq->data[i];
		pq->data[i] = pq->data[(i - 1) / 2]; // 부모 노드와 교환
		pq->data[(i - 1) / 2] = temp;
		i = (i - 1) / 2;
	}
}

int dequeue(priority_queue *pq) {
	if (is_empty(pq)) {
		printf("Queue is empty!\n");
		return -1;
	}
	int data = pq->data[0];
	pq->data[0] = pq->data[pq->size - 1];
	pq->size--;
	int i = 0;
	while (true) {
		int left = 2 * i + 1; // 왼쪽 자식
		int right = 2 * i + 2; // 오른쪽 자식
		int smallest = i; // 가장 작은 값의 인덱스
		if (left < pq->size && pq->data[left] < pq->data[smallest]) // 왼쪽 자식이 가장 작은 값보다 작으면
			smallest = left;
		if (right < pq->size && pq->data[right] < pq->data[smallest]) // 오른쪽 자식이 가장 작은 값보다 작으면
			smallest = right;
		if (smallest == i)
			break;
		int temp = pq->data[i];
		pq->data[i] = pq->data[smallest];
		pq->data[smallest] = temp;
		i = smallest;
	}

	return data;
}

int front(priority_queue *pq) {
	if (is_empty(pq)) {
		printf("Queue is empty!\n");
		return -1;
	}
	return pq->data[0];
}

void display(priority_queue *pq) {
	if (is_empty(pq)) {
		printf("Queue is empty!\n");
		return;
	}
	for (int i = 0; i < pq->size; i++)
		printf("%d ", pq->data[i]);
	printf("\n");
}

int main(void) {
	priority_queue pq;
	init(&pq);

	enqueue(&pq, 8);
	enqueue(&pq, 5);
	enqueue(&pq, 1);
	enqueue(&pq, 3);
	enqueue(&pq, 7);
	display(&pq);

	dequeue(&pq);
	display(&pq);

	dequeue(&pq);
	display(&pq);
	return 0;
}

#include <stdio.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
	int id;
	int category; // 1: 입출금, 예적금 / 2: 종합상담창구 / 3: VIP 창구
} Customer;

typedef struct {
	Customer data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} Queue;

void initQueue(Queue* queue) {
	queue->front = 0;
	queue->rear = 0;
}

int isEmpty(Queue* queue) {
	return (queue->front == queue->rear);
}

int isFull(Queue* queue) {
	return ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

void enqueue(Queue* queue, Customer customer) {
	if (isFull(queue)) {
		printf("Queue is full. Cannot enqueue.\n");
		return;
	}

	queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
	queue->data[queue->rear] = customer;
}

Customer dequeue(Queue* queue) {
	if (isEmpty(queue)) {
		printf("Queue is empty. Cannot dequeue.\n");
		Customer emptyCustomer;
		emptyCustomer.id = -1;
		return emptyCustomer;
	}

	queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
	return queue->data[queue->front];
}

void serveCustomer(Queue* generalCounter, Queue* vipCounter) {
	if (!isEmpty(vipCounter)) {
		Customer vipCustomer = dequeue(vipCounter);
		printf("VIP Counter is serving Customer %d.\n", vipCustomer.id);
	} else if (!isEmpty(generalCounter)) {
		Customer generalCustomer = dequeue(generalCounter);
		printf("General Counter is serving Customer %d.\n", generalCustomer.id);
	} else {
		printf("No customers in the queue.\n");
	}
}

int main() {
	Queue generalCounterQueue; // 입출금, 예적금, 종합상담창구 대기열
	initQueue(&generalCounterQueue);

	Queue vipCounterQueue; // VIP 창구 대기열
	initQueue(&vipCounterQueue);

	while (1) {
		// 은행 업무를 대기열에 추가 (임의의 예시)
		Customer customer1 = {1, 1}; // 입출금, 예적금 업무
		enqueue(&generalCounterQueue, customer1);

		Customer customer2 = {2, 2}; // 종합상담창구 업무
		enqueue(&generalCounterQueue, customer2);

		Customer customer3 = {3, 3}; // VIP 창구 업무
		enqueue(&vipCounterQueue, customer3);

		// 고객 응대
		serveCustomer(&generalCounterQueue, &vipCounterQueue);
		serveCustomer(&generalCounterQueue, &vipCounterQueue);
		serveCustomer(&generalCounterQueue, &vipCounterQueue);

		// 대기 시간을 주기 위한 잠시의 딜레이
		printf("Waiting for the next round...\n");
		printf("\n");
		sleep(3); // 3초 대기
	}

	return 0;
}

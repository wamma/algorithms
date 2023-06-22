#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define NUM_TELLERS 5
#define WAITING_QUEUE_SIZE 10

typedef struct
{
	int id;
	char task[50];
	int category; // 1: 입출금, 예적금 / 2: 종합상담창구 / 3: VIP
} Customer;

typedef struct
{
	Customer data[MAX_QUEUE_SIZE];
	int front;
	int rear;
} Queue;

typedef struct
{
	Queue queues[NUM_TELLERS];
	Queue vipQueue;
} Bank;

void initQueue(Queue* queue)
{
	queue->front = 0;
	queue->rear = -1;
}

int isFull(Queue* queue)
{
	return queue->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(Queue* queue)
{
	return queue->front > queue->rear;
}

void enqueue(Queue* queue, Customer customer)
{
	if (isFull(queue))
	{
		printf("Queue is full. Cannot enqueue.\n");
		return;
	}

	queue->data[++queue->rear] = customer;
}

Customer dequeue(Queue* queue)
{
	if (isEmpty(queue))
	{
		printf("Queue is empty. Cannot dequeue.\n");
		Customer emptyCustomer;
		emptyCustomer.id = -1;
		return emptyCustomer;
	}
	return queue->data[queue->front++];
}

void displayQueue(Queue* queue)
{
	if (isEmpty(queue))
	{
		printf("Queue is empty.\n");
		return;
	}

	printf("현재 업무 리스트:\n");
	for (int i = queue->front; i <= queue->rear; i++)
	{
		printf("ID: %d, Task: %s, Category: %d\n", queue->data[i].id, queue->data[i].task, queue->data[i].category);
	}
}

void serveCustomer(Queue* queue)
{
	if (isEmpty(queue))
	{
		printf("현재 모든 창구가 비어있습니다.\n");
		return;
	}

	Customer customer = dequeue(queue);
	printf("Serving Customer: ID - %d, Task - %s, Category - %d\n", customer.id, customer.task, customer.category);
}

void initBank(Bank* bank)
{
	for (int i = 0; i < NUM_TELLERS; i++)
	{
		initQueue(&bank->queues[i]);
	}
	initQueue(&bank->vipQueue);
}

int getShortestQueue(Bank* bank, int category)
{
	int shortestQueue = 0;
	int shortestQueueLength = MAX_QUEUE_SIZE;

	for (int i = 0; i < NUM_TELLERS; i++) {
		if (bank->queues[i].rear - bank->queues[i].front < shortestQueueLength)
		{
			shortestQueue = i;
			shortestQueueLength = bank->queues[i].rear - bank->queues[i].front;
		}
	}
	return shortestQueue;
}

int main()
{
	Bank bank;
	initBank(&bank);

	int customerId = 1;
	int choice;

	while (1)
	{
		printf("\n--- Bank Task Management ---\n");
		printf("1. Enqueue customer (Category 1: 입출금, 예적금)\n");
		printf("2. Enqueue customer (Category 2: 종합상담창구)\n");
		printf("3. Enqueue customer (Category 3: VIP)\n");
		printf("4. Serve customer\n");
		printf("5. Display queues\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1: {
						char task[50];
						printf("고객님 업무 내용: ");
						scanf(" %[^\n]", task);

						Customer customer;
						customer.id = customerId++;
						strcpy(customer.task, task);
						customer.category = 1;

						int shortestQueue = getShortestQueue(&bank, 1);
						enqueue(&bank.queues[shortestQueue], customer);

						printf("고객님이 창구에 들어갔습니다.\n");
						break;
					}
			case 2: {
						char task[50];
						printf("고객님 업무 내용: ");
						scanf(" %[^\n]", task);

						Customer customer;
						customer.id = customerId++;
						strcpy(customer.task, task);
						customer.category = 2;

						int shortestQueue = getShortestQueue(&bank, 2);
						enqueue(&bank.queues[shortestQueue], customer);

						printf("고객님이 창구에 들어갔습니다.\n");
						break;
					}
			case 3: {
						char task[50];
						printf("Enter customer task: ");
						scanf(" %[^\n]", task);

						Customer customer;
						customer.id = customerId++;
						strcpy(customer.task, task);
						customer.category = 3;

						enqueue(&bank.vipQueue, customer);

						printf("고객님이 창구에 들어갔습니다.\n");
						break;
					}
			case 4: {
						printf("고객님 업무 내용: ");

						printf("VIP Teller:\n");
						serveCustomer(&bank.vipQueue);

						for (int i = 0; i < NUM_TELLERS; i++)
						{
							printf("Teller %d:\n", i + 1);
							serveCustomer(&bank.queues[i]);
						}

						break;
					}
			case 5: {
						printf("Bank Queues:\n");

						printf("VIP Queue:\n");
						displayQueue(&bank.vipQueue);

						for (int i = 0; i < NUM_TELLERS; i++) {
						    printf("Teller %d Queue:\n", i + 1);
						    displayQueue(&bank.queues[i]);
						}

						break;
					}
			case 6: {
						printf("Exiting program.\n");
						exit(0);
					}
			default: {
						 printf("Invalid choice. Please try again.\n");
						 break;
					 }
		}
	}
	return 0;
}

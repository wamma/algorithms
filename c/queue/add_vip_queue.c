#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 1
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
    Customer data[MAX_QUEUE_SIZE]; // 한 은행원당 최대 1명의 고객만 응대
    int front;
    int rear;
} Queue;

typedef struct
{
    Queue queues[NUM_TELLERS];
    Queue vipQueue;
    Queue waitingQueue; // 대기열
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

void enqueue(Queue* queue, Customer customer, Bank* bank)
{
    if (isFull(queue))
    {
        if (queue == &bank->vipQueue)
        {
            printf("The VIP queue is full, but the customer is allowed to enter.\n");
        }
        else if (isFull(&bank->waitingQueue))
        {
            printf("The waiting queue is full. The customer cannot be accommodated.\n");
            return;
        }
        enqueue(&bank->waitingQueue, customer, bank); // 대기열로 이동
        printf("The queue is full. The customer has been placed in the waiting queue.\n");
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

    printf("Current task list:\n");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("ID: %d, Task: %s, Category: %d\n", queue->data[i].id, queue->data[i].task, queue->data[i].category);
    }
}

void serveCustomer(Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("All counters are empty.\n");
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
    initQueue(&bank->waitingQueue); // 대기열 초기화
}

int getShortestQueue(Bank* bank, int category)
{
    int shortestQueue = 0;
    int shortestQueueLength = MAX_QUEUE_SIZE;

    for (int i = 0; i < NUM_TELLERS; i++)
    {
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
                printf("Customer task: ");
                scanf(" %[^\n]", task);

                Customer customer;
                customer.id = customerId++;
                strcpy(customer.task, task);
                customer.category = 1;

                int shortestQueue = getShortestQueue(&bank, 1);
                enqueue(&bank.queues[shortestQueue], customer, &bank);

                printf("The customer has entered the counter.\n");
                break;
            }
            case 2: {
                char task[50];
                printf("Customer task: ");
                scanf(" %[^\n]", task);

                Customer customer;
                customer.id = customerId++;
                strcpy(customer.task, task);
                customer.category = 2;

                int shortestQueue = getShortestQueue(&bank, 2);
                enqueue(&bank.queues[shortestQueue], customer, &bank);

                printf("The customer has entered the counter.\n");
                break;
            }
            case 3: {
                char task[50];
                printf("Customer task: ");
                scanf(" %[^\n]", task);

                Customer customer;
                customer.id = customerId++;
                strcpy(customer.task, task);
                customer.category = 3;

                enqueue(&bank.vipQueue, customer, &bank);

                printf("The customer has entered the counter.\n");
                break;
            }
            case 4: {
                printf("Customer task:\n");

                printf("VIP Counter:\n");
                serveCustomer(&bank.vipQueue);

                for (int i = 0; i < NUM_TELLERS; i++)
                {
                    printf("Counter %d:\n", i + 1);
                    serveCustomer(&bank.queues[i]);
                }

                // 대기열에서 처리
                if (!isEmpty(&bank.waitingQueue))
                {
                    printf("Processing customers from the waiting queue:\n");
                    serveCustomer(&bank.waitingQueue);
                }

                break;
            }
            case 5: {
                printf("Bank Queues:\n");

                printf("VIP Queue:\n");
                displayQueue(&bank.vipQueue);

                for (int i = 0; i < NUM_TELLERS; i++)
                {
                    printf("Counter %d Queue:\n", i + 1);
                    displayQueue(&bank.queues[i]);
                }

                printf("Waiting Queue:\n");
                displayQueue(&bank.waitingQueue);

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

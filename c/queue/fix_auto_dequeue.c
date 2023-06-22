#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_QUEUE_SIZE 1
#define NUM_TELLERS 5
#define WAITING_QUEUE_SIZE 10
#define AUTO_DEQUEUE_TIME 5

typedef struct {
    int id;
    char task[50];
    int category; // 1: 입출금, 예적금 / 2: 종합상담창구 / 3: VIP
    time_t enqueueTime;
} Customer;

typedef struct {
    Customer data[MAX_QUEUE_SIZE]; // 한 은행원당 최대 1명의 고객만 응대
    int front;
    int rear;
} Queue;

typedef struct {
    Queue queues[NUM_TELLERS];
    Queue vipQueue;
    Queue waitingQueue; // 대기열
} Bank;

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isFull(Queue* queue) {
    return queue->rear == MAX_QUEUE_SIZE - 1;
}

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

void enqueue(Queue* queue, Customer customer, Bank* bank) {
    if (isFull(queue)) {
        if (queue == &bank->vipQueue) {
            printf("The VIP queue is full, but the customer is allowed to enter.\n");
        } else if (isFull(&bank->waitingQueue)) {
            printf("The waiting queue is full. The customer cannot be accommodated.\n");
            return;
        }
        enqueue(&bank->waitingQueue, customer, bank); // 대기열로 이동
        printf("The queue is full. The customer has been placed in the waiting queue.\n");
        return;
    }

    queue->data[++queue->rear] = customer;
}

Customer dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        Customer emptyCustomer;
        emptyCustomer.id = -1;
        return emptyCustomer;
    }
    return queue->data[queue->front++];
}

void displayQueue(Queue* queue, int counterNumber) {
    printf("Counter %d Queue:\n", counterNumber);

    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Current task list:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("ID: %d, Task: %s, Category: %d\n", queue->data[i].id, queue->data[i].task, queue->data[i].category);
    }
}

void serveCustomerFromQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    int originalFront = queue->front;
    int originalRear = queue->rear;

    while (queue->front <= queue->rear) {
        Customer customer = dequeue(queue);
        printf("Serving Customer: ID - %d, Task - %s, Category - %d\n", customer.id, customer.task, customer.category);
    }

    queue->front = 0;
    queue->rear = -1;
}

void checkAutoDequeue(Bank* bank) {
    time_t currentTime = time(NULL);

    for (int i = 0; i < NUM_TELLERS; i++) {
        Queue* queue = &bank->queues[i];

        if (!isEmpty(queue)) {
            Customer customer = queue->data[queue->front];
            time_t enqueueTime = customer.enqueueTime;
            double timeElapsed = difftime(currentTime, enqueueTime);

            if (timeElapsed >= AUTO_DEQUEUE_TIME) {
                printf("Auto dequeue from Counter %d:\n", i + 1);
                serveCustomerFromQueue(queue);
            }
        }
    }
}

void initBank(Bank* bank) {
    for (int i = 0; i < NUM_TELLERS; i++) {
        initQueue(&bank->queues[i]);
    }
    initQueue(&bank->vipQueue);
    initQueue(&bank->waitingQueue); // 대기열 초기화
}

int getShortestQueue(Bank* bank, int category) {
    int shortestQueue = 0;
    int shortestQueueLength = MAX_QUEUE_SIZE;

    for (int i = 0; i < NUM_TELLERS; i++) {
        if (bank->queues[i].rear - bank->queues[i].front < shortestQueueLength) {
            shortestQueue = i;
            shortestQueueLength = bank->queues[i].rear - bank->queues[i].front;
        }
    }
    return shortestQueue;
}

int main() {
    Bank bank;
    initBank(&bank);

    int customerId = 1;
    int choice;

    while (1) {
        printf("\n--- Bank Task Management ---\n");
        printf("1. Enqueue customer (Category 1: 입출금, 예적금)\n");
        printf("2. Enqueue customer (Category 2: 종합상담창구)\n");
        printf("3. Enqueue customer (Category 3: VIP)\n");
        printf("4. Serve customer\n"); // 은행원이 한 명의 고객을 응대
        printf("5. Display queues\n"); // 각 은행원의 대기열 출력
        printf("6. Check auto dequeue\n"); // 일정 시간 경과한 고객 자동 응대
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char task[50];
                printf("Enter task: ");
                scanf("%s", task);

                Customer customer;
                customer.id = customerId++;
                strcpy(customer.task, task);
                customer.category = 1;
                customer.enqueueTime = time(NULL);

                int shortestQueue = getShortestQueue(&bank, 1);
                enqueue(&bank.queues[shortestQueue], customer, &bank);

                printf("Customer ID: %d, Category: 1, Task: %s is added to Counter %d queue.\n", customer.id, customer.task, shortestQueue + 1);
                break;
            }
            case 2: {
                char task[50];
                printf("Enter task: ");
                scanf("%s", task);

                Customer customer;
                customer.id = customerId++;
                strcpy(customer.task, task);
                customer.category = 2;
                customer.enqueueTime = time(NULL);

                int shortestQueue = getShortestQueue(&bank, 2);
                enqueue(&bank.queues[shortestQueue], customer, &bank);

                printf("Customer ID: %d, Category: 2, Task: %s is added to Counter %d queue.\n", customer.id, customer.task, shortestQueue + 1);
                break;
            }
            case 3: {
                char task[50];
                printf("Enter task: ");
                scanf("%s", task);

                Customer customer;
                customer.id = customerId++;
                strcpy(customer.task, task);
                customer.category = 3;
                customer.enqueueTime = time(NULL);

                enqueue(&bank.vipQueue, customer, &bank);

                printf("Customer ID: %d, Category: 3, Task: %s is added to VIP queue.\n", customer.id, customer.task);
                break;
            }
            case 4: {
                int counterNumber;
                printf("Enter counter number: ");
                scanf("%d", &counterNumber);

                if (counterNumber >= 1 && counterNumber <= NUM_TELLERS) {
                    Queue* queue = &bank.queues[counterNumber - 1];
                    serveCustomerFromQueue(queue);
                } else {
                    printf("Invalid counter number.\n");
                }
                break;
            }
            case 5: {
                for (int i = 0; i < NUM_TELLERS; i++) {
                    displayQueue(&bank.queues[i], i + 1);
                }
                displayQueue(&bank.vipQueue, -1);
                displayQueue(&bank.waitingQueue, -2);
                break;
            }
            case 6: {
                checkAutoDequeue(&bank);
                break;
            }
            case 0: {
                printf("Exiting the program.\n");
                exit(0);
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

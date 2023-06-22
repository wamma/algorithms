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
    time_t dequeueTime; // 추가
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

		checkAutoDequeue(bank);
        return;
    }

    queue->data[++queue->rear] = customer;

    // 자동 dequeue 설정
    if (queue != &bank->vipQueue && queue != &bank->waitingQueue) {
        time_t currentTime = time(NULL);
        customer.dequeueTime = currentTime + 20;
    }
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

    for (int i = originalFront; i <= originalRear; i++) {
        if (i < originalRear) {
            enqueue(queue, queue->data[i], NULL);
        }
    }
}

void checkAutoDequeue(Bank* bank) {
    time_t currentTime = time(NULL);

    for (int i = 0; i < NUM_TELLERS; i++) {
        Queue* queue = &bank->queues[i];

        if (!isEmpty(queue)) {
            Customer customer = queue->data[queue->front];
            time_t enqueueTime = customer.enqueueTime;
            double timeElapsed = difftime(currentTime, enqueueTime);

            if (timeElapsed >= AUTO_DEQUEUE_TIME || currentTime >= customer.dequeueTime) {
                printf("Auto dequeue from Counter %d:\n", i + 1);
                serveCustomerFromQueue(queue);
                printf("Counter %d is now available.\n", i + 1);
            }
        }
    }
}

int main() {
    Bank bank;
    for (int i = 0; i < NUM_TELLERS; i++) {
        initQueue(&bank.queues[i]);
    }
    initQueue(&bank.vipQueue);
    initQueue(&bank.waitingQueue);

    int customerId = 1;

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Enqueue customer\n");
        printf("2. Dequeue customer from a specific counter\n");
        printf("3. Display counter queues\n");
        printf("4. Display waiting queue\n");
        printf("5. Quit\n");
        printf("Choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Customer customer;
                customer.id = customerId++;
                printf("Enter task: ");
                scanf("%s", customer.task);
                printf("Enter category (1: Deposit/Withdrawal, 2: Comprehensive consultation, 3: VIP): ");
                scanf("%d", &customer.category);
                customer.enqueueTime = time(NULL);

                if (customer.category == 3) {
                    enqueue(&bank.vipQueue, customer, &bank);
                } else {
                    int shortestQueueIndex = 0;
                    int shortestQueueLength = MAX_QUEUE_SIZE + 1;

                    for (int i = 0; i < NUM_TELLERS; i++) {
                        if (bank.queues[i].rear - bank.queues[i].front < shortestQueueLength) {
                            shortestQueueIndex = i;
                            shortestQueueLength = bank.queues[i].rear - bank.queues[i].front;
                        }
                    }

                    enqueue(&bank.queues[shortestQueueIndex], customer, &bank);
                }

                checkAutoDequeue(&bank);
                break;
            }
            case 2: {
                int counterNumber;
                printf("Enter counter number: ");
                scanf("%d", &counterNumber);

                if (counterNumber < 1 || counterNumber > NUM_TELLERS) {
                    printf("Invalid counter number.\n");
                    break;
                }

                Queue* queue = &bank.queues[counterNumber - 1];

                if (isEmpty(queue)) {
                    printf("Counter %d is empty. Cannot dequeue.\n", counterNumber);
                } else {
                    printf("Dequeue from Counter %d:\n", counterNumber);
                    serveCustomerFromQueue(queue);
                    printf("Counter %d is now available.\n", counterNumber);
                }

                checkAutoDequeue(&bank);
                break;
            }
            case 3: {
                for (int i = 0; i < NUM_TELLERS; i++) {
                    displayQueue(&bank.queues[i], i + 1);
                }
                break;
            }
            case 4: {
                displayQueue(&bank.waitingQueue, 0);
                break;
            }
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

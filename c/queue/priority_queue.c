/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_queue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:46:16 by hyungjup          #+#    #+#             */
/*   Updated: 2023/06/14 21:15:56 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

typedef struct
{
	int data[MAX_SIZE];
	int size;
} priority_queue;

void init(priority_queue *pq)
{
	pq->size = 0;
}

bool is_full(priority_queue *pq)
{
	return (pq->size == MAX_SIZE); // size가 MAX_SIZE이면 꽉 참 (true)
}

bool is_empty(priority_queue *pq)
{
	return (pq->size == 0); // size가 0이면 비어있음 (true)
}

void enqueue(priority_queue *pq, int data)
{
	if (is_full(pq))
	{
		printf("Queue is full!");
		return ;
	}
	int i = pq->size - 1; // 마지막 인덱스
	while (i >= 0 && pq->data[i] > data) // 큰 값이 나올 때까지 반복
	{
		pq->data[i + 1] = pq->data[i]; // 한 칸씩 뒤로 밀어줌
		i--;
	}
	pq->data[i + 1] = data; // 큰 값이 나오면 그 다음 칸에 삽입
	pq->size++;
}

int dequeue(priority_queue *pq)
{
	if (is_empty(pq))
	{
		printf("Queue is empty!");
		return (-1);
	}
	int data = pq->data[0]; // 가장 작은 값
	for (int i = 1; i < pq->size; i++)
		pq->data[i - 1] = pq->data[i]; // 한 칸씩 앞으로 당김
	pq->size--;
	return (data);
}

int front(priority_queue *pq)
{
	if (is_empty(pq))
	{
		printf("Queue is empty!");
		return (-1);
	}
	return (pq->data[0]); // 가장 작은 값
}

int rear(priority_queue *pq)
{
	if (is_empty(pq))
	{
		printf("Queue is empty!");
		return (-1);
	}
	return (pq->data[pq->size - 1]); // 가장 큰 값
}

void display(priority_queue *pq)
{
	for (int i = 0; i < pq->size; i++)
		printf("%d ", pq->data[i]);
	printf("\n");
}

int main(void)
{
	priority_queue pq;
	init(&pq);

	enqueue(&pq, 8);
	enqueue(&pq, 5);
	enqueue(&pq, 1);

	display(&pq);
}
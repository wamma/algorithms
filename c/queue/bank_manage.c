#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define 

typedef struct s_customer
{
	int		id;
	int		category;
}	t_customer;

typedef struct s_queue
{
	t_customer	data[MAX_SIZE];
	int			front;
	int			rear;
}	t_queue;

void	init_queue(t_queue *queue)
{
	queue->front = 0;
	queue->rear = 0;
}

int		is_empty(t_queue *queue)
{
	return (queue->front == queue->rear);
}

int		is_full(t_queue *queue)
{
	return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void	enqueue(t_queue *queue, t_customer customer)
{
	if (is_full(queue))
	{
		printf("모든 상담사가 고객님을 응대중입니다.\n");
		return ;
	}
	queue->rear = (queue->rear + 1) % MAX_SIZE;
	queue->data[queue->rear] = customer;
}

int	main(void)
{
	t_queue		general_queue;
	t_queue		loan_queue; // 대출
	t_queue		vip_queue;

	init_queue(&general_queue);
	init_queue(&loan_queue);
	init_queue(&vip_queue);

	while (1)
	{
		int		menu;
		int		id;
		t_customer	customer;

		printf("1.일반고객 2.우대고객 3.대출고객 4.상담종료\n");
		printf("상담원 선택: ");
		scanf("%d", &menu);
		if (menu == 4)
			break ;
		printf("고객번호: ");
		scanf("%d", &id);
		customer.id = id;
		if (menu == 1)
			enqueue(&general_queue, customer);
		else if (menu == 2)
			enqueue(&vip_queue, customer);
		else if (menu == 3)
			enqueue(&loan_queue, customer);
	}
}

#include <stdio.h>

#define MAX_SIZE 4

typedef struct Stack 
{
	int data[MAX_SIZE];
	int top;
} Stack;

void push(Stack *stack, int data) 
{
	if (stack->top == MAX_SIZE - 1) 
	{
		printf("Stack overflow\n");
		return;
	}
	stack->top++;
	stack->data[stack->top] = data;
}

int main(void) 
{
	Stack stack;
	stack.top = -1; // 스택이 공백 상태면 top은 -1로 초기화한다.
	int overflow = 0;

	push(&stack, 1);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);
	// push(&stack, 50);

	if (stack.top == MAX_SIZE - 1)
		overflow = 1;
	if (overflow != 1)
	{
		printf("Stack data list: ");
		for (int i = 0; i <= stack.top; i++)
			printf("%d ", stack.data[i]);
		printf("\n");
	}

	return 0;
}

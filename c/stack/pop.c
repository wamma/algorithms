#include <stdio.h>

#define MAX_SIZE 100

typedef struct Stack
{
	int data[MAX_SIZE];
	int top;
} Stack;

void push(Stack* stack, int data)
{
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack overflow\n");
		return;
	}
	stack->top++;
	stack->data[stack->top] = data;
}

int pop(Stack* stack)
{
	if (stack->top == -1) {
		printf("Stack underflow\n");
		return -1;
	}
	int element = stack->data[stack->top];
	stack->top--;
	return element;
}

void	display_list(Stack *stack)
{
	printf("Stack data list: ");
	for (int i = 0; i <= stack->top; i++)
		printf("%d ", stack->data[i]);
	printf("\n");
}

int main(void)
{
	Stack stack;
	stack.top = -1; // 스택이 공백 상태면 top은 -1로 초기화한다.

	push(&stack, 1);
	push(&stack, 20);
	push(&stack, 30);

	display_list(&stack);
	int popped_element = pop(&stack);
	printf("Popped element: %d\n", popped_element);
	printf("After the pop ");
	display_list(&stack);

	return 0;
}

#include <stdio.h>

#define MAX_SIZE 100

typedef struct Stack {
	int data[MAX_SIZE];
	int top;
} Stack;

void push(Stack* stack, int data) {
	if (stack->top == MAX_SIZE - 1) {
		printf("Stack overflow\n");
		return;
	}
	stack->top++;
	stack->data[stack->top] = data;
}

int main(void) {
	Stack stack;
	stack.top = -1; // 스택이 공백 상태면 top은 -1로 초기화한다.

	push(&stack, 1);
	push(&stack, 20);
	push(&stack, 30);

	if (stack.top == MAX_SIZE - 1)
		printf("Stack overflow\n");
	else {
		printf("Stack data list: ");
		for (int i = 0; i <= stack.top; i++)
			printf("%d ", stack.data[i]);
		printf("\n");

		if (stack.top >= 0)
			printf("Top data: %d\n", stack.data[stack.top]);
		else
			printf("Stack is empty\n");
	}

	return 0;
}

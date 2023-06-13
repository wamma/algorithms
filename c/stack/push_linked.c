#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct Stack {
	Node* top;
} Stack;

void push(Stack* stack, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Memory allocation failed\n");
		return;
	}
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
}

void pop(Stack* stack) {
	if (stack->top == NULL) {
		printf("Stack underflow\n");
		return ;
	}
	Node* temp = stack->top;
	int element = temp->data;
	stack->top = temp->next;
	free(temp);
}

void	display_list(Stack *stack)
{
	printf("Stack data list: ");
	Node	*current = stack->top;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

int main(void) {
	Stack stack;
	stack.top = NULL;

	push(&stack, 1);
	push(&stack, 20);
	push(&stack, 30);

	if (stack.top == NULL) {
		printf("Stack underflow\n");
	} else {
		display_list(&stack);
	}

	pop(&stack);
	printf("After pop ");
	display_list(&stack);
	return 0;
}

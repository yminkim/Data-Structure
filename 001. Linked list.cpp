#include <stdio.h>
#include <stdlib.h>
#define EMPTY 0;

typedef struct Node {
	int data;
	struct Node* link;
}Stack;

Stack* get_node() {
	Stack* node = (Stack*)malloc(sizeof(Stack));
	node->link = NULL;
	return node;
}

void push(Stack* *top ,int input) {
	Stack* temp = *top;
	*top = get_node();
	
	(*top)->data = input;
	(*top)->link = temp;
	

}

void print_stack(Stack* *top) {
	Stack* temp;
	for (temp = *top; temp != NULL; temp = temp->link) {
		printf("%d\n", temp->data);
	}
	
}

void pop(Stack* *top) {
	Stack* temp = *top;
	if (*top == NULL) {
		printf("this stack is Empty");
	}
	else {
		printf("뺄값: %d\n", temp->data);
		*top = temp->link;
		free(temp);
	}
}


void main() {
	Stack* top = EMPTY;

	push(&top, 10);
	push(&top, 20);
	push(&top, 30);

	print_stack(&top);
	printf("--------\n");
	pop(&top);
	pop(&top);
	print_stack(&top);
	printf("--------\n");
	pop(&top);
	print_stack(&top);
	pop(&top);

}

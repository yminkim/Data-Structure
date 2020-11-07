#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node* link;
}Stack;

Stack* get_node() {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	return temp;
}


void enqueue(Stack* *front, int data, Stack* *rear) {
	Stack* temp;
	temp = *front;
	if (temp == 0) {
		*front = get_node();
		(*front)->data = data;
		(*front)->link = 0;
		*rear = *front;
	}
	else {
		temp = *rear;
		*rear = get_node();
		(*rear)->data = data;
		(*rear)->link = 0;
		temp->link = *rear;

	}

}

void print_stack(Stack* *front) {
	Stack* temp = *front;
	for (temp = *front; temp != NULL; temp = temp->link) {
		printf("%d\n", temp->data);
	}
}

void dequeue(Stack* *front) {
	Stack* temp = *front;
	*front = (*front)->link;
	free(temp);
}

int main() {
	Stack* front = 0;
	Stack* rear = 0;

	enqueue(&front, 10, &rear);
	enqueue(&front, 20, &rear);
	enqueue(&front, 30, &rear);
	print_stack(&front);
	dequeue(&front);
	printf("-------\n");
	print_stack(&front);

}

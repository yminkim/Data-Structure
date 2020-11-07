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
		*rear = *front;
		(*rear)->data = data;
		(*rear)->link = 0;
	}
	else {
		temp = *rear;
		*rear = get_node();
		(*rear)->data = data;
		(*rear)->link = 0;
		(*temp).link = *rear;
	}
	
}

int main() {
	Stack* front = 0;
	Stack* rear = 0;

	enqueue(&front, 10, &rear);
	enqueue(&front, 20, &rear);
	enqueue(&front, 30, &rear);

}

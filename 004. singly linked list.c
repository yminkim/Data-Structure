#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Stack;


Stack* get_node() {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	return temp;
}

void insert_node(Stack** head, int data) {
	Stack* temp = *head;
	if (temp == 0) {
		*head = get_node();
		(*head)->data = data;
		(*head)->link = 0;
	}
	else if(temp->link == 0) {
		(*head)->link = get_node();
		(*head)->link->data = data;
		(*head)->link->link = 0;
	}
	else if (temp->link->link == 0) {
		(*head)->link->link = get_node();
		(*head)->link->link->data = data;
		(*head)->link->link->link = 0;
	}



}


int main() {
	Stack* head = NULL;

	insert_node(&head, 10);
	insert_node(&head, 20);
	insert_node(&head, 30);


		
	return 0;
}

#include<stdio.h>
#include<malloc.h>
struct stack {
	int data;
	struct stack* link;
}; typedef struct stack linked;
linked* get_node() {
	linked* tmp;
	tmp = (linked*)malloc(sizeof(linked));
	tmp->link = 0;
	return tmp;
}
void insert_data(linked** head, int data)
{
	if (*head == NULL) {
		*head = get_node();
		(*head)->data = data;
		return;
	}
	insert_data(&(*head)->link, data);
}

void modify(linked** head, int data, int input) {
	linked* temp = *head;
	while (temp->data != data) {
		temp = temp->link;
	}
	temp->data = input;
}

void add(linked** head, int data, int input) {
	linked* temp = *head;
	linked* temp2 = 0;
	while (temp->data != data) {
		temp = temp->link;
		temp2 = temp->link;
	}
	temp->link = get_node();
	temp->link->data = input;
	temp->link->link = temp2;
	
}

void del(linked** head, int data) {
	linked* temp = *head;
	linked* temp2 = 0;
	linked* temp3 = 0;
	while (temp->link->data != data) {
		temp = temp->link;
		
	}
	temp2 = temp->link;
	temp3 = temp2->link;
	free(temp2);
	temp->link = temp3;

}

void print_stack(linked* *head) {
	linked* temp = *head;
	while (temp != 0) {
		printf("%d\n", temp->data);
		
		temp = temp->link;
	}
	//printf("========\n");
}

void main() {
	linked* head = 0;
	insert_data(&head, 10);
	insert_data(&head, 20);
	insert_data(&head, 30);
	add(&head, 20, 25);
	add(&head, 30, 35);
	del(&head, 20);
	modify(&head, 30, 31);
	print_stack(&head);



}

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;

}Stack;

Stack* get_node() {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->link = NULL;
	return temp;
}

void push(Stack* *top, int data) {
	Stack* temp = *top;
	*top = get_node();

	(*top)->data = data;
	(*top)->link = temp;

}

void print(Stack* *top) {
	Stack* temp;
	for (temp = *top; temp != NULL; temp = temp->link) {
		printf("%d\n", temp->data);
	}
}

int pop(Stack* *top) {
	Stack* temp = *top;
	if (*top == NULL) {
		return 0;
	}
	else {
		*top = temp->link;
		printf("%d 뺍니다.\n", temp->data);
		free(temp);
	}


}

int main() {
	Stack* top = NULL;
	int sel =0;
	int number = 0;

	while (1) {
		system("cls");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. print\n");
		printf("4. exit\n");
		printf("번호>");
		scanf_s("%d", &sel);
		switch (sel) {
		case 1: 
			printf("숫자");
			getchar();
			scanf_s("%d", &number);
			push(&top, number); 
			break;
		case 2: 
			pop(&top); 
			system("pause");
			break;
		case 3: 
			print(&top); 
			system("pause");
			break;
		case 4: exit(0); break;
		default: break;

		}

	}



}

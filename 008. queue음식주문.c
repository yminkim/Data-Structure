#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
typedef struct node {
	char menu[100];
	int cnt = 0;
	struct node* link;
}Stack;

Stack* get_node() {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->link = 0;
	return temp;
}

void queue(Stack** front, Stack**rear, char* menu, int cnt) {
	Stack* temp = *front;
	 
	//strcpy_s((*top)->menu, sizeof((*top)->menu), menu);
	if (temp == 0) {
		*front = get_node();
		*rear = *front;
		strcpy_s((*rear)->menu, sizeof((*rear)->menu), menu);
		(*rear)->cnt = cnt;
	}
	else {
		temp = *rear;
		*rear = get_node();
		strcpy_s((*rear)->menu, sizeof((*rear)->menu), menu);
		(*rear)->cnt = cnt;
		temp->link = *rear;
	}


}

void dequeue(Stack* *front) {
	Stack* temp = *front;
	*front = temp->link;
	free(temp);
}


void print_stack(Stack **front) {
	system("cls");
	Stack* temp = *front;
	printf("밀린주문\n");
	while (temp != 0) {
		printf("메뉴: %s / 수량: %d\n", temp->menu, temp->cnt);
		temp = temp->link;
	}
}



int main() {
	Stack* front = 0;
	Stack* rear = 0;
	int sele = 0;
	char menu[100];
	int cnt = 0;

	while (1) {
		system("cls");
		printf("1. 주문\n");
		printf("2. 처리\n");
		printf("3. 밀린주문\n");
		printf("입력> ");
		scanf_s("%d", &sele, sizeof(sele));

		switch (sele) {
		case 1: 
			printf("주문 내용을 입력하세요!\n");
			printf("메뉴명 : ");
			scanf_s("%s", menu, sizeof(menu));
			printf("수량 : ");
			scanf_s("%d", &cnt, sizeof(cnt));

			queue(&front, &rear, menu, cnt);
			break;
		case 2:
			system("cls");
			dequeue(&front);
			printf("요리나갑니다~\n");
			system("pause");
			break;
		case 3:
			
			print_stack(&front);
			system("pause");
			break;
		default :
			break;
		}

	}


	return 0;
}

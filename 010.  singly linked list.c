#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node {
	char name[100];
	int age;
	char adress[100];
	int avg;
	struct node* link;
}Stack;

void print_list(Stack** head) {
	Stack* temp2 = *head;
	system("cls");
	printf("<<학생 리스트>>\n");
	while (temp2 != 0) {
		printf(" - %s\n", temp2->name);
		temp2 = temp2->link;
	}
}

int youmu(Stack** head) {
	if (*head == 0) {
		system("cls");
		printf("학생이 없어요\n");
		system("pause");
		return 0;
	}
}

int youmu2(Stack** head, char* del_name) {
	Stack* temp = *head;
	while (1) {
		if (strcmp(temp->name, del_name) == 0)
			break;
		if (temp->link == 0) {
			system("cls");
			printf("그런 학생은 없습니다.\n");
			system("pause");
			return 2;
		}
		temp = temp->link;
	}
}

Stack* get_node() {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp->link = 0;
	return temp;
}

void insert(Stack** head) {
	char name[100];
	int age;
	char adress[100];
	int avg;

	if (*head == 0) {
		system("cls");
		*head = get_node();
		printf("학생 이름 입력: ");
		scanf_s("%s", name, sizeof(name));
		strcpy_s((*head)->name, sizeof((*head)->name), name);

		printf("%s 학생 나이 입력: ", name);
		scanf_s("%d", &age);
		(*head)->age = age;
		getchar();
		printf("%s 학생 주소 입력: ", name);
		scanf_s("%[^\n]s", adress, sizeof(adress));
		strcpy_s((*head)->adress, sizeof((*head)->adress), adress);

		printf("%s 학생 평균 입력: ", name);
		scanf_s("%d", &avg);
		(*head)->avg = avg;
		return;
	}
	insert(&(*head)->link);
}

void search(Stack** head) {
	Stack* temp2 = *head;
	if (youmu(&(*head)) == 0)
		return;
	Stack* temp = *head;
	char who[100]= "";
	print_list(&temp2);
	printf("검색할 이름 입력: ");
	scanf_s("%s", who, sizeof(who));
	if (youmu2(&(*head), who) == 2)
		return;

	while (strcmp(temp->name, who) != 0) {
		temp = temp->link;
	}
	system("cls");
	printf("<< information >>\n");
	printf("학생 이름 : %s\n", temp->name);
	printf("학생 나이 : %d\n", temp->age);
	printf("학생 주소 : %s\n", temp->adress);
	printf("학생 평균 : %d\n", temp->avg);
	system("pause");
}

void list(Stack** head) {
	Stack* temp = *head;
	system("cls");
	printf("<<student list>>\n\n");
	printf("\t학생이름\t학생나이\t학생주소\n");
	while (temp != 0) {
		printf("\t%s\t\t%d\t\t%s\n", temp->name, temp->age, temp->adress);
		temp = temp->link;
	}
	system("pause");
}



void modify(Stack** head) {
	if (youmu(&(*head)) == 0)
		return;
	Stack* temp = *head;
	Stack* temp2 = *head;
	char name[100];
	char new_name[100];
	int new_age;
	char new_adress[100];
	int new_avg;

	bool modi = true;
	int menu;

	print_list(&temp2);
	
	printf("수정할 학생의 이름: ");
	scanf_s("%s", name, sizeof(name));
	if (youmu2(&(temp), name) == 2)
		return;
	system("cls");
	printf("<<----information---->>\n");
	while (strcmp(temp->name, name) != 0) {
		temp = temp->link;
	}
	while (modi) {
		system("cls");
		printf("<<----information---->>\n");
		printf("학생 이름: %s\n", temp->name);
		printf("학생 나이: %d\n", temp->age);
		printf("학생 주소: %s\n", temp->adress);
		printf("학생 평균: %d\n\n\n", temp->avg);
		printf("수정할 항목을 선택해주세요\n");
		printf("1.이름   2.나이   3.주소   4.평균   5.수정종료\n");
		printf("선택:");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			system("cls");
			printf("현재 이름: %s\n", temp->name);
			printf("수정할 이름:");
			scanf_s("%s", new_name, sizeof(new_name));
			printf("[%s] > [%s] 수정완료\n", temp->name, new_name);
			strcpy_s(temp->name, sizeof(temp->name), new_name);
			system("pause");
			break;
		case 2:
			system("cls");
			printf("현재 나이: %d\n", temp->age);
			printf("수정할 나이:");
			scanf_s("%d", &new_age);
			printf("[%d] > [%d] 수정완료\n", temp->age, new_age);
			temp->age = new_age;
			system("pause");
			break;
		case 3:
			system("cls");
			printf("현재 주소: %s\n", temp->adress);
			printf("수정할 주소:");
			getchar();
			scanf_s("%[^\n]s", new_adress, sizeof(new_adress));
			printf("[%s] > [%s] 수정완료\n", temp->adress, new_adress);
			strcpy_s(temp->adress, sizeof(temp->adress), new_adress);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("현재 평균: %d\n", temp->avg);
			printf("수정할 평균:");
			scanf_s("%d", &new_avg);
			printf("[%d] > [%d] 수정완료\n", temp->avg, new_avg);
			temp->avg = new_avg;
			system("pause");
			break;
		case 5:
			system("cls");
			printf("종료합니다.\n");
			system("pause");
			modi = false;
			break;
		}
	}

}


void del_student(Stack** head) {
	if (youmu(&(*head)) == 0)
		return;
	
	Stack* temp = *head;
	Stack* temp2 = *head; // temp->link를 연결해줄 3번째를 가리킬 변수
	char del_name[100]="";
	print_list(&temp2);
	printf("삭제할 학생 이름: ");
	scanf_s("%s", del_name, sizeof(del_name));
	
	
	if (youmu2(&(temp), del_name) == 2)
		return;

	if (strcmp(temp->name, del_name) == 0) {
		*head = temp->link;
		printf("%s는 이제 떠나주셔도 됩니다.\n", temp->name);
		free(temp);

	}
	else {

		while (strcmp(temp->link->name, del_name) != 0) {
			temp = temp->link;
		}

		printf("%s는 이제 떠나주셔도 됩니다.\n", temp->link->name);
		temp2 = temp->link->link;
		free(temp->link);
		temp->link = temp2;
	}
	system("pause");



}


int main() {
	Stack* head = NULL;
	int menu = 0;

	while (1) {

		system("cls");
		printf("<<===학생부===>>\n");
		printf("1. 학생 등록\n");
		printf("2. 학생 검색\n");
		printf("3. 학생 목록\n");
		printf("4. 학생 수정\n");
		printf("5. 학생 삭제\n");
		printf("6. 종료\n");
		printf("선택 > ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			insert(&head);
			break;
		case 2:
			search(&head);
			break;
		case 3:
			list(&head);
			break;
		case 4:
			modify(&head);
			break;
		case 5:
			del_student(&head);
			break;
		case 6:
			exit(1);
			break;
		default :
			break;
		}
	}
	return 0;
}

#include<stdio.h>

#define FALSE 0
#define TRUE 1
#define LData int // 자유로운 형변환을 위해 define
#define List_Arr 100 // 배열의 길이


typedef struct __ArrayList {
	LData arr[List_Arr];
	int numOfData;
	int curPosition;
}ArrayList;

typedef ArrayList List;

void com() {
	printf("초기화 완료\n");
	system("PUASE");
}

void ListInit(List* plist) {
	plist->numOfData = 0;
	plist->curPosition = -1;
	com();
}

void LInsert(List* plist, LData data) {
	if (plist->numOfData >= List_Arr) {
		printf("못 넣어\n");
		return;
	}
	plist->arr[plist->numOfData] = data;
	plist->numOfData++;
	
	com();
}

int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData == 0) 
		return FALSE;
	plist->curPosition = 0;
	*pdata = plist->arr[0];

	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	
	return TRUE;
}

void LRemove(List* plist, LData pdata) {
	//////////////* 이진탐색 버전
	int first = 0;
	int last = plist->numOfData-1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (plist->arr[mid] == pdata) {
			printf("\n%d를 지웁니다\n", pdata);
			for (int j = mid; j < plist->numOfData; j++)
				plist->arr[j] = plist->arr[j + 1];
			plist->curPosition--;
			plist->numOfData--;
			break;
		}
		else if (plist->arr[mid] > pdata)
			last = mid - 1;
		else
			first = mid + 1;

	}
	*///////////////
	
	printf("\n%d를 지웁니다\n", pdata);
	for (int i = 0; i < plist->numOfData; i++) {
		if (plist->arr[i] == pdata) {
			for (int j = i; j < plist->numOfData; j++) {
				plist->arr[j] = plist->arr[j + 1];
			}
			plist->curPosition--;
			plist->numOfData--;
			return TRUE;
		}
		
			
	}
	printf("그런값 없음");
	return FALSE;
}

int LCount(List* plist) {
	printf("[값: %d개]\n", plist->numOfData);
}

void LPrint(List* list) {
	if (list->numOfData < 0) {
		printf("초기화 되지 않았습니다.\n");
		return;
	}
	if (list->numOfData == 0) {
		printf("출력할 값이 없습니다.\n");
		return;
	}
	LData data;
	LCount(list);

	if (LFirst(list, &data)) {
		printf("%d ", data);
		while (LNext(list, &data))
			printf("%d ", data);
	}
	printf("\n");
}



int main() {
	List list;
	LData data;
	LData input_Data;
	int menu;

	while (1) {
		system("cls");
		LPrint(&list);
		printf("1. 초기화\n2. 값 입력\n3. 값 제거\n4. 종료");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: 
			system("cls");
			ListInit(&list);
			break;

		case 2:
			printf("\n입력할 값 : ");
			scanf_s("%d", &input_Data);
			LInsert(&list, input_Data);
			break;

		case 3:
			printf("\n\n제거할 값 : ");
			scanf_s("%d", &input_Data);
			LRemove(&list, input_Data);
			break;

		case 4:
			exit();
			break;
		default :
			break;
		}
	}


	return 0;
}

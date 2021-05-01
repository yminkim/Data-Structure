#include <stdio.h>

int two(int arr[], int first, int last, int target) {
	int mid;

	if (first > last) // 탈출 조건
		return -1;

	mid = (first + last) / 2;

	if (target == arr[mid])
		return mid;
	else if (target > arr[mid])
		two(arr, mid + 1, last, target);
	else
		two(arr, first, mid - 1, target);

	/* 이렇게도 가능
	else if (target > arr[mid])
		first = mid + 1;
	else
		last = mid - 1;
	
	two(arr, first, last, target);
	*/
}

int main() {
	int arr[10] = {1, 3, 5, 8, 9, 11, 15, 18, 24, 40};
	int len = sizeof(arr) / sizeof(int);
	int target;
	int first = 0;
	int last = len -1;

	
	while (1) {
		system("cls");
		printf("배열: ");
		for (int i = 0; i < len; i++)
			printf("%d\t", arr[i]);
		printf("\n순서: ");
		for (int i = 0; i < len; i++)
			printf("%d\t", i);
		printf("\n찾을 값을 입력: ");
		scanf_s("%d", &target);
		if (two(arr, first, last, target) == -1) {
			printf("찾는 값이 없습니다.\n");
			system("pause");
		}
		else {
			printf("찾는 %d는 %d 번째 index입니다\n", target, two(arr, first, last, target));
			system("pause");
		}
	}
	return 0;
}

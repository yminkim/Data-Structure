#include <stdio.h>

int two(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid])
			return mid;
		else if (target > arr[mid])
			first = mid + 1;
		else
			last = mid - 1;
	}
	return -1;
}


int main() {
	int arr[10] = {1, 3, 5, 8, 9, 11, 15, 18, 24, 40};
	int len = sizeof(arr) / sizeof(int);
	int target;
	
	while (1) {
		system("cls");
		printf("배열: ");
		for (int i = 0; i < len; i++)
			printf("%d ", arr[i]);
		printf("\n찾을 값을 입력: ");
		scanf_s("%d", &target);
		if (two(arr, len, target) == -1) {
			printf("찾는 값이 없습니다.\n");
			system("pause");
		}
		else {
			printf("찾는 %d는 %d 번째 index입니다\n", target, two(arr, len, target));
			system("pause");
		}



	}
	

	return 0;
}

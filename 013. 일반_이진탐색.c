#include <stdio.h>

int two(int arr[], int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (target == arr[mid])
			return mid;
		else {
			if (target > arr[mid])
				first = mid + 1;
			else
				last = mid - 1;
		}

	}
	return -1;

}


int main() {
	int arr[9] = {1,2,3,7,9,12,21,23,27};

	
	int len = sizeof(arr) / sizeof(arr[0]);
	int target;
	printf("배열값: ");
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n찾을 값: ");
	scanf_s("%d", &target);

	printf("찾는 값 %d인덱스인 %d", two(arr, len, target), arr[two(arr, len, target)]);

	return 0;
}

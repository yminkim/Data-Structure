#include <stdio.h>
// n! = n(n-1)(n-2)(n-3)...(2)(1)   As a special case: 0!=1

int facto(int num) {
	if (num == 0)
		return 1;
	else
		return num * facto(num - 1);
}

int main() {
	printf("3! : %d\n", facto(3));
	printf("5! : %d\n", facto(5));
	printf("9! : %d\n", facto(9));

	return 0;
}

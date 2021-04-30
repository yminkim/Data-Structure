#include <stdio.h>
//           // 0   .... n=1
// fib(n) =  // 1   .... n=2
//           // fib(n-1) + fib(n-2) .... otherwise

int fibo(int num) {
	if (num == 1)
		return 0;
	else if (num == 2)
		return 1;
	else
		return fibo(num - 1) + fibo(num - 2);

}

int main() {
	int i;
	for (i = 1; i < 15; i++)
		printf("%d ", fibo(i));

	return 0;
}

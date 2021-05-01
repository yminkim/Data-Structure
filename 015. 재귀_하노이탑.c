#include <stdio.h>

void hanoiTower(int n, char from, char mid, char to) {

	// 원반이 1개인 경우에는 바로 A > C로 이동
	if (n == 1) {
		printf("%d 원반을 %c 에서 %c로 이동\n", n, from, to);
	}

	// n-1개를 A에서 B로 이동
	// n개를 A에서 C로 이동
	// n-1개를 B에서 C로 이동
	else {
		hanoiTower(n - 1, from, to, mid);
		printf("%d 원반을 %c 에서 %c로 이동\n", n, from, to);
		hanoiTower(n - 1, mid, from, to);
	}
}

int main() {
	hanoiTower(5, 'A', 'B', 'C');

	return 0;
}

//어후,,

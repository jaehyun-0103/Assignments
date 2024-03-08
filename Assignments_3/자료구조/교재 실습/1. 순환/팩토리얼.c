#include <stdio.h>

int factorial(int);

int main() {
	int n, r;
	printf("양의 정수를 입력하세요 : ");
	scanf_s("%d", &n);
	r = factorial(n);
	printf("팩토리얼 결과 : %d", r);
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
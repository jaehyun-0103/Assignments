#include <stdio.h>

int factorial(int);

int main() {
	int n, r;
	printf("���� ������ �Է��ϼ��� : ");
	scanf_s("%d", &n);
	r = factorial(n);
	printf("���丮�� ��� : %d", r);
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}
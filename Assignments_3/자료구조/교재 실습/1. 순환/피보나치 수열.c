#include <stdio.h>

int fib(int);

int main() {
    int n, r;
    printf("���� ������ �Է��ϼ��� : ");
    scanf_s("%d", &n);
    r = fib(n);
    printf("�Ǻ���ġ ���� ��� : %d", r);
}

int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
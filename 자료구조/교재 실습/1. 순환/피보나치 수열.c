#include <stdio.h>

int fib(int);

int main() {
    int n, r;
    printf("양의 정수를 입력하세요 : ");
    scanf_s("%d", &n);
    r = fib(n);
    printf("피보나치 수열 결과 : %d", r);
}

int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
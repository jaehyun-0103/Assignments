#include <stdio.h>

double power(double, int);

int main() {
	int n;
	double x, r;
	printf("밑과 지수를 입력하세요 : ");
	scanf_s("%lf %d", &x, &n);
	r = power(x, n);
	printf("거듭제곱 결과 : %.1lf", r);
}

double power(double x, int n) {
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, (n - 1) / 2);
}
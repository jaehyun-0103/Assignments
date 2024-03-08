#include<stdio.h>

int min, max;

void min_max(int a, int b, int c) {	// min_max() 함수 정의
	min = a <= b ? a : b;			// a <= b가 참이면 a가 min, 거짓이면 b가 min
	if (c <= min)					// c가 min보다 작다면
		min = c;					// c가 min
	max = a >= b ? a : b;			// a >= b가 참이면 a가 max, 거짓이면 b가 max
	if (c >= max)					// c가 max보다 크면
		max = c;					// c가 max
}

int main() {
	int a, b, c;
	printf("Enter three integers.\n");
	scanf_s("%d %d %d", &a, &b, &c);
	min_max(a, b, c);				// min_max() 함수 호출
	printf("min is %d, max is %d\n", min, max);
	return 0;
}
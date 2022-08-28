#include<stdio.h>

int power(int a, int b) {			// power() 함수 선언
	if (b == 0)						// 변수 b가 0이라면
		return 1;					// 1 반환
	else							// 변수 b가 0이 아니라면
		return a * power(a, b - 1);	// 재귀 호출
}

int main() {
	int base, multiplier;
	printf("Enter base and multiplier\n");
	scanf_s("%d %d", &base, &multiplier);
	printf("%d to the power of %d is %d\n", base, multiplier, power(base, multiplier));	// power() 함수 호출
	printf("\n");
	return 0;
}


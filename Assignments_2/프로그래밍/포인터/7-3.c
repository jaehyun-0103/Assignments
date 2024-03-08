#include<stdio.h>

void factorial(int n, int* p) {	// factorial() 함수 정의
	if (n == 1)					// 변수 n이 1이라면
		return;					// 재귀 호출 종료
	*p = *p * n;
	factorial(n - 1, p);		// 재귀 호출
}

int main(void) {
	int inputNum, result = 1;
	printf("Enter a natural number.\n");
	scanf_s("%d", &inputNum);
	factorial(inputNum, &result); // factorial() 함수 호출
	printf("%d factorial is %d.\n", inputNum, result);
	return 0;
}
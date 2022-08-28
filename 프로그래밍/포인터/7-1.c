#include<stdio.h>

void add(const int a, const int b, int* p) {	// add() 함수 정의
	*p = a + b;		// 입력한 값을 더함
}

int main(void) {
	int x, y, result;
	printf("Enter two integers.\n");
	scanf_s("%d %d", &x, &y);
	add(x, y, &result);					// add() 함수 호출
	printf("The sum is %d\n", result);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int findsum(int);	// findsum() 함수 선언

int main() {
	int num, x;
	printf("Enter a number: ");
	scanf("%d", &num);
	x = findsum(num);	// 입력된 정수의 각 자리 수의 합을 변수 x에 저장
	printf("Sum of the digits of %d is: %d\n", num, x);
	return 0;
}

int findsum(int num) {	// findsum() 함수 정의
	if (num == 0)		// num 변수가 0이라면
		return 0;		// 프로그램 종료
	else				// num 변수가 0이 아니라면
		return(num % 10) + findsum(num / 10);	// 재귀호출
}
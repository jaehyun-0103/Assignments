#include<stdio.h>

extern int num1, num2;			// 다른 소스 파일에 있는 전역변수 num1, num2 사용
extern char op;					// 다른 소스 파일에 있는 전역변수 op 사용

void myInput() {				// myInput() 함수 정의
	printf("숫자와 연산자를 입력하시오 : ");	// 숫자와 연산자를 입력하시오 : 출력
	scanf_s("%d %d %c", &num1, &num2, &op);		// 두 개의 숫자 num1, num2와 연산자 입력
}

extern double result;			// 다른 소스 파일에 있는 전역변수 result 사용

double myOutput() {				// myOutput() 함수 정의
	func();						// func() 함수 호출
	printf("%.2lf", result);	// 연산결과를 소수점 두 번째 자리까지 출력
}
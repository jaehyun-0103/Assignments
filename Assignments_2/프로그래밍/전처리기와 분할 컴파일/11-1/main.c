#include<stdio.h>
#include"myheader.h"	// 상대 경로

int num1, num2;			// 입력받은 두 개의 숫자를 저장할 변수 선언
char op;				// 입력받은 사칙연산 기호를 저장할 문자 변수 선언
double result;			// 실수 결과값을 저장할 변수 선언

int main(void) {
	myInput();			// myInput() 함수 호출
	myOutput();			// myOutput() 함수 호출
}
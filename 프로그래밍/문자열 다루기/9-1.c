#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void swap_string(str1, str2);		// swap_string() 함수 선언

int main(void) {
	char str1[20] = "apple";		// str1 배열에 문자열 apple 할당
	char str2[20] = "banana";		// str2 배열에 문자열 banana 할당

	swap_string(str1, str2);		// swap_string함수 호출
	printf("str1 : %s\n", str1);	// str1 출력
	printf("str2 : %s\n", str2);	// str2 출력
	system("pause");
	return 0;
}
void swap_string(char* a, char* b) {	// swap_string함수 정의
	char temp[20];						// 배열을 저장할 temp 배열 선언
	strcpy(temp, a);					// a배열을 temp배열에 복사
	strcpy(a, b);						// b배열을 a배열에 복사
	strcpy(b, temp);					// temp배열을 b배열에 복사
}
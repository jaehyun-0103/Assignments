#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char* my_strcpy(char* dest, const char* src, int index);		// my_strcpy() 함수 선언

int main(void) {
	char dest[100];												// dest배열 선언
	char src[100];												// src배열 선언
	int index = 0;												// index변수를 0으로 초기화
	printf("source : ");										// source : 출력
	gets(src);													// gets함수로 입력받은 문자열을 src에 저장
	while (1) {													// 무한반복
		if (strcmp(src, "quit") == 0) break;					// src와 quit이 같다면 반복문 종료
		my_strcpy(dest, src, index);							// my_strcpy함수 호출

		printf("destination : ");								// destination : 출력
		puts(dest);												// puts함수로 dest 문자열 출력
		printf("source : ");									// source : 출력
		gets(src);												// gets함수로 입력받은 문자열을 src에 저장
	}
	system("pause");
	return 0;
}
char* my_strcpy(char* dest, const char* src, int index) {		// my_strcpy함수 정의
	if (src[index] != '\0') {									// src배열의 index번째 인덱스가 널문자가 아니라면
		++index;												// index값을 1씩 증가한 후
		my_strcpy(dest, src, index);							// my_strcpy 함수를 재귀호출 
	}
	else {														// src배열의 index번째 인덱스가 널문자라면
		for (int i = 0; i < index; i++) {						// i가 index보다 작을때까지 i를 1씩 증가
			dest[i] = src[i];									// src 배열의 i번째 인덱스의 값을 dest 배열의 i번째 인덱스의 값에 저장
			dest[i + 1] = '\0';									// scr 배열을 dest 배열에 대입한 그 다음 인덱스의 값에 널문자 저장
		}
		return dest[index];
	}
}
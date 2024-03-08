#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int my_strcmp(const char* str1, const char* str2);		// my_strcmp() 함수 선언

int main(void) {
	char str1[100];										// str1 배열 선언
	char str2[100];										// str2 배열 선언
	printf("문자열입력 : ");							// 문자열입력 : 출력
	scanf("%s", str1);									// str1 입력
	while (1) {											// 무한반복
		if (my_strcmp(str1, "quit") == 0) break;		// my_strcmp함수 호출, str1과 quit을 비교하여 같다면 반복문 종료
		printf("문자열입력 : ");						// 문자열입력 : 출력
		scanf("%s", str2);								// str2 입력

		printf("%d\n", my_strcmp(str1, str2));			// my_strcmp함수 호출

		printf("문자열입력 : ");						// 문자열입력 : 출력
		scanf("%s", str1);								// str1 입력
	}
	system("pause");
	return 0;
}
int my_strcmp(const char* str1, const char* str2) {					// my_strcmp함수 정의
	int result;														// main함수에 반환할 결과값을 저장할 변수
	if (strlen(str1) == strlen(str2)) {								// str1과 str2 문자열 길이가 같을 때
		for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {	// str1 또는 str2가 널문자를 만날때까지 인덱스 번호인 i값을 1씩 증가
			if (str1[i] > str2[i]) {								// str1이 str2보다 크다면
				result = 1;											// result는 1
				break;												// 반복문 종료
			}
			else if (str1[i] == str2[i]) {							// str1과 str2가 같으면
				result = 0;											// result는 0
			}
			else {													// str2가 str1보다 크다면
				result = -1;										// -1
				break;												// 반복문 종료
			}
		}
	}
	else {															// str1과 str2 문자열 길이가 다를 때
		if (strlen(str1) > strlen(str2))							// str1의 길이가 더 길면
			result = 1;												// 1
		else if (strlen(str1) < strlen(str2))						// str2의 길이가 더 길면
			result = -1;											// -1
	}
	return result;													// result값 반환
}
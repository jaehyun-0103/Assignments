#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char* my_strcat(char* dest, char* src);				// my_strcat() 함수 선언

int main(void) {
	char dest[100];									// dest 배열 선언
	char src[100];									// src 배열 선언
	printf("문자열입력 : ");						// 문자열입력 : 출력
	scanf("%s", dest);								// dest에 문자열 입력
	while (1) {										// 무한반복
		if (strcmp(dest, "quit") == 0) break;		// dest와 quit이 같다면 반복문 종료
		printf("문자열입력 : ");					// 문자열입력 : 출력
		scanf("%s", src);							// src에 문자열 입력

		my_strcat(dest, src);						// my_strcat함수 호출

		printf("%s\n", dest);						// dest 문자열 출력

		printf("문자열입력 : ");					// 문자열입력 : 출력
		scanf("%s", dest);							// dest에 문자열 입력
	}
	system("pause");
	return 0;
}
char* my_strcat(char* dest, char* src) {			// my_strcat함수 정의
	int len = 0;									// dest 문자열의 마지막 인덱스 번호를 저장할 변수
	for (int i = 0; dest[i] != '\0'; i++) {			// dest 문자열의 마지막 인덱스 번호
		len = i;									// i값을 len에 저장
	}
	for (int j = 0; src[j] != '\0'; j++) {			// src 문자열의 마지막 인덱스 번호
		*(dest + len + j + 1) = *(src + j);			// dest의 널문자가 있는 곳부터 src 문자열의 길이만큼 하나하나 저장
		*(dest + len + j + 2) = '\0';				// src 문자열을 다 저장했다면 마지막에 널문자 저장
	}
	return *dest;									// dest 반환
}
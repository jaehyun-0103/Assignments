#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char last_name[20];					// 성을 입력할 배열
	char first_name[20];				// 이름을 입력할 배열
	char full_name[20];					// 성과 이름을 모두 저장할 배열
	printf("성을 입력하시오. : ");		// 성을 입력하시오. : 출력
	scanf("%s", last_name);				// 성을 입력
	printf("이름을 입력하시오. : ");	// 이름을 입력하시오. : 출력
	scanf("%s", first_name);			// 이름을 입력
	strcat(last_name, first_name);		// strcat함수로 성 뒤에 이름을 붙여 last_name에 저장
	strcpy(full_name, last_name);		// strcpy함수로 last_name을 full_name에 복사
	printf("성을 포함한 이름은 %s입니다.\n", full_name);	// full_name 출력
	system("pause");
	return 0;
}
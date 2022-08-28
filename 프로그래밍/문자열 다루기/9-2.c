#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(void) {
	char str1[20] = "Long time no see.";		// str1 배열에 Long time no see. 문자열 할당
	char str2[20] = "What's up?";				// str2 배열에 what's up? 할당
	if (strlen(str1) > strlen(str2))			// str1 문자열의 길이가 str2 문자열의 길이보다 더 길다면
		printf("%s\n", str1);					// str1 출력
	else if (strlen(str1) < strlen(str2))		// str2 문자열의 길이가 str1 문자열의 길이보다 더 길다면
		printf("%s\n", str2);					// str2 출력
	else										// str1과 str2의 문자열의 길이가 같다면
		printf("두 문자열의 크기는 같습니다.");	// 두 문자열의 크기는 같습니다. 출력
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>

int count_vowel(char* arr, int length);		// count_vowel() 함수 선언

int main(void) {
	char ch, str[100];						// 입력 가능한 문자 개수 초기화
	int i = 0;
	printf("Enter a sample sentence.\n");	// Enter a sample sentence. 출력
	while ((ch = getchar()) != '\n') {		// 줄바꿈이 아닌 동안
		str[i] = ch;						// 문자 하나하나를 배열에 저장
		i++;								// 배열의 개수 계산
	}
	printf("Vowels appear %d times.\n", count_vowel(str, i));	// count_vowel함수 호출
	system("pause");
	return 0;
}
int count_vowel(char* arr, int length) {	// count_vowel함수 정의
	int cnt = 0;							// 모음의 개수 초기화
	for (int j = 0; j < length; j++) {		// 문자가 저장된 배열의 개수 동안
		if (arr[j] == 'a' || arr[j] == 'e' || arr[j] == 'i' || arr[j] == 'o' || arr[j] == 'u') {	// 모음과 동일한 문자라면
			cnt++;							// 카운트
		}
	}
	return cnt;
}
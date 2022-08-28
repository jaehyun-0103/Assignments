#include<stdio.h>
#include<stdlib.h>

void reverse_array(int* a, int* b, int length);				// reverse_array() 함수 선언

int main(void) {
	int original[10];										// 원래의 배열
	int reverse[10];										// 순서가 바뀐 배열
	int num = 0;											// 배열에 넣을 숫자
	int length;												// 음수가 나오기 전까지 숫자의 개수
	int i = 0;												// 배열의 인덱스
	printf("Enter a sequence of positive integers.\n");
	while (1) {												// 무한 반복
		scanf_s("%d ", &num);								// 배열에 넣을 숫자 입력
		if (num <= 0)										// 숫자가 0보다 작거나 같으면
			break;											// 중지
		else												// 숫자가 0보다 크면
			original[i++] = num;							// 배열의 인덱스에 1을 더함
		if (i == 9)											// 배열의 인덱스가 9이면
			break;											// 중지
	}
	length = i;												// i가 길이
	reverse_array(original, reverse, length);				// reverse_array함수 호출
	for (i = 0; i < length; i++) {
		printf("%d ", reverse[i]);
	}
	system("pause");
	return 0;
}
void reverse_array(int* a, int* b, int length) {			// reverse_array함수 정의
	for (int m = 0; m < length ; m++) {						// 양수까지의 수의 길이 동안
		b[m] = a[length - m - 1];							// 역순으로 저장									// 역순으로 저장한 배열 출력
	}
}
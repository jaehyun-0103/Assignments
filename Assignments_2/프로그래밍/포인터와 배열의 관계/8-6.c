#include<stdio.h>
#include<stdlib.h>

void min_max(int* arr, int* min, int* max, int length);		// min_max() 함수 선언

int main(void) {
	int length=0;											//배열의 길이를 0으로 초기화
	int* arry;
	int min, max;
	int num=0;												// 음수를 입력받기 전까지의 정수 개수
	scanf_s("%d", &length);									// 배열의 길이 입력
	arry = (int *)malloc(sizeof(int) * length);				// 동적으로 배열의 길이 선언
	printf("Enter a sequence of positive integers.\n");
	for (int i = 0; i < length; i++) {						// i가 0부터 길이까지
		scanf_s("%d", &arry[i]);							// 배열에 입력
		num++;												// 양수의 개수를 셈
		if (arry[i] < 0)
			break;
	}
	min_max(arry, &min, &max, num-1);						// min_max함수 호출
	printf("Minimum is %d, Maximum is %d.\n", min, max);
	system("pause");
	return 0;
}
void min_max(int* arr, int* min, int* max, int length) {	// min_max함수 정의
	*min = arr[0];											// 배열의 첫번째 값이 최소라 초기화
	*max = arr[0];											// 배열의 첫번째 값이 최대라 초기화
	for (int j = 0; j < length; j++) {						// j가 0부터 길이미만까지
		if (arr[j] <= *min)									// min보다 배열 값이 작다면
			*min = arr[j];									// min은 그 배열 값
	}
	for (int k = 0; k < length; k++) {						// k가 0부터 길이미만까지
		if (arr[k] >= *max)									// max보다 배열값이 크다면
			*max = arr[k];									// max는 그 배열 값
	}
}
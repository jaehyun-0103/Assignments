#include<stdio.h>
#include<stdlib.h>

void print_array(int* arr, int length);					// print_array() 함수 선언
void swap_array(int* a, int* b, int length);			// swap_array() 함수 선언

int main(void) {
	int arr1[5];
	int arr2[5];
	int length=5;
	printf("Enter the contents of first array.\n");
	for (int i = 0; i<length; i++) {					// i가 0부터 4까지
		scanf_s("%d", &arr1[i]);						// 배열에 입력
	}
	printf("Enter the contents of second array.\n");
	for (int j = 0; j<length; j++) {					// j가 0부터 4까지
		scanf_s("%d", &arr2[j]);						// 배열에 입력
	}
	printf("Before swapping,\n");

	printf("first: ");
	print_array(arr1, length);							// print_array함수 호출
	printf("second: ");
	print_array(arr2, length);							// print_array함수 호출

	swap_array(arr1, arr2, length);						// swap_array함수 호출

	printf("After swapping,\n");

	printf("first: ");
	print_array(arr1, length);							// print_array함수 호출
	printf("second: ");
	print_array(arr2, length);							// print_array함수 호출
	system("pause");
	return 0;
}
void print_array(int* arr, int length) {				// print_array함수 정의
	for (int m = 0; m < length; m++) {					// m가 0부터 4까지
		printf("%d ", arr[m]);							// 배열 출력
	}
	printf("\n");
}
void swap_array(int* a, int* b, int length) {			// swap_array함수 정의
	int arr3;											// 빈 배열 공간 선언
	for (int n = 0; n < length; n++) {					// n가 0부터 4까지
		arr3 = *(a+n);									// arr1배열을 arr3배열에 저장
		*(a+n) = *(b+n);								// arr2배열을 arr1배열에 저장
		*(b+n) = arr3;									// arr3배열을 arr2배열에 저장
	}
	
}
#include<stdio.h>
#include<stdlib.h>

double average_by_array(int p[], int length);		// average_by_array() 함수 선언
double average_by_pointer(int* p, int length);		// average_by_pointer() 함수 선언

int main(void) {
	int arr[5] = { 10, 40, 50, 20, 15 };			// 배열 선언
	printf("%lf\n", average_by_array(arr, 5));		// average_by_array함수 호출 
	printf("%lf\n", average_by_pointer(arr, 5));	// average_by_pointer함수 호출
	system("pause");
	return 0;
}
double average_by_array(int p[], int length) {		// average_by_array함수 정의
	double sumArray = 0.0;							// 평균값 초기화
	for (int i = 0; i < length; i++) {				// i가 0부터 4까지
		sumArray += p[i];							// 포인터 배열 값을 더함
	}
	return sumArray / length;						// 평균 반환
}
double average_by_pointer(int* p, int length) {		// average_by_pointer함수 정의
	double sumPointer = 0.0;						// 평균값 초기화
	for (int j = 0; j < length; j++) {				// i가 0부터 4까지
		sumPointer += *(p+j);						// 포인터 배열 값을 더함
	}
	return sumPointer / length;						// 평균 반환
}
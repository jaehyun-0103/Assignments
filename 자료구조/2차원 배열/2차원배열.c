#define _CRT_SECURE_NO_WARNINGS						// 보안 경고로 인한 컴파일 에러 방지
#include<stdio.h>
void  calculator(int, int, int, int, int);			// 행렬의 곱을 계산하는 함수 선언
void printer(int, int, int);						// 행렬의 곱의 결과를 출력하는 함수 선언

int main() {
	int row1, row2, column1, column2;				// 파일에서 읽은 두 행렬의 행과 열을 저장할 변수
	FILE* fp;
	fp = fopen("Array.txt", "r");					// Array.txt 파일을 읽기 모드
	if (fp == NULL) {								// 파일 열기에 실패하면
		printf("파일을 찾지 못했습니다.\n");		// "파일을 찾지 못했습니다."를 출력
		exit(1);									// 에러메세지 종료
	}

	fscanf(fp, "%d %d %d %d", &row1, &column1, &row2, &column2);	// 서식을 지정하여 파일에서 읽기

	int** a = (int**)malloc(sizeof(int*) * row1);	// 이중 포인터에 동적 메모리 할당
	for (int n = 0; n < row1; n++)					// a배열의 세로 크기만큼 반복
		a[n] = (int*)malloc(sizeof(int) * column1);	// 동적 메모리 할당

	int** b = (int**)malloc(sizeof(int*) * row2);	// 이중 포인터에 동적 메모리 할당
	for (int m = 0; m < row2; m++)					// b배열의 세로 크기만큼 반복
		b[m] = (int*)malloc(sizeof(int) * column2);	// 동적 메모리 할당

	for (int i = 0; i < row1; i++)					// a배열의 세로 크기만큼 반복
		for (int j = 0; j < column1; j++)			// a배열의 가로 크기만큼 반복
			fscanf(fp, "%d", &a[i][j]);				// 행렬 값을 파일에서 읽기

	for (int i = 0; i < row2; i++)					// b배열의 세로 크기만큼 반복
		for (int j = 0; j < column2; j++)			// b배열의 가로 크기만큼 반복
			fscanf(fp, "%d", &b[i][j]);				// 행렬 값을 파일에서 읽기

	calculator(row1, column1, row2, column2, a, b);	// 행렬의 곱을 계산하는 함수 호출

	for (int n = 0; n < row1; n++)					// a배열의 세로 크기만큼 반복
		free(a[n]);									// 2차원 배열의 가로 공간 메모리 해제
	free(a);										// 2차원 배열의 세로 공간 메모리 해제

	for (int m = 0; m < row1; m++)					// a배열의 세로 크기만큼 반복
		free(b[m]);									// 2차원 배열의 가로 공간 메모리 해제
	free(b);										// 2차원 배열의 세로 공간 메모리 해제

	fclose(fp);										// 파일 포인터 닫기
}

void calculator(int row1, int column1, int row2, int column2, int** a, int** b) {	// 행렬의 곱을 계산하는 함수 정의
	int** c = (int**)malloc(sizeof(int*) * row1);	// 이중 포인터에 동적 메모리 할당
	for (int l = 0; l < row1; l++) {				// a배열의 세로 크기만큼 반복
		c[l] = (int*)malloc(sizeof(int) * column2);	// 동적 메모리 할당
	}
	for (int i = 0; i < row1; i++)					// a배열의 세로 크기만큼 반복
		for (int j = 0; j < column2; j++) {			// b배열의 가로 크기만큼 반복
			c[i][j] = 0;							// 2차원 배열 초기화
			for (int k = 0; k < column1; k++) {		// a배열의 가로 크기만큼 반복
				c[i][j] += a[i][k] * b[k][j];		// 행렬의 곱 계산
			}
		}
	printer(row1, column2, c);						// 행렬의 곱의 결과를 출력하는 함수 선언
}

void printer(int row1, int column2, int** c) {		// 행렬의 곱의 결과를 출력하는 함수 정의
	for (int i = 0; i < row1; i++) {				// a배열의 세로 크기만큼 반복
		for (int j = 0; j < column2; j++)			// b배열의 가로 크기만큼 반복
			printf("%d ", c[i][j]);					// 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
		printf("\n");								// 줄바꿈
	}
	for (int l = 0; l < row1; l++)					// a배열의 세로 크기만큼 반복
		free(c[l]);									// 2차원 배열의 가로 공간 메모리 해제
	free(c);										// 2차원 배열의 세로 공간 메모리 해제
}
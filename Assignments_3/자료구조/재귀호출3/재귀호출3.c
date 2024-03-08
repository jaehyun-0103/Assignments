#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillArray(char**, int, int, int, int);
void printArray(char**, int, int);

int main() {
	// 사용자로부터 입력 파일명 받기
	char filename[100];
	printf("Enter the name of data file : ");
	scanf("%s", filename);

	// 파일에서 2차원 배열 읽어오기
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("파일 열기 실패\n");
		return 1;
	}

	// 배열 크기 결정
	int rows = 0, cols = 0;
	char ch;
	while ((ch = fgetc(file)) != EOF) {
		if (ch == '\n') {
			rows++;
		}
		else if (rows == 0 && ch != ' ') {
			cols++;
		}
	}
	rewind(file);
	rows++;

	// 동적 메모리 할당을 통한 배열 생성 및 초기화
	char** arr = (char**)malloc(rows * sizeof(char*));
	for (int i = 0; i < rows; i++) {
		arr[i] = (char*)malloc(cols * sizeof(char));
		for (int j = 0; j < cols; j++) {
			fscanf(file, " %c", &arr[i][j]);
		}
	}
	fclose(file);

	// 사용자로부터 (행, 열) 입력 받기
	int row, col;
	char showSteps[4];
	char input[4];

	do {
		printf("Enter the row number : ");
		scanf("%d", &row);
		printf("Enter the column number : ");
		scanf("%d", &col);

		// 단계 출력 여부 확인
		printf("Do you want to print out step by step? <yes/no> ");
		scanf("%s", showSteps);

		if (strcmp(showSteps, "yes") == 0) {
			// 배열 초기 상태 출력
			printf("\n초기 배열:\n");
			printArray(arr, rows, cols);
			printf("\n");
		}

		fillArray(arr, row, col, rows, cols, showSteps); // 단계 출력 여부를 전달

		// 중간 배열 출력
		printf("\nYour result is\n");
		printArray(arr, rows, cols);
		printf("\n");

		printf("Go again? <yes/no> ");
		scanf("%s", input);

	} while (strcmp(input, "yes") == 0 && strcmp(input, "no") != 0);

	// 최종 배열 출력
	printf("\nYour final result is\n");
	printArray(arr, rows, cols);

	// 동적 메모리 해제
	for (int i = 0; i < rows; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}

// 재귀적으로 배열을 채우는 함수
void fillArray(char** arr, int row, int col, int rows, int cols, int showSteps) {
	// 범위를 벗어나면 종료
	if (row < 0 || row >= rows || col < 0 || col >= cols) {
		return;
	}

	// 현재 위치의 값이 '-'인 경우 '@'로 변경
	if (arr[row][col] == '-') {
		arr[row][col] = '@';

		if (strcmp(showSteps, "yes") == 0) {
			// 단계 출력
			printf("====================================\n");
			printArray(arr, rows, cols);
		}

		// 재귀호출
		fillArray(arr, row - 1, col, rows, cols, showSteps); // 상
		fillArray(arr, row, col - 1, rows, cols, showSteps); // 좌
		fillArray(arr, row, col + 1, rows, cols, showSteps); // 우
		fillArray(arr, row + 1, col, rows, cols, showSteps); // 하
	}
}

// 배열 출력
void printArray(char** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
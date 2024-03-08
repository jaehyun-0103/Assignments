#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillArray(char**, int, int, int, int);
void printArray(char**, int, int);

int main() {
	// ����ڷκ��� �Է� ���ϸ� �ޱ�
	char filename[100];
	printf("Enter the name of data file : ");
	scanf("%s", filename);

	// ���Ͽ��� 2���� �迭 �о����
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("���� ���� ����\n");
		return 1;
	}

	// �迭 ũ�� ����
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

	// ���� �޸� �Ҵ��� ���� �迭 ���� �� �ʱ�ȭ
	char** arr = (char**)malloc(rows * sizeof(char*));
	for (int i = 0; i < rows; i++) {
		arr[i] = (char*)malloc(cols * sizeof(char));
		for (int j = 0; j < cols; j++) {
			fscanf(file, " %c", &arr[i][j]);
		}
	}
	fclose(file);

	// ����ڷκ��� (��, ��) �Է� �ޱ�
	int row, col;
	char showSteps[4];
	char input[4];

	do {
		printf("Enter the row number : ");
		scanf("%d", &row);
		printf("Enter the column number : ");
		scanf("%d", &col);

		// �ܰ� ��� ���� Ȯ��
		printf("Do you want to print out step by step? <yes/no> ");
		scanf("%s", showSteps);

		if (strcmp(showSteps, "yes") == 0) {
			// �迭 �ʱ� ���� ���
			printf("\n�ʱ� �迭:\n");
			printArray(arr, rows, cols);
			printf("\n");
		}

		fillArray(arr, row, col, rows, cols, showSteps); // �ܰ� ��� ���θ� ����

		// �߰� �迭 ���
		printf("\nYour result is\n");
		printArray(arr, rows, cols);
		printf("\n");

		printf("Go again? <yes/no> ");
		scanf("%s", input);

	} while (strcmp(input, "yes") == 0 && strcmp(input, "no") != 0);

	// ���� �迭 ���
	printf("\nYour final result is\n");
	printArray(arr, rows, cols);

	// ���� �޸� ����
	for (int i = 0; i < rows; i++) {
		free(arr[i]);
	}
	free(arr);

	return 0;
}

// ��������� �迭�� ä��� �Լ�
void fillArray(char** arr, int row, int col, int rows, int cols, int showSteps) {
	// ������ ����� ����
	if (row < 0 || row >= rows || col < 0 || col >= cols) {
		return;
	}

	// ���� ��ġ�� ���� '-'�� ��� '@'�� ����
	if (arr[row][col] == '-') {
		arr[row][col] = '@';

		if (strcmp(showSteps, "yes") == 0) {
			// �ܰ� ���
			printf("====================================\n");
			printArray(arr, rows, cols);
		}

		// ���ȣ��
		fillArray(arr, row - 1, col, rows, cols, showSteps); // ��
		fillArray(arr, row, col - 1, rows, cols, showSteps); // ��
		fillArray(arr, row, col + 1, rows, cols, showSteps); // ��
		fillArray(arr, row + 1, col, rows, cols, showSteps); // ��
	}
}

// �迭 ���
void printArray(char** arr, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}
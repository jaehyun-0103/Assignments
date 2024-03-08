#define _CRT_SECURE_NO_WARNINGS						// ���� ���� ���� ������ ���� ����
#include<stdio.h>
void  calculator(int, int, int, int, int);			// ����� ���� ����ϴ� �Լ� ����
void printer(int, int, int);						// ����� ���� ����� ����ϴ� �Լ� ����

int main() {
	int row1, row2, column1, column2;				// ���Ͽ��� ���� �� ����� ��� ���� ������ ����
	FILE* fp;
	fp = fopen("Array.txt", "r");					// Array.txt ������ �б� ���
	if (fp == NULL) {								// ���� ���⿡ �����ϸ�
		printf("������ ã�� ���߽��ϴ�.\n");		// "������ ã�� ���߽��ϴ�."�� ���
		exit(1);									// �����޼��� ����
	}

	fscanf(fp, "%d %d %d %d", &row1, &column1, &row2, &column2);	// ������ �����Ͽ� ���Ͽ��� �б�

	int** a = (int**)malloc(sizeof(int*) * row1);	// ���� �����Ϳ� ���� �޸� �Ҵ�
	for (int n = 0; n < row1; n++)					// a�迭�� ���� ũ�⸸ŭ �ݺ�
		a[n] = (int*)malloc(sizeof(int) * column1);	// ���� �޸� �Ҵ�

	int** b = (int**)malloc(sizeof(int*) * row2);	// ���� �����Ϳ� ���� �޸� �Ҵ�
	for (int m = 0; m < row2; m++)					// b�迭�� ���� ũ�⸸ŭ �ݺ�
		b[m] = (int*)malloc(sizeof(int) * column2);	// ���� �޸� �Ҵ�

	for (int i = 0; i < row1; i++)					// a�迭�� ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < column1; j++)			// a�迭�� ���� ũ�⸸ŭ �ݺ�
			fscanf(fp, "%d", &a[i][j]);				// ��� ���� ���Ͽ��� �б�

	for (int i = 0; i < row2; i++)					// b�迭�� ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < column2; j++)			// b�迭�� ���� ũ�⸸ŭ �ݺ�
			fscanf(fp, "%d", &b[i][j]);				// ��� ���� ���Ͽ��� �б�

	calculator(row1, column1, row2, column2, a, b);	// ����� ���� ����ϴ� �Լ� ȣ��

	for (int n = 0; n < row1; n++)					// a�迭�� ���� ũ�⸸ŭ �ݺ�
		free(a[n]);									// 2���� �迭�� ���� ���� �޸� ����
	free(a);										// 2���� �迭�� ���� ���� �޸� ����

	for (int m = 0; m < row1; m++)					// a�迭�� ���� ũ�⸸ŭ �ݺ�
		free(b[m]);									// 2���� �迭�� ���� ���� �޸� ����
	free(b);										// 2���� �迭�� ���� ���� �޸� ����

	fclose(fp);										// ���� ������ �ݱ�
}

void calculator(int row1, int column1, int row2, int column2, int** a, int** b) {	// ����� ���� ����ϴ� �Լ� ����
	int** c = (int**)malloc(sizeof(int*) * row1);	// ���� �����Ϳ� ���� �޸� �Ҵ�
	for (int l = 0; l < row1; l++) {				// a�迭�� ���� ũ�⸸ŭ �ݺ�
		c[l] = (int*)malloc(sizeof(int) * column2);	// ���� �޸� �Ҵ�
	}
	for (int i = 0; i < row1; i++)					// a�迭�� ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < column2; j++) {			// b�迭�� ���� ũ�⸸ŭ �ݺ�
			c[i][j] = 0;							// 2���� �迭 �ʱ�ȭ
			for (int k = 0; k < column1; k++) {		// a�迭�� ���� ũ�⸸ŭ �ݺ�
				c[i][j] += a[i][k] * b[k][j];		// ����� �� ���
			}
		}
	printer(row1, column2, c);						// ����� ���� ����� ����ϴ� �Լ� ����
}

void printer(int row1, int column2, int** c) {		// ����� ���� ����� ����ϴ� �Լ� ����
	for (int i = 0; i < row1; i++) {				// a�迭�� ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < column2; j++)			// b�迭�� ���� ũ�⸸ŭ �ݺ�
			printf("%d ", c[i][j]);					// 2���� �迭�� �ε����� �ݺ����� ���� i, j�� ����
		printf("\n");								// �ٹٲ�
	}
	for (int l = 0; l < row1; l++)					// a�迭�� ���� ũ�⸸ŭ �ݺ�
		free(c[l]);									// 2���� �迭�� ���� ���� �޸� ����
	free(c);										// 2���� �迭�� ���� ���� �޸� ����
}
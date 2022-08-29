#define _CRT_SECURE_NO_WARNINGS	// ���� ���� ���� ������ ���� ����
#include <stdio.h>				// fopen, fscanf, fclose �Լ��� ����� ��� ����
#include <stdlib.h>				// atoi �Լ��� ����� �������
#include <string.h>				// strlen �Լ��� ����� �������
#include<math.h>				// round �Լ��� ����� �������

typedef struct {	// ����ü �̸��� ���� �͸� ����ü
	int r, g, b;	// �ڷ��� ����̸� r, g, b
}RGB;				// ����ü ��Ī

void* fileName();												// ���� �̸��� �Է¹޴� �Լ�
void extractRC(char*, int*, int*);								// ���ϸ��� ��� ���� �ް� ����ó���� �ϴ� �Լ�
void errorCheck(int, int, float**, int);						// ����ó���� �ϴ� �Լ�
void findMaxMin(int, int, int*, int*, float**);					// �ּҰ��� �ִ밪�� ã�� ���� �Լ�
void loadGreyscale(int, int, int, int, float**, int**, RGB**);	// �������� ����̹��� ������ ��ȯ��Ű�� ���μ����� ���� �Լ�
void outImage(int, int, char*, RGB**);							// PPM �������� output ������ ����� �Լ�


int main() {
	FILE* fIn = NULL;			// ���� ������ ����� �ʱ�ȭ
	char* filename;				// ���ϸ��� ������ ������ ����
	int row = 0, column = 0;	// �Էµ������� ��� ���� ������ ���� ����� �ʱ�ȭ
	int max, min;				// �Էµ� �����Ϳ��� ã�� �ּҰ��� �ִ밪�� ������ ������ ����
	int num = 0;				// �Է¹��� ������ ���� ����ϱ� ���� �ʿ��� ������ ����� �ʱ�ȭ

	filename = fileName();		// fileName()�� ��ȯ���� filename�� ����
	
	extractRC(filename, &row, &column);	// ���ϸ��� ��� ���� �ް� ����ó���� �ϴ� �Լ� ȣ��

	fIn = fopen(filename, "rb");		// ������ ���̳ʸ� �б���� ����
	if (fIn == NULL) {											// ������ ���� ���ߴٸ�
		printf("Error : Unable to open file <%s>\n", filename);	// ���� �޼��� ���
		exit(1);												// ���α׷� ����
	}
	
	float** iArray = (float**)malloc(sizeof(float*) * row);	// ���� �޸� �Ҵ�(�迭�� ����)
	for (int a = 0; a < row; a++)							// ���� ũ�⸸ŭ �ݺ�
		iArray[a] = (float*)malloc(sizeof(float) * column);	// ���� �޸� �Ҵ�(�迭�� ����)
	int** oArray = (int**)malloc(sizeof(int*) * row);		// ���� �޸� �Ҵ�(�迭�� ����)
	for (int b = 0; b < row; b++)							// ���� ũ�⸸ŭ �ݺ�
		oArray[b] = (int*)malloc(sizeof(int) * column);		// ���� �޸� �Ҵ�(�迭�� ����)
	RGB** img = (int**)malloc(sizeof(RGB) * row);			// ���� �޸� �Ҵ�(�迭�� ����), ����ü ��Ī RGB�� ���� ����
	for (int c = 0; c < row; c++)							// ���� ũ�⸸ŭ �ݺ�
		img[c] = (int*)malloc(sizeof(RGB) * column);		// ���� �޸� �Ҵ�(�迭�� ����)

	for (int i = 0; i < row; i++)					// ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < column; j++) {			// ���� ũ�⸸ŭ �ݺ�
			fscanf(fIn, "%f ", &iArray[i][j]);		// ���Ͽ��� �Ǽ��� �о� 2���� �迭 iArray�� ����	
			num++;									// �Է¹��� ������ ���� ���� ���� 1 ����
													// ���� �ȿ� �����Ͱ� row * column���� �������� Ȯ���ϱ� ���� �ʿ�
			if (feof(fIn) == 1)						// ������ ���̶��
				break;								// �ݺ��� ����
		}
	if (feof(fIn) == 0)			// ���� �ݺ����� ���� �Ŀ��� ���� ������ ���� �ƴ϶��
		num++;					// �Է¹��� ������ ���� ���� ���� 1 ����
								// ���� �ȿ� �����Ͱ� row * column���� Ŭ���� Ȯ���ϱ� ���� �ʿ�

	errorCheck(row, column, iArray, num);						// ����ó���� �ϴ� �Լ� ȣ��
	findMaxMin(row, column, &max, &min, iArray);				// �ּҰ��� �ִ밪�� ã�� ���� �Լ� ȣ��
	loadGreyscale(row, column, max, min, iArray, oArray, img);	// �������� ����̹��� ������ ��ȯ��Ű�� ���μ����� ���� �Լ� ȣ��
	outImage(row, column, filename, img);						// PPM �������� output ������ ����� �Լ� ȣ��

	fclose(fIn);				// ���� ������ �ݱ�
}

// ���ϰ� : ���ϸ�
void* fileName() {
	char* filename = malloc(sizeof(char) * 100);	// ���ϸ��� ������ ���� �����Ҵ�
	printf("1. map-input-87-189.dat\n");	// ���ϸ� ���
	printf("2. map-input-100-100.dat\n");	// ���ϸ� ���
	printf("3. map-input-480-480.dat\n");	// ���ϸ� ���
	printf("4. map-input-844-480.dat\n");	// ���ϸ� ���
	printf("���� ���� ���ϸ��� ���ÿ�: \n");
	scanf("%s", filename);	// ���� �̸� �Է�
	return filename;		// ���ϸ� ��ȯ
	free(filename);			// �����Ҵ� �޸� ����
}

// �Ű����� : ���ϸ�, ��, ��
void extractRC(char* filename, int* row, int* column) {
	int cntC = 0, cntR = 0;		// ���ϸ��� ��� ���� �Է¹ޱ� ���� '-' ������ ���� ����
	int len; 					// ���ڿ��� ���̸� ������ ���� ����

	len = strlen(filename);				// �Է��� ���ϸ��� ���ڿ� ���� ����

	for (int i = 0; i < len; i++) {		// ���ϸ��� ���ڿ� ���̸�ŭ �ݺ�
		if (filename[i] == '-') {		// ���� '-' ���ڸ� �����ٸ�
			cntC++;						// cntC 1 ����
			if (cntC == 2)				// ���� cntC�� 2���
				*column = atoi(&filename[i + 1]);
			// �� ���� �ε������� �ٽ� ���ĺ��̳� Ư�����ڸ� ������ �������� ���ڿ��� ������ �ٲ� �� ������ ����
		}
	}
	for (int j = 0; j < len; j++) {		// ���ϸ��� ���ڿ� ���̸�ŭ �ݺ�
		if (filename[j] == '-') {		// ���� '-' ���ڸ� �����ٸ�
			cntR++;						// cntR 1 ����
			if (cntR == 3)				// ���� cntC�� 3�̶��
				*row = atoi(&filename[j + 1]);
			// �� ���� �ε������� �ٽ� ���ĺ��̳� Ư�����ڸ� ������ �������� ���ڿ��� ������ �ٲ� �� ������ ����
		}
	}
	if (*row == NULL || *column == NULL) {						// �� ���� NULL�̰ų� �� ���� NULL�̶��
		printf("Error : Problem reading in rows and columns");	// ���� �޼��� ���
		exit(1);												// ���α׷� ����
	}
}

// �Ű����� : ��, ��, �Է¹��� 2���� �迭, �Է¹��� ���� ����
void errorCheck(int row, int column, float** iArray, int num) {
	for (int m = 0; m < row; m++)							// ���� ũ�⸸ŭ �ݺ�
		for (int n = 0; n < column; n++)					// ���� ũ�⸸ŭ �ݺ�
			if (iArray[m][n] - (int)iArray[m][n] != 0) {	// ����ȯ�� ���� �Էµ� �����Ͱ� ������ �ƴ϶��
				printf("Error : Read a non-integer value");	// ���� �޼��� ���
				exit(1);									// ���α׷� ����
			}
	if (num < row * column) {					// �Է¹��� ������ ���ٸ�
		printf("Error : End of file reached prior to getting all the required data");	// ���� �޼��� ���
		exit(1);								// ���α׷� ����
	}
	if (num > row * column) {					// �Է¹��� ������ ���ٸ�
		printf("Error : Too many data points");	// ���� �޼��� ���
		exit(1);								// ���α׷� ����
	}
}

// �Ű����� : ��, ��, �ִ밪, �ּҰ�, �Է¹��� 2���� �迭
void findMaxMin(int row, int column, int* max, int* min, float** iArray) {
	*max = iArray[0][0];					// �ִ밪 �ʱ�ȭ
	*min = iArray[0][0];					// �ּҰ� �ʱ�ȭ
	for (int i = 0; i < row; i++)			// ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < column; j++)	// ���� ũ�⸸ŭ �ݺ�
			if (iArray[i][j] >= *max) 		// 2���� �迭�� ���� max���� ũ�ų� ���ٸ�
				*max = iArray[i][j];		// �� ���� max

	for (int i = 0; i < row; i++)			// ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < column; j++)	// ���� ũ�⸸ŭ �ݺ�
			if (iArray[i][j] <= *min) 		// 2���� �迭�� ���� min���� �۰ų� ���ٸ�
				*min = iArray[i][j];		// �� ���� min
}

// �Ű����� : ��, ��, �ִ밪, �ּҰ�, �Է¹��� 2���� �迭, ����� ���� ������ 2���� �迭, ����ü ���� ������
void loadGreyscale(int row, int column, int maximumElevation, int minimumElevation, float** iArray, int** oArray, RGB** img) {
	for (int i = 0; i < row; i++) {			// ���� ũ�⸸ŭ �ݺ�
		printf("\n");						// �ٹٲ� ���
		for (int j = 0; j < column; j++) {	// ���� ũ�⸸ŭ �ݺ�
			float elevation = iArray[i][j];	// 2���� �迭�� ���� �Ǽ����� elevation ������ ����
			float result = ((elevation - minimumElevation) * 255) / (maximumElevation - minimumElevation);
			// ��� ����� ���� ������ ������ �Ǽ��� ���
			oArray[i][j] = round(result);	// ����� ���� ���� �ٻ��� ������ ��ȯ 
		}
	}
	for (int i = 0; i < row; i++)			// ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < column; j++) {	// ���� ũ�⸸ŭ �ݺ�
			img[i][j].r = oArray[i][j];		// ��� ����� ���� ����� ���� r ��� ������ ����
			img[i][j].g = oArray[i][j];		// ��� ����� ���� ����� ���� g ��� ������ ����
			img[i][j].b = oArray[i][j];		// ��� ����� ���� ����� ���� b ��� ������ ����
		}
	for (int a = 0; a < row; a++)	// ���� ũ�⸸ŭ �ݺ�
		free(iArray[a]);			// 2���� �迭�� ���� ���� �޸� ����
	free(iArray);					// 2���� �迭�� ���� ���� �޸� ����
	for (int b = 0; b < row; b++)	// ���� ũ�⸸ŭ �ݺ�
		free(oArray[b]);			// 2���� �迭�� ���� ���� �޸� ����
	free(oArray);					// 2���� �迭�� ���� ���� �޸� ����
}

// �Ű����� : ��, ��, ���ϸ�, ����ü ���� ������
void outImage(int row, int column, char* filename, RGB** img) {
	strcat(filename, ".ppm");			// ������ ���ϸ� ���� .ppm ���̱�
	FILE* fOut = fopen(filename, "w");	// ���� �����͸� ����� ���ÿ� ������ ���� ���� ����

	if (fOut == NULL) {					// ������ ���� ���ߴٸ�
		printf("Error : Unable to write file <%s>\n", filename);	// ���� �޼��� ���
		exit(1);						// ���α׷� ����
	}

	fprintf(fOut, "P3\n%d %d\n%d", column, row, 255);	// ppm ������ ����� ���� ���

	for (int i = 0; i < row; i++) {						// ���� ũ�⸸ŭ �ݺ�
		fprintf(fOut, "\n");							// �ٹٲ� ���
		for (int j = 0; j < column; j++) {				// ���� ũ�⸸ŭ �ݺ�
			fprintf(fOut, "%d %d %d ", img[i][j].r, img[i][j].g, img[i][j].b);	// r, g, b ���� ��� ���� ���
		}
	}
	for (int c = 0; c < row; c++)	// ���� ũ�⸸ŭ �ݺ�
		free(img[c]);				// 2���� �迭�� ���� ���� �޸� ����
	free(img);						// 2���� �迭�� ���� ���� �޸� ����

	fclose(fOut);					// ���� ������ �ݱ�
}
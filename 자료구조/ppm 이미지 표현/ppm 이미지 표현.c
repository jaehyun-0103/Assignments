#define _CRT_SECURE_NO_WARNINGS	// 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>				// fopen, fscanf, fclose 함수가 선언된 헤더 파일
#include <stdlib.h>				// atoi 함수가 선언된 헤더파일
#include <string.h>				// strlen 함수가 선언된 헤더파일
#include<math.h>				// round 함수가 선언된 헤더파일

typedef struct {	// 구조체 이름이 없는 익명 구조체
	int r, g, b;	// 자료형 멤버이름 r, g, b
}RGB;				// 구조체 별칭

void* fileName();												// 파일 이름을 입력받는 함수
void extractRC(char*, int*, int*);								// 파일명에서 행과 열을 받고 예외처리를 하는 함수
void errorCheck(int, int, float**, int);						// 예외처리를 하는 함수
void findMaxMin(int, int, int*, int*, float**);					// 최소값과 최대값을 찾기 위한 함수
void loadGreyscale(int, int, int, int, float**, int**, RGB**);	// 고도값에서 흑백이미지 값으로 변환시키는 프로세스에 대한 함수
void outImage(int, int, char*, RGB**);							// PPM 형식으로 output 파일을 만드는 함수


int main() {
	FILE* fIn = NULL;			// 파일 포인터 선언과 초기화
	char* filename;				// 파일명을 저장할 포인터 선언
	int row = 0, column = 0;	// 입력데이터인 행과 열을 저장할 변수 선언과 초기화
	int max, min;				// 입력된 데이터에서 찾은 최소값과 최대값을 저장할 변수를 선언
	int num = 0;				// 입력받은 정수의 수를 계산하기 위해 필요한 변수를 선언과 초기화

	filename = fileName();		// fileName()의 반환값을 filename에 저장
	
	extractRC(filename, &row, &column);	// 파일명에서 행과 열을 받고 예외처리를 하는 함수 호출

	fIn = fopen(filename, "rb");		// 파일을 바이너리 읽기모드로 열기
	if (fIn == NULL) {											// 파일을 읽지 못했다면
		printf("Error : Unable to open file <%s>\n", filename);	// 오류 메세지 출력
		exit(1);												// 프로그램 종료
	}
	
	float** iArray = (float**)malloc(sizeof(float*) * row);	// 동적 메모리 할당(배열의 세로)
	for (int a = 0; a < row; a++)							// 세로 크기만큼 반복
		iArray[a] = (float*)malloc(sizeof(float) * column);	// 동적 메모리 할당(배열의 가로)
	int** oArray = (int**)malloc(sizeof(int*) * row);		// 동적 메모리 할당(배열의 세로)
	for (int b = 0; b < row; b++)							// 세로 크기만큼 반복
		oArray[b] = (int*)malloc(sizeof(int) * column);		// 동적 메모리 할당(배열의 가로)
	RGB** img = (int**)malloc(sizeof(RGB) * row);			// 동적 메모리 할당(배열의 세로), 구조체 별칭 RGB로 변수 선언
	for (int c = 0; c < row; c++)							// 세로 크기만큼 반복
		img[c] = (int*)malloc(sizeof(RGB) * column);		// 동적 메모리 할당(배열의 가로)

	for (int i = 0; i < row; i++)					// 세로 크기만큼 반복
		for (int j = 0; j < column; j++) {			// 가로 크기만큼 반복
			fscanf(fIn, "%f ", &iArray[i][j]);		// 파일에서 실수를 읽어 2차원 배열 iArray에 저장	
			num++;									// 입력받은 정수의 수를 세는 변수 1 증가
													// 파일 안에 데이터가 row * column보다 작을때를 확인하기 위해 필요
			if (feof(fIn) == 1)						// 파일의 끝이라면
				break;								// 반복문 종료
		}
	if (feof(fIn) == 0)			// 위의 반복문이 끝난 후에도 만약 파일의 끝이 아니라면
		num++;					// 입력받은 정수의 수를 세는 변수 1 증가
								// 파일 안에 데이터가 row * column보다 클때를 확인하기 위해 필요

	errorCheck(row, column, iArray, num);						// 예외처리를 하는 함수 호출
	findMaxMin(row, column, &max, &min, iArray);				// 최소값과 최대값을 찾기 위한 함수 호출
	loadGreyscale(row, column, max, min, iArray, oArray, img);	// 고도값에서 흑백이미지 값으로 변환시키는 프로세스에 대한 함수 호출
	outImage(row, column, filename, img);						// PPM 형식으로 output 파일을 만드는 함수 호출

	fclose(fIn);				// 파일 포인터 닫기
}

// 리턴값 : 파일명
void* fileName() {
	char* filename = malloc(sizeof(char) * 100);	// 파일명을 저장할 변수 동적할당
	printf("1. map-input-87-189.dat\n");	// 파일명 출력
	printf("2. map-input-100-100.dat\n");	// 파일명 출력
	printf("3. map-input-480-480.dat\n");	// 파일명 출력
	printf("4. map-input-844-480.dat\n");	// 파일명 출력
	printf("열고 싶은 파일명을 쓰시오: \n");
	scanf("%s", filename);	// 파일 이름 입력
	return filename;		// 파일명 반환
	free(filename);			// 동적할당 메모리 해제
}

// 매개변수 : 파일명, 행, 열
void extractRC(char* filename, int* row, int* column) {
	int cntC = 0, cntR = 0;		// 파일명에서 행과 열을 입력받기 위해 '-' 개수를 세는 변수
	int len; 					// 문자열의 길이를 저장할 변수 선언

	len = strlen(filename);				// 입력한 파일명의 문자열 길이 저장

	for (int i = 0; i < len; i++) {		// 파일명의 문자열 길이만큼 반복
		if (filename[i] == '-') {		// 만약 '-' 문자를 만났다면
			cntC++;						// cntC 1 증가
			if (cntC == 2)				// 만약 cntC가 2라면
				*column = atoi(&filename[i + 1]);
			// 그 다음 인덱스부터 다시 알파벳이나 특수문자를 만나기 전까지의 문자열을 정수로 바꿔 열 변수에 저장
		}
	}
	for (int j = 0; j < len; j++) {		// 파일명의 문자열 길이만큼 반복
		if (filename[j] == '-') {		// 만약 '-' 문자를 만났다면
			cntR++;						// cntR 1 증가
			if (cntR == 3)				// 만약 cntC가 3이라면
				*row = atoi(&filename[j + 1]);
			// 그 다음 인덱스부터 다시 알파벳이나 특수문자를 만나기 전까지의 문자열을 정수로 바꿔 행 변수에 저장
		}
	}
	if (*row == NULL || *column == NULL) {						// 행 값이 NULL이거나 열 값이 NULL이라면
		printf("Error : Problem reading in rows and columns");	// 오류 메세지 출력
		exit(1);												// 프로그램 종료
	}
}

// 매개변수 : 행, 열, 입력받은 2차원 배열, 입력받은 정수 개수
void errorCheck(int row, int column, float** iArray, int num) {
	for (int m = 0; m < row; m++)							// 세로 크기만큼 반복
		for (int n = 0; n < column; n++)					// 가로 크기만큼 반복
			if (iArray[m][n] - (int)iArray[m][n] != 0) {	// 형변환을 통해 입력된 데이터가 정수가 아니라면
				printf("Error : Read a non-integer value");	// 오류 메세지 출력
				exit(1);									// 프로그램 종료
			}
	if (num < row * column) {					// 입력받은 정수가 적다면
		printf("Error : End of file reached prior to getting all the required data");	// 오류 메세지 출력
		exit(1);								// 프로그램 종료
	}
	if (num > row * column) {					// 입력받은 정수가 많다면
		printf("Error : Too many data points");	// 오류 메세지 출력
		exit(1);								// 프로그램 종료
	}
}

// 매개변수 : 행, 열, 최대값, 최소값, 입력받은 2차원 배열
void findMaxMin(int row, int column, int* max, int* min, float** iArray) {
	*max = iArray[0][0];					// 최대값 초기화
	*min = iArray[0][0];					// 최소값 초기화
	for (int i = 0; i < row; i++)			// 세로 크기만큼 반복
		for (int j = 0; j < column; j++)	// 가로 크기만큼 반복
			if (iArray[i][j] >= *max) 		// 2차원 배열의 값이 max보다 크거나 같다면
				*max = iArray[i][j];		// 그 값이 max

	for (int i = 0; i < row; i++)			// 세로 크기만큼 반복
		for (int j = 0; j < column; j++)	// 가로 크기만큼 반복
			if (iArray[i][j] <= *min) 		// 2차원 배열의 값이 min보다 작거나 같다면
				*min = iArray[i][j];		// 그 값이 min
}

// 매개변수 : 행, 열, 최대값, 최소값, 입력받은 2차원 배열, 계산한 값을 저장할 2차원 배열, 구조체 이중 포인터
void loadGreyscale(int row, int column, int maximumElevation, int minimumElevation, float** iArray, int** oArray, RGB** img) {
	for (int i = 0; i < row; i++) {			// 세로 크기만큼 반복
		printf("\n");						// 줄바꿈 출력
		for (int j = 0; j < column; j++) {	// 가로 크기만큼 반복
			float elevation = iArray[i][j];	// 2차원 배열의 값을 실수형인 elevation 변수에 저장
			float result = ((elevation - minimumElevation) * 255) / (maximumElevation - minimumElevation);
			// 흑백 출력을 위한 공식을 적용해 실수로 계산
			oArray[i][j] = round(result);	// 계산한 값을 가장 근사한 정수로 변환 
		}
	}
	for (int i = 0; i < row; i++)			// 세로 크기만큼 반복
		for (int j = 0; j < column; j++) {	// 가로 크기만큼 반복
			img[i][j].r = oArray[i][j];		// 흑백 출력을 위해 계산한 값을 r 멤버 변수에 접근
			img[i][j].g = oArray[i][j];		// 흑백 출력을 위해 계산한 값을 g 멤버 변수에 접근
			img[i][j].b = oArray[i][j];		// 흑백 출력을 위해 계산한 값을 b 멤버 변수에 접근
		}
	for (int a = 0; a < row; a++)	// 세로 크기만큼 반복
		free(iArray[a]);			// 2차원 배열의 가로 공간 메모리 해제
	free(iArray);					// 2차원 배열의 세로 공간 메모리 해제
	for (int b = 0; b < row; b++)	// 세로 크기만큼 반복
		free(oArray[b]);			// 2차원 배열의 가로 공간 메모리 해제
	free(oArray);					// 2차원 배열의 세로 공간 메모리 해제
}

// 매개변수 : 행, 열, 파일명, 구조체 이중 포인터
void outImage(int row, int column, char* filename, RGB** img) {
	strcat(filename, ".ppm");			// 열었던 파일명 끝에 .ppm 붙이기
	FILE* fOut = fopen(filename, "w");	// 파일 포인터를 선언과 동시에 파일을 쓰기 모드로 열기

	if (fOut == NULL) {					// 파일을 쓰지 못했다면
		printf("Error : Unable to write file <%s>\n", filename);	// 오류 메세지 출력
		exit(1);						// 프로그램 종료
	}

	fprintf(fOut, "P3\n%d %d\n%d", column, row, 255);	// ppm 파일을 만드는 포멧 출력

	for (int i = 0; i < row; i++) {						// 세로 크기만큼 반복
		fprintf(fOut, "\n");							// 줄바꿈 출력
		for (int j = 0; j < column; j++) {				// 가로 크기만큼 반복
			fprintf(fOut, "%d %d %d ", img[i][j].r, img[i][j].g, img[i][j].b);	// r, g, b 각각 멤버 변수 출력
		}
	}
	for (int c = 0; c < row; c++)	// 세로 크기만큼 반복
		free(img[c]);				// 2차원 배열의 가로 공간 메모리 해제
	free(img);						// 2차원 배열의 세로 공간 메모리 해제

	fclose(fOut);					// 파일 포인터 닫기
}
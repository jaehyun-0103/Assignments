#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int row, column;				                // 행: 세로, 열: 가로
    printf("Enter row and column.\n");              // Enter row and column. 출력
    scanf_s("%d %d", &row, &column);                // 행과 열 입력
    printf("Enter the value of array elements.\n"); // Enter the value of array elements.출력
    int** arry = malloc(sizeof(int*) * row);        // 이중 포인터에 (int 포인터 크기 * row)만큼 동적 메모리 할당
    for (int i = 0; i < row; i++) {                 // 세로 크기만큼 반복
        arry[i] = malloc(sizeof(int) * column);     // (int의 크기 * col)만큼 동적 메모리 할당
    }
    for (int i = 0; i < row; i++) {                 // 세로 크기만큼 반복
        for (int j = 0; j < column; j++) {          // 가로 크기만큼 반복
            scanf_s("%d", &arry[i][j]);             // 각 요소 입력
        }
    }
    for (int i = 0; i < row; i++) {                 // 세로 크기만큼 반복
        for (int j = 0; j < column; j++) {          // 가로 크기만큼 반복
            arry[i][j] = arry[i][j] * arry[i][j];   // 2차원 배열의 각 요소를 제곱
        }
    }
    printf("The result is,\n");
    for (int i = 0; i < row; i++) {                 // 세로 크기만큼 반복
        for (int j = 0; j < column; j++) {          // 가로 크기만큼 반복
            printf("%d ", arry[i][j]);              // 2차원 배열의 인덱스에 반복문의 변수 i, j를 지정
        }
        printf("\n");                               // 가로 요소를 출력한 뒤 줄바꿈
    }
    for (int i = 0; i < row; i++) {                 // 세로 크기만큼 반복
        free(arry[i]);                              // 2차원 배열의 가로 공간 메모리 해제
    }
    free(arry);                                     // 2차원 배열의 세로 공간 메모리 해제
    system("pause");
    return 0;
}
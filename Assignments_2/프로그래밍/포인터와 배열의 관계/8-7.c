#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int row, column;				                // ��: ����, ��: ����
    printf("Enter row and column.\n");              // Enter row and column. ���
    scanf_s("%d %d", &row, &column);                // ��� �� �Է�
    printf("Enter the value of array elements.\n"); // Enter the value of array elements.���
    int** arry = malloc(sizeof(int*) * row);        // ���� �����Ϳ� (int ������ ũ�� * row)��ŭ ���� �޸� �Ҵ�
    for (int i = 0; i < row; i++) {                 // ���� ũ�⸸ŭ �ݺ�
        arry[i] = malloc(sizeof(int) * column);     // (int�� ũ�� * col)��ŭ ���� �޸� �Ҵ�
    }
    for (int i = 0; i < row; i++) {                 // ���� ũ�⸸ŭ �ݺ�
        for (int j = 0; j < column; j++) {          // ���� ũ�⸸ŭ �ݺ�
            scanf_s("%d", &arry[i][j]);             // �� ��� �Է�
        }
    }
    for (int i = 0; i < row; i++) {                 // ���� ũ�⸸ŭ �ݺ�
        for (int j = 0; j < column; j++) {          // ���� ũ�⸸ŭ �ݺ�
            arry[i][j] = arry[i][j] * arry[i][j];   // 2���� �迭�� �� ��Ҹ� ����
        }
    }
    printf("The result is,\n");
    for (int i = 0; i < row; i++) {                 // ���� ũ�⸸ŭ �ݺ�
        for (int j = 0; j < column; j++) {          // ���� ũ�⸸ŭ �ݺ�
            printf("%d ", arry[i][j]);              // 2���� �迭�� �ε����� �ݺ����� ���� i, j�� ����
        }
        printf("\n");                               // ���� ��Ҹ� ����� �� �ٹٲ�
    }
    for (int i = 0; i < row; i++) {                 // ���� ũ�⸸ŭ �ݺ�
        free(arry[i]);                              // 2���� �迭�� ���� ���� �޸� ����
    }
    free(arry);                                     // 2���� �迭�� ���� ���� �޸� ����
    system("pause");
    return 0;
}
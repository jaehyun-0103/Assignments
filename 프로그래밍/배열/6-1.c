#include<stdio.h>

int main(void) {
	int inputNum, i = 0;
	int ary[4];
	printf("Enter a decimal number.\n");
	scanf_s("%d", &inputNum);
	while (1) {	// ���� �ݺ�
		ary[i] = inputNum % 2;	// �Է��� 10������ 2�� ������ �������� �迭�� ����
		inputNum /= 2;
		i++;
		if (inputNum == 0) {	// ���� 0�̶��
			break;				// �ݺ��� ����
		}
	}
	for (i = 3; i >= 0; i--) {	// �迭�� �Ųٷ� ����
		printf("%d", ary[i]);
	}
	printf("\n");
	return 0;
}
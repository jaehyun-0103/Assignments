#include<stdio.h>

int main() {
	int num1, num2, num3, hap, bigNum;
	printf("3���� ������ ���ʷ� �Է� : ");
	scanf_s("%d %d %d", &num1, &num2, &num3);
	hap = num1 + num2 + num3;
	if (hap % 2 == 0) {			// ������ ������ ���� ¦�����
		if (num1 >= num2) {
			if (num1 >= num3)
				bigNum = num1;	// ���� ū ���� num1
			else
				bigNum = num3;	// ���� ū ���� num3
		}
		else {
			if (num2 >= num3)
				bigNum = num2;	// ���� ū ���� num2
			else
				bigNum = num3;	// ���� ū ���� num3
		}
		printf("�Է� ���� ������ ������ �� ���� ū���� : %d\n", bigNum);
	}
	else						// ������ ������ ���� Ȧ�����
		printf("�Է� ���� ������ �������� �� : %d\n", hap);
}
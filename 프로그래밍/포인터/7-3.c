#include<stdio.h>

void factorial(int n, int* p) {	// factorial() �Լ� ����
	if (n == 1)					// ���� n�� 1�̶��
		return;					// ��� ȣ�� ����
	*p = *p * n;
	factorial(n - 1, p);		// ��� ȣ��
}

int main(void) {
	int inputNum, result = 1;
	printf("Enter a natural number.\n");
	scanf_s("%d", &inputNum);
	factorial(inputNum, &result); // factorial() �Լ� ȣ��
	printf("%d factorial is %d.\n", inputNum, result);
	return 0;
}
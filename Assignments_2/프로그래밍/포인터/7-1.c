#include<stdio.h>

void add(const int a, const int b, int* p) {	// add() �Լ� ����
	*p = a + b;		// �Է��� ���� ����
}

int main(void) {
	int x, y, result;
	printf("Enter two integers.\n");
	scanf_s("%d %d", &x, &y);
	add(x, y, &result);					// add() �Լ� ȣ��
	printf("The sum is %d\n", result);
	return 0;
}
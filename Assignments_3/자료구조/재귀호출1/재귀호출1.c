#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int findsum(int);	// findsum() �Լ� ����

int main() {
	int num, x;
	printf("Enter a number: ");
	scanf("%d", &num);
	x = findsum(num);	// �Էµ� ������ �� �ڸ� ���� ���� ���� x�� ����
	printf("Sum of the digits of %d is: %d\n", num, x);
	return 0;
}

int findsum(int num) {	// findsum() �Լ� ����
	if (num == 0)		// num ������ 0�̶��
		return 0;		// ���α׷� ����
	else				// num ������ 0�� �ƴ϶��
		return(num % 10) + findsum(num / 10);	// ���ȣ��
}
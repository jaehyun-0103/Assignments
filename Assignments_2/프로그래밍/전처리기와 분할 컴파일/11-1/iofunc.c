#include<stdio.h>

extern int num1, num2;			// �ٸ� �ҽ� ���Ͽ� �ִ� �������� num1, num2 ���
extern char op;					// �ٸ� �ҽ� ���Ͽ� �ִ� �������� op ���

void myInput() {				// myInput() �Լ� ����
	printf("���ڿ� �����ڸ� �Է��Ͻÿ� : ");	// ���ڿ� �����ڸ� �Է��Ͻÿ� : ���
	scanf_s("%d %d %c", &num1, &num2, &op);		// �� ���� ���� num1, num2�� ������ �Է�
}

extern double result;			// �ٸ� �ҽ� ���Ͽ� �ִ� �������� result ���

double myOutput() {				// myOutput() �Լ� ����
	func();						// func() �Լ� ȣ��
	printf("%.2lf", result);	// �������� �Ҽ��� �� ��° �ڸ����� ���
}
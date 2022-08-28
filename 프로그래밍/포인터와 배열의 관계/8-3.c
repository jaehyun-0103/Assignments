#include<stdio.h>
#include<stdlib.h>

void reverse_array(int* a, int* b, int length);				// reverse_array() �Լ� ����

int main(void) {
	int original[10];										// ������ �迭
	int reverse[10];										// ������ �ٲ� �迭
	int num = 0;											// �迭�� ���� ����
	int length;												// ������ ������ ������ ������ ����
	int i = 0;												// �迭�� �ε���
	printf("Enter a sequence of positive integers.\n");
	while (1) {												// ���� �ݺ�
		scanf_s("%d ", &num);								// �迭�� ���� ���� �Է�
		if (num <= 0)										// ���ڰ� 0���� �۰ų� ������
			break;											// ����
		else												// ���ڰ� 0���� ũ��
			original[i++] = num;							// �迭�� �ε����� 1�� ����
		if (i == 9)											// �迭�� �ε����� 9�̸�
			break;											// ����
	}
	length = i;												// i�� ����
	reverse_array(original, reverse, length);				// reverse_array�Լ� ȣ��
	for (i = 0; i < length; i++) {
		printf("%d ", reverse[i]);
	}
	system("pause");
	return 0;
}
void reverse_array(int* a, int* b, int length) {			// reverse_array�Լ� ����
	for (int m = 0; m < length ; m++) {						// ��������� ���� ���� ����
		b[m] = a[length - m - 1];							// �������� ����									// �������� ������ �迭 ���
	}
}
#include<stdio.h>

int min, max;

void min_max(int a, int b, int c) {	// min_max() �Լ� ����
	min = a <= b ? a : b;			// a <= b�� ���̸� a�� min, �����̸� b�� min
	if (c <= min)					// c�� min���� �۴ٸ�
		min = c;					// c�� min
	max = a >= b ? a : b;			// a >= b�� ���̸� a�� max, �����̸� b�� max
	if (c >= max)					// c�� max���� ũ��
		max = c;					// c�� max
}

int main() {
	int a, b, c;
	printf("Enter three integers.\n");
	scanf_s("%d %d %d", &a, &b, &c);
	min_max(a, b, c);				// min_max() �Լ� ȣ��
	printf("min is %d, max is %d\n", min, max);
	return 0;
}
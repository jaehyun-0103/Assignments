#include<stdio.h>

int main(void) {
	int num;
	int* p;
	int** q;
	p = &num;				// num�� �ּҸ� ������ ������ ����
	q = &p;					// p�� �ּҸ� ���������� ������ ����
	*p = 5;					// p�� ����Ͽ� 5�� ����
	printf("%d\n", **q);	// 5 ���
	**q = 10;				// q�� ����Ͽ� 10�� ����
	printf("%d\n", *p);		// 10 ���
	return 0;
}
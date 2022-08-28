#include<stdio.h>

void cyclic_swap(int* a, int* b, int* c) {	// cyclic_swap() �Լ� ����
	int temp;
	temp = *a;
	*a = *c;	// c�� a�� ����
	*c = *b;	// b�� c�� ����
	*b = temp;	// a�� b�� ����
}

int main(void) {
	int x, y, z, result;
	printf("Enter three integers. a, b, c\n");
	scanf_s("%d %d %d", &x, &y, &z);
	printf("Before cyclic swap, a = %d, b = %d, c = %d.\n", x, y, z);
	cyclic_swap(&x, &y, &z);	// cyclic_swap() �Լ� ȣ��
	printf("After cyclic swap, a = %d, b = %d, c = %d.\n", x, y, z);
	return 0;
}
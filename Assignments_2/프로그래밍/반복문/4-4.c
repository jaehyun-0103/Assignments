#include<stdio.h>

int main() {
	int base = -1, power = -1, result = 1;
	printf("Enter base and power.\n");
	scanf_s("%d %d", &base, &power);
	for (int i = 0; i < power; i++) {	// �ι�°�� �Է��� ����ŭ �ݺ�
		result *= base;					// ù��°�� �Է��� ���� ����
	}
	printf("%d to the power of %d is %d\n", base, power, result);
	return 0;
}
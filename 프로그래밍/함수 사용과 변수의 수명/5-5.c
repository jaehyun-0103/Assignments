#include<stdio.h>

int power(int a, int b) {			// power() �Լ� ����
	if (b == 0)						// ���� b�� 0�̶��
		return 1;					// 1 ��ȯ
	else							// ���� b�� 0�� �ƴ϶��
		return a * power(a, b - 1);	// ��� ȣ��
}

int main() {
	int base, multiplier;
	printf("Enter base and multiplier\n");
	scanf_s("%d %d", &base, &multiplier);
	printf("%d to the power of %d is %d\n", base, multiplier, power(base, multiplier));	// power() �Լ� ȣ��
	printf("\n");
	return 0;
}


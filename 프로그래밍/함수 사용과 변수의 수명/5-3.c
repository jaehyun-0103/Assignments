#include<stdio.h>

int sum(int n) {		// sum() �Լ� ����
	if (n == 0)			// ���� n�� 0�̶��
		return 0;		// 0 ��ȯ
	else
		return n + sum(n + 1);	// ��� ȣ��
}

int main() {
	int num;
	do {
		printf("Enter n\n");
		scanf_s("%d", &num);
		if (num >= 0)	// ����� �Է��Ѵٸ�
			printf("Please enter it again.\n");
		else			// ������ �Է��Ѵٸ�
			break;		// �ݺ��� ����
	} while (1);		// ���� �ݺ�
	printf("The sum is %d.\n", sum(num));	// sum() �Լ� ȣ��
	return 0;
}
#include<stdio.h>

int current_min(int n) {	// current_min() �Լ� ����
	static int min = 100;	// ���� ���� min�� ����
	if (min > n)			// �Է��� ���� min���� �۴ٸ�
		min = n;			// �Է��� ���� min
	return min;				// min ��ȯ
}

int main(){
	int num;
	while (1) {
		printf("Enter a number.\n");
		scanf_s("%d", &num);
		if (num < 0)		// ������ �Է��ϸ�
			break;			// �ݺ��� ����
		printf("Current min is %d\n", current_min(num)); // current_min() �Լ� ȣ��
	}
	return 0;
}
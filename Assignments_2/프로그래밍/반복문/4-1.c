#include<stdio.h>

int main() {
	int cnt = 1, total = 0, maxNum = -1;
	do {
		printf("Enter a Mzximum number.\n");
		scanf_s("%d", &maxNum);
	} while (maxNum < 1);		// ���� ������ �Է��� ������ �ݺ�
	while (1) {
		total += cnt;
		if (total > maxNum)		// ���� �Է��� ������ ũ�ٸ�
			break;				// �ݺ��� ����
		else					// ���� �Է��� ������ �۰ų� ���ٸ�
			cnt++;				// cnt ���� 1 ����
	}
	printf("The sum from 1 to %d is %d\n", cnt - 1, total - cnt);
	return 0;
}
#include<stdio.h>

int main() {
	int cnt = 0, total = 0, maxNum = -1;
	do {
		printf("Enter a natural number.\n");
		scanf_s("%d", &maxNum);
	} while (maxNum < 1);		// ���� ������ �Է��� ������ �ݺ�
	while (cnt < maxNum) {		// cnt ������ �Է��� ������ ���� ����
		cnt++;					// cnt ���� 1 ����
		if (cnt % 5 == 0)		// ���� 5�� ������
			continue;			// �Ʒ� �ڵ带 �������� �ʰ� �ǳʶ�
		else					// 5�� ����� �ƴ϶��
			total += cnt;		// ����
	}
	printf("The sum is %d\n", total);
	return 0;
}
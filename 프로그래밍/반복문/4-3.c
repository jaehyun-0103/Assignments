#include<stdio.h>

int main() {
	int cnt = 0, total = 0, maxNum = -1;
	do {
		printf("Enter a natural number.\n");
		scanf_s("%d", &maxNum);
	} while (maxNum < 1);		// ���� ������ �Է��� ������ �ݺ�
	while (cnt < maxNum) {		// cnt ������ �Է��� ������ ���� ����
		cnt++;					// 1 ����
		if (maxNum % cnt == 0)	// ���� �Է��� ���� ������
			printf("%d ", cnt);
		if (maxNum / 2 == cnt)	// �Է��� ���� �����̶��
			break;				// �ݺ��� ����
	}
	printf("%d ", maxNum);
	return 0;
}
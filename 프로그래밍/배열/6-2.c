#include<stdio.h>

int main(void) {
	int vote[10], count[8] = { 0 };
	int i, max, winner;
	printf("Enter the result of voting.\n");
	for (i = 0; i < sizeof(vote) / sizeof(int); i++) {	// 10���� ��ǥ
		printf("%02d. ��ǥ�ϼ���.", i + 1);
		scanf_s("%d", &vote[i]);
	}
	for (i = 0; i < sizeof(vote) / sizeof(int); i++) {	// 10���� ��ǥ�� ��ǥ
		count[vote[i] - 1] += 1;
	}
	for (i = 0; i < sizeof(vote) / sizeof(int); i++) {	// ���� ���� ǥ�� ���� �ĺ��� ã��
		if (i == 0) {
			max = count[i];
			winner = i;
		}
		else if (max < count[i]) {
			max = count[i];
			winner = i;
		}
	}
	if (sizeof(vote) / sizeof(int) / 2 < max)	// ���ݼ� ��ǥ�� �����ߴٸ�
		printf("Number %d is the winner.\n", winner+1);
	else										// ���ݼ� ��ǥ�� �����ߴٸ�
		printf("No one is the winner.\n");
}
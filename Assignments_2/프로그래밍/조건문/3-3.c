#include<stdio.h>

int main(){
	int apple = 1000, grap = 3000, pear = 2000, mandarin = 500;
	int aNum, gNum, pNum, mNum, total, result, discount;
	printf("��� ���� : ");
	scanf_s("%d", &aNum);
	printf("���� ���� : ");
	scanf_s("%d", &gNum);
	printf("�� ���� : ");
	scanf_s("%d", &pNum);
	printf("�� ���� : ");
	scanf_s("%d", &mNum);

	total = apple * aNum + grap * gNum + pear * pNum + mandarin * mNum;
	if (gNum >= 3) {			// ������ 3���� �̻� ������ ���
		discount = total * 0.1;	// 10% ����
		result = total - discount;
		printf("�� ���� �ݾ� : %d - %d = %d", total, discount, result);
		return 0;
	}
	printf("�� ���� �ݾ� : %d\n", total);
	return 0;
}
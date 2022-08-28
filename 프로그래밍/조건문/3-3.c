#include<stdio.h>

int main(){
	int apple = 1000, grap = 3000, pear = 2000, mandarin = 500;
	int aNum, gNum, pNum, mNum, total, result, discount;
	printf("사과 개수 : ");
	scanf_s("%d", &aNum);
	printf("포도 개수 : ");
	scanf_s("%d", &gNum);
	printf("배 개수 : ");
	scanf_s("%d", &pNum);
	printf("귤 개수 : ");
	scanf_s("%d", &mNum);

	total = apple * aNum + grap * gNum + pear * pNum + mandarin * mNum;
	if (gNum >= 3) {			// 포도를 3송이 이상 구매할 경우
		discount = total * 0.1;	// 10% 할인
		result = total - discount;
		printf("총 결재 금액 : %d - %d = %d", total, discount, result);
		return 0;
	}
	printf("총 결재 금액 : %d\n", total);
	return 0;
}
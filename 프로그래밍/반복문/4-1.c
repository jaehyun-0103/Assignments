#include<stdio.h>

int main() {
	int cnt = 1, total = 0, maxNum = -1;
	do {
		printf("Enter a Mzximum number.\n");
		scanf_s("%d", &maxNum);
	} while (maxNum < 1);		// 양의 정수를 입력할 때까지 반복
	while (1) {
		total += cnt;
		if (total > maxNum)		// 합이 입력한 값보다 크다면
			break;				// 반복문 종료
		else					// 합이 입력한 값보다 작거나 같다면
			cnt++;				// cnt 변수 1 증가
	}
	printf("The sum from 1 to %d is %d\n", cnt - 1, total - cnt);
	return 0;
}
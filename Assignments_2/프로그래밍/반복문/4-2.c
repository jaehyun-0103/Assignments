#include<stdio.h>

int main() {
	int cnt = 0, total = 0, maxNum = -1;
	do {
		printf("Enter a natural number.\n");
		scanf_s("%d", &maxNum);
	} while (maxNum < 1);		// 양의 정수를 입력할 때까지 반복
	while (cnt < maxNum) {		// cnt 변수가 입력한 값보다 작은 동안
		cnt++;					// cnt 변수 1 증가
		if (cnt % 5 == 0)		// 만약 5의 배수라면
			continue;			// 아래 코드를 실행하지 않고 건너뜀
		else					// 5의 배수가 아니라면
			total += cnt;		// 더함
	}
	printf("The sum is %d\n", total);
	return 0;
}
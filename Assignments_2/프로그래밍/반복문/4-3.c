#include<stdio.h>

int main() {
	int cnt = 0, total = 0, maxNum = -1;
	do {
		printf("Enter a natural number.\n");
		scanf_s("%d", &maxNum);
	} while (maxNum < 1);		// 양의 정수를 입력할 때까지 반복
	while (cnt < maxNum) {		// cnt 변수가 입력한 값보다 작은 동안
		cnt++;					// 1 증가
		if (maxNum % cnt == 0)	// 만약 입력한 값의 약수라면
			printf("%d ", cnt);
		if (maxNum / 2 == cnt)	// 입력한 값의 절반이라면
			break;				// 반복문 종료
	}
	printf("%d ", maxNum);
	return 0;
}
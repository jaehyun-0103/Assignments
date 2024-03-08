#include<stdio.h>

int sum(int n) {		// sum() 함수 정의
	if (n == 0)			// 변수 n이 0이라면
		return 0;		// 0 반환
	else
		return n + sum(n + 1);	// 재귀 호출
}

int main() {
	int num;
	do {
		printf("Enter n\n");
		scanf_s("%d", &num);
		if (num >= 0)	// 양수를 입력한다면
			printf("Please enter it again.\n");
		else			// 음수를 입력한다면
			break;		// 반복문 종료
	} while (1);		// 무한 반복
	printf("The sum is %d.\n", sum(num));	// sum() 함수 호출
	return 0;
}
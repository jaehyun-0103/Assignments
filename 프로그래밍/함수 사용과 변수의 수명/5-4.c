#include<stdio.h>

int asterisk(int n) {		// asterisk() 함수 정의
	if (n > 0) {			// 변수 n이 0보다 크다면
		printf("%c", '*');	// * 출력
		asterisk(n - 1);	// 재귀 호출
	}
}

int main() {
	int num;
	do {
		printf("Enter n\n");
		scanf_s("%d", &num);
		if (num <= 0)	// 입력한 값이 양수가 아니라면
			printf("Please enter it again.\n");
		else			// 입력한 값이 양수라면
			break;		// 반복문 종료
	} while (1);		// 무한 반복
	asterisk(num);		// asterisk() 함수 호출
	printf("\n");
	return 0;
}
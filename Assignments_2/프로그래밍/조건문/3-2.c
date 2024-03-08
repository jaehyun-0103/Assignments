#include<stdio.h>

int main() {
	int inputNum = 0;
	while (1) {
		printf("양수 입력 : ");
		scanf_s("%d", &inputNum);
		if (inputNum < 0) {			// 입력한 값이 음수라면
			printf("양수를 입력하세요.\n");
			continue;				// 아래 코드를 실행하지 않고 건너뜀
		}
		if (inputNum == 0) {		// 입력한 값이 0이라면
			printf("프로그램 종료...");
			break;					// 반복문 종료
		}
		printf("%d\n", inputNum * inputNum);
	}
}
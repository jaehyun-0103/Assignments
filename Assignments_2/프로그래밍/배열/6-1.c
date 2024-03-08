#include<stdio.h>

int main(void) {
	int inputNum, i = 0;
	int ary[4];
	printf("Enter a decimal number.\n");
	scanf_s("%d", &inputNum);
	while (1) {	// 무한 반복
		ary[i] = inputNum % 2;	// 입력한 10진수를 2로 나누어 나머지를 배열에 저장
		inputNum /= 2;
		i++;
		if (inputNum == 0) {	// 몫이 0이라면
			break;				// 반복문 종료
		}
	}
	for (i = 3; i >= 0; i--) {	// 배열을 거꾸로 읽음
		printf("%d", ary[i]);
	}
	printf("\n");
	return 0;
}
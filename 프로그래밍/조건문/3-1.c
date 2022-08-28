#include<stdio.h>

int main() {
	int num;
	while (1) {	// 무한반복문
		printf("정수 입력 : ");
		scanf_s("%d", &num);
		if (num < 0)						// 입력한 값이 0보다 작다면
			printf("입력한 값은 0보다 작습니다.\n");
		else if (num >= 0 && 10 > num) {	// 입력한 값이 0이상 10미만이라면
			printf("입력한 값은 0이상 10미만입니다.\n");
			if (num == 0)					// 입력한 값이 0이라면
				break;
		}
		else if (20 > num)					// 입력한 값이 10이상 20미만이라면
			printf("입력한 값은 10이상 20미만입니다.\n");
		else if (30 > num)					// 입력한 값이 20이상 30미만이라면
			printf("입력한 값은 20이상 30미만입니다.\n");
		else								// 입력한 값이 30이상이라면
			printf("입력한 값은 30이상입니다.\n");
	}
}
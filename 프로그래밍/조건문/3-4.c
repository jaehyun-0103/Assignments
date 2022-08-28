#include<stdio.h>

int main() {
	int num1, num2, num3, hap, bigNum;
	printf("3개의 정수를 차례로 입력 : ");
	scanf_s("%d %d %d", &num1, &num2, &num3);
	hap = num1 + num2 + num3;
	if (hap % 2 == 0) {			// 세개의 정수의 합이 짝수라면
		if (num1 >= num2) {
			if (num1 >= num3)
				bigNum = num1;	// 가장 큰 수는 num1
			else
				bigNum = num3;	// 가장 큰 수는 num3
		}
		else {
			if (num2 >= num3)
				bigNum = num2;	// 가장 큰 수는 num2
			else
				bigNum = num3;	// 가장 큰 수는 num3
		}
		printf("입력 받은 세개의 정수들 중 가장 큰수는 : %d\n", bigNum);
	}
	else						// 세개의 정수의 합이 홀수라면
		printf("입력 받은 세개의 정수들의 합 : %d\n", hap);
}
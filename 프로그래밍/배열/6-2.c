#include<stdio.h>

int main(void) {
	int vote[10], count[8] = { 0 };
	int i, max, winner;
	printf("Enter the result of voting.\n");
	for (i = 0; i < sizeof(vote) / sizeof(int); i++) {	// 10명이 투표
		printf("%02d. 투표하세요.", i + 1);
		scanf_s("%d", &vote[i]);
	}
	for (i = 0; i < sizeof(vote) / sizeof(int); i++) {	// 10개의 투표지 개표
		count[vote[i] - 1] += 1;
	}
	for (i = 0; i < sizeof(vote) / sizeof(int); i++) {	// 가장 많은 표를 받은 후보를 찾음
		if (i == 0) {
			max = count[i];
			winner = i;
		}
		else if (max < count[i]) {
			max = count[i];
			winner = i;
		}
	}
	if (sizeof(vote) / sizeof(int) / 2 < max)	// 과반수 득표애 성공했다면
		printf("Number %d is the winner.\n", winner+1);
	else										// 과반수 득표애 실패했다면
		printf("No one is the winner.\n");
}
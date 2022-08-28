#include<stdio.h>

int current_min(int n) {	// current_min() 함수 정의
	static int min = 100;	// 정적 변수 min을 선언
	if (min > n)			// 입력한 값이 min보다 작다면
		min = n;			// 입력한 값이 min
	return min;				// min 반환
}

int main(){
	int num;
	while (1) {
		printf("Enter a number.\n");
		scanf_s("%d", &num);
		if (num < 0)		// 음수를 입력하면
			break;			// 반복문 종료
		printf("Current min is %d\n", current_min(num)); // current_min() 함수 호출
	}
	return 0;
}
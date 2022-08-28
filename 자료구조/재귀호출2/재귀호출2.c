#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int lcm(int, int);	// lcm() 함수 호출

int main() {
	int a, b, l;
	printf("Enter any two positive integers: ");
	scanf("%d%d", &a, &b);
	if (a > b)			// a가 b보다 크다면
		l = lcm(a, b);
	else				// b가 a보다 크거나 같다면
		l = lcm(b, a);
	printf("LCM of two integers is %d\n", l);
	return 0;
}

// 최소공배수를 구하는 함수
int lcm(int a, int b) {		// lcm() 함수 정의
	static int temp = 1;	// 정적변수 선언
	if (temp % a == 0 && temp % b == 0)	// tmp 변수가 a와 b의 최소공배수라면
		return temp;		// 최소공배수 반환
	else {					// tmp 변수가 a와 b의 최소공배수가 아니라면
		temp++;				// tmp 변수 1 증가
		lcm(a, b);			// 재귀호출
	}
}
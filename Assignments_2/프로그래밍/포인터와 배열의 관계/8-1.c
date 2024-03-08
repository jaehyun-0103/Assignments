#include<stdio.h>

int main(void) {
	int num;
	int* p;
	int** q;
	p = &num;				// num의 주소를 포인터 변수에 저장
	q = &p;					// p의 주소를 이중포인터 변수에 저장
	*p = 5;					// p를 사용하여 5를 저장
	printf("%d\n", **q);	// 5 출력
	**q = 10;				// q를 사용하여 10을 저장
	printf("%d\n", *p);		// 10 출력
	return 0;
}
#include<stdio.h>

void cyclic_swap(int* a, int* b, int* c) {	// cyclic_swap() 함수 정의
	int temp;
	temp = *a;
	*a = *c;	// c를 a로 스왑
	*c = *b;	// b를 c로 스왑
	*b = temp;	// a를 b로 스왑
}

int main(void) {
	int x, y, z, result;
	printf("Enter three integers. a, b, c\n");
	scanf_s("%d %d %d", &x, &y, &z);
	printf("Before cyclic swap, a = %d, b = %d, c = %d.\n", x, y, z);
	cyclic_swap(&x, &y, &z);	// cyclic_swap() 함수 호출
	printf("After cyclic swap, a = %d, b = %d, c = %d.\n", x, y, z);
	return 0;
}
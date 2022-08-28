#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
int lcm(int, int);	// lcm() �Լ� ȣ��

int main() {
	int a, b, l;
	printf("Enter any two positive integers: ");
	scanf("%d%d", &a, &b);
	if (a > b)			// a�� b���� ũ�ٸ�
		l = lcm(a, b);
	else				// b�� a���� ũ�ų� ���ٸ�
		l = lcm(b, a);
	printf("LCM of two integers is %d\n", l);
	return 0;
}

// �ּҰ������ ���ϴ� �Լ�
int lcm(int a, int b) {		// lcm() �Լ� ����
	static int temp = 1;	// �������� ����
	if (temp % a == 0 && temp % b == 0)	// tmp ������ a�� b�� �ּҰ�������
		return temp;		// �ּҰ���� ��ȯ
	else {					// tmp ������ a�� b�� �ּҰ������ �ƴ϶��
		temp++;				// tmp ���� 1 ����
		lcm(a, b);			// ���ȣ��
	}
}
#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat ���� ���� ���� ������ ���� ����
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void swap_string(str1, str2);		// swap_string() �Լ� ����

int main(void) {
	char str1[20] = "apple";		// str1 �迭�� ���ڿ� apple �Ҵ�
	char str2[20] = "banana";		// str2 �迭�� ���ڿ� banana �Ҵ�

	swap_string(str1, str2);		// swap_string�Լ� ȣ��
	printf("str1 : %s\n", str1);	// str1 ���
	printf("str2 : %s\n", str2);	// str2 ���
	system("pause");
	return 0;
}
void swap_string(char* a, char* b) {	// swap_string�Լ� ����
	char temp[20];						// �迭�� ������ temp �迭 ����
	strcpy(temp, a);					// a�迭�� temp�迭�� ����
	strcpy(a, b);						// b�迭�� a�迭�� ����
	strcpy(b, temp);					// temp�迭�� b�迭�� ����
}
#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat ���� ���� ���� ������ ���� ����
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char* my_strcpy(char* dest, const char* src, int index);		// my_strcpy() �Լ� ����

int main(void) {
	char dest[100];												// dest�迭 ����
	char src[100];												// src�迭 ����
	int index = 0;												// index������ 0���� �ʱ�ȭ
	printf("source : ");										// source : ���
	gets(src);													// gets�Լ��� �Է¹��� ���ڿ��� src�� ����
	while (1) {													// ���ѹݺ�
		if (strcmp(src, "quit") == 0) break;					// src�� quit�� ���ٸ� �ݺ��� ����
		my_strcpy(dest, src, index);							// my_strcpy�Լ� ȣ��

		printf("destination : ");								// destination : ���
		puts(dest);												// puts�Լ��� dest ���ڿ� ���
		printf("source : ");									// source : ���
		gets(src);												// gets�Լ��� �Է¹��� ���ڿ��� src�� ����
	}
	system("pause");
	return 0;
}
char* my_strcpy(char* dest, const char* src, int index) {		// my_strcpy�Լ� ����
	if (src[index] != '\0') {									// src�迭�� index��° �ε����� �ι��ڰ� �ƴ϶��
		++index;												// index���� 1�� ������ ��
		my_strcpy(dest, src, index);							// my_strcpy �Լ��� ���ȣ�� 
	}
	else {														// src�迭�� index��° �ε����� �ι��ڶ��
		for (int i = 0; i < index; i++) {						// i�� index���� ���������� i�� 1�� ����
			dest[i] = src[i];									// src �迭�� i��° �ε����� ���� dest �迭�� i��° �ε����� ���� ����
			dest[i + 1] = '\0';									// scr �迭�� dest �迭�� ������ �� ���� �ε����� ���� �ι��� ����
		}
		return dest[index];
	}
}
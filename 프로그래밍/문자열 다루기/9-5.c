#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat ���� ���� ���� ������ ���� ����
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

char* my_strcat(char* dest, char* src);				// my_strcat() �Լ� ����

int main(void) {
	char dest[100];									// dest �迭 ����
	char src[100];									// src �迭 ����
	printf("���ڿ��Է� : ");						// ���ڿ��Է� : ���
	scanf("%s", dest);								// dest�� ���ڿ� �Է�
	while (1) {										// ���ѹݺ�
		if (strcmp(dest, "quit") == 0) break;		// dest�� quit�� ���ٸ� �ݺ��� ����
		printf("���ڿ��Է� : ");					// ���ڿ��Է� : ���
		scanf("%s", src);							// src�� ���ڿ� �Է�

		my_strcat(dest, src);						// my_strcat�Լ� ȣ��

		printf("%s\n", dest);						// dest ���ڿ� ���

		printf("���ڿ��Է� : ");					// ���ڿ��Է� : ���
		scanf("%s", dest);							// dest�� ���ڿ� �Է�
	}
	system("pause");
	return 0;
}
char* my_strcat(char* dest, char* src) {			// my_strcat�Լ� ����
	int len = 0;									// dest ���ڿ��� ������ �ε��� ��ȣ�� ������ ����
	for (int i = 0; dest[i] != '\0'; i++) {			// dest ���ڿ��� ������ �ε��� ��ȣ
		len = i;									// i���� len�� ����
	}
	for (int j = 0; src[j] != '\0'; j++) {			// src ���ڿ��� ������ �ε��� ��ȣ
		*(dest + len + j + 1) = *(src + j);			// dest�� �ι��ڰ� �ִ� ������ src ���ڿ��� ���̸�ŭ �ϳ��ϳ� ����
		*(dest + len + j + 2) = '\0';				// src ���ڿ��� �� �����ߴٸ� �������� �ι��� ����
	}
	return *dest;									// dest ��ȯ
}
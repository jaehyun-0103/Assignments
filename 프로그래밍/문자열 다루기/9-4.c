#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat ���� ���� ���� ������ ���� ����
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int my_strcmp(const char* str1, const char* str2);		// my_strcmp() �Լ� ����

int main(void) {
	char str1[100];										// str1 �迭 ����
	char str2[100];										// str2 �迭 ����
	printf("���ڿ��Է� : ");							// ���ڿ��Է� : ���
	scanf("%s", str1);									// str1 �Է�
	while (1) {											// ���ѹݺ�
		if (my_strcmp(str1, "quit") == 0) break;		// my_strcmp�Լ� ȣ��, str1�� quit�� ���Ͽ� ���ٸ� �ݺ��� ����
		printf("���ڿ��Է� : ");						// ���ڿ��Է� : ���
		scanf("%s", str2);								// str2 �Է�

		printf("%d\n", my_strcmp(str1, str2));			// my_strcmp�Լ� ȣ��

		printf("���ڿ��Է� : ");						// ���ڿ��Է� : ���
		scanf("%s", str1);								// str1 �Է�
	}
	system("pause");
	return 0;
}
int my_strcmp(const char* str1, const char* str2) {					// my_strcmp�Լ� ����
	int result;														// main�Լ��� ��ȯ�� ������� ������ ����
	if (strlen(str1) == strlen(str2)) {								// str1�� str2 ���ڿ� ���̰� ���� ��
		for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {	// str1 �Ǵ� str2�� �ι��ڸ� ���������� �ε��� ��ȣ�� i���� 1�� ����
			if (str1[i] > str2[i]) {								// str1�� str2���� ũ�ٸ�
				result = 1;											// result�� 1
				break;												// �ݺ��� ����
			}
			else if (str1[i] == str2[i]) {							// str1�� str2�� ������
				result = 0;											// result�� 0
			}
			else {													// str2�� str1���� ũ�ٸ�
				result = -1;										// -1
				break;												// �ݺ��� ����
			}
		}
	}
	else {															// str1�� str2 ���ڿ� ���̰� �ٸ� ��
		if (strlen(str1) > strlen(str2))							// str1�� ���̰� �� ���
			result = 1;												// 1
		else if (strlen(str1) < strlen(str2))						// str2�� ���̰� �� ���
			result = -1;											// -1
	}
	return result;													// result�� ��ȯ
}
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(void) {
	char str1[20] = "Long time no see.";		// str1 �迭�� Long time no see. ���ڿ� �Ҵ�
	char str2[20] = "What's up?";				// str2 �迭�� what's up? �Ҵ�
	if (strlen(str1) > strlen(str2))			// str1 ���ڿ��� ���̰� str2 ���ڿ��� ���̺��� �� ��ٸ�
		printf("%s\n", str1);					// str1 ���
	else if (strlen(str1) < strlen(str2))		// str2 ���ڿ��� ���̰� str1 ���ڿ��� ���̺��� �� ��ٸ�
		printf("%s\n", str2);					// str2 ���
	else										// str1�� str2�� ���ڿ��� ���̰� ���ٸ�
		printf("�� ���ڿ��� ũ��� �����ϴ�.");	// �� ���ڿ��� ũ��� �����ϴ�. ���
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS // strcpy, strcat ���� ���� ���� ������ ���� ����
#include<stdio.h>
#include<stdlib.h>

int main(void) {
	char last_name[20];					// ���� �Է��� �迭
	char first_name[20];				// �̸��� �Է��� �迭
	char full_name[20];					// ���� �̸��� ��� ������ �迭
	printf("���� �Է��Ͻÿ�. : ");		// ���� �Է��Ͻÿ�. : ���
	scanf("%s", last_name);				// ���� �Է�
	printf("�̸��� �Է��Ͻÿ�. : ");	// �̸��� �Է��Ͻÿ�. : ���
	scanf("%s", first_name);			// �̸��� �Է�
	strcat(last_name, first_name);		// strcat�Լ��� �� �ڿ� �̸��� �ٿ� last_name�� ����
	strcpy(full_name, last_name);		// strcpy�Լ��� last_name�� full_name�� ����
	printf("���� ������ �̸��� %s�Դϴ�.\n", full_name);	// full_name ���
	system("pause");
	return 0;
}
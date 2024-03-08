#define _CRT_SECURE_NO_WARNINGS	//	strcpy ���� ���� ���� ������ ���� ����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>			//	strcpy �Լ��� ����� ��� ����

typedef struct {			//	����ü �̸��� ���� �͸� ����ü
	char name[100];			//	����� �̸��� ������ ����
	int age;				//	����� ���̸� ������ ����
	char gender[10];		//	����� ������ ������ ����
}Person;					//	typedef�� ����Ͽ� ����ü ��Ī�� Person���� ����

void Person_printf(Person* data1, Person* data2, Person* data3) {				//	Person_printf �Լ� ����, �����͸� ����ϴ� �Լ�
	printf("%s�� %s�̰� %d���̴�.\n", data1->name, data1->gender, data1->age);	//	�ε��� 1��°�� �̸�, ����, ���� �� ���
	printf("%s�� %s�̰� %d���̴�.\n", data2->name, data2->gender, data2->age);	//	�ε��� 2��°�� �̸�, ����, ���� �� ���
	printf("%s�� %s�̰� %d���̴�.\n", data3->name, data3->gender, data3->age);	//	�ε��� 3��°�� �̸�, ����, ���� �� ���
}

int main(void) {
	Person temp;			//	���� ������ ����ϱ� ���� ���� ����
	Person data[4] = { 0 };	//	����ü �迭 �ʱ�ȭ
	Person* p = data;		//	����ü ��Ī���� ������ ����
	for (int i = 1; i < 4; i++) {							//	i�� 1���� 3���� 1�� �����ϴ� ����
		printf("%d��° ��� : ", i);						//	i��° ��� : ���
		scanf("%s %d %s", &p->name, &p->age, &p->gender);	//	�ε��� i��° ����� �̸�, ����, ���� ������ �Է�
		if (p->age < 0 || p->age >120) {					//	���̰� 0�̸� 120 �ʰ����
			printf("�Էµ� ���� Ȯ��\n");					//	�Էµ� ���� Ȯ�� ���
			i--;											//	i�� 1 ����
			continue;										//	�ǳʶٱ�
		}
		if (strcmp(&p->gender, "m") == 0)		//	strcmp �Լ��� �̿��Ͽ� �Է��� ������ m�̶��
			strcpy(&p->gender, "����");			//	m�� ���ڷ� ����
		else if (strcmp(&p->gender, "f") == 0)	//	strcmp �Լ��� �̿��Ͽ� �Է��� ������ f���
			strcpy(&p->gender, "����");			//	f�� ���ڷ� ����
		strcpy(&data[i].name, &p->name);		//	�Է¹��� �̸��� ����ü �迭�� i��°�� ����
		strcpy(&data[i].age, &p->age);			//	�Է¹��� ���̸� ����ü �迭�� i��°�� ����
		strcpy(&data[i].gender, &p->gender);	//	�Է¹��� ������ ����ü �迭�� i��°�� ����

	}
	for (int i = 1; i < 3; i++) {							//	i�� 1���� 2���� 1�� ����
		if (strcmp(data[i].name, data[i + 1].name) == 1) {	//	data�� i��° �ε����� �̸��� data�� i+1��° �ε����� �̸����� ũ�ٸ�
			temp = data[i];									//	data�� i��° �ε����� temp�� ����
			data[i] = data[i + 1];							//	data�� i+1��° �ε����� data�� i��° �ε����� ����
			data[i + 1] = temp;								//	temp�� data�� i+1��° �ε����� ����
		}
	}
	Person_printf(&data[1], &data[2], &data[3]);			//	Person_printf �Լ� ȣ��
	system("pause");
	return 0;
}
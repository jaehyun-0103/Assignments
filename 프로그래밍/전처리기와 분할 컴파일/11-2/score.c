#include<stdio.h>

extern int kor, eng, math;				// �ٸ� �ҽ� ���Ͽ� �ִ� �������� kor, eng, math ���
extern double aver;						// �ٸ� �ҽ� ���Ͽ� �ִ� �������� aver ���
extern double total;					// �ٸ� �ҽ� ���Ͽ� �ִ� �������� total ���

void myInput() {						// myInput() �Լ� ����
	printf("���� ���� ���� ������ �Է��Ͻÿ� : ");	// ���� ���� ���� ������ �Է��Ͻÿ� : ���
	scanf_s("%d %d %d", &kor, &eng, &math);			// ���� ���� ���� ���� �Է�
}

double myOutput() {						// myOutput() �Լ� ����
	int grade;							// ������ ������ ���� ����
	aver = (kor + eng + math) / 3.0;	// �Է¹��� ����� ��� ���
	total = kor + eng + math;			// �Է����� ����� ���� ���
	if (total <= 100 && total >= 90)	// ������ 90���� ũ�ų� ���� 100���� �۰ų� ������
		grade = 'A';					// A����
	else if (total >= 80)				// ������ 80���� ũ�ų� ������
		grade = 'B';					// B����
	else if (total >= 70)				// ������ 70���� ũ�ų� ������
		grade = 'C';					// C����
	else if (total >= 60)				// ������ 60���� ũ�ų� ������
		grade = 'D';					// D����
	else								// ������ 60���� ������
		grade = 'F';					// F����
	printf("����� %.2lf, ������ %.2lf, ������ %c�̴�.", aver, total, grade);	// ���, ����, ���� ���
}
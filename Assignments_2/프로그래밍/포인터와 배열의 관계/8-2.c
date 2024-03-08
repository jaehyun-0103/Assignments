#include<stdio.h>
#include<stdlib.h>

double average_by_array(int p[], int length);		// average_by_array() �Լ� ����
double average_by_pointer(int* p, int length);		// average_by_pointer() �Լ� ����

int main(void) {
	int arr[5] = { 10, 40, 50, 20, 15 };			// �迭 ����
	printf("%lf\n", average_by_array(arr, 5));		// average_by_array�Լ� ȣ�� 
	printf("%lf\n", average_by_pointer(arr, 5));	// average_by_pointer�Լ� ȣ��
	system("pause");
	return 0;
}
double average_by_array(int p[], int length) {		// average_by_array�Լ� ����
	double sumArray = 0.0;							// ��հ� �ʱ�ȭ
	for (int i = 0; i < length; i++) {				// i�� 0���� 4����
		sumArray += p[i];							// ������ �迭 ���� ����
	}
	return sumArray / length;						// ��� ��ȯ
}
double average_by_pointer(int* p, int length) {		// average_by_pointer�Լ� ����
	double sumPointer = 0.0;						// ��հ� �ʱ�ȭ
	for (int j = 0; j < length; j++) {				// i�� 0���� 4����
		sumPointer += *(p+j);						// ������ �迭 ���� ����
	}
	return sumPointer / length;						// ��� ��ȯ
}
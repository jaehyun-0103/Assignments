#include<stdio.h>
#include<stdlib.h>

void print_array(int* arr, int length);					// print_array() �Լ� ����
void swap_array(int* a, int* b, int length);			// swap_array() �Լ� ����

int main(void) {
	int arr1[5];
	int arr2[5];
	int length=5;
	printf("Enter the contents of first array.\n");
	for (int i = 0; i<length; i++) {					// i�� 0���� 4����
		scanf_s("%d", &arr1[i]);						// �迭�� �Է�
	}
	printf("Enter the contents of second array.\n");
	for (int j = 0; j<length; j++) {					// j�� 0���� 4����
		scanf_s("%d", &arr2[j]);						// �迭�� �Է�
	}
	printf("Before swapping,\n");

	printf("first: ");
	print_array(arr1, length);							// print_array�Լ� ȣ��
	printf("second: ");
	print_array(arr2, length);							// print_array�Լ� ȣ��

	swap_array(arr1, arr2, length);						// swap_array�Լ� ȣ��

	printf("After swapping,\n");

	printf("first: ");
	print_array(arr1, length);							// print_array�Լ� ȣ��
	printf("second: ");
	print_array(arr2, length);							// print_array�Լ� ȣ��
	system("pause");
	return 0;
}
void print_array(int* arr, int length) {				// print_array�Լ� ����
	for (int m = 0; m < length; m++) {					// m�� 0���� 4����
		printf("%d ", arr[m]);							// �迭 ���
	}
	printf("\n");
}
void swap_array(int* a, int* b, int length) {			// swap_array�Լ� ����
	int arr3;											// �� �迭 ���� ����
	for (int n = 0; n < length; n++) {					// n�� 0���� 4����
		arr3 = *(a+n);									// arr1�迭�� arr3�迭�� ����
		*(a+n) = *(b+n);								// arr2�迭�� arr1�迭�� ����
		*(b+n) = arr3;									// arr3�迭�� arr2�迭�� ����
	}
	
}
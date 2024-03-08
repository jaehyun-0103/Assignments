#include<stdio.h>
#include<stdlib.h>

void min_max(int* arr, int* min, int* max, int length);		// min_max() �Լ� ����

int main(void) {
	int length=0;											//�迭�� ���̸� 0���� �ʱ�ȭ
	int* arry;
	int min, max;
	int num=0;												// ������ �Է¹ޱ� �������� ���� ����
	scanf_s("%d", &length);									// �迭�� ���� �Է�
	arry = (int *)malloc(sizeof(int) * length);				// �������� �迭�� ���� ����
	printf("Enter a sequence of positive integers.\n");
	for (int i = 0; i < length; i++) {						// i�� 0���� ���̱���
		scanf_s("%d", &arry[i]);							// �迭�� �Է�
		num++;												// ����� ������ ��
		if (arry[i] < 0)
			break;
	}
	min_max(arry, &min, &max, num-1);						// min_max�Լ� ȣ��
	printf("Minimum is %d, Maximum is %d.\n", min, max);
	system("pause");
	return 0;
}
void min_max(int* arr, int* min, int* max, int length) {	// min_max�Լ� ����
	*min = arr[0];											// �迭�� ù��° ���� �ּҶ� �ʱ�ȭ
	*max = arr[0];											// �迭�� ù��° ���� �ִ�� �ʱ�ȭ
	for (int j = 0; j < length; j++) {						// j�� 0���� ���̸̹�����
		if (arr[j] <= *min)									// min���� �迭 ���� �۴ٸ�
			*min = arr[j];									// min�� �� �迭 ��
	}
	for (int k = 0; k < length; k++) {						// k�� 0���� ���̸̹�����
		if (arr[k] >= *max)									// max���� �迭���� ũ�ٸ�
			*max = arr[k];									// max�� �� �迭 ��
	}
}
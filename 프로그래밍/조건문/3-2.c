#include<stdio.h>

int main() {
	int inputNum = 0;
	while (1) {
		printf("��� �Է� : ");
		scanf_s("%d", &inputNum);
		if (inputNum < 0) {			// �Է��� ���� �������
			printf("����� �Է��ϼ���.\n");
			continue;				// �Ʒ� �ڵ带 �������� �ʰ� �ǳʶ�
		}
		if (inputNum == 0) {		// �Է��� ���� 0�̶��
			printf("���α׷� ����...");
			break;					// �ݺ��� ����
		}
		printf("%d\n", inputNum * inputNum);
	}
}
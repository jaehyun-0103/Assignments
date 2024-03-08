#include<stdio.h>

int asterisk(int n) {		// asterisk() �Լ� ����
	if (n > 0) {			// ���� n�� 0���� ũ�ٸ�
		printf("%c", '*');	// * ���
		asterisk(n - 1);	// ��� ȣ��
	}
}

int main() {
	int num;
	do {
		printf("Enter n\n");
		scanf_s("%d", &num);
		if (num <= 0)	// �Է��� ���� ����� �ƴ϶��
			printf("Please enter it again.\n");
		else			// �Է��� ���� ������
			break;		// �ݺ��� ����
	} while (1);		// ���� �ݺ�
	asterisk(num);		// asterisk() �Լ� ȣ��
	printf("\n");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>

int count_vowel(char* arr, int length);		// count_vowel() �Լ� ����

int main(void) {
	char ch, str[100];						// �Է� ������ ���� ���� �ʱ�ȭ
	int i = 0;
	printf("Enter a sample sentence.\n");	// Enter a sample sentence. ���
	while ((ch = getchar()) != '\n') {		// �ٹٲ��� �ƴ� ����
		str[i] = ch;						// ���� �ϳ��ϳ��� �迭�� ����
		i++;								// �迭�� ���� ���
	}
	printf("Vowels appear %d times.\n", count_vowel(str, i));	// count_vowel�Լ� ȣ��
	system("pause");
	return 0;
}
int count_vowel(char* arr, int length) {	// count_vowel�Լ� ����
	int cnt = 0;							// ������ ���� �ʱ�ȭ
	for (int j = 0; j < length; j++) {		// ���ڰ� ����� �迭�� ���� ����
		if (arr[j] == 'a' || arr[j] == 'e' || arr[j] == 'i' || arr[j] == 'o' || arr[j] == 'u') {	// ������ ������ ���ڶ��
			cnt++;							// ī��Ʈ
		}
	}
	return cnt;
}
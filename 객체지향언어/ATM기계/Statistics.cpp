#include <iostream>
#include "Statistics.h"
#include "Account.h"

using namespace std;

// ���� �ܰ� ����
int Statistics::sum(Account* pArray, int size) {
	int sumBal = 0;							// ������ ������ ���� ����, �ʱ�ȭ
	for (int i = 0; i < size; i++)			// ���� ������ŭ �ݺ�
		sumBal += pArray[i].getBalance();	// ���µ��� �ܰ� ����
	return sumBal;							// ���� �ܰ� ���� ����
}

// ���� �ܰ� ���
int Statistics::average(Account* pArray, int size) {
	int sumBal = 0;							// ������ ������ ���� ����, �ʱ�ȭ
	if (size == 0)							// ���� ������ ���°� ���ٸ�
		return 0;							// �Լ� ����
	for (int i = 0; i < size; i++)			// ���� ������ŭ �ݺ�
		sumBal += pArray[i].getBalance();	// ���µ��� �ܰ� ����
	int aver = sumBal / size;				// ���� �ܰ� ������ ����� ���
	return aver;							// ���� �ܰ� ������ ��� ����
}

// ���� �ܰ� �ְ�
int Statistics::max(Account* pArray, int size) {
	int max = pArray[0].getBalance();		// ���� �ܰ��� �ִ밪�� ù��° ���� �ܰ�� �ʱ�ȭ
	for (int i = 1; i < size; i++) 			// ���� ������ŭ �ݺ�
		if (max < pArray[i].getBalance())	// ���� ���� �ܰ��� �ִ밪���� ũ�ٸ�
			max = pArray[i].getBalance();	// �� ������ �ܰ� �ִ밪
	return max;								// �ִ밪 ����
}

// ���� ���� ����
void Statistics::sort(Account* pArray, int size) {
	Account tmp;
	for (int i = 0; i < size; i++)										// ���� ������ŭ �ݺ�
		for (int j = 0; j < (size - 1) - i; j++)						// ������ �������� 1 ���� �ݺ�
			if (pArray[j].getBalance() < pArray[j + 1].getBalance()) {	// ���� [j] �ε����� �ܰ� [j+1] �ε����� �ܰ��� �۴ٸ�
				tmp = pArray[j];			// [j] �ε����� tmp�� ����
				pArray[j] = pArray[j + 1];	// [j+1] �ε����� [j] �ε����� ����
				pArray[j + 1] = tmp;		// tmp�� [j+1] �ε����� ����
			}
}
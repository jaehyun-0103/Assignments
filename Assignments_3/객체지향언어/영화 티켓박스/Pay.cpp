#include <iostream>
#include <string>
#include "Pay.h"
using namespace std;

// ����� ���� �ݾ�
int  MobilePay::charge(int amount) {	// �����Ḧ �ΰ��ϱ� ���� �ݾ��� �Ű�����
	amount = amount + amount * interest;// �����ݾ� = Ƽ�� ���� + Ƽ�� ���� * 0.2
	return amount;						// �����ݾ� ����
}

// ���� ��ü ���� �ݾ�
int BankTransfer::charge(int amount) {	// �����Ḧ �ΰ��ϱ� ���� �ݾ��� �Ű�����
	amount = amount + amount * interest;// �����ݾ� = Ƽ�� ���� + Ƽ�� ���� * 0.1
	return amount;						// �����ݾ� ����
}

// ī�� ���� �ݾ�
int CardPay::charge(int amount) {		// �����Ḧ �ΰ��ϱ� ���� �ݾ��� �Ű�����
	amount = amount + amount * interest;// �����ݾ� = Ƽ�� ���� + Ƽ�� ���� * 0.15
	return amount;						// �����ݾ� ����
}
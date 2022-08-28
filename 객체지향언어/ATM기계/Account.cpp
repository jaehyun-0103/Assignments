#include <iostream>
#include "ATMachine.h"
#include "Account.h"

using namespace std;

// ���� ���� : true(1), ���� ���� : false(0)
inline bool Account::authenticate(int id, string passwd) {
	if (strPassword == passwd)	// �Է��� ��й�ȣ�� ������
		return true;			// true ����
	else						// �Է��� ��й�ȣ�� Ʋ����
		return false;			// false ����
}

// �Ű� ���� ���� ������
Account::Account() { }

// ���� ����
void Account::create(int id, int money, string name, string password) {
	nID = id;				// �������� �������� ���¹�ȣ�� id�� nID�� ����
	nBalance = money;		// �ܰ��� money�� nBalance�� ����
	strAccountName = name;	// �� �̸��� name�� strAccountName�� ����
	strPassword = password;	// ���� ��й�ȣ�� password�� strPassword�� ����

	cout << strAccountName << "�� " << nID << "�� ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�.\n" << endl;
}

// return �� : nBalance (�ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
int Account::check(int id, string password) {
	if (authenticate(id, password)) {			// ��й�ȣ�� ��ġ�ϸ�
		return nBalance;						// �ܰ� ����
	}
	else {										// ��й�ȣ�� ��ġ���� ������
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl << "�ʱ� ȭ������ ���ư��ϴ�.\n" << endl;
		return AUTHENTIFICATION_FAIL;			// AUTHENTIFICATION_FAIL ����
	}
}

// ���� ����
void Account::close() {
	if (nBalance == 0)				// �ܰ� 0�̶��
		cout << nID << " ���°� �����Ǿ����ϴ�. �����մϴ�.\n" << endl;
	else							// �ܰ� 0�� �ƴ϶��
		cout << nID << " ���¸� ������ �� �����ϴ�. �ܾ� : " << nBalance << endl << endl;
}

// return �� : nBalance (�����ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
int Account::deposit(int id, string password, int money) {
	if (authenticate(id, password)) {	// ��й�ȣ�� ��ġ�ϸ�
		nBalance += money;				// �ܰ� �Աݾ��� ����
		return nBalance;				// �ܰ� ����
	}
	else {								// ��й�ȣ�� ��ġ���� ������
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl << "�ʱ� ȭ������ ���ư��ϴ�.\n" << endl;
		return AUTHENTIFICATION_FAIL;	// AUTHENTIFICATION_FAIL ����
	}
}

// return �� : nBalance (�����ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
int Account::widraw(int id, string password, int money) {
	if (authenticate(id, password)) {		// ��й�ȣ�� ��ġ�ϸ�
		if (nBalance - money >= 0) {		// �ܰ� ����ϴٸ�
			nBalance -= money;				// �ܰ� ��ݾ��� ��
			return nBalance;				// �ܰ� ����
		}
		else								// �ܰ� ������� �ʴٸ�
			return AUTHENTIFICATION_FAIL;	// AUTHENTIFICATION_FAIL ����
	}
	else {								// ��й�ȣ�� ��ġ���� ������
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl << "�ʱ� ȭ������ ���ư��ϴ�.\n" << endl;
		return AUTHENTIFICATION_FAIL;	// AUTHENTIFICATION_FAIL ����
	}
}

// return �� : nBalance (���� �ܰ�)
int Account::deposit(int id, int money) {
	nBalance += money;	// �ܰ� ��ü�ݾ��� ����
	return nBalance;	// �ܰ� ����
}
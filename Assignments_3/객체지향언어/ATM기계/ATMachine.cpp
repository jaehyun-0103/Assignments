#include <iostream>
#include <stdlib.h>	// srand, rand�� ����ϱ� ���� �������
#include <time.h>	// time�� ����ϱ� ���� �������
#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"

using namespace std;

// ���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ
ATMachine::ATMachine(int size, int balance, string password) {
	nCurrentAccountNum = size;		// ���� �迭 ũ���� size�� nCurrentAccountNum�� ����
	nMachineBalance = balance;		// ATM �ܰ��� balance�� nMachineBalance�� ����
	strManagerPassword = password;
	pAcctArray = new Account[901];	// ũ�Ⱑ 901�� Account ��ü �迭�� ���� ����
}

// �����ϴ� �Ҹ���
ATMachine::~ATMachine() {
	cout << "***���� �� ���� : " << nCurrentAccountNum << "***" << endl;
	delete[] pAcctArray;	// ���� �Ҵ� ����
}

// ATM ��� ���� ȭ��
void ATMachine::displayMenu() {
	cout << "----------------------" << endl << " --  TUKOREA BANK  -- " << endl << "----------------------" << endl;
	cout << "1. ���� ����" << endl << "2. ���� ��ȸ" << endl << "3. ���� �Ա�" << endl << "4. ���� ���" << endl <<
		"5. ���� ��ü" << endl << "6. ���� ����" << endl << "7. �� ����" << endl << "9. ���� ����" << endl;
}

// ���� ����
void ATMachine::createAccount() {
	srand((unsigned)time(NULL));				// ���� �ʱ�ȭ
	int id = rand() % 901 + BASE_ACCOUNT_ID;	// 100���� 1000 ������ ���ڸ� ��� id�� ����

	int money = 0;
	string name;
	string password;

	cout << endl << " --------����-------- " << endl;
	cout << "�̸� �Է�: ";
	cin >> name;			// �� �̸� �Է�
	cout << "��ȣ �Է�: ";
	cin >> password;		// ���� ��й�ȣ �Է�

	pAcctArray[nMaxAccountNum].create(id, money, name, password);	// �迭�� nMaxAccountNum��° ��ü�� create() ��� �Լ� ȣ��
	nMaxAccountNum++;		// ���� ������ ������ �迭 ũ���� nMaxAccountNum 1 ����
	nCurrentAccountNum++;	// ������ �� ���� ���� nCurrentAccountNum 1 ����
}

// ���� ��ȸ
void ATMachine::checkMoney() {
	int id;
	string password;

	cout << endl << " --------��ȸ-------- " << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;			// ���¹�ȣ �Է�
	cout << "��й�ȣ �Է�: ";
	cin >> password;	// ���� ��й�ȣ �Է�

	for (int i = 0; i < nMaxAccountNum; i++) {				// ���� �迭ũ�⸸ŭ �ݺ�
		if (pAcctArray[i].getAcctID() == id) {				// �Է��� ���� ��ȣ�� ��ġ�ϴ� ��ü�� ã�Ҵٸ�
			int bal = pAcctArray[i].check(id, password);	// check() ��� �Լ��� ���ϰ��� bal�� ����
			if (bal == -1)	// ���ϰ��� -1�̸� (��й�ȣ�� Ʋ��)
				break;		// �ݺ��� ����
			else			// ���ϰ��� -1�� �ƴϸ� (��й�ȣ�� ����)
				cout << "���� �ܾ� : " << bal << endl << endl;
		}
	}
}

// ���� ����
void ATMachine::closeAccount() {
	int id;
	string password;
	cout << endl << " --------����-------- " << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;			// ���¹�ȣ �Է�
	cout << "��й�ȣ �Է�: ";
	cin >> password;	// ���� ��й�ȣ �Է�

	for (int i = 0; i < nMaxAccountNum; i++) {		// ���� �迭ũ�⸸ŭ �ݺ�
		if (pAcctArray[i].getAcctID() == id) {		// �Է��� ���� ��ȣ�� ��ġ�ϴ� ��ü�� ã�Ҵٸ�
			pAcctArray[i].close();					// �� ��ü�� close() ��� �Լ� ȣ��
			int bal = pAcctArray[i].getBalance();	// getBalance() ��� �Լ��� ���ϰ��� bal�� ����
			if (bal == 0) {							// ���ϰ��� 0�̸� (�ܰ� 0�̶��)
				if (i == nMaxAccountNum - 1) {		// ���� ������ �迭�� �������� �ִٸ�
					nMaxAccountNum--;				// nMaxAccountNum 1 ����
					nCurrentAccountNum--;			// nCurrentAccountNum 1 ����
					break;							// �ݺ��� ����
				}
				else {								// ���� ������ �迭�� �������� ���� �ʴٸ�
					for (int j = i + 1; j < nMaxAccountNum; j++)
						pAcctArray[j - 1] = pAcctArray[j];	// ���� ������ �迭�� ���������� �̵�
					nMaxAccountNum--;			// nMaxAccountNum 1 ����
					nCurrentAccountNum--;		// nCurrentAccountNum 1 ����
					break;						// �ݺ��� ����
				}
			}
			else			// ���ϰ��� 0�� �ƴ϶�� (�ܰ� 0�� �ƴ϶��)
				break;		// �ݺ��� ����
		}
	}
}

// ���� �Ա�
void ATMachine::depositMoney() {
	int id;
	string password;
	int money;

	cout << endl << " --------�Ա�-------- " << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;			// ���¹�ȣ �Է�
	cout << "��й�ȣ �Է�: ";
	cin >> password;	// ���� ��й�ȣ �Է�
	cout << "�Աݾ� �Է�: ";
	cin >> money;		// �ӱݾ� �Է�

	for (int i = 0; i < nMaxAccountNum; i++) {						// ���� �迭ũ�⸸ŭ �ݺ�
		if (pAcctArray[i].getAcctID() == id) {						// �Է��� ���� ��ȣ�� ��ġ�ϴ� ��ü�� ã�Ҵٸ�
			int bal = pAcctArray[i].deposit(id, password, money);	// deposit() ��� �Լ��� ���ϰ��� bal�� ����
			if (bal == -1)	// ���ϰ��� -1�̸� (��й�ȣ�� Ʋ��)
				break;		// �ݺ��� ����
			else {			// ���ϰ��� -1�� �ƴ϶�� (��й�ȣ�� ����)
				cout << "���� �ܾ� : " << bal << endl;
				cout << "�Ա� �Ϸ�\n" << endl;
				nMachineBalance += bal;	// ATM �ܰ� �ݾ� �߰�
			}
		}
	}
}

// ���� ���
void ATMachine::widrawMoney() {
	int id;
	string password;
	int money;

	cout << endl << " --------���-------- " << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> id;			// ���¹�ȣ �Է�
	cout << "��й�ȣ �Է�: ";
	cin >> password;	// ���� ��й�ȣ �Է�
	cout << "��ݾ� �Է�: ";
	cin >> money;		// ��ݾ� �Է�

	for (int i = 0; i < nMaxAccountNum; i++) {						// ���� �迭ũ�⸸ŭ �ݺ�
		if (pAcctArray[i].getAcctID() == id) {						// �Է��� ���� ��ȣ�� ��ġ�ϴ� ��ü�� ã�Ҵٸ�
			int bal = pAcctArray[i].widraw(id, password, money);	// widraw() ��� �Լ��� ���ϰ��� bal�� ����
			if (bal == -1) {	// ���ϰ��� -1�̸� (�ܰ� ������)
				cout << "���¿� �ܰ� �����մϴ�.\n" << endl;
				break;			// �ݺ��� ����
			}
			else {				// ���ϰ��� -1�� �ƴ϶�� (�ܰ� �����)
				if (nMachineBalance - money >= 0) {	// ATM �ܰ� ����ϴٸ�
					cout << "���� �ܾ� : " << bal << endl;
					cout << "��� �Ϸ�\n" << endl;
					nMachineBalance -= money;			// ��ݾ׸�ŭ ATM�ܰ��� ��
				}
				else			// ATM �ܰ� ������� �ʴٸ�
					cout << "ATM��⿡ �ܰ� �����մϴ�.\n" << endl;
			}
		}
	}
}

// ��ü�Ϸ��� �� �ܰ� �����ϴٸ� -1�� ��ȯ�ϰ� �Ԥ��� �ݾ��� ����
// ���� ��ü
void ATMachine::transfer() {
	int give_id, receive_id;// ��ü�� ���� id�� ��ü���� ���� id
	string password;
	int money = 0;
	int give_bal = 0;		// ��ü�� ������ �ܰ�

	cout << endl << " --------��ü-------- " << endl;
	cout << "���¹�ȣ �Է�: ";
	cin >> give_id;		// ���¹�ȣ �Է�
	cout << "��й�ȣ �Է�: ";
	cin >> password;	// ���� ��й�ȣ �Է�
	cout << "��ü���� �Է�: ";
	cin >> receive_id;	// ��ü���� �Է�
	cout << "��ü�ݾ� �Է�: ";
	cin >> money;		// ��ü�ݾ� �Է�

	for (int i = 0; i < nMaxAccountNum; i++)								// ���� �迭ũ�⸸ŭ �ݺ�
		if (pAcctArray[i].getAcctID() == give_id) 							// �Է��� ���� ��ȣ�� ��ġ�ϴ� ��ü�� ã�Ҵٸ�
			give_bal = pAcctArray[i].widraw(give_id, password, money);		// widraw() ��� �Լ��� ���ϰ��� give_bal�� ����
	
	if (give_bal == -1)		// ���ϰ��� -1�̸� (�ܰ� ������)
		cout << "���¿� �ܰ� �����մϴ�.\n" << "��ü ����\n" << endl;
	else {					// ���ϰ��� -1�� �ƴ϶��
		for (int i = 0; i < nMaxAccountNum; i++) {							// ���� �迭ũ�⸸ŭ �ݺ�
			if (pAcctArray[i].getAcctID() == receive_id) 					// �Է��� ���� ��ȣ�� ��ġ�ϴ� ��ü�� ã�Ҵٸ�
				int receive_bal = pAcctArray[i].deposit(receive_id, money);	// deposit() ��� �Լ��� ���ϰ��� receive_bal�� ����
		}
		cout << "���� �ܾ� : " << give_bal << endl;
		cout << "��ü �Ϸ�\n" << endl;
	}
}

// �Ŵ��� ��ȣ Ȯ��
bool ATMachine::isManager(string password) {
	if (password == strManagerPassword)	// ��ȣ�� ��ġ�ϸ�
		return true;
	else 								// ��ȣ�� ��ġ���� ������
		return false;
}

// ��� ȭ�� ó��
void ATMachine::displayReport() {
	cout << endl << " -------------------- " << endl;
	cout << "ATM ���� �ܰ�:\t" << nMachineBalance << "��" << endl;
	cout << "�� �ܰ� �Ѿ�:\t" << Statistics::sum(pAcctArray, nMaxAccountNum) << "��" << " (��" << nMaxAccountNum << "��)" << endl;	// ���� �ܰ� ���� ���
	cout << "�� �ܰ� ���:\t" << Statistics::average(pAcctArray, nMaxAccountNum) << "��" << endl;										// ���� �ܰ� ��� ����
	cout << "�� �ܰ� �ְ�:\t" << Statistics::max(pAcctArray, nMaxAccountNum) << "��" << endl;											// ���� �ܰ� �ְ� ���
	cout << " -------------------- " << endl;
	cout << " -- �� ���� ��� -- " << endl;
	cout << " -------------------- " << endl;

	Statistics::sort(pAcctArray, nMaxAccountNum);	// ���� ���� ���� (�ܾ� ����)

	for (int i = 0; i < nMaxAccountNum; i++) {		// ���� ������ŭ �ݺ�
		cout << i + 1 << ". " << pAcctArray[i].getAccountName() << "\t"
			<< pAcctArray[i].getAcctID() << "\t" << pAcctArray[i].getBalance() << "��" << endl;
	}

	cout << "\n";
}

// �� ����
void ATMachine::managerMode() {
	string password;

	cout << endl << " --------����-------- " << endl;
	cout << "������ ��й�ȣ �Է�: ";
	cin >> password;				// ������ ��ȣ�� �Է�

	if (isManager(password)) {		// ������ ��ȣ�� �´ٸ�
		cout << "\n�������Դϴ�." << endl;
		displayReport();			// displayReport() �Լ� ȣ��
	}
	else							// ������ ��ȣ�� Ʋ�ȴٸ�
		cout << "\n�����ڰ� �ƴմϴ�.\n" << endl;
}
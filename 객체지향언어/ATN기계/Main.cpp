#include <iostream>
#include "ATMachine.h"

using namespace std;

int main() {
	int select;	// ���� �� �޴� ��ȣ
	ATMachine atm(100, 50000, "admin");	// ����(100��), ATM �ܱ� �ʱ�ȭ, ������ ��ȣ
	while (1) {
		atm.displayMenu();			// displayMenu() �Լ� ȣ��
		cout << "�޴��� �����ϼ��� : ";
		cin >> select;				// �޴� ��ȣ �Է�
		switch (select) {			// �� �޴� ��ȣ�� ���Ͽ�
		case 1:						// 1�� ����ٸ�
			atm.createAccount();	// createAccount() �Լ� ȣ��
			break;					// while �ݺ��� ó������
		case 2:						// 2�� ����ٸ�
			atm.checkMoney();		// checkMoney() �Լ� ȣ��
			break;					// while �ݺ��� ó������
		case 3:						// 3�� ����ٸ�
			atm.depositMoney();		// depositMoney() �Լ� ȣ��
			break;					// while �ݺ��� ó������
		case 4:						// 4�� ����ٸ�
			atm.widrawMoney();		// widrawMoney() �Լ� ȣ��
			break;					// while �ݺ��� ó������
		case 5:						// 5�� ����ٸ�
			atm.transfer();			// transfer() �Լ� ȣ��
			break;					// while �ݺ��� ó������
		case 6:						// 6�� ����ٸ�
			atm.closeAccount();		// closeAccount() �Լ� ȣ��
			break;					// while �ݺ��� ó������
		case 7:						// 7�� ����ٸ�
			atm.managerMode();		// managerMode() �Լ� ȣ��
			break;					// while �ݺ��� ó������
		case 9:						// 9�� ����ٸ�
			cout << "\n�ȳ��� ������" << endl;
			return 0;				// ���α׷� ����
		default:					// �ش��ϴ� ��ȣ�� ������
			cout << "��ȣ Ȯ�� �� �ٽ� �Է��ϼ���.\n" << endl;
		}
	}
	return 0;
}
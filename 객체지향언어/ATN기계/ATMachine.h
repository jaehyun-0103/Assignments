#ifndef ATMACHINE_H
#define ATMACHINE_H

using std::string;

#define NEGATIVE_ATM_BALANCE -10 // ATM �ܾ� ����

//class Account;

class ATMachine {
private:
	Account* pAcctArray;		// ���� ������ ������ �迭 ������
	int nMachineBalance;		// ATM �ܰ�
	int nMaxAccountNum = 0;		// ���� ������ ������ �迭 ũ��
	int nCurrentAccountNum = 0;	// ������ �� ���� ��
	string strManagerPassword;	// ������ ��й�ȣ

	// �߰� ���
	bool isManager(string password);	// �޴��� ��ȣ Ȯ��
	void displayReport();				// ��� ȭ�� ó��
public:
	ATMachine(int size, int balance, string password); // ���� �迭ũ��, ATM �ܰ�, ������ ��ȣ �ʱ�ȭ
	~ATMachine();
	void displayMenu();		// ATM ��� ���� ȭ��
	void createAccount();	// ���� ����
	void closeAccount();	// ���� ����
	void checkMoney();		// ���� ��ȸ
	void depositMoney();	// ���� �Ա�
	void widrawMoney();		// ���� ���

	// �߰� ���
	void transfer();		// ���� ��ü
	void managerMode();		// �� ����
};

#endif
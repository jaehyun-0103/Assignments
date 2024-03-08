#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

// ������
TUKoreaTBox::TUKoreaTBox() { }

// �Ҹ���
TUKoreaTBox::~TUKoreaTBox() { cout << "\n???\n"; }

// �󿵰� ���� �޴�
Screen* TUKoreaTBox::selectMenu() {
	int chose = 0;	// ������ �޴� ��ȣ
	cout << "------------------------------\n";
	cout << "       �󿵰� ���� �޴�" << endl;
	cout << "------------------------------\n";
	cout << "1.   ����   ��ȭ 1��" << endl;
	cout << "2.  �ƽþ�  ��ȭ 2��" << endl;
	cout << "3. �����̾� ��ȭ 3��" << endl;
	cout << "9.   ���   ����" << endl << endl;
	cout << "����(1~3, 9) �׿� ���� : ";
	cin >> chose;

	if (chose == 1) {			// 1�� ����ٸ�
		return pEuropeScreen;	// ��ü pEuropeScreen ��ȯ
	}
	else if (chose == 2) {		// 2�� ����ٸ�
		return pAsiaScreen;		// ��ü pAsiaScreen ��ȯ
	}
	else if (chose == 3) {		// 3�� ����ٸ�
		return pPremiumScreen;	// ��ü pPremiumScreen ��ȯ
	}
	else if (chose == 9) {		// 9�� ����ٸ�
		Manage();				// ��� ����
		cout << "\n���α׷��� �����մϴ�.\n";
		delete pEuropeScreen;	// ���� ������ ��ü ����
		delete pAsiaScreen;		// ���� ������ ��ü ����
		delete pPremiumScreen;	// ���� ������ ��ü ����
		exit(1);				// ���α׷� ����
	}
	else {						// �ٸ� ��ȣ�� ����ٸ�
		cout << "���α׷��� �����մϴ�.\n";
		exit(1);				// ���α׷� ����
	}
}

// ��ũ�� ��ü ����
void TUKoreaTBox::Initialize() {
	// Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax))
	pEuropeScreen = new EuropeScreen("���˵���2", 10000, 10, 10);	// �������� ��ü ����
	pAsiaScreen = new AsiaScreen("��Ʋ ������Ʈ", 12000, 10, 10);	// �������� ��ü ����
	pPremiumScreen = new PremiumScreen("���׶�", 30000, 6, 6);		// �������� ��ü ����
}

// ��� ����
void TUKoreaTBox::Manage() {
	string passwd;	// �Է��� ��й�ȣ
	cout << "\n------------------------------\n";
	cout << "         ������ �޴�" << endl;
	cout << "------------------------------\n";
	while (true) {	// ���� �ݺ���
		cout << "������ ��й�ȣ �Է� : ";
		cin >> passwd;
		if (passwd == TICKETBOX_MANAGER_PWD)	// ������ ��й�ȣ�� �´ٸ�
			break;	// �ݺ��� ����
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�.\n";
	}
	cout << "\n1. ������ȭ �󿵰� �����ݾ� : " << Statistics::totalRevenue(pEuropeScreen) << endl;		// 1�� �Ѿ��� �����ϴ� �Լ� ȣ��
	cout << "2. �ƽþƿ�ȭ �󿵰� �����ݾ� : " << Statistics::totalRevenue(pAsiaScreen) << endl;		// 2�� �Ѿ��� �����ϴ� �Լ� ȣ��
	cout << "3. �����̾���ȭ �󿵰� �����ݾ� : " << Statistics::totalRevenue(pPremiumScreen) << endl;	// 3�� �Ѿ��� �����ϴ� �Լ� ȣ��
	cout << "4. ��ü Ƽ�� �Ǹŷ� : " << Statistics::totalSalesCount(pEuropeScreen) +
		Statistics::totalSalesCount(pAsiaScreen) + Statistics::totalSalesCount(pPremiumScreen) << endl;	// �󿵰��� �� Ƽ�� �Ǹŷ��� �����ϴ� �Լ� ���� ȣ���ؼ� ����
}
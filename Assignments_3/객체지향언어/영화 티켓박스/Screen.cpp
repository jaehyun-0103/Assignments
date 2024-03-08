#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"
using namespace std;

// ������
Screen::Screen(string name, int price, int row, int col) {
	strMovieName = name;
	nRowMax = row;
	nColMax = col;
	nTicketPrice = price;
	pSeatArray = new Ticket * [nRowMax];	// ���� ����
	for (int r = 0; r < nRowMax; r++) {		// �¼��� ���� ũ�⸸ŭ �ݺ�
		pSeatArray[r] = new Ticket[nColMax];// ���� ����
	}
	for (int i = 0; i < nRowMax; i++) {		// �¼��� ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < nColMax; j++) {	// �¼��� ���� ũ�⸸ŭ �ݺ�
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);	// ��� �¼��� ���� ���θ� �������(-)���� ����
		}
	}
}

// �Ҹ���
Screen::~Screen() {
	for (int n = 0; n < nRowMax; n++)
		delete[] pSeatArray[n];				// ���� ������ ��ü ����
	delete[] pSeatArray;					// ���� ������ ��ü ����
}	


// �¼� ���� ���� ������ ����
void Screen::showSeatMap() {
	cout << "\t[ �¼� ���� ��Ȳ ]\n";

	cout << "\t";
	for (int i = 0; i < nColMax; i++) {		// �¼��� ���� ũ�⸸ŭ �ݺ�
		cout << "[" << i + 1 << "] ";		// �� ��ȣ ���
	}

	cout << endl;
	for (int i = 0; i < nRowMax; i++) {		// �¼��� ���� ũ�⸸ŭ �ݺ�
		cout << "[" << i + 1 << "]\t";		// �� ��ȣ ���
		for (int j = 0; j < nColMax; j++) {	// �¼��� ���� ũ�⸸ŭ �ݺ�
			cout << "[" << pSeatArray[i][j].getCheck() << "] ";	// �¼��� ���� ���� ���
		}
		cout << "\n";
	}
}

// ��ȭ ���� �޴�
void Screen::showMovieMenu() {
	cout << "\n----------------------------------------\n";
	cout << "        ��ȭ �޴� - " << strMovieName << endl;
	cout << "----------------------------------------\n";
	cout << "1. ��ȭ ����" << endl;
	cout << "2. ���� ��Ȳ" << endl;
	cout << "3. ���� �ϱ�" << endl;
	cout << "4. ���� ���" << endl;
	cout << "5. ���� �ϱ�" << endl;
	cout << "7. ���� �޴� �̵�" << endl;
}

// ���� ��ȭ�� �Ұ� ����
void EuropeScreen::showMovieInfo() {
	cout << "----------------------------------------\n";
	cout << "             [" << strMovieName << "]" << endl;
	cout << "----------------------------------------\n";
	cout << "��ȭ�� : ������ȭ 1��" << endl;
	cout << "���ΰ� : ������" << endl;
	cout << "�ٰŸ� :\n";
	cout << "�������� �������� �� 4�� ��, ��õ�� ���¹��� ��Ʈ������ ������ �����ڸ� �ε��޾� ����� �̼��� ";
	cout << "�޴´�. �������� ����������(������)�� �����ϸ���(�ֱ�ȭ) ������ ���� �����ڿ��Լ� �������� ";
	cout << "������, ���� �ڿ� ���ں��� ������ ���̴� �����ػ�(�ռ���)�� ������ �˰� �ȴ�.\n";

	cout << "���� : " << nTicketPrice << endl;
}

// �ƽþ� ��ȭ�� �Ұ� ����
void AsiaScreen::showMovieInfo() {
	cout << "----------------------------------------\n";
	cout << "            [" << strMovieName << "]" << endl;
	cout << "----------------------------------------\n";
	cout << "��ȭ�� : �ƽþƿ�ȭ 2��" << endl;
	cout << "���ΰ� : ���¸�" << endl;
	cout << "�ٰŸ� :\n";
	cout << "����, ����, ����� ���ϳ� ���� ���� �ʴ� �ϻ��� ��� ���߰� �������� ���ƿ� ������ ���� ģ���� ";
	cout << "���Ͽ� ������ ������. ������� �ٸ�, �ڽŸ��� ���� ��� ���� �������� ���ƿ� �����ϡ�, ";
	cout << "����� �ϻ󿡼��� ��Ż�� �޲ٴ� ���������� �Բ� ���� Ű�� ���۹��� �ѳ� �ѳ��� ����� ������ ";
	cout << "�ܿ￡�� ��, �׸��� ����, ������ ������ �ٽ� �ܿ��� �����ϰ� �� ����. �׷��� Ư���� ������� ������ ";
	cout << "�������� ���ƿ� ��¥ ������ ���ݰ� �� ������ ���ο� ���� �����ϱ� ���� ù ���� ����µ�\n";

	cout << "���� : " << nTicketPrice << endl;
}

// �����̾� ��ȭ�� �Ұ� ����
void PremiumScreen::showMovieInfo() {
	cout << "----------------------------------------\n";
	cout << "               [" << strMovieName << "]" << endl;
	cout << "----------------------------------------\n";
	cout << "��ȭ�� : �����̾���ȭ 3��" << endl;
	cout << "���ΰ� : Ȳ����" << endl;
	cout << "�ٰŸ� :\n";
	cout << "�� ����, �� ��� �� ����, �� �ִ� �� ���� Ư�� ���»�� ��� ���������. �������� �Ѵ� ���� ���˸� ";
	cout << "�ذ��� �� ���� �������� ����, ����ö�� ��� 3�� �����¿���(������)�� ������ �ȴ�. ���� ������ �� ���� ";
	cout << "���Ϲ����� ���¿��� ������ ���� ���� ��Ű�� ������ ���ֻ󹫡�(������).����ö�� �ǹ��� ����� �Ѵ� �� ";
	cout << "�׵��� ����� ���Ŀ� ������ �����Ѵ�. �ǵ�� ��ģ�ٴ� ����� �ұ��ϰ� �������� �ʴ� ����ö�� ���信 ";
	cout << "���� ������ �� ���� Ŀ������ ���¿��� �̸� ������ �ϵ� ������ �������� ���� �����µ�\n";

	cout << "���� : " << nTicketPrice << endl;
}

// �¼� �����ϱ�
void Screen::reserveTicket() {
	int row = 0, col = 0;	// �Է¹��� ��� ��

	cout << "     [ �¼� ���� ]" << endl;
	cout << "�¼� �� ��ȣ �Է�(1 - " << nRowMax << ") : ";
	cin >> row;
	cout << "�¼� �� ��ȣ �Է�(1 - " << nColMax << ") : ";
	cin >> col;
	if (0 < row && row <= nRowMax && 0 < col && col <= nColMax) {			// ���� �¼��� �󿵰��� �ִٸ�
		if (pSeatArray[row - 1][col - 1].getCheck() == SEAT_RESERVED_MARK)	// ���� ����� �¼��̶��
			cout << "�̹� ����� �¼��Դϴ�.\n";
		else {	// ���� ����� �¼��� �ƴ϶��
			pSeatArray[row - 1][col - 1].setSeat(row, col);					// �¼���ȣ ����
			pSeatArray[row - 1][col - 1].setReservedID(nCurrentReservedId);	// �¼� ���� ��ȣ ����
			pSeatArray[row - 1][col - 1].setCheck(SEAT_RESERVED_MARK);		// �¼� ���� ���θ� 'R'�� �ٲ�
			cout << "��[" << row << "] " << "��[" << col << "] " << nCurrentReservedId << " ���� ��ȣ�� �����Ǿ����ϴ�." << endl;
			nCurrentReservedId++;	// ���� ��ȣ 1 ����
		}
	}
	else		// ���� �¼��� �󿵰��� ���ٸ�
		cout << "�ش��ϴ� �¼��� �����ϴ�.\n";
	
}

// ���� ��ȣ Ȯ��
Ticket* Screen::checkReservedID(int id) {
	for (int i = 0; i < nRowMax; i++)						// �¼��� ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < nColMax; j++)					// �¼��� ���� ũ�⸸ŭ �ݺ�
			if (pSeatArray[i][j].getReservedID() == id)		// ���� ��ȣ�� �´� �¼��� �ִٸ�
				return 0;									// 0 ����
	cout << "���� ������ �����ϴ�.\n";
}

// �¼� ���� ����ϱ�
void Screen::cancelReservation() {
	int reserved = 0;	// �Է¹��� ���� ��ȣ
	bool flag = 0;		// ���� for���� �����ϱ� ���� ����
	cout << "     [ �¼� ���� ��� ]" << endl;
	cout << "���� ��ȣ �Է� : ";
	cin >> reserved;
	if (checkReservedID(reserved) == 0) {	// ��ġ�ϴ� �����ȣ�� �ִٸ�
		int i = 0, j = 0;
		for (i = 0; i < nRowMax; i++) {		// �¼��� ���� ũ�⸸ŭ �ݺ�
			for (j = 0; j < nColMax; j++) 	// �¼��� ���� ũ�⸸ŭ �ݺ�
				if (pSeatArray[i][j].getReservedID() == reserved) {	// ���� ��ȣ�� ���� �迭�� ã�Ҵٸ�
					flag = 1;	// ���� for�� ����
					break;		// ���� for�� ����
				}
			if (flag)			// ���� for�� ����
				break;			// ���� for�� ����
		}
		if (pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK)	// �¼� ���� ���ΰ� '$'���
			cout << "���� �Ϸ� �� ���� ��Ұ� �Ұ����մϴ�.\n";
		else {	// �¼� ���� ���ΰ� '$'�� �ƴ϶��
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);	// ���� ���θ� '-'�� �ٲ�
			pSeatArray[i][j].setReservedID(0);			// ���� ��ȣ�� 0���� �ٲ�
			cout << reserved << " ���� ��ȣ�� ��� ó���Ǿ����ϴ�." << endl;
		}
	}
}

// �����ϱ�
void Screen::Payment() {
	int reserved = 0;		// �Է¹��� �����ȣ
	int choice = 0;			// ���� ����� ���� ����
	char num[100];			// �� ������ �Է¹��� ����
	int length = 0;			// �Է¹��� ���� ���̸� Ȯ���� ����
	string name;			// ������ �̸�
	bool flag = 0;			// ���� for���� �����ϱ� ���� ����
	cout << "     [ �¼� ���� ���� ]" << endl;
	cout << "���� ��ȣ �Է� : ";
	cin >> reserved;
	
	if (checkReservedID(reserved) == 0) {	// ��ġ�ϴ� �����ȣ�� �ִٸ�
		int i = 0, j = 0;
		for (i = 0; i < nRowMax; i++) {		// �¼��� ���� ũ�⸸ŭ �ݺ�
			for (j = 0; j < nColMax; j++)	// �¼��� ���� ũ�⸸ŭ �ݺ�
				if (pSeatArray[i][j].getReservedID() == reserved) {
					flag = 1;	// ���� for�� ����
					break;		// ���� for�� ����
				}
			if (flag)			// ���� for�� ����
				break;			// ���� for�� ����
		}
		if (pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK)	// �¼� ���� ���ΰ� '$'���
			cout << "�̹� ������ �����ȣ�Դϴ�.\n";
		else {	// �¼� ���� ���ΰ� '$'�� �ƴ϶��
			cout << "----------------------------------------\n";
			cout << "            ���� ��� ����\n";
			cout << "----------------------------------------\n";
			cout << "1. ����� ����" << endl;
			cout << "2. ���� ��ü ����" << endl;
			cout << "3. ī�� ����" << endl;
			cout << "\n���� ��� (1~3) : ";
			cin >> choice;
			pSeatArray[i][j].setPayMethod(choice);				// ���� ��ȣ�� nPayMethod�� ����

			if (choice == MOBILE_PHONE_PAYMENT) {				// ���� ��ȣ�� 1���̶��
				MobilePay* Mobile = new MobilePay(MOBILE_PHONE_INTEREST_RATE);	// ������ ������ �Ű������� ���� ��ü�� ���� ����
				int price = Mobile->charge(getTicketPrice());	// �����Ḧ ������ ������ ����
				pSeatArray[i][j].setPayAmount(price);			// �����Ḧ ������ ������ nPayAmount�� ����
				cout << "       [ ����� ���� ]" << endl;
				cout << "�ڵ��� ��ȣ �Է� (11�ڸ� ��) : ";
				cin >> num;
				length = strlen(num);		// num�� ���� Ȯ��
				while (length != 11) {		// 11�ڸ� ���� �ƴϸ� �ݺ�
					cout << "11�ڸ� ���� �Է����ּ���.\n";
					cout << "�ڵ��� ��ȣ �Է� (11�ڸ� ��) : ";
					cin >> num;
					length = strlen(num);	// num�� ���� Ȯ��
				}
				cout << "�̸� : ";
				cin >> name;
				cout << "����� ������ �Ϸ�Ǿ����ϴ�. : " << pSeatArray[i][j].getPayAmount() << endl;	// ���� �ݾ� ���
				pSeatArray[i][j].setCheck(SEAT_COMPLETION_MARK);	// ���� ���θ� '$'�� �ٲ�
				delete Mobile;										// ���� ������ ��ü ����
			}
			else if (choice == BANK_TRANSFER_PAYMENT) {			// ���� ��ȣ�� 2���̶��
				BankTransfer* Bank = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);	// ������ ������ �Ű������� ���� ��ü�� ���� ����
				int price = Bank->charge(getTicketPrice());		// �����Ḧ ������ ������ ����
				pSeatArray[i][j].setPayAmount(price);			// �����Ḧ ������ ������ nPayAmount�� ����
				cout << "       [ KPU ���� ���� ]" << endl;
				cout << "���� ��ȣ �Է� (12�ڸ� ��) : ";
				cin >> num;
				length = strlen(num);		// num�� ���� Ȯ��
				while (length != 12) {		// 12�ڸ� ���� �ƴϸ� �ݺ�
					cout << "12�ڸ� ���� �Է����ּ���.\n";
					cout << "���� ��ȣ �Է� (12�ڸ� ��) : ";
					cin >> num;
					length = strlen(num);	// num�� ���� Ȯ��
				}
				cout << "�̸� : ";
				cin >> name;
				cout << "KPU ���� ������ �Ϸ�Ǿ����ϴ�. : " << pSeatArray[i][j].getPayAmount() << endl;	// ���� �ݾ� ���
				pSeatArray[i][j].setCheck(SEAT_COMPLETION_MARK);// ���� ���θ� '$'�� �ٲ�
				delete Bank;									// ���� ������ ��ü ����
			}
			else if (choice == CREDIT_CARD_PAYMENT) {			// ���� ��ȣ�� 3���̶��
				CardPay* Card = new CardPay(CREDIT_CARD_INTEREST_RATE);	// ������ ������ �Ű������� ���� ��ü�� ���� ����
				int price = Card->charge(getTicketPrice());		// �����Ḧ ������ ������ ����
				pSeatArray[i][j].setPayAmount(price);			// �����Ḧ ������ ������ nPayAmount�� ����
				cout << "       [ �ſ�ī�� ���� ]" << endl;
				cout << "ī�� ��ȣ �Է� (12�ڸ� ��) : ";
				cin >> num;
				length = strlen(num);		// num�� ���� Ȯ��
				while (length != 12) {		// 12�ڸ� ���� �ƴϸ� �ݺ�
					cout << "12�ڸ� ���� �Է����ּ���.\n";
					cout << "ī�� ��ȣ �Է� (12�ڸ� ��) : ";
					cin >> num;
					length = strlen(num);	// num�� ���� Ȯ��
				}
				cout << "�̸� : ";
				cin >> name;
				cout << "�ſ�ī�� ������ �Ϸ�Ǿ����ϴ�. : " << pSeatArray[i][j].getPayAmount() << endl;	// ���� �ݾ� ���
				pSeatArray[i][j].setCheck(SEAT_COMPLETION_MARK);	// ���� ���θ� '$'�� �ٲ�
				delete Card;										// ���� ������ ��ü ����
			}
			else
				cout << "�ش� ��ȣ�� ���� ������ �����ϴ�.";
		}
	}
}
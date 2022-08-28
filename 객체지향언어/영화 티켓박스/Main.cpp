#include <iostream>
#include <string>
#include "Screen.h"
#include "TicketBox.h"
using namespace std;

int main() {
	TUKoreaTBox tBox;
	Screen* screen = NULL;
	bool bScreenMenu = true;
	int select = 0;

	tBox.Initialize(); // 3���� ��ũ�� ��ü ����
	while (1) {
		if (bScreenMenu) {
			screen = tBox.selectMenu();
			bScreenMenu = false;
			if (!screen)
				return 0;
		}
		screen->showMovieMenu();
		cout << "�޴��� �����ϼ���: ";
		cin >> select; cout << endl;
		switch (select) {
		case 1:							// �޴� 1��
			screen->showMovieInfo();	// ��ȭ ����
			break;
		case 2: 						// �޴� 2��
			screen->showSeatMap();		// ���� ��Ȳ
			break;
		case 3: 						// �޴� 3��
			screen->reserveTicket();	// ���� �ϱ�
			break;
		case 4: 						// �޴� 4��
			screen->cancelReservation();// ���� ���
			break;
		case 5: 						// �޴� 5��
			screen->Payment();			// ���� �ϱ�
			break;
		case 7: 						// �޴� 7��
			bScreenMenu = true;			// ���� �޴� �̵�
			break;
		}
	}
	return 0;
}
#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include "Ticket.h"
using namespace std;

class Screen {
protected:
	int nTicketPrice;		// Ƽ�� ����
	int nRowMax, nColMax;	// �¼� ��� �� �ִ� ��
	int nCurrentReservedId = 100;	// �߱޵� ������ ���� ��ȣ
	Ticket** pSeatArray;	// ��ũ�� �¼��� ���� Ƽ�� �迭
	string strMovieName;	// ��ũ�� ������ ��ȭ ����

	// �߰� ��� 2
	Ticket* checkReservedID(int id);	// ���� ��ȣ Ȯ��
public:
	Screen(string name, int price, int row, int col);
	~Screen();
	void showSeatMap();					// �¼� ���� ���� ������ ����
	virtual void showMovieMenu();		// ��ȭ ���� �޴�
	virtual void showMovieInfo() = 0;	// ��ȭ �Ұ� ����

	// �߰� ��� 1
	void reserveTicket();		// �¼� �����ϱ�

	// �߰� ��� 2
	void cancelReservation();	// �¼� ���� ����ϱ�

	// �߰� ��� 3
	int getTicketPrice() { return nTicketPrice; }
	void Payment();				// �����ϱ�

	// �߰� ��� 4
	int getRowMax() { return nRowMax; }
	int getColMax() { return nColMax; }
	Ticket** getTicketArray() { return pSeatArray; }
};

class EuropeScreen : public Screen {
public:
	EuropeScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};

class AsiaScreen : public Screen {
public:
	AsiaScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};

class PremiumScreen : public Screen {
public:
	PremiumScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};
#endif
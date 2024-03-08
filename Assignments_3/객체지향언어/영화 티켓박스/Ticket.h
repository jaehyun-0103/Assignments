#ifndef TICKET_H
#define TICKET_H
#include "Screen.h"
#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
	int nRow; // �¼� ��
	int nCol; // �¼� ��
	char charCheck; // ���� ����
	int nReservedID; // ���� ��ȣ
	int nPayAmount; // ���� �ݾ�
	int nPayMethod; // ���� ����
public:
	Ticket() {}
	void setCheck(char check) { charCheck = check; }
	char getCheck() { return charCheck; }

	// �߰� ��� 1
	void setSeat(int row, int col) { nRow = row; nCol = col; }	// �¼� ��ȣ ����
	void setReservedID(int reserved) { nReservedID = reserved; }// �¼� ���� ��ȣ ����

	// �߰� ��� 2
	int getReservedID() { return nReservedID; }					// �¼� ���� ��ȣ �б�

	// �߰� ��� 3
	void setPayAmount(int amount) { nPayAmount = amount; }
	int getPayAmount() { return nPayAmount; }
	void setPayMethod(int method) { nPayMethod = method; }
};
#endif
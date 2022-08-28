#include <iostream>
#include "Statistics.h"
using namespace std;

// ��ũ�� �� �� Ƽ�� ���� �ݾ� �Ѿ�
int Statistics::totalRevenue(Screen* pScreen) {
	Ticket** Array = pScreen->getTicketArray();	// Ƽ�� �迭 ����
	int total = 0;	// Ƽ�� ���� �ݾ� �Ѿ�
	
	for (int i = 0; i < pScreen->getRowMax(); i++)				// �¼��� ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < pScreen->getColMax(); j++) 			// �¼��� ���� ũ�⸸ŭ �ݺ�
			if (Array[i][j].getCheck() == SEAT_COMPLETION_MARK)	// ���� ���ΰ� ������($)�̶��
				total += Array[i][j].getPayAmount();			// �Ѿ׿� ����
	return total;	// �Ѿ� ����
}

// ��ũ�� ��ü Ƽ�� �Ǹŷ�
int Statistics::totalSalesCount(Screen* pScreen) {
	Ticket** Array = pScreen->getTicketArray();	// Ƽ�� �迭 ����
	int num = 0;	// ��ü Ƽ�� �Ǹŷ�
	
	for (int i = 0; i < pScreen->getRowMax(); i++)				// �¼��� ���� ũ�⸸ŭ �ݺ�
		for (int j = 0; j < pScreen->getColMax(); j++)	 		// �¼��� ���� ũ�⸸ŭ �ݺ�
			if (Array[i][j].getCheck() == SEAT_COMPLETION_MARK)	// ���� ���ΰ� ������($)�̶��
				num += 1;										// 1�� Ƽ�� �Ǹŷ��� ����
	return num;		// ��ü Ƽ�� �Ǹŷ� ����
}
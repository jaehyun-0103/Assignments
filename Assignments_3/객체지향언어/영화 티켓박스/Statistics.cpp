#include <iostream>
#include "Statistics.h"
using namespace std;

// 스크린 관 별 티켓 결제 금액 총액
int Statistics::totalRevenue(Screen* pScreen) {
	Ticket** Array = pScreen->getTicketArray();	// 티켓 배열 선언
	int total = 0;	// 티켓 결제 금액 총액
	
	for (int i = 0; i < pScreen->getRowMax(); i++)				// 좌석의 행의 크기만큼 반복
		for (int j = 0; j < pScreen->getColMax(); j++) 			// 좌석의 열의 크기만큼 반복
			if (Array[i][j].getCheck() == SEAT_COMPLETION_MARK)	// 예약 여부가 결제함($)이라면
				total += Array[i][j].getPayAmount();			// 총액에 더함
	return total;	// 총액 리턴
}

// 스크린 전체 티켓 판매량
int Statistics::totalSalesCount(Screen* pScreen) {
	Ticket** Array = pScreen->getTicketArray();	// 티켓 배열 선언
	int num = 0;	// 전체 티켓 판매량
	
	for (int i = 0; i < pScreen->getRowMax(); i++)				// 좌석의 행의 크기만큼 반복
		for (int j = 0; j < pScreen->getColMax(); j++)	 		// 좌석의 열의 크기만큼 반복
			if (Array[i][j].getCheck() == SEAT_COMPLETION_MARK)	// 예약 여부가 결제함($)이라면
				num += 1;										// 1을 티켓 판매량에 더함
	return num;		// 전체 티켓 판매량 리턴
}
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

	tBox.Initialize(); // 3개의 스크린 객체 생성
	while (1) {
		if (bScreenMenu) {
			screen = tBox.selectMenu();
			bScreenMenu = false;
			if (!screen)
				return 0;
		}
		screen->showMovieMenu();
		cout << "메뉴를 선택하세요: ";
		cin >> select; cout << endl;
		switch (select) {
		case 1:							// 메뉴 1번
			screen->showMovieInfo();	// 영화 정보
			break;
		case 2: 						// 메뉴 2번
			screen->showSeatMap();		// 예약 현황
			break;
		case 3: 						// 메뉴 3번
			screen->reserveTicket();	// 예약 하기
			break;
		case 4: 						// 메뉴 4번
			screen->cancelReservation();// 예약 취소
			break;
		case 5: 						// 메뉴 5번
			screen->Payment();			// 결제 하기
			break;
		case 7: 						// 메뉴 7번
			bScreenMenu = true;			// 메인 메뉴 이동
			break;
		}
	}
	return 0;
}
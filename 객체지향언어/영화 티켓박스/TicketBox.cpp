#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

// 생성자
TUKoreaTBox::TUKoreaTBox() { }

// 소멸자
TUKoreaTBox::~TUKoreaTBox() { cout << "\n???\n"; }

// 상영관 선택 메뉴
Screen* TUKoreaTBox::selectMenu() {
	int chose = 0;	// 선택한 메뉴 번호
	cout << "------------------------------\n";
	cout << "       상영관 메인 메뉴" << endl;
	cout << "------------------------------\n";
	cout << "1.   유럽   영화 1관" << endl;
	cout << "2.  아시아  영화 2관" << endl;
	cout << "3. 프리미엄 영화 3관" << endl;
	cout << "9.   통계   관리" << endl << endl;
	cout << "선택(1~3, 9) 그외 종료 : ";
	cin >> chose;

	if (chose == 1) {			// 1을 골랐다면
		return pEuropeScreen;	// 객체 pEuropeScreen 반환
	}
	else if (chose == 2) {		// 2를 골랐다면
		return pAsiaScreen;		// 객체 pAsiaScreen 반환
	}
	else if (chose == 3) {		// 3을 골랐다면
		return pPremiumScreen;	// 객체 pPremiumScreen 반환
	}
	else if (chose == 9) {		// 9를 골랐다면
		Manage();				// 통계 관리
		cout << "\n프로그램을 종료합니다.\n";
		delete pEuropeScreen;	// 동적 생성한 객체 해제
		delete pAsiaScreen;		// 동적 생성한 객체 해제
		delete pPremiumScreen;	// 동적 생성한 객체 해제
		exit(1);				// 프로그램 종료
	}
	else {						// 다른 번호를 골랐다면
		cout << "프로그램을 종료합니다.\n";
		exit(1);				// 프로그램 종료
	}
}

// 스크린 객체 생성
void TUKoreaTBox::Initialize() {
	// Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
	pEuropeScreen = new EuropeScreen("범죄도시2", 10000, 10, 10);	// 동적으로 객체 생성
	pAsiaScreen = new AsiaScreen("리틀 포레스트", 12000, 10, 10);	// 동적으로 객체 생성
	pPremiumScreen = new PremiumScreen("베테랑", 30000, 6, 6);		// 동적으로 객체 생성
}

// 통계 관리
void TUKoreaTBox::Manage() {
	string passwd;	// 입력한 비밀번호
	cout << "\n------------------------------\n";
	cout << "         관리자 메뉴" << endl;
	cout << "------------------------------\n";
	while (true) {	// 무한 반복문
		cout << "관리자 비밀번호 입력 : ";
		cin >> passwd;
		if (passwd == TICKETBOX_MANAGER_PWD)	// 관리자 비밀번호가 맞다면
			break;	// 반복문 종료
		cout << "비밀번호가 틀렸습니다.\n";
	}
	cout << "\n1. 유럽영화 상영관 결제금액 : " << Statistics::totalRevenue(pEuropeScreen) << endl;		// 1관 총액을 리턴하는 함수 호출
	cout << "2. 아시아영화 상영관 결제금액 : " << Statistics::totalRevenue(pAsiaScreen) << endl;		// 2관 총액을 리턴하는 함수 호출
	cout << "3. 프리미엄영화 상영관 결제금액 : " << Statistics::totalRevenue(pPremiumScreen) << endl;	// 3관 총액을 리턴하는 함수 호출
	cout << "4. 전체 티켓 판매량 : " << Statistics::totalSalesCount(pEuropeScreen) +
		Statistics::totalSalesCount(pAsiaScreen) + Statistics::totalSalesCount(pPremiumScreen) << endl;	// 상영관의 총 티켓 판매량을 리턴하는 함수 각각 호출해서 더함
}
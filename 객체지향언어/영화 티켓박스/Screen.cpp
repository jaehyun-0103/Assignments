#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"
using namespace std;

// 생성자
Screen::Screen(string name, int price, int row, int col) {
	strMovieName = name;
	nRowMax = row;
	nColMax = col;
	nTicketPrice = price;
	pSeatArray = new Ticket * [nRowMax];	// 동적 생성
	for (int r = 0; r < nRowMax; r++) {		// 좌석의 행의 크기만큼 반복
		pSeatArray[r] = new Ticket[nColMax];// 동적 생성
	}
	for (int i = 0; i < nRowMax; i++) {		// 좌석의 행의 크기만큼 반복
		for (int j = 0; j < nColMax; j++) {	// 좌석의 열의 크기만큼 반복
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);	// 모든 좌석의 예약 여부를 비어있음(-)으로 변경
		}
	}
}

// 소멸자
Screen::~Screen() {
	for (int n = 0; n < nRowMax; n++)
		delete[] pSeatArray[n];				// 동적 생성한 객체 해제
	delete[] pSeatArray;					// 동적 생성한 객체 해제
}	


// 좌석 예약 여부 맵으로 보기
void Screen::showSeatMap() {
	cout << "\t[ 좌석 예약 현황 ]\n";

	cout << "\t";
	for (int i = 0; i < nColMax; i++) {		// 좌석의 열의 크기만큼 반복
		cout << "[" << i + 1 << "] ";		// 열 번호 출력
	}

	cout << endl;
	for (int i = 0; i < nRowMax; i++) {		// 좌석의 행의 크기만큼 반복
		cout << "[" << i + 1 << "]\t";		// 행 번호 출력
		for (int j = 0; j < nColMax; j++) {	// 좌석의 열의 크기만큼 반복
			cout << "[" << pSeatArray[i][j].getCheck() << "] ";	// 좌석별 예약 여부 출력
		}
		cout << "\n";
	}
}

// 영화 예매 메뉴
void Screen::showMovieMenu() {
	cout << "\n----------------------------------------\n";
	cout << "        영화 메뉴 - " << strMovieName << endl;
	cout << "----------------------------------------\n";
	cout << "1. 영화 정보" << endl;
	cout << "2. 예약 현황" << endl;
	cout << "3. 예약 하기" << endl;
	cout << "4. 예약 취소" << endl;
	cout << "5. 결제 하기" << endl;
	cout << "7. 메인 메뉴 이동" << endl;
}

// 유럽 영화관 소개 정보
void EuropeScreen::showMovieInfo() {
	cout << "----------------------------------------\n";
	cout << "             [" << strMovieName << "]" << endl;
	cout << "----------------------------------------\n";
	cout << "영화관 : 유럽영화 1관" << endl;
	cout << "주인공 : 마동석" << endl;
	cout << "줄거리 :\n";
	cout << "가리봉동 소탕작전 후 4년 뒤, 금천서 강력반은 베트남으로 도주한 용의자를 인도받아 오라는 미션을 ";
	cout << "받는다. 괴물형사 ‘마석도’(마동석)와 ‘전일만’(최귀화) 반장은 현지 용의자에게서 수상함을 ";
	cout << "느끼고, 그의 뒤에 무자비한 악행을 벌이는 ‘강해상’(손석구)이 있음을 알게 된다.\n";

	cout << "가격 : " << nTicketPrice << endl;
}

// 아시아 영화관 소개 정보
void AsiaScreen::showMovieInfo() {
	cout << "----------------------------------------\n";
	cout << "            [" << strMovieName << "]" << endl;
	cout << "----------------------------------------\n";
	cout << "영화관 : 아시아영화 2관" << endl;
	cout << "주인공 : 김태리" << endl;
	cout << "줄거리 :\n";
	cout << "시험, 연애, 취업… 뭐하나 뜻대로 되지 않는 일상을 잠시 멈추고 고향으로 돌아온 혜원은 오랜 친구인 ";
	cout << "재하와 은숙을 만난다. 남들과는 다른, 자신만의 삶을 살기 위해 고향으로 돌아온 ‘재하’, ";
	cout << "평범한 일상에서의 일탈을 꿈꾸는 ‘은숙’과 함께 직접 키운 농작물로 한끼 한끼를 만들어 먹으며 ";
	cout << "겨울에서 봄, 그리고 여름, 가을을 보내고 다시 겨울을 맞이하게 된 혜원. 그렇게 특별한 사계절을 보내며 ";
	cout << "고향으로 돌아온 진짜 이유를 깨닫게 된 혜원은 새로운 봄을 맞이하기 위한 첫 발을 내딛는데\n";

	cout << "가격 : " << nTicketPrice << endl;
}

// 프리미엄 영화관 소개 정보
void PremiumScreen::showMovieInfo() {
	cout << "----------------------------------------\n";
	cout << "               [" << strMovieName << "]" << endl;
	cout << "----------------------------------------\n";
	cout << "영화관 : 프리미엄영화 3관" << endl;
	cout << "주인공 : 황정민" << endl;
	cout << "줄거리 :\n";
	cout << "겁 없고, 못 잡는 것 없고, 봐 주는 것 없는 특수 강력사건 담당 광역수사대. 오랫동안 쫓던 대형 범죄를 ";
	cout << "해결한 후 숨을 돌리려는 찰나, 서도철은 재벌 3세 ‘조태오’(유아인)를 만나게 된다. 세상 무서울 것 없는 ";
	cout << "안하무인의 조태오와 언제나 그의 곁을 지키는 오른팔 ‘최상무’(유해진).서도철은 의문의 사건을 쫓던 중 ";
	cout << "그들이 사건의 배후에 있음을 직감한다. 건들면 다친다는 충고에도 불구하고 포기하지 않는 서도철의 집념에 ";
	cout << "판은 걷잡을 수 없이 커져가고 조태오는 이를 비웃기라도 하듯 유유히 포위망을 빠져 나가는데\n";

	cout << "가격 : " << nTicketPrice << endl;
}

// 좌석 예약하기
void Screen::reserveTicket() {
	int row = 0, col = 0;	// 입력받을 행과 열

	cout << "     [ 좌석 예약 ]" << endl;
	cout << "좌석 행 번호 입력(1 - " << nRowMax << ") : ";
	cin >> row;
	cout << "좌석 열 번호 입력(1 - " << nColMax << ") : ";
	cin >> col;
	if (0 < row && row <= nRowMax && 0 < col && col <= nColMax) {			// 만약 좌석이 상영관에 있다면
		if (pSeatArray[row - 1][col - 1].getCheck() == SEAT_RESERVED_MARK)	// 만약 예약된 좌석이라면
			cout << "이미 예약된 좌석입니다.\n";
		else {	// 만약 예약된 좌석이 아니라면
			pSeatArray[row - 1][col - 1].setSeat(row, col);					// 좌석번호 저장
			pSeatArray[row - 1][col - 1].setReservedID(nCurrentReservedId);	// 좌석 예약 번호 저장
			pSeatArray[row - 1][col - 1].setCheck(SEAT_RESERVED_MARK);		// 좌석 예약 예부를 'R'로 바꿈
			cout << "행[" << row << "] " << "열[" << col << "] " << nCurrentReservedId << " 예약 번호로 접수되었습니다." << endl;
			nCurrentReservedId++;	// 예약 번호 1 증가
		}
	}
	else		// 만약 좌석이 상영관에 없다면
		cout << "해당하는 좌석이 없습니다.\n";
	
}

// 예약 번호 확인
Ticket* Screen::checkReservedID(int id) {
	for (int i = 0; i < nRowMax; i++)						// 좌석의 행의 크기만큼 반복
		for (int j = 0; j < nColMax; j++)					// 좌석의 열의 크기만큼 반복
			if (pSeatArray[i][j].getReservedID() == id)		// 예약 번호와 맞는 좌석이 있다면
				return 0;									// 0 리턴
	cout << "예약 정보가 없습니다.\n";
}

// 좌석 예약 취소하기
void Screen::cancelReservation() {
	int reserved = 0;	// 입력받을 예약 번호
	bool flag = 0;		// 이중 for문을 종료하기 위한 변수
	cout << "     [ 좌석 예약 취소 ]" << endl;
	cout << "예약 번호 입력 : ";
	cin >> reserved;
	if (checkReservedID(reserved) == 0) {	// 일치하는 예약번호가 있다면
		int i = 0, j = 0;
		for (i = 0; i < nRowMax; i++) {		// 좌석의 행의 크기만큼 반복
			for (j = 0; j < nColMax; j++) 	// 좌석의 열의 크기만큼 반복
				if (pSeatArray[i][j].getReservedID() == reserved) {	// 예약 번호가 같은 배열을 찾았다면
					flag = 1;	// 이중 for문 종료
					break;		// 이중 for문 종료
				}
			if (flag)			// 이중 for문 종료
				break;			// 이중 for문 종료
		}
		if (pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK)	// 좌석 예약 여부가 '$'라면
			cout << "결제 완료 시 예약 취소가 불가능합니다.\n";
		else {	// 좌석 예약 여부가 '$'가 아니라면
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);	// 예약 여부를 '-'로 바꿈
			pSeatArray[i][j].setReservedID(0);			// 예약 번호를 0으로 바꿈
			cout << reserved << " 예약 번호가 취소 처리되었습니다." << endl;
		}
	}
}

// 결제하기
void Screen::Payment() {
	int reserved = 0;		// 입력받을 예약번호
	int choice = 0;			// 결제 방식을 받을 변수
	char num[100];			// 긴 정수를 입력받을 변수
	int length = 0;			// 입력받은 문자 길이를 확인할 변수
	string name;			// 결제자 이름
	bool flag = 0;			// 이중 for문을 종료하기 위한 변수
	cout << "     [ 좌석 예약 결제 ]" << endl;
	cout << "예약 번호 입력 : ";
	cin >> reserved;
	
	if (checkReservedID(reserved) == 0) {	// 일치하는 예약번호가 있다면
		int i = 0, j = 0;
		for (i = 0; i < nRowMax; i++) {		// 좌석의 행의 크기만큼 반복
			for (j = 0; j < nColMax; j++)	// 좌석의 열의 크기만큼 반복
				if (pSeatArray[i][j].getReservedID() == reserved) {
					flag = 1;	// 이중 for문 종료
					break;		// 이중 for문 종료
				}
			if (flag)			// 이중 for문 종료
				break;			// 이중 for문 종료
		}
		if (pSeatArray[i][j].getCheck() == SEAT_COMPLETION_MARK)	// 좌석 예약 여부가 '$'라면
			cout << "이미 결제한 예약번호입니다.\n";
		else {	// 좌석 예약 여부가 '$'가 아니라면
			cout << "----------------------------------------\n";
			cout << "            결제 방식 선택\n";
			cout << "----------------------------------------\n";
			cout << "1. 모바일 결제" << endl;
			cout << "2. 은행 이체 결제" << endl;
			cout << "3. 카드 결제" << endl;
			cout << "\n결재 방식 (1~3) : ";
			cin >> choice;
			pSeatArray[i][j].setPayMethod(choice);				// 선택 번호를 nPayMethod에 저장

			if (choice == MOBILE_PHONE_PAYMENT) {				// 선택 번호가 1번이라면
				MobilePay* Mobile = new MobilePay(MOBILE_PHONE_INTEREST_RATE);	// 수수료 비율을 매개변수로 가진 객체를 동적 생성
				int price = Mobile->charge(getTicketPrice());	// 수수료를 적용한 가격을 구함
				pSeatArray[i][j].setPayAmount(price);			// 수수료를 적용한 가격을 nPayAmount에 저장
				cout << "       [ 모바일 결제 ]" << endl;
				cout << "핸드폰 번호 입력 (11자리 수) : ";
				cin >> num;
				length = strlen(num);		// num의 길이 확인
				while (length != 11) {		// 11자리 수가 아니면 반복
					cout << "11자리 수를 입력해주세요.\n";
					cout << "핸드폰 번호 입력 (11자리 수) : ";
					cin >> num;
					length = strlen(num);	// num의 길이 확인
				}
				cout << "이름 : ";
				cin >> name;
				cout << "모바일 결제가 완료되었습니다. : " << pSeatArray[i][j].getPayAmount() << endl;	// 결제 금액 출력
				pSeatArray[i][j].setCheck(SEAT_COMPLETION_MARK);	// 예약 여부를 '$'로 바꿈
				delete Mobile;										// 동적 생성한 객체 해제
			}
			else if (choice == BANK_TRANSFER_PAYMENT) {			// 선택 번호가 2번이라면
				BankTransfer* Bank = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);	// 수수료 비율을 매개변수로 가진 객체를 동적 생성
				int price = Bank->charge(getTicketPrice());		// 수수료를 적용한 가격을 구함
				pSeatArray[i][j].setPayAmount(price);			// 수수료를 적용한 가격을 nPayAmount에 저장
				cout << "       [ KPU 은행 결제 ]" << endl;
				cout << "은행 번호 입력 (12자리 수) : ";
				cin >> num;
				length = strlen(num);		// num의 길이 확인
				while (length != 12) {		// 12자리 수가 아니면 반복
					cout << "12자리 수를 입력해주세요.\n";
					cout << "은행 번호 입력 (12자리 수) : ";
					cin >> num;
					length = strlen(num);	// num의 길이 확인
				}
				cout << "이름 : ";
				cin >> name;
				cout << "KPU 은행 결제가 완료되었습니다. : " << pSeatArray[i][j].getPayAmount() << endl;	// 결제 금액 출력
				pSeatArray[i][j].setCheck(SEAT_COMPLETION_MARK);// 예약 여부를 '$'로 바꿈
				delete Bank;									// 동적 생성한 객체 해제
			}
			else if (choice == CREDIT_CARD_PAYMENT) {			// 선택 번호가 3번이라면
				CardPay* Card = new CardPay(CREDIT_CARD_INTEREST_RATE);	// 수수료 비율을 매개변수로 가진 객체를 동적 생성
				int price = Card->charge(getTicketPrice());		// 수수료를 적용한 가격을 구함
				pSeatArray[i][j].setPayAmount(price);			// 수수료를 적용한 가격을 nPayAmount에 저장
				cout << "       [ 신용카드 결제 ]" << endl;
				cout << "카드 번호 입력 (12자리 수) : ";
				cin >> num;
				length = strlen(num);		// num의 길이 확인
				while (length != 12) {		// 12자리 수가 아니면 반복
					cout << "12자리 수를 입력해주세요.\n";
					cout << "카드 번호 입력 (12자리 수) : ";
					cin >> num;
					length = strlen(num);	// num의 길이 확인
				}
				cout << "이름 : ";
				cin >> name;
				cout << "신용카드 결제가 완료되었습니다. : " << pSeatArray[i][j].getPayAmount() << endl;	// 결제 금액 출력
				pSeatArray[i][j].setCheck(SEAT_COMPLETION_MARK);	// 예약 여부를 '$'로 바꿈
				delete Card;										// 동적 생성한 객체 해제
			}
			else
				cout << "해당 번호의 결제 수단이 없습니다.";
		}
	}
}
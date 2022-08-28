#include <iostream>
#include "ATMachine.h"

using namespace std;

int main() {
	int select;	// 고객이 고른 메뉴 번호
	ATMachine atm(100, 50000, "admin");	// 고객수(100명), ATM 잔금 초기화, 관리자 암호
	while (1) {
		atm.displayMenu();			// displayMenu() 함수 호출
		cout << "메뉴를 선택하세요 : ";
		cin >> select;				// 메뉴 번호 입력
		switch (select) {			// 고른 메뉴 번호와 비교하여
		case 1:						// 1을 골랐다면
			atm.createAccount();	// createAccount() 함수 호출
			break;					// while 반복문 처음으로
		case 2:						// 2를 골랐다면
			atm.checkMoney();		// checkMoney() 함수 호출
			break;					// while 반복문 처음으로
		case 3:						// 3을 골랐다면
			atm.depositMoney();		// depositMoney() 함수 호출
			break;					// while 반복문 처음으로
		case 4:						// 4를 골랐다면
			atm.widrawMoney();		// widrawMoney() 함수 호출
			break;					// while 반복문 처음으로
		case 5:						// 5를 골랐다면
			atm.transfer();			// transfer() 함수 호출
			break;					// while 반복문 처음으로
		case 6:						// 6을 골랐다면
			atm.closeAccount();		// closeAccount() 함수 호출
			break;					// while 반복문 처음으로
		case 7:						// 7을 골랐다면
			atm.managerMode();		// managerMode() 함수 호출
			break;					// while 반복문 처음으로
		case 9:						// 9를 골랐다면
			cout << "\n안녕히 가세요" << endl;
			return 0;				// 프로그램 종료
		default:					// 해당하는 번호가 없으면
			cout << "번호 확인 후 다시 입력하세요.\n" << endl;
		}
	}
	return 0;
}
#include <iostream>
#include "ATMachine.h"
#include "Account.h"

using namespace std;

// 인증 성공 : true(1), 인증 실패 : false(0)
inline bool Account::authenticate(int id, string passwd) {
	if (strPassword == passwd)	// 입력한 비밀번호가 맞으면
		return true;			// true 리턴
	else						// 입력한 비밀번호가 틀리면
		return false;			// false 리턴
}

// 매개 변수 없는 생성자
Account::Account() { }

// 계좌 개설
void Account::create(int id, int money, string name, string password) {
	nID = id;				// 랜덤으로 배정받은 계좌번호인 id를 nID에 저장
	nBalance = money;		// 잔고인 money를 nBalance에 저장
	strAccountName = name;	// 고객 이름인 name을 strAccountName에 저장
	strPassword = password;	// 계좌 비밀번호인 password를 strPassword에 저장

	cout << strAccountName << "님 " << nID << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다.\n" << endl;
}

// return 값 : nBalance (잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
int Account::check(int id, string password) {
	if (authenticate(id, password)) {			// 비밀번호가 일치하면
		return nBalance;						// 잔고 리턴
	}
	else {										// 비밀번호가 일치하지 않으면
		cout << "비밀번호가 틀렸습니다." << endl << "초기 화면으로 돌아갑니다.\n" << endl;
		return AUTHENTIFICATION_FAIL;			// AUTHENTIFICATION_FAIL 리턴
	}
}

// 계좌 해지
void Account::close() {
	if (nBalance == 0)				// 잔고가 0이라면
		cout << nID << " 계좌가 해지되었습니다. 감사합니다.\n" << endl;
	else							// 잔고가 0이 아니라면
		cout << nID << " 계좌를 해지할 수 없습니다. 잔액 : " << nBalance << endl << endl;
}

// return 값 : nBalance (최종잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
int Account::deposit(int id, string password, int money) {
	if (authenticate(id, password)) {	// 비밀번호가 일치하면
		nBalance += money;				// 잔고에 입금액을 더함
		return nBalance;				// 잔고 리턴
	}
	else {								// 비밀번호가 일치하지 않으면
		cout << "비밀번호가 틀렸습니다." << endl << "초기 화면으로 돌아갑니다.\n" << endl;
		return AUTHENTIFICATION_FAIL;	// AUTHENTIFICATION_FAIL 리턴
	}
}

// return 값 : nBalance (최종잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
int Account::widraw(int id, string password, int money) {
	if (authenticate(id, password)) {		// 비밀번호가 일치하면
		if (nBalance - money >= 0) {		// 잔고가 충분하다면
			nBalance -= money;				// 잔고에 출금액을 뺌
			return nBalance;				// 잔고 리턴
		}
		else								// 잔고가 충분하지 않다면
			return AUTHENTIFICATION_FAIL;	// AUTHENTIFICATION_FAIL 리턴
	}
	else {								// 비밀번호가 일치하지 않으면
		cout << "비밀번호가 틀렸습니다." << endl << "초기 화면으로 돌아갑니다.\n" << endl;
		return AUTHENTIFICATION_FAIL;	// AUTHENTIFICATION_FAIL 리턴
	}
}

// return 값 : nBalance (최종 잔고)
int Account::deposit(int id, int money) {
	nBalance += money;	// 잔고에 이체금액을 더함
	return nBalance;	// 잔고 리턴
}
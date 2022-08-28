#include <iostream>
#include <stdlib.h>	// srand, rand를 사용하기 위한 헤더파일
#include <time.h>	// time을 사용하기 위한 헤더파일
#include "Account.h"
#include "ATMachine.h"
#include "Statistics.h"

using namespace std;

// 계좌 배열크기, ATM 잔고, 관리자 암호 초기화
ATMachine::ATMachine(int size, int balance, string password) {
	nCurrentAccountNum = size;		// 계좌 배열 크기인 size를 nCurrentAccountNum에 저장
	nMachineBalance = balance;		// ATM 잔고인 balance를 nMachineBalance에 저장
	strManagerPassword = password;
	pAcctArray = new Account[901];	// 크기가 901인 Account 객체 배열의 동적 생성
}

// 정산하는 소멸자
ATMachine::~ATMachine() {
	cout << "***현재 총 고객수 : " << nCurrentAccountNum << "***" << endl;
	delete[] pAcctArray;	// 동적 할당 해제
}

// ATM 기능 선택 화면
void ATMachine::displayMenu() {
	cout << "----------------------" << endl << " --  TUKOREA BANK  -- " << endl << "----------------------" << endl;
	cout << "1. 계좌 개설" << endl << "2. 계좌 조회" << endl << "3. 계좌 입금" << endl << "4. 계좌 출금" << endl <<
		"5. 계좌 이체" << endl << "6. 계좌 해지" << endl << "7. 고객 관리" << endl << "9. 업무 종료" << endl;
}

// 계좌 개설
void ATMachine::createAccount() {
	srand((unsigned)time(NULL));				// 난수 초기화
	int id = rand() % 901 + BASE_ACCOUNT_ID;	// 100부터 1000 사이의 숫자를 골라 id에 저장

	int money = 0;
	string name;
	string password;

	cout << endl << " --------개설-------- " << endl;
	cout << "이름 입력: ";
	cin >> name;			// 고객 이름 입력
	cout << "암호 입력: ";
	cin >> password;		// 계좌 비밀번호 입력

	pAcctArray[nMaxAccountNum].create(id, money, name, password);	// 배열의 nMaxAccountNum번째 객체의 create() 멤버 함수 호출
	nMaxAccountNum++;		// 동적 생성된 고객계좌 배열 크기인 nMaxAccountNum 1 증가
	nCurrentAccountNum++;	// 개설된 고객 계좌 수인 nCurrentAccountNum 1 증가
}

// 계좌 조회
void ATMachine::checkMoney() {
	int id;
	string password;

	cout << endl << " --------조회-------- " << endl;
	cout << "계좌번호 입력: ";
	cin >> id;			// 계좌번호 입력
	cout << "비밀번호 입력: ";
	cin >> password;	// 계좌 비밀번호 입력

	for (int i = 0; i < nMaxAccountNum; i++) {				// 계좌 배열크기만큼 반복
		if (pAcctArray[i].getAcctID() == id) {				// 입력한 계좌 번호와 일치하는 객체를 찾았다면
			int bal = pAcctArray[i].check(id, password);	// check() 멤버 함수의 리턴값을 bal에 저장
			if (bal == -1)	// 리턴값이 -1이면 (비밀번호가 틀림)
				break;		// 반복문 종료
			else			// 리턴값이 -1이 아니면 (비밀번호가 맞음)
				cout << "현재 잔액 : " << bal << endl << endl;
		}
	}
}

// 계좌 해지
void ATMachine::closeAccount() {
	int id;
	string password;
	cout << endl << " --------해지-------- " << endl;
	cout << "계좌번호 입력: ";
	cin >> id;			// 계좌번호 입력
	cout << "비밀번호 입력: ";
	cin >> password;	// 계좌 비밀번호 입력

	for (int i = 0; i < nMaxAccountNum; i++) {		// 계좌 배열크기만큼 반복
		if (pAcctArray[i].getAcctID() == id) {		// 입력한 계좌 번호와 일치하는 객체를 찾았다면
			pAcctArray[i].close();					// 그 객체의 close() 멤버 함수 호출
			int bal = pAcctArray[i].getBalance();	// getBalance() 멤버 함수의 리턴값을 bal에 저장
			if (bal == 0) {							// 리턴값이 0이면 (잔고가 0이라면)
				if (i == nMaxAccountNum - 1) {		// 계좌 정보가 배열의 마지막에 있다면
					nMaxAccountNum--;				// nMaxAccountNum 1 감소
					nCurrentAccountNum--;			// nCurrentAccountNum 1 감소
					break;							// 반복문 종료
				}
				else {								// 계좌 정보가 배열의 마지막에 있지 않다면
					for (int j = i + 1; j < nMaxAccountNum; j++)
						pAcctArray[j - 1] = pAcctArray[j];	// 계좌 정보를 배열의 마지막으로 이동
					nMaxAccountNum--;			// nMaxAccountNum 1 감소
					nCurrentAccountNum--;		// nCurrentAccountNum 1 감소
					break;						// 반복문 종료
				}
			}
			else			// 리턴값이 0이 아니라면 (잔고가 0이 아니라면)
				break;		// 반복문 종료
		}
	}
}

// 계좌 입금
void ATMachine::depositMoney() {
	int id;
	string password;
	int money;

	cout << endl << " --------입금-------- " << endl;
	cout << "계좌번호 입력: ";
	cin >> id;			// 계좌번호 입력
	cout << "비밀번호 입력: ";
	cin >> password;	// 계좌 비밀번호 입력
	cout << "입금액 입력: ";
	cin >> money;		// 임금액 입력

	for (int i = 0; i < nMaxAccountNum; i++) {						// 계좌 배열크기만큼 반복
		if (pAcctArray[i].getAcctID() == id) {						// 입력한 계좌 번호와 일치하는 객체를 찾았다면
			int bal = pAcctArray[i].deposit(id, password, money);	// deposit() 멤버 함수의 리턴값을 bal에 저장
			if (bal == -1)	// 리턴값이 -1이면 (비밀번호가 틀림)
				break;		// 반복문 종료
			else {			// 리턴값이 -1이 아니라면 (비밀번호가 맞음)
				cout << "현재 잔액 : " << bal << endl;
				cout << "입금 완료\n" << endl;
				nMachineBalance += bal;	// ATM 잔고에 금액 추가
			}
		}
	}
}

// 계좌 출금
void ATMachine::widrawMoney() {
	int id;
	string password;
	int money;

	cout << endl << " --------출금-------- " << endl;
	cout << "계좌번호 입력: ";
	cin >> id;			// 계좌번호 입력
	cout << "비밀번호 입력: ";
	cin >> password;	// 계좌 비밀번호 입력
	cout << "출금액 입력: ";
	cin >> money;		// 출금액 입력

	for (int i = 0; i < nMaxAccountNum; i++) {						// 계좌 배열크기만큼 반복
		if (pAcctArray[i].getAcctID() == id) {						// 입력한 계좌 번호와 일치하는 객체를 찾았다면
			int bal = pAcctArray[i].widraw(id, password, money);	// widraw() 멤버 함수의 리턴값을 bal에 저장
			if (bal == -1) {	// 리턴값이 -1이면 (잔고가 부족함)
				cout << "계좌에 잔고가 부족합니다.\n" << endl;
				break;			// 반복문 종료
			}
			else {				// 리턴값이 -1이 아니라면 (잔고가 충분함)
				if (nMachineBalance - money >= 0) {	// ATM 잔고가 충분하다면
					cout << "현재 잔액 : " << bal << endl;
					cout << "출금 완료\n" << endl;
					nMachineBalance -= money;			// 출금액만큼 ATM잔고에서 뺌
				}
				else			// ATM 잔고가 충분하지 않다면
					cout << "ATM기기에 잔고가 부족합니다.\n" << endl;
			}
		}
	}
}

// 이체하려할 때 잔고가 부족하다면 -1을 반환하고 입ㄺ한 금액이 오름
// 계좌 이체
void ATMachine::transfer() {
	int give_id, receive_id;// 이체할 계좌 id와 이체받을 계좌 id
	string password;
	int money = 0;
	int give_bal = 0;		// 이체할 계좌의 잔고

	cout << endl << " --------이체-------- " << endl;
	cout << "계좌번호 입력: ";
	cin >> give_id;		// 계좌번호 입력
	cout << "비밀번호 입력: ";
	cin >> password;	// 계좌 비밀번호 입력
	cout << "이체계좌 입력: ";
	cin >> receive_id;	// 이체계좌 입력
	cout << "이체금액 입력: ";
	cin >> money;		// 이체금액 입력

	for (int i = 0; i < nMaxAccountNum; i++)								// 계좌 배열크기만큼 반복
		if (pAcctArray[i].getAcctID() == give_id) 							// 입력한 계좌 번호와 일치하는 객체를 찾았다면
			give_bal = pAcctArray[i].widraw(give_id, password, money);		// widraw() 멤버 함수의 리턴값을 give_bal에 저장
	
	if (give_bal == -1)		// 리턴값이 -1이면 (잔고가 부족함)
		cout << "계좌에 잔고가 부족합니다.\n" << "이체 실패\n" << endl;
	else {					// 리턴값이 -1이 아니라면
		for (int i = 0; i < nMaxAccountNum; i++) {							// 계좌 배열크기만큼 반복
			if (pAcctArray[i].getAcctID() == receive_id) 					// 입력한 계좌 번호와 일치하는 객체를 찾았다면
				int receive_bal = pAcctArray[i].deposit(receive_id, money);	// deposit() 멤버 함수의 리턴값을 receive_bal에 저장
		}
		cout << "현재 잔액 : " << give_bal << endl;
		cout << "이체 완료\n" << endl;
	}
}

// 매니저 암호 확인
bool ATMachine::isManager(string password) {
	if (password == strManagerPassword)	// 암호가 일치하면
		return true;
	else 								// 암호가 일치하지 않으면
		return false;
}

// 통계 화면 처리
void ATMachine::displayReport() {
	cout << endl << " -------------------- " << endl;
	cout << "ATM 현재 잔고:\t" << nMachineBalance << "원" << endl;
	cout << "고객 잔고 총액:\t" << Statistics::sum(pAcctArray, nMaxAccountNum) << "원" << " (총" << nMaxAccountNum << "명)" << endl;	// 계좌 잔고 총합 출력
	cout << "고객 잔고 평균:\t" << Statistics::average(pAcctArray, nMaxAccountNum) << "원" << endl;										// 계좌 잔고 평균 츨력
	cout << "고객 잔고 최고:\t" << Statistics::max(pAcctArray, nMaxAccountNum) << "원" << endl;											// 계좌 잔고 최고 출력
	cout << " -------------------- " << endl;
	cout << " -- 고객 계좌 목록 -- " << endl;
	cout << " -------------------- " << endl;

	Statistics::sort(pAcctArray, nMaxAccountNum);	// 내림 차순 정렬 (잔액 기준)

	for (int i = 0; i < nMaxAccountNum; i++) {		// 계좌 개수만큼 반복
		cout << i + 1 << ". " << pAcctArray[i].getAccountName() << "\t"
			<< pAcctArray[i].getAcctID() << "\t" << pAcctArray[i].getBalance() << "원" << endl;
	}

	cout << "\n";
}

// 고객 관리
void ATMachine::managerMode() {
	string password;

	cout << endl << " --------관리-------- " << endl;
	cout << "관리자 비밀번호 입력: ";
	cin >> password;				// 관리자 암호를 입력

	if (isManager(password)) {		// 관리자 암호가 맞다면
		cout << "\n관리자입니다." << endl;
		displayReport();			// displayReport() 함수 호출
	}
	else							// 관리자 암호가 틀렸다면
		cout << "\n관리자가 아닙니다.\n" << endl;
}
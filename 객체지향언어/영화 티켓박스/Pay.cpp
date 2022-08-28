#include <iostream>
#include <string>
#include "Pay.h"
using namespace std;

// 모바일 결제 금액
int  MobilePay::charge(int amount) {	// 수수료를 부과하기 전의 금액인 매개변수
	amount = amount + amount * interest;// 결제금액 = 티켓 가격 + 티켓 가격 * 0.2
	return amount;						// 결제금액 리턴
}

// 은행 이체 결제 금액
int BankTransfer::charge(int amount) {	// 수수료를 부과하기 전의 금액인 매개변수
	amount = amount + amount * interest;// 결제금액 = 티켓 가격 + 티켓 가격 * 0.1
	return amount;						// 결제금액 리턴
}

// 카드 결제 금액
int CardPay::charge(int amount) {		// 수수료를 부과하기 전의 금액인 매개변수
	amount = amount + amount * interest;// 결제금액 = 티켓 가격 + 티켓 가격 * 0.15
	return amount;						// 결제금액 리턴
}
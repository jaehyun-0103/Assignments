#include <iostream>
#include "Statistics.h"
#include "Account.h"

using namespace std;

// 계좌 잔고 총합
int Statistics::sum(Account* pArray, int size) {
	int sumBal = 0;							// 총합을 저장할 변수 선언, 초기화
	for (int i = 0; i < size; i++)			// 계좌 개수만큼 반복
		sumBal += pArray[i].getBalance();	// 계좌들의 잔고를 더함
	return sumBal;							// 계좌 잔고 총합 리턴
}

// 계좌 잔고 평균
int Statistics::average(Account* pArray, int size) {
	int sumBal = 0;							// 총합을 저장할 변수 선언, 초기화
	if (size == 0)							// 만약 개설된 계좌가 없다면
		return 0;							// 함수 종료
	for (int i = 0; i < size; i++)			// 계좌 개수만큼 반복
		sumBal += pArray[i].getBalance();	// 계좌들의 잔고를 더함
	int aver = sumBal / size;				// 계좌 잔고 총합의 평균을 계산
	return aver;							// 계좌 잔고 총합의 평균 리턴
}

// 계좌 잔고 최고
int Statistics::max(Account* pArray, int size) {
	int max = pArray[0].getBalance();		// 계좌 잔고의 최대값을 첫번째 계좌 잔고로 초기화
	for (int i = 1; i < size; i++) 			// 계좌 개수만큼 반복
		if (max < pArray[i].getBalance())	// 만약 계좌 잔고의 최대값보다 크다면
			max = pArray[i].getBalance();	// 그 계좌의 잔고가 최대값
	return max;								// 최대값 리턴
}

// 내림 차순 정렬
void Statistics::sort(Account* pArray, int size) {
	Account tmp;
	for (int i = 0; i < size; i++)										// 계좌 개수만큼 반복
		for (int j = 0; j < (size - 1) - i; j++)						// 계좌의 개수보다 1 적게 반복
			if (pArray[j].getBalance() < pArray[j + 1].getBalance()) {	// 만약 [j] 인덱스의 잔고가 [j+1] 인덱스의 잔고보다 작다면
				tmp = pArray[j];			// [j] 인덱스를 tmp에 저장
				pArray[j] = pArray[j + 1];	// [j+1] 인덱스를 [j] 인덱스에 저장
				pArray[j + 1] = tmp;		// tmp를 [j+1] 인덱스에 저장
			}
}
#include<stdio.h>

extern int kor, eng, math;				// 다른 소스 파일에 있는 전역변수 kor, eng, math 사용
extern double aver;						// 다른 소스 파일에 있는 전역변수 aver 사용
extern double total;					// 다른 소스 파일에 있는 전역변수 total 사용

void myInput() {						// myInput() 함수 정의
	printf("국어 영어 수학 점수를 입력하시오 : ");	// 국어 영어 수학 점수를 입력하시오 : 출력
	scanf_s("%d %d %d", &kor, &eng, &math);			// 국어 영어 수학 점수 입력
}

double myOutput() {						// myOutput() 함수 정의
	int grade;							// 학점을 저장할 변수 선언
	aver = (kor + eng + math) / 3.0;	// 입력받은 값들로 평균 계산
	total = kor + eng + math;			// 입략받은 값들로 총합 계산
	if (total <= 100 && total >= 90)	// 총합이 90보다 크거나 같고 100보다 작거나 같으면
		grade = 'A';					// A학점
	else if (total >= 80)				// 총합이 80보다 크거나 같으면
		grade = 'B';					// B학점
	else if (total >= 70)				// 총합이 70보다 크거나 같으면
		grade = 'C';					// C학점
	else if (total >= 60)				// 총합이 60보다 크거나 같으면
		grade = 'D';					// D학점
	else								// 총합이 60보다 작으면
		grade = 'F';					// F학점
	printf("평균은 %.2lf, 총점은 %.2lf, 학점은 %c이다.", aver, total, grade);	// 평균, 총점, 학점 출력
}
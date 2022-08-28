extern int num1, num2;					// 다른 소스 파일에 있는 전역변수 num1, num2 사용
extern char op;							// 다른 소스 파일에 있는 전역변수 op 사용
extern double result;					// 다른 소스 파일에 있는 전역변수 result 사용

double func() {							// 사칙연산을 해주는 func() 함수 정의
	if (op == '+') {					// 만약 입력한 연산자가 + 라면
		result = num1 + num2;			// 입력받은 두 값의 합을 result에 저장
	}
	if (op == '-') {					// 만약 입력한 연산자가 - 라면
		result = num1 - num2;			// 입력받은 두 값의 합을 result에 저장 
	}
	if (op == '%') {					// 만약 입력한 연산자가 % 라면
		result = num1 % num2;			// 입력받은 두 값의 나눈 값의 나머지을 result에 저장
	}
	if (op == '/') {					// 만약 입력한 연산자가 / 라면
		result = (double)num1 / num2;	// 입력받은 두 값의 나눈 값을 result에 저장, 실수 출력을 위해 강제 형변환
	}
}
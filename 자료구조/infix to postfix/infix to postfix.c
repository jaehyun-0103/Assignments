#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// atof 함수가 선언된 헤더 파일
#include <string.h>	// strlen, memset 함수가 선언된 헤더 파일
#include <math.h>	// pow 함수가 선언된 헤더 파일

typedef char elementChar;
typedef float elementFloat;
typedef struct {
	elementFloat data[100];
	int top;
} Stack;

void initStack(Stack* s);				// 스택을 초기화하는 함수
int empty(Stack* s);					// 공백 상태를 검사하는 함수
int full(Stack* s);						// 포화 상태를 검사하는 함수
void push(Stack* s, elementFloat item); // 삽입 함수
elementFloat pop(Stack* s);				// 삭제 함수
elementFloat peek(Stack* s);			// 피크 함수
float eval(char exp[]);					// 후위 표기 수식을 계산하는 함수
int prec(char op);						// 연산기호의 우선순위를 반환하는 함수
int error(elementChar exp[]);			// 예외처리를 하는 함수
elementChar* infix_to_postfix(elementChar exp[]);	// 수식을 변환하는 함수

int main() {
	elementChar expression[100];

	while (1) { // 무한 반복문
		printf("중위 표기 수식 입력(종료하려면 0을 입력) :");
		scanf(" %[^\n]s", expression);	// 공백 포함 입력 가능
		if (expression[0] == '0' && expression[1] == '\0')	// 만약 '0'만 입력했다면
			exit(1);	// 프로그램 종료

		printf("중위-후위표기 변환\n");
		elementChar* result = infix_to_postfix(expression);	// 후위 표기법으로 변환한 수식을 result에 저장
		if (result != NULL) {								// 변환한 수식이 널이 아니라면
			printf("후위 표기 수식 : %s\n", result);		// 후위 표기법으로 변환한 수식 출력
			printf("결과값 : %.2f\n\n", eval(result));		// 후위 표기법으로 변환한 수식으로 계산한 값 출력
		}
	}
}

// 스택을 초기화하는 함수
void initStack(Stack* s) { s->top = -1; }

// 공백 상태를 검사하는 함수
int empty(Stack* s) { return (s->top == -1); }

// 포화 상태를 검사하는 함수
int full(Stack* s) { return (s->top == (99)); }

// 삽입 함수
void push(Stack* s, elementFloat item) {
	if (full(s)) {
		printf("스택 포화 에러(push)\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// 삭제 함수
elementFloat pop(Stack* s) {
	if (empty(s)) {
		printf("스택 공백 에러(pop)\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// 피크 함수
elementFloat peek(Stack* s) {
	if (empty(s)) {
		printf("스택 공백 에러(peek)\n");
		exit(1);
	}
	else return s->data[s->top];
}

// 후위 표기 수식을 계산하는 함수
float eval(char exp[]) {
	float op1 = 0, op2 = 0;	// 계산할 피연산자를 저장할 변수
	float value;			// 문자 형태의 피연산자를 실수형으로 바꿔 저장할 변수
	int i = 0, k = 0;		// 인덱스 번호를 나타낼 변수
	char buf[100];			// 공백을 기준으로 나눠진 피연산자를 합쳐 저장할 변수
	Stack s;

	initStack(&s);	// 스택을 초기화하는 함수 호출

	while (exp[i] != '\0') {	// 문자열의 끝이 아닌 동안
		if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '^' && exp[i] != ' ') {	// 연산기호가 아니거나 공백이 아니라면
			while ((48 <= exp[i] && exp[i] <= 57) || exp[i] == '.') {	// 숫자나 소수점일 동안
				buf[k] = exp[i];	// buf에 저장
				k++;				// buf 인덱스 증가
				i++;				// 문자열 인덱스 증가
			}
			value = atof(buf);	// buf를 실수형으로 바꿈
			memset(buf, 0, k);	// buf를 비움
			k = 0;				// buf 인덱스 0으로 초기화
			push(&s, value);	// value 값 스택에 삽입
		}
		else if (exp[i] == ' ') {	// 공백이라면
			i++;					// 문자열 인덱스 증가
			continue;				// 코드 건너뜀
		}
		else {							// 연산기호라면
			op2 = pop(&s);				// 스택에서 제거한 값을 저장
			op1 = pop(&s);				// 스택에서 제거한 값을 저장
			switch (exp[i]) {
			case '+':					// '+'라면
				push(&s, op1 + op2);	// 연산기호에 맞는 연산을 한 값을 스택에 삽입
				break;					// switch 문 종료
			case '-':					// '-'라면
				push(&s, op1 - op2);	// 연산기호에 맞는 연산을 한 값을 스택에 삽입
				break;					// switch 문 종료
			case '*':					// '*'라면
				push(&s, op1 * op2);	// 연산기호에 맞는 연산을 한 값을 스택에 삽입
				break;					// switch 문 종료
			case '/':					// '/'라면
				push(&s, op1 / op2);	// 연산기호에 맞는 연산을 한 값을 스택에 삽입
				break;					// switch 문 종료
			case '^':					// '^'라면
				push(&s, pow(op1, op2));// 연산기호에 맞는 연산을 한 값을 스택에 삽입
				break;					// switch 문 종료
			}
			i++;	// 문자열 인덱스 증가
		}
	}
	return pop(&s);	// 스택에서 제거한 값을 리턴
}

// 연산기호의 우선순위를 반환하는 함수
int prec(char op) {	// 연산자가 파라미터
	switch (op) {
	case '(':		// '('라면
	case ')':		// ')'라면
		return 0;	// 0 리턴
	case '+':		// '+'라면
	case '-':		// '-'라면
		return 1;	// 1 리턴
	case '*':		// '*'라면
	case '/':		// '/'라면
		return 2;	// 2 리턴
	case '^':		// '^'라면
		return 3;	// 3 리턴
	}
	return -1;		// -1 리턴
}

// 예외처리를 하는 함수 (1 반환시 오류 발생)
int error(elementChar exp[]) {
	int len = strlen(exp);			// 문자열의 길이를 len에 저장

	// 0으로 나눈 경우 예외처리
	for (int i = 0; i < len; i++) {	// 문자열의 길이만큼 반복
		if (i + 1 < len && exp[i] == '/' && exp[i + 1] == '0') {	// '/' 연산기호 다음에 0이 나왔다면
			printf("Error : 수식 문법을 위반하였습니다. (0으로 나눔)\n\n");
			return 1;	// 1 리턴
		}
	}

	// '(' 와 ')'의 개수가 다른 경우 예외처리
	int count = 0;					// '('와 ')'의 개수를 세는 변수
	for (int i = 0; i < len; i++) {	// 문자열의 길이만큼 반복
		if (exp[i] == '(')			// '('이라면
			count++;				// count 1 증가
		else if (exp[i] == ')') 	// '('이라면
			count--;				// count 1 감소
	}
	if (count > 0) {				// '('의 개수가 더 많으면
		printf("Error : 수식 문법을 위반하였습니다. (')'이 없음)\n\n");
		return 1;					// 1 리턴
	}
	else if (count < 0) {			// ')'의 개수가 더 많으면
		printf("Error : '('이 없음\n\n");
		return 1;					// 1 리턴
	}

	// 수식의 맨 앞에 연산기호나 ')'가 오는 경우 예외처리
	if (exp[0] == '.' || exp[0] == ')' || exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/' || exp[0] == '^' || exp[0] == '\0') {	// 수식의 맨 앞에 연산기호나 ')'가 나왔다면
		printf("Error : 수식 문법을 위반하였습니다. (처음에 연산기호나 ')'가 옴)\n\n");
		return 1;	// 1 리턴
	}

	// '(', ')', 숫자(실수형의 '.' 포함), '+', '-', '*', '/' , '^' 외 다른 기호 사용에 대한 예외처리
	for (int i = 0; i < len; i++) {	// 문자열의 길이만큼 반복
		if (exp[i] == '\n' || exp[i] == ' ' || exp[i] == '.' || exp[i] == '(' || exp[i] == ')' || (48 <= exp[i] && exp[i] <= 57) ||
			exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')	// 사용 가능한 연산기호가 왔다면
			continue;	// 코드 건너뜀
		else {			// 사용 가능한 연산기호 외 다른 연산기호가 왔다면
			printf("Error : 수식 문법을 위반하였습니다. (다른 연산 기호 사용)\n\n");
			return 1;	// 1 리턴
		}
	}

	// 다양한 예외처리
	for (int i = 0; i < len; i++) {		// 문자열의 길이만큼 반복
		// '(' 다음에 '(' 또는 숫자(실수형의 '.' 포함)나 '+'나 '-' 외에 다른 연산기호 사용에 대한 예외처리
		if (exp[i] == '(') {			// '('라면
			if (exp[i + 1] == ' ' || (48 <= exp[i + 1] && exp[i + 1] <= 57) || exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '(')	// '(' 다음에 '(' 또는 숫자(실수형의 '.' 포함)나 '+'나 '-'가 왔다면
				continue;				// 코드 건너뜀
			else {						// 아니라면
				printf("Error : 수식 문법을 위반하였습니다. ('(' 다음엔 '('나 피연산자, '+', '-'가 와야함)\n\n");
				return 1;				// 1 리턴
			}
		}
		// 숫자 다음에 숫자(실수형의 '.' 포함) 또는 연산기호나 ')' 외에 다른 연산기호 사용에 대한 예외처리
		else if (48 <= exp[i] && exp[i] <= 57) {	// 만약 숫자라면
			if (exp[i + 1] == ' ' || (48 <= exp[i + 1] && exp[i + 1] <= 57) || exp[i + 1] == '.' || exp[i + 1] == ')' ||
				exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '^' || exp[i + 1] == '\0') {	// 숫자 다음에 숫자(실수형의 '.' 포함) 또는 연산기호나 ')'가 왔다면
				continue;				// 코드 건너뜀
			}
			else {						// 아니라면
				printf("Error : 수식 문법을 위반하였습니다. (피연산자 다음엔 ')'나 연산기호가 와야함)\n\n");
				return 1;				// 1 리턴
			}
		}
		// ')' 다음에 연산기호나 ')' 외 다른 연산기호나 숫자 사용에 대한 예외처리
		else if (exp[i] == ')') {		// ')'라면
			if (exp[i + 1] == ' ' || exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' ||
				exp[i + 1] == '/' || exp[i + 1] == '^' || exp[i + 1] == '\0' || exp[i + 1] == ')')	// ')' 다음에 연산기호나 ')'가 왔다면
				continue;				// 코드 건너뜀
			else {						// 아니라면
				printf("Error : 수식 문법을 위반하였습니다. (')' 다음엔 연산자나 ')'가 와야함)\n\n");
				return 1;				// 1 리턴
			}
		}
		// 연산기호 다음에 '('나 숫자 외 다른 연산기호 사용에 대한 예외처리
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^') {	// 연산기호라면
			if (exp[i + 1] == '(' || exp[i + 1] == ' ' || (48 <= exp[i + 1] && exp[i + 1] <= 57))	// 연산기호 다음에 숫자나 '('가 왔다면
				continue;				// 코드 건너뜀
			else						// 아니라면
				printf("Error : 수식 문법을 위반하였습니다. (연산 기호 다음엔 숫자가 와야함)\n\n");
			return 1;					// 1 리턴
		}
	}
}

// 수식을 변환하는 함수
elementChar* infix_to_postfix(elementChar exp[]) {
	int i, index = 0;		// 인덱스 번호를 저장할 변수
	int len = strlen(exp);	// 문자열의 길이를 len에 저장
	char ch, op;			// 문자나 연산기호를 저장할 변수
	Stack s;

	if (error(exp) == 1) {	// 수식문법에 준수하였는지 확인
		return NULL;		// 준수하지 않았다면 널 리턴
	}

	elementChar* postfix_arr = (elementChar*)malloc(100);	// postfix_arr 배열 동적 생성
	if (postfix_arr == NULL) {	// 동적 생성한 문자열이 널이라면
		printf("Error : 메모리 할당 에러\n");
		exit(1);				// 프로그램 종료
	}

	initStack(&s);  //스택 초기화

	// '(' 다음에 '+'나 '-'가 나오는 경우 연산을 위해 앞에 '0' 삽입
	for (int i = 0; i < len; i++) {			// 문자열의 길이만큼 반복
		if (exp[i] == '(' && (exp[i + 1] == '+' || exp[i + 1] == '-')) {	// '(' 다음에 '+'나 '-'가 나왔다면
			exp[len + 1] = '\0';			// 문자열의 마지막을 1 증가
			for (int j = len; j > i; j--)	// 조건에 맞는 인덱스부터 마지막 인덱스까지 반복
				exp[j] = exp[j - 1];		// 문자를 한칸씩 뒤로 이동
			exp[i + 1] = '0';				// 조건에 해당하는 인덱스에 0 삽입
		}
	}
	len++;			// 문자열의 길이 1 증가

	// 중위 표기식으로 표현된 식을 순회
	for (int i = 0; i < len; i++) {					// 문자열의 길이만큼 반복
		ch = exp[i];								// i번째 인덱스의 값을 ch에 저장
		if ((48 <= ch && ch <= 57) || ch == '.') {	// 숫자거나 소수점이면
			postfix_arr[index++] = ch;				// 배열에 저장하고 인덱스 증가
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {   // 연산기호라면
			postfix_arr[index++] = ' ';				// 배열에 공백 저장
			while (!empty(&s) && (prec(ch) <= prec(peek(&s)))) {	// 스택의 top 값이 현재 연산기호보다 우선순위가 높다면
				postfix_arr[index++] = peek(&s);	// 스택의 top 값을 배열에 추가
				pop(&s);		// 스택에서 가장 위에 있는 항목 제거
			}
			push(&s, ch);		// 연산기호 스택에 추가
		}
		else if (ch == '(')		// '('이라면
			push(&s, ch);		// 스택에 추가
		else if (ch == ')') {	// ')'이면
			op = pop(&s);		// 스택에서 가장 위에 있는 항목 제거하고 op에 저장
			while (op != '(') {	// '('가 아닌동안
				postfix_arr[index++] = op;	// 배열에 저장하고 인덱스 증가
				op = pop(&s);	// 스택에서 가장 위에 있는 항목 제거하고 op에 저장
			}
		}
	}

	while (!empty(&s)) {			// 아직 스택에 값이 남아있다면
		op = peek(&s);				// 스택에서 가장 위에 있는 항목 추가
		pop(&s);					// 스택에서 가장 위에 있는 항목 제거
		postfix_arr[index++] = op;	// 배열에 저장하고 인덱스 증가
	}
	postfix_arr[index] = '\0';		// 문자열의 끝을 지정

	return postfix_arr;				// postfix_arr 배열 리턴
}
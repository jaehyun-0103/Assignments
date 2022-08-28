#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	// atof �Լ��� ����� ��� ����
#include <string.h>	// strlen, memset �Լ��� ����� ��� ����
#include <math.h>	// pow �Լ��� ����� ��� ����

typedef char elementChar;
typedef float elementFloat;
typedef struct {
	elementFloat data[100];
	int top;
} Stack;

void initStack(Stack* s);				// ������ �ʱ�ȭ�ϴ� �Լ�
int empty(Stack* s);					// ���� ���¸� �˻��ϴ� �Լ�
int full(Stack* s);						// ��ȭ ���¸� �˻��ϴ� �Լ�
void push(Stack* s, elementFloat item); // ���� �Լ�
elementFloat pop(Stack* s);				// ���� �Լ�
elementFloat peek(Stack* s);			// ��ũ �Լ�
float eval(char exp[]);					// ���� ǥ�� ������ ����ϴ� �Լ�
int prec(char op);						// �����ȣ�� �켱������ ��ȯ�ϴ� �Լ�
int error(elementChar exp[]);			// ����ó���� �ϴ� �Լ�
elementChar* infix_to_postfix(elementChar exp[]);	// ������ ��ȯ�ϴ� �Լ�

int main() {
	elementChar expression[100];

	while (1) { // ���� �ݺ���
		printf("���� ǥ�� ���� �Է�(�����Ϸ��� 0�� �Է�) :");
		scanf(" %[^\n]s", expression);	// ���� ���� �Է� ����
		if (expression[0] == '0' && expression[1] == '\0')	// ���� '0'�� �Է��ߴٸ�
			exit(1);	// ���α׷� ����

		printf("����-����ǥ�� ��ȯ\n");
		elementChar* result = infix_to_postfix(expression);	// ���� ǥ������� ��ȯ�� ������ result�� ����
		if (result != NULL) {								// ��ȯ�� ������ ���� �ƴ϶��
			printf("���� ǥ�� ���� : %s\n", result);		// ���� ǥ������� ��ȯ�� ���� ���
			printf("����� : %.2f\n\n", eval(result));		// ���� ǥ������� ��ȯ�� �������� ����� �� ���
		}
	}
}

// ������ �ʱ�ȭ�ϴ� �Լ�
void initStack(Stack* s) { s->top = -1; }

// ���� ���¸� �˻��ϴ� �Լ�
int empty(Stack* s) { return (s->top == -1); }

// ��ȭ ���¸� �˻��ϴ� �Լ�
int full(Stack* s) { return (s->top == (99)); }

// ���� �Լ�
void push(Stack* s, elementFloat item) {
	if (full(s)) {
		printf("���� ��ȭ ����(push)\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

// ���� �Լ�
elementFloat pop(Stack* s) {
	if (empty(s)) {
		printf("���� ���� ����(pop)\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

// ��ũ �Լ�
elementFloat peek(Stack* s) {
	if (empty(s)) {
		printf("���� ���� ����(peek)\n");
		exit(1);
	}
	else return s->data[s->top];
}

// ���� ǥ�� ������ ����ϴ� �Լ�
float eval(char exp[]) {
	float op1 = 0, op2 = 0;	// ����� �ǿ����ڸ� ������ ����
	float value;			// ���� ������ �ǿ����ڸ� �Ǽ������� �ٲ� ������ ����
	int i = 0, k = 0;		// �ε��� ��ȣ�� ��Ÿ�� ����
	char buf[100];			// ������ �������� ������ �ǿ����ڸ� ���� ������ ����
	Stack s;

	initStack(&s);	// ������ �ʱ�ȭ�ϴ� �Լ� ȣ��

	while (exp[i] != '\0') {	// ���ڿ��� ���� �ƴ� ����
		if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '^' && exp[i] != ' ') {	// �����ȣ�� �ƴϰų� ������ �ƴ϶��
			while ((48 <= exp[i] && exp[i] <= 57) || exp[i] == '.') {	// ���ڳ� �Ҽ����� ����
				buf[k] = exp[i];	// buf�� ����
				k++;				// buf �ε��� ����
				i++;				// ���ڿ� �ε��� ����
			}
			value = atof(buf);	// buf�� �Ǽ������� �ٲ�
			memset(buf, 0, k);	// buf�� ���
			k = 0;				// buf �ε��� 0���� �ʱ�ȭ
			push(&s, value);	// value �� ���ÿ� ����
		}
		else if (exp[i] == ' ') {	// �����̶��
			i++;					// ���ڿ� �ε��� ����
			continue;				// �ڵ� �ǳʶ�
		}
		else {							// �����ȣ���
			op2 = pop(&s);				// ���ÿ��� ������ ���� ����
			op1 = pop(&s);				// ���ÿ��� ������ ���� ����
			switch (exp[i]) {
			case '+':					// '+'���
				push(&s, op1 + op2);	// �����ȣ�� �´� ������ �� ���� ���ÿ� ����
				break;					// switch �� ����
			case '-':					// '-'���
				push(&s, op1 - op2);	// �����ȣ�� �´� ������ �� ���� ���ÿ� ����
				break;					// switch �� ����
			case '*':					// '*'���
				push(&s, op1 * op2);	// �����ȣ�� �´� ������ �� ���� ���ÿ� ����
				break;					// switch �� ����
			case '/':					// '/'���
				push(&s, op1 / op2);	// �����ȣ�� �´� ������ �� ���� ���ÿ� ����
				break;					// switch �� ����
			case '^':					// '^'���
				push(&s, pow(op1, op2));// �����ȣ�� �´� ������ �� ���� ���ÿ� ����
				break;					// switch �� ����
			}
			i++;	// ���ڿ� �ε��� ����
		}
	}
	return pop(&s);	// ���ÿ��� ������ ���� ����
}

// �����ȣ�� �켱������ ��ȯ�ϴ� �Լ�
int prec(char op) {	// �����ڰ� �Ķ����
	switch (op) {
	case '(':		// '('���
	case ')':		// ')'���
		return 0;	// 0 ����
	case '+':		// '+'���
	case '-':		// '-'���
		return 1;	// 1 ����
	case '*':		// '*'���
	case '/':		// '/'���
		return 2;	// 2 ����
	case '^':		// '^'���
		return 3;	// 3 ����
	}
	return -1;		// -1 ����
}

// ����ó���� �ϴ� �Լ� (1 ��ȯ�� ���� �߻�)
int error(elementChar exp[]) {
	int len = strlen(exp);			// ���ڿ��� ���̸� len�� ����

	// 0���� ���� ��� ����ó��
	for (int i = 0; i < len; i++) {	// ���ڿ��� ���̸�ŭ �ݺ�
		if (i + 1 < len && exp[i] == '/' && exp[i + 1] == '0') {	// '/' �����ȣ ������ 0�� ���Դٸ�
			printf("Error : ���� ������ �����Ͽ����ϴ�. (0���� ����)\n\n");
			return 1;	// 1 ����
		}
	}

	// '(' �� ')'�� ������ �ٸ� ��� ����ó��
	int count = 0;					// '('�� ')'�� ������ ���� ����
	for (int i = 0; i < len; i++) {	// ���ڿ��� ���̸�ŭ �ݺ�
		if (exp[i] == '(')			// '('�̶��
			count++;				// count 1 ����
		else if (exp[i] == ')') 	// '('�̶��
			count--;				// count 1 ����
	}
	if (count > 0) {				// '('�� ������ �� ������
		printf("Error : ���� ������ �����Ͽ����ϴ�. (')'�� ����)\n\n");
		return 1;					// 1 ����
	}
	else if (count < 0) {			// ')'�� ������ �� ������
		printf("Error : '('�� ����\n\n");
		return 1;					// 1 ����
	}

	// ������ �� �տ� �����ȣ�� ')'�� ���� ��� ����ó��
	if (exp[0] == '.' || exp[0] == ')' || exp[0] == '+' || exp[0] == '-' || exp[0] == '*' || exp[0] == '/' || exp[0] == '^' || exp[0] == '\0') {	// ������ �� �տ� �����ȣ�� ')'�� ���Դٸ�
		printf("Error : ���� ������ �����Ͽ����ϴ�. (ó���� �����ȣ�� ')'�� ��)\n\n");
		return 1;	// 1 ����
	}

	// '(', ')', ����(�Ǽ����� '.' ����), '+', '-', '*', '/' , '^' �� �ٸ� ��ȣ ��뿡 ���� ����ó��
	for (int i = 0; i < len; i++) {	// ���ڿ��� ���̸�ŭ �ݺ�
		if (exp[i] == '\n' || exp[i] == ' ' || exp[i] == '.' || exp[i] == '(' || exp[i] == ')' || (48 <= exp[i] && exp[i] <= 57) ||
			exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')	// ��� ������ �����ȣ�� �Դٸ�
			continue;	// �ڵ� �ǳʶ�
		else {			// ��� ������ �����ȣ �� �ٸ� �����ȣ�� �Դٸ�
			printf("Error : ���� ������ �����Ͽ����ϴ�. (�ٸ� ���� ��ȣ ���)\n\n");
			return 1;	// 1 ����
		}
	}

	// �پ��� ����ó��
	for (int i = 0; i < len; i++) {		// ���ڿ��� ���̸�ŭ �ݺ�
		// '(' ������ '(' �Ǵ� ����(�Ǽ����� '.' ����)�� '+'�� '-' �ܿ� �ٸ� �����ȣ ��뿡 ���� ����ó��
		if (exp[i] == '(') {			// '('���
			if (exp[i + 1] == ' ' || (48 <= exp[i + 1] && exp[i + 1] <= 57) || exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '(')	// '(' ������ '(' �Ǵ� ����(�Ǽ����� '.' ����)�� '+'�� '-'�� �Դٸ�
				continue;				// �ڵ� �ǳʶ�
			else {						// �ƴ϶��
				printf("Error : ���� ������ �����Ͽ����ϴ�. ('(' ������ '('�� �ǿ�����, '+', '-'�� �;���)\n\n");
				return 1;				// 1 ����
			}
		}
		// ���� ������ ����(�Ǽ����� '.' ����) �Ǵ� �����ȣ�� ')' �ܿ� �ٸ� �����ȣ ��뿡 ���� ����ó��
		else if (48 <= exp[i] && exp[i] <= 57) {	// ���� ���ڶ��
			if (exp[i + 1] == ' ' || (48 <= exp[i + 1] && exp[i + 1] <= 57) || exp[i + 1] == '.' || exp[i + 1] == ')' ||
				exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/' || exp[i + 1] == '^' || exp[i + 1] == '\0') {	// ���� ������ ����(�Ǽ����� '.' ����) �Ǵ� �����ȣ�� ')'�� �Դٸ�
				continue;				// �ڵ� �ǳʶ�
			}
			else {						// �ƴ϶��
				printf("Error : ���� ������ �����Ͽ����ϴ�. (�ǿ����� ������ ')'�� �����ȣ�� �;���)\n\n");
				return 1;				// 1 ����
			}
		}
		// ')' ������ �����ȣ�� ')' �� �ٸ� �����ȣ�� ���� ��뿡 ���� ����ó��
		else if (exp[i] == ')') {		// ')'���
			if (exp[i + 1] == ' ' || exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' ||
				exp[i + 1] == '/' || exp[i + 1] == '^' || exp[i + 1] == '\0' || exp[i + 1] == ')')	// ')' ������ �����ȣ�� ')'�� �Դٸ�
				continue;				// �ڵ� �ǳʶ�
			else {						// �ƴ϶��
				printf("Error : ���� ������ �����Ͽ����ϴ�. (')' ������ �����ڳ� ')'�� �;���)\n\n");
				return 1;				// 1 ����
			}
		}
		// �����ȣ ������ '('�� ���� �� �ٸ� �����ȣ ��뿡 ���� ����ó��
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^') {	// �����ȣ���
			if (exp[i + 1] == '(' || exp[i + 1] == ' ' || (48 <= exp[i + 1] && exp[i + 1] <= 57))	// �����ȣ ������ ���ڳ� '('�� �Դٸ�
				continue;				// �ڵ� �ǳʶ�
			else						// �ƴ϶��
				printf("Error : ���� ������ �����Ͽ����ϴ�. (���� ��ȣ ������ ���ڰ� �;���)\n\n");
			return 1;					// 1 ����
		}
	}
}

// ������ ��ȯ�ϴ� �Լ�
elementChar* infix_to_postfix(elementChar exp[]) {
	int i, index = 0;		// �ε��� ��ȣ�� ������ ����
	int len = strlen(exp);	// ���ڿ��� ���̸� len�� ����
	char ch, op;			// ���ڳ� �����ȣ�� ������ ����
	Stack s;

	if (error(exp) == 1) {	// ���Ĺ����� �ؼ��Ͽ����� Ȯ��
		return NULL;		// �ؼ����� �ʾҴٸ� �� ����
	}

	elementChar* postfix_arr = (elementChar*)malloc(100);	// postfix_arr �迭 ���� ����
	if (postfix_arr == NULL) {	// ���� ������ ���ڿ��� ���̶��
		printf("Error : �޸� �Ҵ� ����\n");
		exit(1);				// ���α׷� ����
	}

	initStack(&s);  //���� �ʱ�ȭ

	// '(' ������ '+'�� '-'�� ������ ��� ������ ���� �տ� '0' ����
	for (int i = 0; i < len; i++) {			// ���ڿ��� ���̸�ŭ �ݺ�
		if (exp[i] == '(' && (exp[i + 1] == '+' || exp[i + 1] == '-')) {	// '(' ������ '+'�� '-'�� ���Դٸ�
			exp[len + 1] = '\0';			// ���ڿ��� �������� 1 ����
			for (int j = len; j > i; j--)	// ���ǿ� �´� �ε������� ������ �ε������� �ݺ�
				exp[j] = exp[j - 1];		// ���ڸ� ��ĭ�� �ڷ� �̵�
			exp[i + 1] = '0';				// ���ǿ� �ش��ϴ� �ε����� 0 ����
		}
	}
	len++;			// ���ڿ��� ���� 1 ����

	// ���� ǥ������� ǥ���� ���� ��ȸ
	for (int i = 0; i < len; i++) {					// ���ڿ��� ���̸�ŭ �ݺ�
		ch = exp[i];								// i��° �ε����� ���� ch�� ����
		if ((48 <= ch && ch <= 57) || ch == '.') {	// ���ڰų� �Ҽ����̸�
			postfix_arr[index++] = ch;				// �迭�� �����ϰ� �ε��� ����
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {   // �����ȣ���
			postfix_arr[index++] = ' ';				// �迭�� ���� ����
			while (!empty(&s) && (prec(ch) <= prec(peek(&s)))) {	// ������ top ���� ���� �����ȣ���� �켱������ ���ٸ�
				postfix_arr[index++] = peek(&s);	// ������ top ���� �迭�� �߰�
				pop(&s);		// ���ÿ��� ���� ���� �ִ� �׸� ����
			}
			push(&s, ch);		// �����ȣ ���ÿ� �߰�
		}
		else if (ch == '(')		// '('�̶��
			push(&s, ch);		// ���ÿ� �߰�
		else if (ch == ')') {	// ')'�̸�
			op = pop(&s);		// ���ÿ��� ���� ���� �ִ� �׸� �����ϰ� op�� ����
			while (op != '(') {	// '('�� �ƴѵ���
				postfix_arr[index++] = op;	// �迭�� �����ϰ� �ε��� ����
				op = pop(&s);	// ���ÿ��� ���� ���� �ִ� �׸� �����ϰ� op�� ����
			}
		}
	}

	while (!empty(&s)) {			// ���� ���ÿ� ���� �����ִٸ�
		op = peek(&s);				// ���ÿ��� ���� ���� �ִ� �׸� �߰�
		pop(&s);					// ���ÿ��� ���� ���� �ִ� �׸� ����
		postfix_arr[index++] = op;	// �迭�� �����ϰ� �ε��� ����
	}
	postfix_arr[index] = '\0';		// ���ڿ��� ���� ����

	return postfix_arr;				// postfix_arr �迭 ����
}
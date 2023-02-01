#include<stdio.h>

#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty() {
    return (top == -1);
}

int isFull() {
    return (top == MAX_STACK_SIZE - 1);
}

void push(int item) {
    if (isFull()) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else
        stack[++top] = item;
}

int pop() {
    if (isEmpty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return stack[top--];
}

int peek() {
    if (isEmpty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else
        return stack[top];
}

int main() {
    push(3);
    push(5);
    push(12);

    printf("peek : %d\n\n", peek());

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
}
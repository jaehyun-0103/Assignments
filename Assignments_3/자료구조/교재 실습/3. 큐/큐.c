#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    if (front == rear)
        return 1;
    else
        return 0;
}

int isFull() {
    if (rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

void enqueue(int value) {
    if (isFull())
        printf("ť ��ȭ ����\n");
    else {
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        queue[rear] = value;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("ť ���� ����\n");
        exit(1);
    }
    else {
        front = (front + 1) % MAX_QUEUE_SIZE;
        return queue[front];
    }
}

int peek() {
    if (isEmpty()) {
        fprintf(stderr, "ť ���� ����\n");
        exit(1);
    }
    else
        return queue[front + 1];
}

int main() {
    enqueue(4);
    enqueue(7);
    enqueue(12);

    printf("peek : %d\n\n", peek());

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
}

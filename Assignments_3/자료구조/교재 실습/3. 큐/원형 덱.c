#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} DequeType;

void error(char* message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(DequeType* q) {
    q->front = q->rear = 0;
}

void deque_print(DequeType* q) {
    printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
    if (!isEmpty(q)) {
        int i = q->front;
        do {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

int isEmpty(DequeType* q) {
    return (q->front == q->rear);
}

int isFull(DequeType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void add_front(DequeType* q, element item) {
    if (isFull(q))
        error("큐 포화 에러\n");
    q->data[q->front] = item;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void add_rear(DequeType* q, element item) {
    if (isFull(q))
        error("큐 포화 에러\n");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element delete_front(DequeType* q) {
    if (isEmpty(q))
        error("큐 공백 에러\n");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element delete_rear(DequeType* q) {
    if (isEmpty(q))
        error("큐 공백 에러\n");
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[q->rear];
}

element get_front(DequeType* q) {
    if (isEmpty(q))
        error("큐 공백 에러\n");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element get_rear(DequeType* q) {
    if (isEmpty(q))
        error("큐 공백 에러\n");
    return q->data[q->rear];
}

int main() {
    DequeType queue;

    init(&queue);

    for (int i = 0; i < 3; i++) {
        add_front(&queue, i);
        deque_print(&queue);
    }

    for (int i = 0; i < 3; i++) {
        delete_rear(&queue);
        deque_print(&queue);
    }
}
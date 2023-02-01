#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int  front, rear;
	element  data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(QueueType* q) {
	q->rear = -1;
	q->front = -1;
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%2d rear=%d) = ", q->front, q->rear);
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}

int isFull(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int isEmpty(QueueType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item) {
	if (isFull(q)) {
		error("큐 포화 에러\n");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {
	if (isEmpty(q)) {
		error("큐 공백 에러\n");
		return -1;
	}
	int item = q->data[++(q->front)];
	return item;
}

int main() {
	int element = 0;
	QueueType q;

	init(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);
	enqueue(&q, 40); queue_print(&q);
	enqueue(&q, 50); queue_print(&q);

	element = dequeue(&q); queue_print(&q);
	element = dequeue(&q); queue_print(&q);
	element = dequeue(&q); queue_print(&q);
}
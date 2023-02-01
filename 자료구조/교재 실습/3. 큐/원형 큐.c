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
	q->front = q->rear = 0;
}

void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
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

int isEmpty(QueueType* q) {
	return (q->front == q->rear);
}

int isFull(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (isFull(q))
		error("ť ��ȭ ����\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (isEmpty(q))
		error("ť ���� ����\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

int main(void) {
	QueueType queue;
	int element;

	init(&queue);

	printf("--������ �߰� �ܰ�--\n");
	while (!isFull(&queue)) {
		printf("������ �Է��Ͻÿ�: ");
		scanf_s("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);
	}
	printf("ť�� ��ȭ�����Դϴ�.\n\n");

	printf("--������ ���� �ܰ�--\n");
	while (!isEmpty(&queue)) {
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�.\n");
}
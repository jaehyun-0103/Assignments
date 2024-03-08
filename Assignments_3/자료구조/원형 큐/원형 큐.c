#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element queue[MAX];
	int front, rear;
}QueueType;

void error(char* message);			// ���� �޽��� ����ϴ� �Լ� ����
void Create(QueueType*);			// ���ο� ť �����ϴ� �Լ� ����
int Empty(QueueType*);				// ť�� ������� Ȯ���ϴ� �Լ� ����
int Full(QueueType*);				// ť�� ���� á���� Ȯ���ϴ� �Լ� ����
void Enqueuer(QueueType*, element);	// ���ο� �����͸� queue, rear�� �����ϴ� �Լ� ����
element Dequeuer(QueueType*);		// front�� ��ġ�� �����͸� �����ϰ� �����Ͽ� ����ϴ� �Լ� ����
void QueueDisplay(QueueType*);		// ť�� ����� ��� ������ ����ϴ� �Լ� ����

int main() {
	QueueType queue;
	int element, select = 0;
	Create(&queue);		// ���� ť �ʱ�ȭ
	while (1) {			// ���� �ݺ�
		printf("1. Create\n2. Enqueuer\n3. Dequeuer\n4. QueueDisplay\n5. EXIT\n");
		printf("\n���� : ");
		scanf("%d", &select);
		printf("\n");
		if (select == 1) {				// 1���� ����ٸ�
			Create(&queue);				// Create() �Լ� ȣ��
		}
		else if (select == 2) {			// 2���� ����ٸ�
			printf("�Է� : ");
			scanf("%d", &element);
			Enqueuer(&queue, element);	// Enqueuer() �Լ� ȣ��
			printf("\n");
		}
		else if (select == 3)			// 3���� ����ٸ�
			Dequeuer(&queue);			// Dequeuer() �Լ� ȣ��
		else if (select == 4)			// 4���� ����ٸ�
			QueueDisplay(&queue);		// QueueDisplay() �Լ� ȣ��
		else if (select == 5)			// 5���� ����ٸ�
			exit(1);					// ���α׷� ����
		else
			printf("�ٽ� �Է����ּ���.\n\n");
	}
	return 0;
}

// ���� �޽��� ����ϴ� �Լ� ����
void error(char* message) {
	fprintf(stderr, "%s\n", message);	// ���� �޽��� ���
	exit(1);							// ���α׷� ����
}

// ���ο� ť �����ϴ� �Լ� ����
void Create(QueueType* q) {
	q->front = q->rear = 0;	// front, rear �ʱ�ȭ
}

// ť�� ������� Ȯ���ϴ� �Լ� ����
int Empty(QueueType* q) {
	return q->front == q->rear;	// front == rear�� ������ �������� �Ǻ�
}

// ť�� ���� á���� Ȯ���ϴ� �Լ� ����
int Full(QueueType* q) {
	return q->front == (q->rear + 1) % MAX;	// ���� ť���� rear ������ front���� �Ǻ�
}

// ���ο� �����͸� queue, rear�� �����ϴ� �Լ� ����
void Enqueuer(QueueType* q, element value) {
	if (Full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX;	// ���� �ε���
	q->queue[q->rear] = value;		// �� �ε����� ���ο� ������ ����
}

// front�� ��ġ�� �����͸� �����ϰ� �����Ͽ� ����ϴ� �Լ� ����
element Dequeuer(QueueType* q) {
	if (Empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX;	// ù��° �ε����� �� �������� �ٲ�
	return q->queue[q->front];
}

// ť�� ����� ��� ������ ����ϴ� �Լ� ����
void QueueDisplay(QueueType* q) {
	int i, turn = (q->front + 1);
	printf("������ : ");
	for (i = 0; i < (q->rear - q->front + MAX) % MAX; i++) {
		if (turn >= MAX)
			turn %= MAX;
		printf("%d ", q->queue[turn++]);
	}
	printf("\n\n");
}
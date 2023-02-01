#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 30

typedef struct { // ��� Ÿ��
	int id;
	int arrival_time;
	int service_time;
	int start_time;
} element;

typedef struct { // ť Ÿ��
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

//���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//ť �ʱ�ȭ �Լ�
void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

// ť ���� Ȯ�� �Լ�
int isEmpty(QueueType* q) {
	return (q->front == q->rear);
}

// ť ��ȭ Ȯ�� �Լ�
int isFull(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//ť ���� ��� �Լ�
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!isEmpty(&q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)		// ���� �����϶�
				break;
		} while (i != q->front);
		printf("\n");
	}
}

// ť ���� �Լ�
void enqueue(QueueType* q, element item) {
	if (isFull(q)) {
		error("ť ��ȭ ����\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// ť ���� �Լ�
element dequeue(QueueType* q) {
	if (isEmpty(q)) {
		error("ť ���� ����\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (isEmpty(&q)) {
		error("ť ���� ����\n");
		exit(1);
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// ��� �ο� Ȯ�� �Լ�
int get_count(QueueType* q) {
	if (q->front <= q->rear) return q->rear - q->front;
	else return (q->rear + 1) + (MAX_QUEUE_SIZE - 1 - q->front);
}

int main() {
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	QueueType log;

	init_queue(&queue);
	init_queue(&log);

	printf("<���� �ùķ��̼�>\n");

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("\n����ð� : %d�� [%d�� ���]\n", clock, get_count(&queue));
		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. \t\t| ����ó���ð� : %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) {
			printf(">> �� %d ����ó�����Դϴ�. \n", service_customer);
			service_time--;
		}
		else if (!isEmpty(&queue)) {
			element customer = dequeue(&queue);
			customer.start_time = clock;
			enqueue(&log, customer);
			service_customer = customer.id;
			service_time = customer.service_time;
			printf("�� %d�� %d�п� ������ �����մϴ�. \t| ���ð� : %d��\n", customer.id, clock, clock - customer.arrival_time);
			total_wait += clock - customer.arrival_time;
		}
	}

	printf("\n��ü���ð� : %d�� \n", total_wait);
	printf("\n���� %d��\n", get_count(&queue));

	if (!isEmpty(&queue)) {
		if (queue.front < queue.rear)
			for (int i = queue.front + 1; i <= queue.rear; i++)
				printf("[%d] : %d�� ����, [%d�� ���] �۾��ð� : %d��\n", queue.data[i].id, queue.data[i].arrival_time, minutes - queue.data[i].arrival_time, queue.data[i].service_time);
		else {
			for (int i = queue.front + 1; i < MAX_QUEUE_SIZE; i++)
				printf("[%d] : %d�� ����, [%d�� ���] �۾��ð� : %d��\n", queue.data[i].id, queue.data[i].arrival_time, minutes - queue.data[i].arrival_time, queue.data[i].service_time);
			for (int i = 0; i < queue.rear + 1; i++)
				printf("[%d] : %d�� ����, [%d�� ���] �۾��ð� : %d��\n", queue.data[i].id, queue.data[i].arrival_time, minutes - queue.data[i].arrival_time, queue.data[i].service_time);
		}
	}

	printf("\n�� �α�\n");

	if (!isEmpty(&log)) {
		for (int i = log.front + 1; i <= log.rear; i++)
			printf("[%2d] : %2d�� ����, [%2d�� ���] %2d ~ %2d��\n", log.data[i].id, log.data[i].arrival_time, log.data[i].start_time - log.data[i].arrival_time, log.data[i].start_time, log.data[i].start_time + log.data[i].service_time);
	}
}
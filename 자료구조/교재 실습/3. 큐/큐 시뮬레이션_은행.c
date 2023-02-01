#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 30

typedef struct { // 요소 타입
	int id;
	int arrival_time;
	int service_time;
	int start_time;
} element;

typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

//오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//큐 초기화 함수
void init_queue(QueueType* q) {
	q->rear = 0;
	q->front = 0;
}

// 큐 공백 확인 함수
int isEmpty(QueueType* q) {
	return (q->front == q->rear);
}

// 큐 포화 확인 함수
int isFull(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//큐 상태 출력 함수
void queue_print(QueueType* q) {
	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!isEmpty(&q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)		// 공백 상태일때
				break;
		} while (i != q->front);
		printf("\n");
	}
}

// 큐 삽입 함수
void enqueue(QueueType* q, element item) {
	if (isFull(q)) {
		error("큐 포화 에러\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

// 큐 삭제 함수
element dequeue(QueueType* q) {
	if (isEmpty(q)) {
		error("큐 공백 에러\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (isEmpty(&q)) {
		error("큐 공백 에러\n");
		exit(1);
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// 대기 인원 확인 함수
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

	printf("<은행 시뮬레이션>\n");

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++) {
		printf("\n현재시각 : %d분 [%d명 대기]\n", clock, get_count(&queue));
		if ((rand() % 10) < 3) {
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);
			printf("고객 %d이 %d분에 들어옵니다. \t\t| 예상처리시간 : %d분\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if (service_time > 0) {
			printf(">> 고객 %d 업무처리중입니다. \n", service_customer);
			service_time--;
		}
		else if (!isEmpty(&queue)) {
			element customer = dequeue(&queue);
			customer.start_time = clock;
			enqueue(&log, customer);
			service_customer = customer.id;
			service_time = customer.service_time;
			printf("고객 %d이 %d분에 업무를 시작합니다. \t| 대기시간 : %d분\n", customer.id, clock, clock - customer.arrival_time);
			total_wait += clock - customer.arrival_time;
		}
	}

	printf("\n전체대기시간 : %d분 \n", total_wait);
	printf("\n대기고객 %d명\n", get_count(&queue));

	if (!isEmpty(&queue)) {
		if (queue.front < queue.rear)
			for (int i = queue.front + 1; i <= queue.rear; i++)
				printf("[%d] : %d분 도착, [%d분 대기] 작업시간 : %d분\n", queue.data[i].id, queue.data[i].arrival_time, minutes - queue.data[i].arrival_time, queue.data[i].service_time);
		else {
			for (int i = queue.front + 1; i < MAX_QUEUE_SIZE; i++)
				printf("[%d] : %d분 도착, [%d분 대기] 작업시간 : %d분\n", queue.data[i].id, queue.data[i].arrival_time, minutes - queue.data[i].arrival_time, queue.data[i].service_time);
			for (int i = 0; i < queue.rear + 1; i++)
				printf("[%d] : %d분 도착, [%d분 대기] 작업시간 : %d분\n", queue.data[i].id, queue.data[i].arrival_time, minutes - queue.data[i].arrival_time, queue.data[i].service_time);
		}
	}

	printf("\n고객 로그\n");

	if (!isEmpty(&log)) {
		for (int i = log.front + 1; i <= log.rear; i++)
			printf("[%2d] : %2d분 도착, [%2d분 대기] %2d ~ %2d분\n", log.data[i].id, log.data[i].arrival_time, log.data[i].start_time - log.data[i].arrival_time, log.data[i].start_time, log.data[i].start_time + log.data[i].service_time);
	}
}
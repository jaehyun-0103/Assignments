#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct {
	element queue[MAX];
	int front, rear;
}QueueType;

void error(char* message);			// 에러 메시지 출력하는 함수 선언
void Create(QueueType*);			// 새로운 큐 생성하는 함수 선언
int Empty(QueueType*);				// 큐가 비었는지 확인하는 함수 선언
int Full(QueueType*);				// 큐가 가득 찼는지 확인하는 함수 선언
void Enqueuer(QueueType*, element);	// 새로운 데이터를 queue, rear에 삽입하는 함수 선언
element Dequeuer(QueueType*);		// front에 위치한 데이터를 삭제하고 리턴하여 출력하는 함수 선언
void QueueDisplay(QueueType*);		// 큐에 저장된 모든 데이터 출력하는 함수 선언

int main() {
	QueueType queue;
	int element, select = 0;
	Create(&queue);		// 원형 큐 초기화
	while (1) {			// 무한 반복
		printf("1. Create\n2. Enqueuer\n3. Dequeuer\n4. QueueDisplay\n5. EXIT\n");
		printf("\n선택 : ");
		scanf("%d", &select);
		printf("\n");
		if (select == 1) {				// 1번을 골랐다면
			Create(&queue);				// Create() 함수 호출
		}
		else if (select == 2) {			// 2번을 골랐다면
			printf("입력 : ");
			scanf("%d", &element);
			Enqueuer(&queue, element);	// Enqueuer() 함수 호출
			printf("\n");
		}
		else if (select == 3)			// 3번을 골랐다면
			Dequeuer(&queue);			// Dequeuer() 함수 호출
		else if (select == 4)			// 4번을 골랐다면
			QueueDisplay(&queue);		// QueueDisplay() 함수 호출
		else if (select == 5)			// 5번을 골랐다면
			exit(1);					// 프로그램 종료
		else
			printf("다시 입력해주세요.\n\n");
	}
	return 0;
}

// 에러 메시지 출력하는 함수 정의
void error(char* message) {
	fprintf(stderr, "%s\n", message);	// 에러 메시지 출력
	exit(1);							// 프로그램 종료
}

// 새로운 큐 생성하는 함수 정의
void Create(QueueType* q) {
	q->front = q->rear = 0;	// front, rear 초기화
}

// 큐가 비었는지 확인하는 함수 정의
int Empty(QueueType* q) {
	return q->front == q->rear;	// front == rear가 참인지 거짓인지 판별
}

// 큐가 가득 찼는지 확인하는 함수 정의
int Full(QueueType* q) {
	return q->front == (q->rear + 1) % MAX;	// 원형 큐에서 rear 다음이 front인지 판별
}

// 새로운 데이터를 queue, rear에 삽입하는 함수 정의
void Enqueuer(QueueType* q, element value) {
	if (Full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX;	// 다음 인덱스
	q->queue[q->rear] = value;		// 그 인덱스에 새로운 데이터 삽입
}

// front에 위치한 데이터를 삭제하고 리턴하여 출력하는 함수 정의
element Dequeuer(QueueType* q) {
	if (Empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX;	// 첫번째 인덱스를 그 다음으로 바꿈
	return q->queue[q->front];
}

// 큐에 저장된 모든 데이터 출력하는 함수 정의
void QueueDisplay(QueueType* q) {
	int i, turn = (q->front + 1);
	printf("데이터 : ");
	for (i = 0; i < (q->rear - q->front + MAX) % MAX; i++) {
		if (turn >= MAX)
			turn %= MAX;
		printf("%d ", q->queue[turn++]);
	}
	printf("\n\n");
}
#include <stdio.h>
#include <malloc.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;	// ���� ����Ʈ�� ���¸� ���߱� ���� ����ü

typedef struct {
	Node *front, *rear;
}Queue;	// ť�� ���¸� ���߱� ���� ����ü

void init(Queue* q) {
	q->front = q->rear = NULL;
}

int isEmpty(Queue* q) {
	return (q->front == NULL);
}

void enqueue(Queue* q, int data) {
	Node* temp = (Node*)malloc(sizeof(Node));	// ������ ��� ���� ����

	temp->data = data;	// ������ ������ ����
	temp->link = NULL;	// rear�κ� �� ť�� �������� ���Ƿ� ���ο� ����� ��ũ�κ��� NULL�̿��� �Ѵ�.
	if (isEmpty(q)) {	// ť�� ����ִ� ���
		q->front = temp;
		q->rear = temp;	// front,rear��� ���ο� ��带 ����Ű���� ��
	}
	else {	// ť�� ������� �ʴ� ���
		q->rear->link = temp;	// rear����� ��ũ�� ������ ��带 ����Ű���� ��
		q->rear = temp;			// rear�����͸� ������ ��带 ����Ű���� ����
	}
}

int dequeue(Queue* q) {
	Node* temp;			//������ ��带 ���� �ӽ� ��� ����

	int data;
	if (isEmpty(q)) {	// ť�� ����������� �˻�
		printf("error");
	}
	else {
		temp = q->front;		// temp�� q->front ��� ����Ŵ
		data = temp->data;
		q->front = temp->link;	// front�� ���� ��带 ����Ű���� ��( ������ ù��° ��尡 �� ���)
		if (q->front == NULL)	// ������¸� ����� �ֱ� ����
			q->rear == NULL;
		free(temp);		// �����޸� ����
		return data;	// ������ ��ȯ
	}
}

void print_queue(Queue* q) {
	Node* p;
	for (p = q->front; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL\n");
}

int main() {
	Queue que;

	init(&que); // �ʱ�ȭ 

	enqueue(&que, 10); print_queue(&que); // 10 ����
	enqueue(&que, 30); print_queue(&que); // 30 ����
	enqueue(&que, 40); print_queue(&que); // 40 ����
	enqueue(&que, 60); print_queue(&que); // 60 ����
	dequeue(&que); print_queue(&que); // 10 ����
	dequeue(&que); print_queue(&que); // 30 ����
	dequeue(&que); print_queue(&que); // 40 ����
	dequeue(&que); print_queue(&que); // 60 ����
}
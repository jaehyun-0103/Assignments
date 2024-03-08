#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct { 	// ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;

// ����Ʈ�� �׸� ���
void print_list(ListNode* head) {
	ListNode* p = head->link;

	if (head == NULL)
		return;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p!= head); // ù��° ��� head->link�� �����ϸ� ������ ���
	printf("%d->", p->data); // ������ ���
}

// �պκ� ����
ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head; // ���� ���Ե� ù��° ����� ��ũ�� �ٽ� �ڱ� �ڽ�(head)�� ����Ű����
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

// �޺κ� ����
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head; // ���� ���Ե� ù��° ����� ��ũ�� �ٽ� �ڱ� �ڽ�(head)�� ����Ű����
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node; // head�� ��ġ�� ���ο� ���� �ٲپ��� -> ���ο� ��尡 ������ ��尡 ��
	}
	return head; // ����� ��� ������ ��ȯ
}

int main() {
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
}
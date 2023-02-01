#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct { 	// 노드 타입
	element data;
	struct ListNode* link;
} ListNode;

// 리스트의 항목 출력
void print_list(ListNode* head) {
	ListNode* p = head->link;

	if (head == NULL)
		return;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p!= head); // 첫번째 노드 head->link에 도달하면 마지막 노드
	printf("%d->", p->data); // 마지막 노드
}

// 앞부분 삽입
ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head; // 새로 삽입된 첫번째 노드의 링크는 다시 자기 자신(head)을 가리키도록
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

// 뒷부분 삽입
ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));

	node->data = data;

	if (head == NULL) {
		head = node;
		node->link = head; // 새로 삽입된 첫번째 노드의 링크는 다시 자기 자신(head)을 가리키도록
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node; // head의 위치만 새로운 노드로 바꾸어줌 -> 새로운 노드가 마지막 노드가 됨
	}
	return head; // 변경된 헤드 포인터 반환
}

int main() {
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);
}
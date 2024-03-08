#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* link;
} node; // 노드 타입 정의

void makeList(node**);
void viewList(node*);
node* findLast(node*);
int findPosition(node*, node**, node**, int);
void insertList(node**, node*, int);
void deleteList(node**, node*, node*);

int main() {
	node* head = NULL;
	node* pre = NULL;
	node* targetPtr = NULL;
	int newData, target;
	int found;

	makeList(&head);

	viewList(head);

	fflush(stdin);

	printf("Enter data to insert :\n");
	scanf("%d", &newData);

	printf("Enter position to insert from list <enter -1 to front> :\n");
	scanf("%d", &target);

	if (target == -1) {
		targetPtr = NULL;
		insertList(&head, targetPtr, newData);
	}
	else {
		found = 0;
		found = findPosition(head, &pre, &targetPtr, target);
		if (found == 1)
			insertList(&head, targetPtr, newData);
		else
			printf("There is no %d in the list\n", target);
	}

	viewList(head);

	printf("Enter data to delete from list :\n");
	scanf("%d", &target);

	found = 0;
	found = findPosition(head, &pre, &targetPtr, target);

	if (found == 1)
		deleteList(&head, pre, targetPtr);
	else
		printf("There is no %d in the list\n", target);

	viewList(head);

	return 0;
}

void makeList(node** hptr) {
	node* pre = NULL;
	int data;

	printf("Enter data to add  from list <enter -1 to end> :\n");
	scanf("%d", &data);

	while (data != -1) {
		insertList(hptr, pre, data);
		pre = findLast(*hptr);
		printf("Enter data again\n");
		scanf("%d", &data);
	}
}

void viewList(node* ptr) {
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

node* findLast(node* hptr) {
	if (hptr == NULL)
		return hptr;

	while (hptr->link != NULL)
		hptr = hptr->link;

	return hptr;
}

int findPosition(node* hptr, node** pre, node** targetPtr, int data) {
	*pre = NULL;
	*targetPtr = NULL;

	while (hptr != NULL) {
		if (hptr->data == data) {
			*targetPtr = hptr;
			return 1;
		}
		*pre = hptr;
		hptr = hptr->link;
	}

	return 0;
}

void insertList(node** hptr, node* pptr, int data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->link = NULL;

	if (*hptr == NULL) {
		*hptr = newNode;
	}
	else if (pptr == NULL) {
		newNode->link = *hptr;
		*hptr = newNode;
	}
	else {
		newNode->link = pptr->link;
		pptr->link = newNode;
	}
}

void deleteList(node** hptr, node* pre, node* target) {
	if (pre == NULL)
		*hptr = target->link;
	else
		pre->link = target->link;

	free(target);
}
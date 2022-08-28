#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void greeting();						// ���ٴ� ǥ���� ����ϴ� �Լ�
void readDatabase(inventory);			// theInventory�� ����� �Լ�
int printMenu();						// ����� �޴��� ����ϴ� �Լ�
void originInventory(inventory);		// �Էµ� ������� ����ϴ� �Լ�
void displayInventory(inventory);		// ������ �̸� ������, ���ں��δ� å ���� ������ �����Ͽ� ����ϴ� �Լ�
void displayAuthorsWork(inventory);		// Ư�� �۰��� ������ ���� ������ ����ϴ� �Լ�
void addBook(inventory);				// ���ο� ���� ������ �Է��ϴ� �Լ�
void changePrice(inventory);			// Ư�� ������ ���� ������ �����ϴ� �Լ�
void changeQty(inventory);				// Ư�� ������ ����� �����ϴ� �Լ�
void totalQty(inventory);				// ��� �ִ� ��ü ������ ����� ����ϴ� �Լ�
void calculateTotalAmount(inventory);	// ��� �ִ� ��ü ������ ������ ����ϴ� �Լ�

typedef struct book_info {	// ���� ����Ʈ�� ��� ����ü
	char title[100];		// ������
	int qty;				// ���
	float price;			// å�� ����
	struct book_info* next;	// �ڱ����� ����ü
}b[100];	// ����ü ��Ī

typedef struct person_info {
	char lastname[1000];		// ��
	char firstname[1000];		// �̸�
	char author[1000];			// ��+�̸�
	struct book_info bookPtr;	// ���������� ��� ���Ḯ��Ʈ�� �ּҸ� ������ ����
}p[100];	// ����ü ��Ī

int main(void) {
	greeting();

	struct person_info theInventory[100];	// ����ü�� ���ҷ��� ������ �迭

	readDatabase(theInventory);

	int flag = 1;
	while (flag) {
		int choice = printMenu();
		if (choice == 1)
			originInventory(theInventory);
		else if (choice == 2)
			displayInventory(theInventory);
		else if (choice == 3)
			displayAuthorsWork(theInventory);
		else if (choice == 4)
			addBook(theInventory);
		else if (choice == 5)
			changePrice(theInventory);
		else if (choice == 6)
			changeQty(theInventory);
		else if (choice == 7)
			totalQty(theInventory);
		else if (choice == 8)
			calculateTotalAmount(theInventory);
		else if (choice == 9) {
			printf("Thank you for using this program.\n");
			flag = 0;
		}
		else
			printf("Invalid choice!\n");
	}
	return 0;
}

// ���ٴ� ǥ���� ����ϴ� �Լ�
void greeting() {
	printf("�ȳ��ϼ���. ���� ��� ���� ���α׷��� ���� ���� ȯ���մϴ�.\n\n");
}

// theInventory�� ����� �Լ�
void readDatabase(struct person_info inventory[100]) {
	char firstCap[100], lastCap[100], titleCap[100];	// ���� ���ڿ��� ù ���ڸ� �빮�ڷ� ���� �� ���
	char authorlist[100][100];		// �۰��� �̸��� "��, �̸�" ���·� ������ ����
	char filename[100];				// �Է¹��� ���ϸ��� ������ ����
	char str[100];					// ���Ͽ��� ������ �Է¹޾� ������ ����
	char* ptr;						// �ڸ� ���ڿ��� ������ ������
	char* sArr[100] = { NULL, };	// �ڸ� ���ڿ��� ����
	int token = 0, bookNum = 0, index = 0, listNum = 0;
	
	FILE* fp = NULL;

	do {
		printf("�� ���� �̸��� �Է��ϼ���: ");
		scanf("%s", filename);
		fp = fopen(filename, "rt");
		if (fp == NULL) {	// ������ ������ �ʴ´ٸ�
			printf("������ �������� �ʽ��ϴ�.\n");
		}
	} while (fp == NULL);	// ������ ������ �ʴ� ����

	/*������ ���� �ƴѵ��� ������ ���پ� �о� ����ü ����� ����*/
	while (!feof(fp)) {					// ������ ���� �ƴ� ����
		fgets(str, "%s", fp);			// ���� �Է� ������ ����
		ptr = strtok(str, ",");			// ���ڿ��� �߶� �����͸� ��ȯ
		while (ptr != NULL) {			// �ڸ� ���ڿ��� ������ ���� ������ �ݺ�
			sArr[token] = ptr;			// ���ڿ��� �ڸ� �� �޸� �ּҸ� ���ڿ� ������ �迭�� ����
			token++;					// �ε��� ����
			ptr = strtok(NULL, ",");	// ���� ���ڿ��� �߶� �����͸� ��ȯ
		}
		token = 0;

		/*���� �ڸ� ���ڿ��� ���� ������ ����*/
		strcpy(inventory[bookNum].lastname, sArr[0]);
		strcpy(inventory[bookNum].firstname, sArr[1]);
		strcpy(inventory[bookNum].bookPtr.title, sArr[2]);
		inventory[bookNum].bookPtr.qty = atoi(sArr[3]);
		inventory[bookNum].bookPtr.price = atof(sArr[4]);

		/*�Է��� �̸��� ù���ڸ� �빮�ڷ� �ٲ�*/
		strcpy(firstCap, inventory[bookNum].firstname);
		for (index = 0; firstCap[index] != '\0'; index++) {
			if (index == 0) {
				if ((firstCap[index] >= 'a' && firstCap[index] <= 'z'))
					firstCap[index] = firstCap[index] - 32;
				continue;
			}
			if (firstCap[index] == ' ') {
				++index;
				if (firstCap[index] >= 'a' && firstCap[index] <= 'z') {
					firstCap[index] = firstCap[index] - 32;
					continue;
				}
			}
			else {
				if (firstCap[index] >= 'A' && firstCap[index] <= 'Z')
					firstCap[index] = firstCap[index] + 32;
			}
		}
		strcpy(inventory[bookNum].firstname, firstCap);
		firstCap[0] = '\0';

		/*�Է��� ���� ù���ڸ� �빮�ڷ� �ٲ�*/
		strcpy(lastCap, inventory[bookNum].lastname);
		for (index = 0; lastCap[index] != '\0'; index++) {
			if (index == 0) {
				if ((lastCap[index] >= 'a' && lastCap[index] <= 'z'))
					lastCap[index] = lastCap[index] - 32;
				continue;
			}
			if (lastCap[index] == ' ') {
				++index;
				if (lastCap[index] >= 'a' && lastCap[index] <= 'z') {
					lastCap[index] = lastCap[index] - 32;
					continue;
				}
			}
			else
				if (lastCap[index] >= 'A' && lastCap[index] <= 'Z')
					lastCap[index] = lastCap[index] + 32;
		}
		strcpy(inventory[bookNum].lastname, lastCap);
		lastCap[0] = '\0';

		/*�Է��� ������ ù���ڸ� �빮�ڷ� �ٲ�*/
		strcpy(titleCap, inventory[bookNum].bookPtr.title);
		for (index = 0; titleCap[index] != '\0'; index++) {
			if (index == 0) {
				if ((titleCap[index] >= 'a' && titleCap[index] <= 'z'))
					titleCap[index] = titleCap[index] - 32;
				continue;
			}
			if (titleCap[index] == ' ') {
				++index;
				if (titleCap[index] >= 'a' && titleCap[index] <= 'z') {
					titleCap[index] = titleCap[index] - 32;
					continue;
				}
			}
			else
				if (titleCap[index] >= 'A' && titleCap[index] <= 'Z')
					titleCap[index] = titleCap[index] + 32;
		}
		strcpy(inventory[bookNum].bookPtr.title, titleCap);
		titleCap[0] = '\0';

		bookNum++;	// å�� �� �� 1 ����
	}

	/*�۰��� �̸��� "��, �̸�" �������� ����*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	strcpy(inventory[bookNum].lastname, "\0");	// å�� ���� �����ϱ� ���� ���� ����

	/*�Է����Ͽ� ���� �۰��� �̸�������� �ߺ����� author ����ü ��� ������ ����*/
	for (int m = 0; m < 30; m++) {
		listNum++;	// ����ü ����� ������ �۰��� �ε���
		strcpy(inventory[m].author, authorlist[0]);
		for (int n = 0; n < bookNum;) {
			if (strcmp(inventory[m].author, authorlist[n]) == 0) {	// �Է¹��� �۰��� �̸��� ����ü ����� ����� �۰��� �̸��� ���ٸ�
				for (int k = n; k < bookNum - 1; k++) {
					strcpy(authorlist[k], authorlist[k + 1]);	// �迭�� k���� �������� �̵�
				}
				bookNum--;
			}
			else
				n++;
		}
		if (bookNum == 0)
			break;
	}

	strcpy(inventory[listNum].author, "\0");	// �۰� ���� �����ϱ� ���� ���� ����

	fclose(fp);	// ���� �ݱ�
}

// ����� �޴��� ����ϴ� �Լ�
int printMenu() {
	int choice = 0;	// ������ ���ڸ� ����
	int in = 0;		// �Է��� ���� �������� Ȯ��
	printf("\n-------------------------------------------\n");
	printf("1. �Էµ� ������� ���\n");
	printf("2. ������ �̸� ������ ����\n");
	printf("3. Ư�� �۰��� ������ ����\n");
	printf("4. ���ο� ���� ���� �Է�\n");
	printf("5. Ư�� ������ ���� ����\n");
	printf("6. Ư�� ������ ��� ����\n");
	printf("7. ��ü ������ ���\n");
	printf("8. ��ü ������ ����\n");
	printf("9. ����\n");
	while (1) {
		printf("Enter your choice: ");
		in = scanf("%d", &choice);		// ���ڸ� �Է��ߴ��� Ȯ��
		while (getchar() != '\n');		// �Է¹��ۿ� ����� ���� �����
		if (in == 1)					// ���ڸ� �Է��ߴٸ�
			break;
		else							// ���ڸ� �Է����� �ʾҴٸ�
			printf("���ڸ� �Է��ϼ���.\n");
	}
	return choice;	// ������ ���� ����
}

// �Էµ� ������� ����ϴ� �Լ�
void originInventory(struct person_info inventory[100]) {
	int authorNum = 0, bookNum = 0;	// ���α׷��� �ִ� �۰��� å�� ��
	char authorlist[100][100];		// �۰��� �̸��� "��, �̸�" ���·� ������ ����
	int index = 0;					// ����� �۰� �迭�� �ε���

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum��° �ε����� ����ü ����� ���� \0�� ������
		authorNum++;	// �۰��� �� 1 ����
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum��° �ε����� ����ü ����� ���� \0�� ������
		bookNum++;		// å�� �� 1 ����

	/*�۰��� �̸��� "��, �̸�" �������� ����*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*���Ḯ��Ʈ ����*/
	struct book_info* head = NULL;
	struct book_info* curr = NULL;
	struct book_info* newNode = NULL;
	for (int i = 0; i < bookNum; i++) {
		newNode = (struct book_info*)malloc(sizeof(b));		// ���ο� ��� ����
		strcpy(newNode->title, inventory[i].bookPtr.title);	// ������ ����
		newNode->qty = inventory[i].bookPtr.qty;			// ������ ����
		newNode->price = inventory[i].bookPtr.price;		// ������ ����
		if (head == NULL) {
			head = curr = newNode;
		}
		else {
			curr->next = newNode;
			curr = newNode;
		}
	}

	/*���Ḯ��Ʈ ���*/
	curr->next = NULL;
	curr = head;
	while (curr != NULL) {
		printf("\n***The author is: %s***\n", authorlist[index++]);
		printf("-------------------------------------------");
		printf("\n|The title is: %s", curr->title);
		printf("\n|The qty is: %d", curr->qty);
		printf("\n|The price is: %.2lf", curr->price);
		printf("\n-------------------------------------------");
		curr = curr->next;
	}
	printf("\n");
}

// ������ �̸� ������, ���ں��δ� å ���� ������ �����Ͽ� ����ϴ� �Լ�
void displayInventory(struct person_info inventory[100]) {
	int authorNum = 0, bookNum = 0;	// ���α׷��� �ִ� �۰��� å�� ��
	char authorlist[100][100];		// �۰��� �̸��� "��, �̸�" ���·� ������ ����
	char authorname[100][100];		// �۰��� �̸��� ������ ����
	char tmp[100];					// ������ �� ����� ����

	while (strcmp(inventory[authorNum].author, "\0") != 0)  // authorNum��° �ε����� ����ü ����� ���� \0�� ������
		authorNum++;	// �۰��� �� 1 ����
	while (strcmp(inventory[bookNum].lastname, "\0") != 0)	// bookNum��° �ε����� ����ü ����� ���� \0�� ������
		bookNum++;		// å�� �� 1 ����

	/*�۰��� �̸��� "��, �̸�" �������� ����*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*�۰��� �̸��� �迭�� ����*/
	for (int num = 0; num < authorNum; num++) {
		strcpy(authorname[num], inventory[num].author);
	}

	/*�۰��� �̸� ����*/
	for (int m = 0; m < authorNum - 1; m++) {
		for (int n = 0; n < authorNum - 1 - m; n++) {
			if (strcmp(authorname[n], authorname[n + 1]) > 0) {	// ���� �۰��� �̸��� �� ũ�ٸ� �ڸ��� �ٲ�
				strcpy(tmp, authorname[n]);
				strcpy(authorname[n], authorname[n + 1]);
				strcpy(authorname[n + 1], tmp);
			}
		}
	}

	/*���Ḯ��Ʈ ����*/
	for (int j = 0; j < authorNum; j++) {
		struct book_info* head = NULL;
		struct book_info* curr;
		struct book_info* prev = (struct book_info*)malloc(sizeof(b));
		struct book_info* newNode;
		for (int i = 0; i < bookNum; i++) {
			if (strcmp(authorname[j], authorlist[i]) == 0) {
				newNode = (struct book_info*)malloc(sizeof(b));		// ���ο� ��� ����
				strcpy(newNode->title, inventory[i].bookPtr.title);	// ������ ����
				newNode->qty = inventory[i].bookPtr.qty;			// ������ ����
				newNode->price = inventory[i].bookPtr.price;		// ������ ����
				newNode->next = NULL;
				if (head == NULL) {
					head = newNode;
				}
				else {
					if (strcmp(inventory[i].bookPtr.title, head->title) == -1) {	// �����Ϸ��� ������ �۴ٸ�
						newNode->next = head;
						head = newNode;			// ���ε��� ��尡 head
					}
					else {						// �����Ϸ��� ������ ũ�ٸ�
						curr = head;
						while (curr != NULL && (strcmp(inventory[i].bookPtr.title, curr->title) == 1)) {// �����Ϸ��� ������ ���� ������
							prev = curr;		// ���� ��带 ����
							curr = curr->next;	// ���� ���� �̵�
						}
						newNode->next = prev->next;
						prev->next = newNode;		// ����
					}
				}
			}
		}
		/*���Ḯ��Ʈ ���*/
		curr = head;
		printf("\n***The author is: %s***\n", authorname[j]);
		printf("-------------------------------------------");
		while (curr != NULL) {
			printf("\n|The title is: %s", curr->title);
			printf("\n|The qty is: %d", curr->qty);
			printf("\n|The price is: %.2lf", curr->price);
			printf("\n-------------------------------------------");
			curr = curr->next;
		}
		printf("\n");
	}
}

// Ư�� �۰��� ������ ���� ������ ����ϴ� �Լ�
void displayAuthorsWork(struct person_info inventory[100]) {
	char firstnameIn[100], lastnameIn[100], authorIn[100];	// �Է��� �̸�, ��, �Է��� �۰��� ��+�̸�
	char firstCap[100], lastCap[100];	// ���� ���ڿ��� ù ���ڸ� �빮�ڷ� ���� �� ���
	char authorlist[100][100];			// �۰��� �̸��� "��, �̸�" ���·� ������ ����
	int authorNum = 0, bookNum = 0;		// ���α׷��� �ִ� �۰��� å�� ��
	int k = 0, check = 0, index = 0;

	printf("\n�۰��� first name�� �����ּ���: ");
	scanf("%s", firstnameIn);
	printf("�۰��� last name�� �����ּ���: ");
	scanf("%s", lastnameIn);

	/*�Է��� �̸��� ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(firstCap, firstnameIn);
	for (index = 0; firstCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((firstCap[index] >= 'a' && firstCap[index] <= 'z'))
				firstCap[index] = firstCap[index] - 32;
			continue;
		}
		if (firstCap[index] == ' ') {
			++index;
			if (firstCap[index] >= 'a' && firstCap[index] <= 'z') {
				firstCap[index] = firstCap[index] - 32;
				continue;
			}
		}
		else {
			if (firstCap[index] >= 'A' && firstCap[index] <= 'Z')
				firstCap[index] = firstCap[index] + 32;
		}
	}
	strcpy(firstnameIn, firstCap);
	firstCap[0] = '\0';

	/*�Է��� ���� ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(lastCap, lastnameIn);
	for (index = 0; lastCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((lastCap[index] >= 'a' && lastCap[index] <= 'z'))
				lastCap[index] = lastCap[index] - 32;
			continue;
		}
		if (lastCap[index] == ' ') {
			++index;
			if (lastCap[index] >= 'a' && lastCap[index] <= 'z') {
				lastCap[index] = lastCap[index] - 32;
				continue;
			}
		}
		else
			if (lastCap[index] >= 'A' && lastCap[index] <= 'Z')
				lastCap[index] = lastCap[index] + 32;
	}
	strcpy(lastnameIn, lastCap);
	lastCap[0] = '\0';

	/*�۰��� �̸��� "��, �̸�" �������� ����*/
	strcpy(authorIn, lastnameIn);	// �Է¹��� �۰��� ���� authorIn�� ����
	strcat(authorIn, ", ");
	strcat(authorIn, firstnameIn);	// �Է¹��� �۰��� �̸��� authorIn�� �̾����

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum��° �ε����� ����ü ����� ���� \0�� ������
		authorNum++;	// �۰��� �� 1 ����
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum��° �ε����� ����ü ����� ���� \0�� ������
		bookNum++;		// å�� �� 1 ����

	/*�۰��� �̸��� "��, �̸�" �������� ����*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*�Է��� �۰� �̸��� ��ġ�ϴ� �̸��� ���α׷��� �����ϴ��� �˻�*/
	for (k = 0; k < authorNum; k++) {
		if (strcmp(inventory[k].author, authorIn) == 0)
			break;
		else
			check++;
	}

	/*�Է��� �۰��� ���α׷��� �ֳ� Ȯ��*/
	if (check == authorNum) {
		printf("\nNo such author in your database.\nSo you cannot sort and print.\n");
		return 0;
	}
	
	/*���Ḯ��Ʈ ����*/
	struct book_info* head = NULL;
	struct book_info* curr = (struct book_info*)malloc(sizeof(b));
	struct book_info* prev = (struct book_info*)malloc(sizeof(b));
	struct book_info* newNode;
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(inventory[k].author, authorlist[i]) == 0) {	// �Է��� �۰� �̸��� ���� �̸� ã��
			newNode = (struct book_info*)malloc(sizeof(b));		// ���ο� ��� ����
			strcpy(newNode->title, inventory[i].bookPtr.title);	// ������ ����
			newNode->qty = inventory[i].bookPtr.qty;			// ������ ����
			newNode->price = inventory[i].bookPtr.price;		// ������ ����
			newNode->next = NULL;
			if (head == NULL) {
				head = newNode;
			}
			else {
				if (strcmp(inventory[i].bookPtr.title, head->title) == -1) {	// �����Ϸ��� ������ �۴ٸ�
					newNode->next = head;
					head = newNode;			// ���ε��� ��尡 head
				}
				else {						// �����Ϸ��� ������ ũ�ٸ�
					curr = head;
					while (curr != NULL && (strcmp(inventory[i].bookPtr.title, curr->title) == 1)) {	// �����Ϸ��� ������ ���� ������
						prev = curr;		// ���� ��带 ����
						curr = curr->next;	// ���� ���� �̵�
					}
					newNode->next = prev->next;
					prev->next = newNode;	// ����
				}
			}
		}
	}
	
	/*���Ḯ��Ʈ ���*/
	curr = head;
	printf("\n***The author is: %s***\n", inventory[k].author);
	printf("-------------------------------------------");
	while (curr != NULL) {
		printf("\n|The title is: %s", curr->title);
		printf("\n|The qty is: %d", curr->qty);
		printf("\n|The price is: %.2lf", curr->price);
		printf("\n-------------------------------------------");
		curr = curr->next;
	}
	printf("\n");
}

// ���ο� ���� ������ �Է��ϴ� �Լ�
void addBook(struct person_info inventory[100]) {
	char firstnameIn[100], lastnameIn[100], titleIn[100];	// �Է��� �̸�, ��, å�� ����
	char firstCap[100], lastCap[100], titleCap[100];		// ���� ���ڿ��� ù ���ڸ� �빮�ڷ� ���� �� ���
	double qtyIn, priceIn;			// �Է��� å�� ����
	char authorIn[100];				// �Է��� �۰��� ��+�̸�
	char authorlist[100][100];		// �۰��� �̸��� "��, �̸�" ���·� ������ ����
	int authorNum = 0, bookNum = 0;	// ���α׷��� �ִ� �۰��� å�� ��
	double point1, point2;			// �Ҽ��� Ȯ���� ���� ����
	int cnt = 0, checkAuthor = 0, index = 0, in;

	while (strcmp(inventory[authorNum].author, "\0") != 0)	// authorNum��° �ε����� ����ü ����� ���� \0�� ������
		authorNum++;	// �۰��� �� 1 ����
	while (strcmp(inventory[bookNum].lastname, "\0") != 0)	// bookNum��° �ε����� ����ü ����� ���� \0�� ������
		bookNum++;		// å�� �� 1 ����

	printf("\n�۰��� first name�� �����ּ���: ");
	scanf("%s", firstnameIn);
	printf("�۰��� last name�� �����ּ���: ");
	scanf("%s", lastnameIn);

	/*�Է��� �̸��� ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(firstCap, firstnameIn);
	for (index = 0; firstCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((firstCap[index] >= 'a' && firstCap[index] <= 'z'))
				firstCap[index] = firstCap[index] - 32;
			continue;
		}
		if (firstCap[index] == ' ') {
			++index;
			if (firstCap[index] >= 'a' && firstCap[index] <= 'z') {
				firstCap[index] = firstCap[index] - 32;
				continue;
			}
		}
		else {
			if (firstCap[index] >= 'A' && firstCap[index] <= 'Z')
				firstCap[index] = firstCap[index] + 32;
		}
	}
	strcpy(firstnameIn, firstCap);
	firstCap[0] = '\0';

	/*�Է��� ���� ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(lastCap, lastnameIn);
	for (index = 0; lastCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((lastCap[index] >= 'a' && lastCap[index] <= 'z'))
				lastCap[index] = lastCap[index] - 32;
			continue;
		}
		if (lastCap[index] == ' ') {
			++index;
			if (lastCap[index] >= 'a' && lastCap[index] <= 'z') {
				lastCap[index] = lastCap[index] - 32;
				continue;
			}
		}
		else
			if (lastCap[index] >= 'A' && lastCap[index] <= 'Z')
				lastCap[index] = lastCap[index] + 32;
	}
	strcpy(lastnameIn, lastCap);
	lastCap[0] = '\0';

	/*�۰��� �̸��� "��, �̸�" �������� ����*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	printf("������ ������ �����ּ���: ");
	scanf(" %[^\n]s", titleIn);				// ���� ���� �Է�

	/*�Է��� ������ ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(titleCap, titleIn);
	for (index = 0; titleCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((titleCap[index] >= 'a' && titleCap[index] <= 'z'))
				titleCap[index] = titleCap[index] - 32;
			continue;
		}
		if (titleCap[index] == ' ') {
			++index;
			if (titleCap[index] >= 'a' && titleCap[index] <= 'z') {
				titleCap[index] = titleCap[index] - 32;
				continue;
			}
		}
		else
			if (titleCap[index] >= 'A' && titleCap[index] <= 'Z')
				titleCap[index] = titleCap[index] + 32;
	}

	strcpy(titleIn, titleCap);
	titleCap[0] = '\0';
	
	/*���� å ������ �ִ��� Ȯ��*/
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(titleIn, inventory[i].bookPtr.title) == 0) {
			printf("\n���� ������ å�� �ֽ��ϴ�.\n");
			return 0;
		}
	}

	/*��� ���� ������ �Է��� ������ �ݺ�*/
	in = 0;
	do {
		printf("������ ��� �����ּ���: ");
		in = scanf("%lf", &qtyIn);
		while (getchar() != '\n');	// �Է¹��ۿ� ����� ���� �����
		if (in == 1) {
			if (qtyIn <= 0 || (int)qtyIn - qtyIn != 0)	// �Է��� ���� ���� ������ �ƴ϶��
				printf("���� ������ �Է��ؾ� �մϴ�.\n");
		}
		else
			printf("���ڸ� �Է��ϼ���.\n");
	} while (qtyIn <= 0 || (int)qtyIn - qtyIn != 0);	// ���� ������ �Է��� ������ �ݺ�

	/*������ �Ҽ��� �ι�°�� �Ǽ��� �Է��� ������ �ݺ�*/
	in = 0;
	do {
		printf("������ ������ �����ּ���: ");
		in = scanf("%lf", &priceIn);
		point1 = priceIn * 100;		// �Ҽ��� Ȯ���� ���� ����
		point2 = priceIn * 10;		// �Ҽ��� Ȯ���� ���� ����

		while (getchar() != '\n');	// �Է¹��ۿ� ����� ���� �����
		if (in == 1) {
			if (priceIn <= 0)		// �������
				printf("���� �Ǽ��� �Է��ؾ� �մϴ�.\n");
			else if ((int)point1 - point1 != 0 || (int)point2 - point2 == 0)	// �Ҽ��� �ι�°�� �Ǽ��� �ƴ϶��
				printf("�Ҽ��� ���ڸ� �Ǽ��� �Է��ؾ� �մϴ�.\n");
		}
		else	// ���ڰ� �ƴ϶��
			printf("���ڸ� �Է��ϼ���.\n");
	} while (priceIn <= 0 || (int)point1 - point1 != 0 || (int)point2 - point2 == 0);	// �Ҽ��� �ι�°�� �Ǽ��� �ƴϰų� ������ ���� �ݺ�

	strcpy(authorIn, lastnameIn);	// �Է¹��� �۰��� ���� authorIn�� ����
	strcat(authorIn, ", ");
	strcat(authorIn, firstnameIn);	// �Է¹��� �۰��� �̸��� authorIn�� �̾����

	/*�Է��� �۰� �̸��� ��ġ�ϴ� �̸��� ���α׷��� �����ϴ��� �˻�*/
	for (cnt = 0; cnt < authorNum; cnt++) {
		if (strcmp(inventory[cnt].author, authorIn) == 0)
			break;
		else
			checkAuthor++;
	}

	/*���ο� �������� ����*/
	if (checkAuthor == authorNum) {	// ��ġ�ϴ� �۰� �̸��� ���ٸ� 
		strcpy(inventory[authorNum].author, authorIn);	// �۰� �̸� ����ü ��� ������ �߰�
		strcpy(inventory[authorNum + 1].author, "\0");
		// ���� ���� ����
		strcpy(inventory[bookNum].bookPtr.title, titleIn);
		inventory[bookNum].bookPtr.qty = qtyIn;
		inventory[bookNum].bookPtr.price = priceIn;
		strcpy(inventory[bookNum].lastname, lastnameIn);
		strcpy(inventory[bookNum].firstname, firstnameIn);
		strcpy(inventory[bookNum + 1].lastname, "\0");
		printf("\n���������� �߰��Ǿ����ϴ�.\n");
	}
	else {							// ��ġ�ϴ� �۰� �̸��� �ִٸ� ���� ���� ����
		strcpy(inventory[bookNum].bookPtr.title, titleIn);
		inventory[bookNum].bookPtr.qty = qtyIn;
		inventory[bookNum].bookPtr.price = priceIn;
		strcpy(inventory[bookNum].lastname, lastnameIn);
		strcpy(inventory[bookNum].firstname, firstnameIn);
		strcpy(inventory[bookNum + 1].lastname, "\0");
		printf("\n���������� �߰��Ǿ����ϴ�.\n");
	}
}

// Ư�� ������ ���� ������ �����ϴ� �Լ�
void changePrice(struct person_info inventory[100]) {
	char firstnameIn[100], lastnameIn[100], titleIn[100];	// �Է��� �̸�, ��, å�� ����
	char firstCap[100], lastCap[100], titleCap[100];		// ���� ���ڿ��� ù ���ڸ� �빮�ڷ� ���� �� ���
	int check = 0, checkAuthor = 0, checkBook = 0;			// �Է°� ��ġ�ϴ� ������ �ֳ� Ȯ��
	char authorlist[100][100];			// �۰��� �̸��� "��, �̸�" ���·� ������ ����
	double priceIn = 0, pricePre = 0;	// �Է� �Ŀ� ���� ����
	char authorIn[100];					// �Է��� �۰��� ��+�̸�
	int authorNum = 0, bookNum = 0;		// ���α׷��� �ִ� �۰��� å�� ��
	double point1, point2;				// �Ҽ��� Ȯ���� ���� ����
	int cnt = 0, index = 0, in;
	bool exitOuterLoop = false;			// �ٱ��� ������ ���������� �����ϴ� ����

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum��° �ε����� ����ü ����� ���� \0�� ������
		authorNum++;	// �۰��� �� 1 ����
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum��° �ε����� ����ü ����� ���� \0�� ������
		bookNum++;		// å�� �� 1 ����

	printf("\n�۰��� firstname�� �����ּ���: ");
	scanf("%s", firstnameIn);
	printf("�۰��� lastname�� �����ּ���: ");
	scanf("%s", lastnameIn);

	/*�Է��� �̸��� ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(firstCap, firstnameIn);
	for (index = 0; firstCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((firstCap[index] >= 'a' && firstCap[index] <= 'z'))
				firstCap[index] = firstCap[index] - 32;
			continue;
		}
		if (firstCap[index] == ' ') {
			++index;
			if (firstCap[index] >= 'a' && firstCap[index] <= 'z') {
				firstCap[index] = firstCap[index] - 32;
				continue;
			}
		}
		else {
			if (firstCap[index] >= 'A' && firstCap[index] <= 'Z')
				firstCap[index] = firstCap[index] + 32;
		}
	}
	strcpy(firstnameIn, firstCap);
	firstCap[0] = '\0';

	/*�Է��� �̸��� ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(lastCap, lastnameIn);
	for (index = 0; lastCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((lastCap[index] >= 'a' && lastCap[index] <= 'z'))
				lastCap[index] = lastCap[index] - 32;
			continue;
		}
		if (lastCap[index] == ' ') {
			++index;
			if (lastCap[index] >= 'a' && lastCap[index] <= 'z') {
				lastCap[index] = lastCap[index] - 32;
				continue;
			}
		}
		else
			if (lastCap[index] >= 'A' && lastCap[index] <= 'Z')
				lastCap[index] = lastCap[index] + 32;
	}
	strcpy(lastnameIn, lastCap);
	lastCap[0] = '\0';

	strcpy(authorIn, lastnameIn);	// �Է¹��� �۰��� ���� authorIn�� ����
	strcat(authorIn, ", ");
	strcat(authorIn, firstnameIn);	// �Է¹��� �۰��� �̸��� authorIn�� �̾����

	/*�۰��� �̸��� "��, �̸�" �������� ����*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*�Է��� �۰� �̸��� ��ġ�ϴ� �̸��� ���α׷��� �����ϴ��� �˻�*/
	for (cnt = 0; cnt < authorNum; cnt++) {
		if (strcmp(inventory[cnt].author, authorIn) == 0)
			break;
		else
			checkAuthor++;
	}

	/*�Է��� �۰��� ���α׷��� �ֳ� Ȯ��*/
	if (checkAuthor == authorNum) {
		printf("\nNo such author in your database.\nSo you cannot change the price.\n");
		return 0;
	}

	printf("å ������ �����ּ���: ");
	scanf(" %[^\n]s", titleIn);			// ���� ���� �Է�

	/*�Է��� ������ ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(titleCap, titleIn);
	for (index = 0; titleCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((titleCap[index] >= 'a' && titleCap[index] <= 'z'))
				titleCap[index] = titleCap[index] - 32;
			continue;
		}
		if (titleCap[index] == ' ') {
			++index;
			if (titleCap[index] >= 'a' && titleCap[index] <= 'z') {
				titleCap[index] = titleCap[index] - 32;
				continue;
			}
		}
		else
			if (titleCap[index] >= 'A' && titleCap[index] <= 'Z')
				titleCap[index] = titleCap[index] + 32;
	}
	strcpy(titleIn, titleCap);
	titleCap[0] = '\0';

	/*�Է��� å�� ����� ��ġ�ϴ� ������ ���α׷��� �����ϴ��� �˻�*/
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(inventory[cnt].author, authorlist[i]) == 0) {
			for (int j = 0; j < bookNum; j++) {
				check++;
				if (strcmp(titleIn, inventory[j].bookPtr.title) != 0) {
					checkBook++;
				}
			}
		}
	}

	/*�Է��� ������ ���α׷��� �ֳ� Ȯ��*/
	if (checkBook == check) {
		printf("\nNo book with the title %s by %s in inventory\n", titleIn, inventory[cnt].author);
		return 0;
	}

	/*������ �Ҽ��� �ι�°�� �Ǽ��� �Է��� ������ �ݺ�*/
	in = 0;
	do {
		printf("������ ������ �����ּ���: ");
		in = scanf("%lf", &priceIn);
		point1 = priceIn * 100;		// �Ҽ��� Ȯ���� ���� ����
		point2 = priceIn * 10;		// �Ҽ��� Ȯ���� ���� ����

		while (getchar() != '\n');	// �Է¹��ۿ� ����� ���� �����
		if (in == 1) {
			if (priceIn <= 0)		// �������
				printf("���� �Ǽ��� �Է��ؾ� �մϴ�.\n");
			else if ((int)point1 - point1 != 0 || (int)point2 - point2 == 0)	// �Ҽ��� �ι�°�� �Ǽ��� �ƴ϶��
				printf("�Ҽ��� ���ڸ� �Ǽ��� �Է��ؾ� �մϴ�.\n");
		}
		else	// ���ڰ� �ƴ϶��
			printf("���ڸ� �Է��ϼ���.\n");
	} while (priceIn <= 0 || (int)point1 - point1 != 0 || (int)point2 - point2 == 0);	// �Ҽ��� �ι�°�� �Ǽ��� �ƴϰų� ������ ���� �ݺ�

	/*���� ������ ���� Ž��*/
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(inventory[cnt].author, authorlist[i]) == 0) {
			for (int j = 0; j < bookNum; j++) {
				if (strcmp(titleIn, inventory[j].bookPtr.title) == 0) {
					pricePre = inventory[j].bookPtr.price;	// ���� �ٲٱ� ���� ��� ����
					exitOuterLoop = true;					// �ٱ��� ������ ������������
					inventory[j].bookPtr.price = priceIn;	// ���� ����
					break;									// �ݺ��� ����
				}
			}
		}
		if (exitOuterLoop == true)    // �ٱ��� ������ ���������ڴٰ� ����������
			break;                    // �ٱ��� ������ ����
	}

	printf("\nPrice will be updated from %.2f to %.2f\n", pricePre, priceIn);
}

// Ư�� ������ ����� �����ϴ� �Լ�
void changeQty(struct person_info inventory[100]) {
	char firstnameIn[100], lastnameIn[100], titleIn[100];	// �Է��� �̸�, ��, å�� ����
	int checkAuthor = 0, checkBook = 0, check = 0;			// �Է°� ��ġ�ϴ� ������ �ֳ� Ȯ��
	char firstCap[100], lastCap[100], titleCap[100];		// ���� ���ڿ��� ù ���ڸ� �빮�ڷ� ���� �� ���
	double qtyIn, qtyPre;			// �Է� �Ŀ� ���� ���
	char authorIn[100];				// �Է��� �۰��� ��+�̸�
	char authorlist[100][100];		// ���α׷��� �����ϴ� �۰� �̸�
	int authorNum = 0, bookNum = 0;	// ���α׷��� �ִ� �۰��� å�� ��
	int cnt = 0, index = 0, in;
	bool exitOuterLoop = false;		// �ٱ��� ������ ���������� �����ϴ� ����

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum��° �ε����� ����ü ����� ���� \0�� ������
		authorNum++;	// �۰��� �� 1 ����
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum��° �ε����� ����ü ����� ���� \0�� ������
		bookNum++;		// å�� �� 1 ����

	printf("\n�۰��� firstname�� �����ּ���: ");
	scanf("%s", firstnameIn);
	printf("�۰��� lastname�� �����ּ���: ");
	scanf("%s", lastnameIn);

	/*�Է��� �̸��� ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(firstCap, firstnameIn);
	for (index = 0; firstCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((firstCap[index] >= 'a' && firstCap[index] <= 'z'))
				firstCap[index] = firstCap[index] - 32;
			continue;
		}
		if (firstCap[index] == ' ') {
			++index;
			if (firstCap[index] >= 'a' && firstCap[index] <= 'z') {
				firstCap[index] = firstCap[index] - 32;
				continue;
			}
		}
		else {
			if (firstCap[index] >= 'A' && firstCap[index] <= 'Z')
				firstCap[index] = firstCap[index] + 32;
		}
	}
	strcpy(firstnameIn, firstCap);
	firstCap[0] = '\0';

	/*�Է��� ���� ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(lastCap, lastnameIn);
	for (index = 0; lastCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((lastCap[index] >= 'a' && lastCap[index] <= 'z'))
				lastCap[index] = lastCap[index] - 32;
			continue;
		}
		if (lastCap[index] == ' ') {
			++index;
			if (lastCap[index] >= 'a' && lastCap[index] <= 'z') {
				lastCap[index] = lastCap[index] - 32;
				continue;
			}
		}
		else
			if (lastCap[index] >= 'A' && lastCap[index] <= 'Z')
				lastCap[index] = lastCap[index] + 32;
	}
	strcpy(lastnameIn, lastCap);
	lastCap[0] = '\0';

	strcpy(authorIn, lastnameIn);	// �Է¹��� �۰��� ���� authorIn�� ����
	strcat(authorIn, ", ");
	strcat(authorIn, firstnameIn);	// �Է¹��� �۰��� �̸��� authorIn�� �̾����

	/*�۰��� �̸��� "��, �̸�" �������� ����*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*�Է��� �۰� �̸��� ��ġ�ϴ� �̸��� ���α׷��� �����ϴ��� �˻�*/
	for (cnt = 0; cnt < authorNum; cnt++) {
		if (strcmp(inventory[cnt].author, authorIn) == 0)
			break;
		else
			checkAuthor++;
	}

	/*�Է��� �۰��� ���α׷��� �ֳ� Ȯ��*/
	if (checkAuthor == authorNum) {
		printf("\nNo such author in your database.\nSo you cannot change the qty.\n");
		return 0;
	}

	printf("å ������ �����ּ���: ");
	scanf(" %[^\n]s", titleIn);			// ���� ���� �Է�

	/*�Է��� ������ ù���ڸ� �빮�ڷ� �ٲ�*/
	strcpy(titleCap, titleIn);
	for (index = 0; titleCap[index] != '\0'; index++) {
		if (index == 0) {
			if ((titleCap[index] >= 'a' && titleCap[index] <= 'z'))
				titleCap[index] = titleCap[index] - 32;
			continue;
		}
		if (titleCap[index] == ' ') {
			++index;
			if (titleCap[index] >= 'a' && titleCap[index] <= 'z') {
				titleCap[index] = titleCap[index] - 32;
				continue;
			}
		}
		else
			if (titleCap[index] >= 'A' && titleCap[index] <= 'Z')
				titleCap[index] = titleCap[index] + 32;
	}
	strcpy(titleIn, titleCap);
	titleCap[0] = '\0';

	/*�Է��� å�� ����� ��ġ�ϴ� ������ ���α׷��� �����ϴ��� �˻�*/
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(inventory[cnt].author, authorlist[i]) == 0) {
			for (int j = 0; j < bookNum; j++) {
				check++;
				if (strcmp(titleIn, inventory[j].bookPtr.title) != 0) {
					checkBook++;
				}
			}
		}
	}

	/*�Է��� ������ ���α׷��� �ֳ� Ȯ��*/
	if (checkBook == check) {
		printf("\nNo book with the title %s by %s in inventory\n", titleIn, inventory[cnt].author);
		return 0;
	}

	/*��� ���� ������ �Է��� ������ �ݺ�*/
	in = 0;
	do {
		printf("��� ����: ");
		in = scanf("%lf", &qtyIn);
		while (getchar() != '\n');	// �Է¹��ۿ� ����� ���� �����
		if (in == 1) {
			if (qtyIn <= 0 || (int)qtyIn - qtyIn != 0)	// �Է��� ���� ���� ������ �ƴ϶��
				printf("���� ������ �Է��ؾ� �մϴ�.\n");
		}
		else
			printf("���ڸ� �Է��ϼ���.\n");
	} while (qtyIn <= 0 || (int)qtyIn - qtyIn != 0);	// ���� ������ �Է��� ������ �ݺ�

	/*��� ������ ���� Ž��*/
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(inventory[cnt].author, authorlist[i]) == 0) {
			for (int j = 0; j < bookNum; j++) {
				if (strcmp(titleIn, inventory[j].bookPtr.title) == 0) {
					qtyPre = inventory[j].bookPtr.qty;	// ��� �ٲٱ� ���� ��� ����
					inventory[j].bookPtr.qty = qtyIn;	// ��� ����
					exitOuterLoop = true;				// �ٱ��� ������ ������������
					break;								// �ݺ��� ����
				}
			}
		}
		if (exitOuterLoop == true)		// �ٱ��� ������ ���������ڴٰ� ����������
			break;						// �ٱ��� ������ ����
	}

	printf("\nQty will be updated from %d to %d\n", (int)qtyPre, (int)qtyIn);
}

// ��� �ִ� ��ü ������ ����� ����ϴ� �Լ�
void totalQty(struct person_info inventory[100]) {
	int authorNum = 0, bookNum = 0;	// ���α׷��� �ִ� �۰��� å�� ��
	int sum = 0;					// ��ü ������ ������ ����

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum��° �ε����� ����ü ����� ���� \0�� ������
		authorNum++;	// �۰��� �� 1 ����
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum��° �ε����� ����ü ����� ���� \0�� ������
		bookNum++;		// å�� �� 1 ����

	for (int i = 0; i < bookNum; i++)		// å�� ����ŭ �ݺ�
		sum += inventory[i].bookPtr.qty;	// ��� ����ü ����� sum�� ����
	printf("\n-------------------------------------------");
	printf("\nThe total number of books is %d", sum);	// ��ü �� �� ���
	printf("\n-------------------------------------------\n");
}

// ��� �ִ� ��ü ������ ������ ����ϴ� �Լ�
void calculateTotalAmount(struct person_info inventory[100]) {
	int authorNum = 0, bookNum = 0;	// ���α׷��� �ִ� �۰��� å�� ��
	float sum = 0;					// ��ü ������ ������ ����

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum��° �ε����� ����ü ����� ���� \0�� ������
		authorNum++;	// �۰��� �� 1 ����
	while (strcmp(inventory[bookNum].lastname, "\0") != 0)	// bookNum��° �ε����� ����ü ����� ���� \0�� ������
		bookNum++;		// å�� �� 1 ����

	for (int i = 0; i < bookNum; i++)		// å�� ����ŭ �ݺ�
		sum += inventory[i].bookPtr.price;	// ���� ����ü ����� sum�� ����
	printf("\n-------------------------------------------");
	printf("\nThe total value of the inventory is $%.2f", sum);	// ��ü ���� ���
	printf("\n-------------------------------------------\n");
}
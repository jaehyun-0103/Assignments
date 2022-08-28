#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void greeting();						// 고맙다는 표현을 출력하는 함수
void readDatabase(inventory);			// theInventory를 만드는 함수
int printMenu();						// 사용자 메뉴를 출력하는 함수
void originInventory(inventory);		// 입력된 순서대로 출력하는 함수
void displayInventory(inventory);		// 저자의 이름 순으로, 저자별로는 책 제목 순으로 정렬하여 출력하는 함수
void displayAuthorsWork(inventory);		// 특정 작가의 서적을 제목 순으로 출력하는 함수
void addBook(inventory);				// 새로운 서적 정보를 입력하는 함수
void changePrice(inventory);			// 특정 서적의 가격 정보를 변경하는 함수
void changeQty(inventory);				// 특정 서적의 재고량을 변경하는 함수
void totalQty(inventory);				// 재고에 있는 전체 서적의 재고량을 출력하는 함수
void calculateTotalAmount(inventory);	// 재고에 있는 전체 서적의 가격을 출력하는 함수

typedef struct book_info {	// 연결 리스트의 노드 구조체
	char title[100];		// 서적명
	int qty;				// 재고량
	float price;			// 책의 가격
	struct book_info* next;	// 자기참조 구조체
}b[100];	// 구조체 별칭

typedef struct person_info {
	char lastname[1000];		// 성
	char firstname[1000];		// 이름
	char author[1000];			// 성+이름
	struct book_info bookPtr;	// 서적정보를 담는 연결리스트의 주소를 저장할 변수
}p[100];	// 구조체 별칭

int main(void) {
	greeting();

	struct person_info theInventory[100];	// 구조체를 원소로한 일차원 배열

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

// 고맙다는 표현을 출력하는 함수
void greeting() {
	printf("안녕하세요. 서점 재고 관리 프로그램에 오신 것을 환영합니다.\n\n");
}

// theInventory를 만드는 함수
void readDatabase(struct person_info inventory[100]) {
	char firstCap[100], lastCap[100], titleCap[100];	// 각각 문자열을 첫 글자만 대문자로 만들 때 사용
	char authorlist[100][100];		// 작가의 이름을 "성, 이름" 형태로 저장할 변수
	char filename[100];				// 입력받은 파일명을 저장할 변수
	char str[100];					// 파일에서 한줄을 입력받아 저장할 변수
	char* ptr;						// 자른 문자열을 저장할 포인터
	char* sArr[100] = { NULL, };	// 자른 문자열을 저장
	int token = 0, bookNum = 0, index = 0, listNum = 0;
	
	FILE* fp = NULL;

	do {
		printf("열 파일 이름을 입력하세요: ");
		scanf("%s", filename);
		fp = fopen(filename, "rt");
		if (fp == NULL) {	// 파일이 열리지 않는다면
			printf("파일이 존재하지 않습니다.\n");
		}
	} while (fp == NULL);	// 파일이 열리지 않는 동안

	/*파일의 끝이 아닌동안 파일을 한줄씩 읽어 구조체 멤버에 저장*/
	while (!feof(fp)) {					// 파일의 끝이 아닌 동안
		fgets(str, "%s", fp);			// 한줄 입력 파일을 읽음
		ptr = strtok(str, ",");			// 문자열을 잘라서 포인터를 반환
		while (ptr != NULL) {			// 자른 문자열이 나오지 않을 때까지 반복
			sArr[token] = ptr;			// 문자열을 자른 뒤 메모리 주소를 문자열 포인터 배열에 저장
			token++;					// 인덱스 증가
			ptr = strtok(NULL, ",");	// 다음 문자열을 잘라서 포인터를 반환
		}
		token = 0;

		/*각각 자른 문자열을 서적 정보에 저장*/
		strcpy(inventory[bookNum].lastname, sArr[0]);
		strcpy(inventory[bookNum].firstname, sArr[1]);
		strcpy(inventory[bookNum].bookPtr.title, sArr[2]);
		inventory[bookNum].bookPtr.qty = atoi(sArr[3]);
		inventory[bookNum].bookPtr.price = atof(sArr[4]);

		/*입력한 이름을 첫글자만 대문자로 바꿈*/
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

		/*입력한 성을 첫글자만 대문자로 바꿈*/
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

		/*입력한 제목을 첫글자만 대문자로 바꿈*/
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

		bookNum++;	// 책의 권 수 1 증가
	}

	/*작가의 이름을 "성, 이름" 형식으로 저장*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	strcpy(inventory[bookNum].lastname, "\0");	// 책의 수를 구분하기 위한 문자 복사

	/*입력파일에 적힌 작가의 이름순서대로 중복없이 author 구조체 멤버 변수에 저장*/
	for (int m = 0; m < 30; m++) {
		listNum++;	// 구조체 멤버에 저장할 작가의 인덱스
		strcpy(inventory[m].author, authorlist[0]);
		for (int n = 0; n < bookNum;) {
			if (strcmp(inventory[m].author, authorlist[n]) == 0) {	// 입력받은 작가의 이름이 구조체 멤버에 저장된 작가와 이름이 같다면
				for (int k = n; k < bookNum - 1; k++) {
					strcpy(authorlist[k], authorlist[k + 1]);	// 배열을 k부터 왼쪽으로 이동
				}
				bookNum--;
			}
			else
				n++;
		}
		if (bookNum == 0)
			break;
	}

	strcpy(inventory[listNum].author, "\0");	// 작가 수를 구분하기 위한 문자 복사

	fclose(fp);	// 파일 닫기
}

// 사용자 메뉴를 출력하는 함수
int printMenu() {
	int choice = 0;	// 선택한 숫자를 저장
	int in = 0;		// 입력한 수가 숫자인지 확인
	printf("\n-------------------------------------------\n");
	printf("1. 입력된 순서대로 출력\n");
	printf("2. 저자의 이름 순으로 정렬\n");
	printf("3. 특정 작가의 서적을 정렬\n");
	printf("4. 새로운 서적 정보 입력\n");
	printf("5. 특정 서적의 가격 변경\n");
	printf("6. 특정 서적의 재고량 변경\n");
	printf("7. 전체 서적의 재고량\n");
	printf("8. 전체 서적의 가격\n");
	printf("9. 종료\n");
	while (1) {
		printf("Enter your choice: ");
		in = scanf("%d", &choice);		// 숫자를 입력했는지 확인
		while (getchar() != '\n');		// 입력버퍼에 저장된 문자 지우기
		if (in == 1)					// 숫자를 입력했다면
			break;
		else							// 숫자를 입력하지 않았다면
			printf("숫자를 입력하세요.\n");
	}
	return choice;	// 선택한 숫자 리턴
}

// 입력된 순서대로 출력하는 함수
void originInventory(struct person_info inventory[100]) {
	int authorNum = 0, bookNum = 0;	// 프로그램에 있는 작가와 책의 수
	char authorlist[100][100];		// 작가의 이름을 "성, 이름" 형태로 저장할 변수
	int index = 0;					// 출력할 작가 배열의 인덱스

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		authorNum++;	// 작가의 수 1 증가
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		bookNum++;		// 책의 수 1 증가

	/*작가의 이름을 "성, 이름" 형식으로 저장*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*연결리스트 구현*/
	struct book_info* head = NULL;
	struct book_info* curr = NULL;
	struct book_info* newNode = NULL;
	for (int i = 0; i < bookNum; i++) {
		newNode = (struct book_info*)malloc(sizeof(b));		// 새로운 노드 생성
		strcpy(newNode->title, inventory[i].bookPtr.title);	// 데이터 저장
		newNode->qty = inventory[i].bookPtr.qty;			// 데이터 저장
		newNode->price = inventory[i].bookPtr.price;		// 데이터 저장
		if (head == NULL) {
			head = curr = newNode;
		}
		else {
			curr->next = newNode;
			curr = newNode;
		}
	}

	/*연결리스트 출력*/
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

// 저자의 이름 순으로, 저자별로는 책 제목 순으로 정렬하여 출력하는 함수
void displayInventory(struct person_info inventory[100]) {
	int authorNum = 0, bookNum = 0;	// 프로그램에 있는 작가와 책의 수
	char authorlist[100][100];		// 작가의 이름을 "성, 이름" 형태로 저장할 변수
	char authorname[100][100];		// 작가의 이름을 저장할 변수
	char tmp[100];					// 정렬할 때 사용할 변수

	while (strcmp(inventory[authorNum].author, "\0") != 0)  // authorNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		authorNum++;	// 작가의 수 1 증가
	while (strcmp(inventory[bookNum].lastname, "\0") != 0)	// bookNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		bookNum++;		// 책의 수 1 증가

	/*작가의 이름을 "성, 이름" 형식으로 저장*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*작가의 이름을 배열에 저장*/
	for (int num = 0; num < authorNum; num++) {
		strcpy(authorname[num], inventory[num].author);
	}

	/*작가의 이름 정렬*/
	for (int m = 0; m < authorNum - 1; m++) {
		for (int n = 0; n < authorNum - 1 - m; n++) {
			if (strcmp(authorname[n], authorname[n + 1]) > 0) {	// 앞의 작가의 이름이 더 크다면 자리를 바꿈
				strcpy(tmp, authorname[n]);
				strcpy(authorname[n], authorname[n + 1]);
				strcpy(authorname[n + 1], tmp);
			}
		}
	}

	/*연결리스트 구현*/
	for (int j = 0; j < authorNum; j++) {
		struct book_info* head = NULL;
		struct book_info* curr;
		struct book_info* prev = (struct book_info*)malloc(sizeof(b));
		struct book_info* newNode;
		for (int i = 0; i < bookNum; i++) {
			if (strcmp(authorname[j], authorlist[i]) == 0) {
				newNode = (struct book_info*)malloc(sizeof(b));		// 새로운 노드 생성
				strcpy(newNode->title, inventory[i].bookPtr.title);	// 데이터 저장
				newNode->qty = inventory[i].bookPtr.qty;			// 데이터 저장
				newNode->price = inventory[i].bookPtr.price;		// 데이터 저장
				newNode->next = NULL;
				if (head == NULL) {
					head = newNode;
				}
				else {
					if (strcmp(inventory[i].bookPtr.title, head->title) == -1) {	// 연결하려는 제목이 작다면
						newNode->next = head;
						head = newNode;			// 새로들어온 노드가 head
					}
					else {						// 연결하려는 제목이 크다면
						curr = head;
						while (curr != NULL && (strcmp(inventory[i].bookPtr.title, curr->title) == 1)) {// 연결하려는 제목이 작을 때까지
							prev = curr;		// 현재 노드를 저장
							curr = curr->next;	// 다음 노드로 이동
						}
						newNode->next = prev->next;
						prev->next = newNode;		// 연결
					}
				}
			}
		}
		/*연결리스트 출력*/
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

// 특정 작가의 서적을 제목 순으로 출력하는 함수
void displayAuthorsWork(struct person_info inventory[100]) {
	char firstnameIn[100], lastnameIn[100], authorIn[100];	// 입력할 이름, 성, 입력한 작가의 성+이름
	char firstCap[100], lastCap[100];	// 각각 문자열을 첫 글자만 대문자로 만들 때 사용
	char authorlist[100][100];			// 작가의 이름을 "성, 이름" 형태로 저장할 변수
	int authorNum = 0, bookNum = 0;		// 프로그램에 있는 작가와 책의 수
	int k = 0, check = 0, index = 0;

	printf("\n작가의 first name을 적어주세요: ");
	scanf("%s", firstnameIn);
	printf("작가의 last name을 적어주세요: ");
	scanf("%s", lastnameIn);

	/*입력한 이름을 첫글자만 대문자로 바꿈*/
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

	/*입력한 성을 첫글자만 대문자로 바꿈*/
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

	/*작가의 이름을 "성, 이름" 형식으로 저장*/
	strcpy(authorIn, lastnameIn);	// 입력받은 작가의 성을 authorIn에 복사
	strcat(authorIn, ", ");
	strcat(authorIn, firstnameIn);	// 입력받은 작가의 이름을 authorIn에 이어붙임

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		authorNum++;	// 작가의 수 1 증가
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		bookNum++;		// 책의 수 1 증가

	/*작가의 이름을 "성, 이름" 형식으로 저장*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*입력한 작가 이름과 일치하는 이름이 프로그램에 존재하는지 검사*/
	for (k = 0; k < authorNum; k++) {
		if (strcmp(inventory[k].author, authorIn) == 0)
			break;
		else
			check++;
	}

	/*입력한 작가가 프로그램에 있나 확인*/
	if (check == authorNum) {
		printf("\nNo such author in your database.\nSo you cannot sort and print.\n");
		return 0;
	}
	
	/*연결리스트 구현*/
	struct book_info* head = NULL;
	struct book_info* curr = (struct book_info*)malloc(sizeof(b));
	struct book_info* prev = (struct book_info*)malloc(sizeof(b));
	struct book_info* newNode;
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(inventory[k].author, authorlist[i]) == 0) {	// 입력한 작가 이름과 같은 이름 찾기
			newNode = (struct book_info*)malloc(sizeof(b));		// 새로운 노드 생성
			strcpy(newNode->title, inventory[i].bookPtr.title);	// 데이터 저장
			newNode->qty = inventory[i].bookPtr.qty;			// 데이터 저장
			newNode->price = inventory[i].bookPtr.price;		// 데이터 저장
			newNode->next = NULL;
			if (head == NULL) {
				head = newNode;
			}
			else {
				if (strcmp(inventory[i].bookPtr.title, head->title) == -1) {	// 연결하려는 제목이 작다면
					newNode->next = head;
					head = newNode;			// 새로들어온 노드가 head
				}
				else {						// 연결하려는 제목이 크다면
					curr = head;
					while (curr != NULL && (strcmp(inventory[i].bookPtr.title, curr->title) == 1)) {	// 연결하려는 제목이 작을 때까지
						prev = curr;		// 현재 노드를 저장
						curr = curr->next;	// 다음 노드로 이동
					}
					newNode->next = prev->next;
					prev->next = newNode;	// 연결
				}
			}
		}
	}
	
	/*연결리스트 출력*/
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

// 새로운 서적 정보를 입력하는 함수
void addBook(struct person_info inventory[100]) {
	char firstnameIn[100], lastnameIn[100], titleIn[100];	// 입력할 이름, 성, 책의 제목
	char firstCap[100], lastCap[100], titleCap[100];		// 각각 문자열을 첫 글자만 대문자로 만들 때 사용
	double qtyIn, priceIn;			// 입력할 책의 가격
	char authorIn[100];				// 입력한 작가의 성+이름
	char authorlist[100][100];		// 작가의 이름을 "성, 이름" 형태로 저장할 변수
	int authorNum = 0, bookNum = 0;	// 프로그램에 있는 작가와 책의 수
	double point1, point2;			// 소수점 확인을 위한 변수
	int cnt = 0, checkAuthor = 0, index = 0, in;

	while (strcmp(inventory[authorNum].author, "\0") != 0)	// authorNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		authorNum++;	// 작가의 수 1 증가
	while (strcmp(inventory[bookNum].lastname, "\0") != 0)	// bookNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		bookNum++;		// 책의 수 1 증가

	printf("\n작가의 first name을 적어주세요: ");
	scanf("%s", firstnameIn);
	printf("작가의 last name을 적어주세요: ");
	scanf("%s", lastnameIn);

	/*입력한 이름을 첫글자만 대문자로 바꿈*/
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

	/*입력한 성을 첫글자만 대문자로 바꿈*/
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

	/*작가의 이름을 "성, 이름" 형식으로 저장*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	printf("서적의 제목을 적어주세요: ");
	scanf(" %[^\n]s", titleIn);				// 공백 포함 입력

	/*입력한 제목을 첫글자만 대문자로 바꿈*/
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
	
	/*같은 책 제목이 있는지 확인*/
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(titleIn, inventory[i].bookPtr.title) == 0) {
			printf("\n같은 제목의 책이 있습니다.\n");
			return 0;
		}
	}

	/*재고를 양의 정수를 입력할 때까지 반복*/
	in = 0;
	do {
		printf("서적의 재고를 적어주세요: ");
		in = scanf("%lf", &qtyIn);
		while (getchar() != '\n');	// 입력버퍼에 저장된 문자 지우기
		if (in == 1) {
			if (qtyIn <= 0 || (int)qtyIn - qtyIn != 0)	// 입력한 값이 양의 정수가 아니라면
				printf("양의 정수를 입력해야 합니다.\n");
		}
		else
			printf("숫자를 입력하세요.\n");
	} while (qtyIn <= 0 || (int)qtyIn - qtyIn != 0);	// 양의 정수를 입력할 때까지 반복

	/*가격이 소수점 두번째의 실수로 입력할 때까지 반복*/
	in = 0;
	do {
		printf("서적의 가격을 적어주세요: ");
		in = scanf("%lf", &priceIn);
		point1 = priceIn * 100;		// 소수점 확인을 위한 변수
		point2 = priceIn * 10;		// 소수점 확인을 위한 변수

		while (getchar() != '\n');	// 입력버퍼에 저장된 문자 지우기
		if (in == 1) {
			if (priceIn <= 0)		// 음수라면
				printf("양의 실수를 입력해야 합니다.\n");
			else if ((int)point1 - point1 != 0 || (int)point2 - point2 == 0)	// 소수점 두번째의 실수가 아니라면
				printf("소수점 두자리 실수를 입력해야 합니다.\n");
		}
		else	// 숫자가 아니라면
			printf("숫자를 입력하세요.\n");
	} while (priceIn <= 0 || (int)point1 - point1 != 0 || (int)point2 - point2 == 0);	// 소수점 두번째의 실수가 아니거나 음수인 동안 반복

	strcpy(authorIn, lastnameIn);	// 입력받은 작가의 성을 authorIn에 복사
	strcat(authorIn, ", ");
	strcat(authorIn, firstnameIn);	// 입력받은 작가의 이름을 authorIn에 이어붙임

	/*입력한 작가 이름과 일치하는 이름이 프로그램에 존재하는지 검사*/
	for (cnt = 0; cnt < authorNum; cnt++) {
		if (strcmp(inventory[cnt].author, authorIn) == 0)
			break;
		else
			checkAuthor++;
	}

	/*새로운 서적정보 저장*/
	if (checkAuthor == authorNum) {	// 일치하는 작가 이름이 없다면 
		strcpy(inventory[authorNum].author, authorIn);	// 작가 이름 구조체 멤버 변수에 추가
		strcpy(inventory[authorNum + 1].author, "\0");
		// 서적 정보 저장
		strcpy(inventory[bookNum].bookPtr.title, titleIn);
		inventory[bookNum].bookPtr.qty = qtyIn;
		inventory[bookNum].bookPtr.price = priceIn;
		strcpy(inventory[bookNum].lastname, lastnameIn);
		strcpy(inventory[bookNum].firstname, firstnameIn);
		strcpy(inventory[bookNum + 1].lastname, "\0");
		printf("\n정상적으로 추가되었습니다.\n");
	}
	else {							// 일치하는 작가 이름이 있다면 서적 정보 저장
		strcpy(inventory[bookNum].bookPtr.title, titleIn);
		inventory[bookNum].bookPtr.qty = qtyIn;
		inventory[bookNum].bookPtr.price = priceIn;
		strcpy(inventory[bookNum].lastname, lastnameIn);
		strcpy(inventory[bookNum].firstname, firstnameIn);
		strcpy(inventory[bookNum + 1].lastname, "\0");
		printf("\n정상적으로 추가되었습니다.\n");
	}
}

// 특정 서적의 가격 정보를 변경하는 함수
void changePrice(struct person_info inventory[100]) {
	char firstnameIn[100], lastnameIn[100], titleIn[100];	// 입력할 이름, 성, 책의 제목
	char firstCap[100], lastCap[100], titleCap[100];		// 각각 문자열을 첫 글자만 대문자로 만들 때 사용
	int check = 0, checkAuthor = 0, checkBook = 0;			// 입력과 일치하는 정보가 있나 확인
	char authorlist[100][100];			// 작가의 이름을 "성, 이름" 형태로 저장할 변수
	double priceIn = 0, pricePre = 0;	// 입력 후와 전의 가격
	char authorIn[100];					// 입력한 작가의 성+이름
	int authorNum = 0, bookNum = 0;		// 프로그램에 있는 작가와 책의 수
	double point1, point2;				// 소수점 확인을 위한 변수
	int cnt = 0, index = 0, in;
	bool exitOuterLoop = false;			// 바깥쪽 루프를 빠져나올지 결정하는 변수

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		authorNum++;	// 작가의 수 1 증가
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		bookNum++;		// 책의 수 1 증가

	printf("\n작가의 firstname을 적어주세요: ");
	scanf("%s", firstnameIn);
	printf("작가의 lastname을 적어주세요: ");
	scanf("%s", lastnameIn);

	/*입력한 이름을 첫글자만 대문자로 바꿈*/
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

	/*입력한 이름을 첫글자만 대문자로 바꿈*/
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

	strcpy(authorIn, lastnameIn);	// 입력받은 작가의 성을 authorIn에 복사
	strcat(authorIn, ", ");
	strcat(authorIn, firstnameIn);	// 입력받은 작가의 이름을 authorIn에 이어붙임

	/*작가의 이름을 "성, 이름" 형식으로 저장*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*입력한 작가 이름과 일치하는 이름이 프로그램에 존재하는지 검사*/
	for (cnt = 0; cnt < authorNum; cnt++) {
		if (strcmp(inventory[cnt].author, authorIn) == 0)
			break;
		else
			checkAuthor++;
	}

	/*입력한 작가가 프로그램에 있나 확인*/
	if (checkAuthor == authorNum) {
		printf("\nNo such author in your database.\nSo you cannot change the price.\n");
		return 0;
	}

	printf("책 제목을 적어주세요: ");
	scanf(" %[^\n]s", titleIn);			// 공백 포함 입력

	/*입력한 제목을 첫글자만 대문자로 바꿈*/
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

	/*입력한 책의 제목과 일치하는 제목이 프로그램에 존재하는지 검사*/
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

	/*입력한 제목이 프로그램에 있나 확인*/
	if (checkBook == check) {
		printf("\nNo book with the title %s by %s in inventory\n", titleIn, inventory[cnt].author);
		return 0;
	}

	/*가격이 소수점 두번째의 실수로 입력할 때까지 반복*/
	in = 0;
	do {
		printf("서적의 가격을 적어주세요: ");
		in = scanf("%lf", &priceIn);
		point1 = priceIn * 100;		// 소수점 확인을 위한 변수
		point2 = priceIn * 10;		// 소수점 확인을 위한 변수

		while (getchar() != '\n');	// 입력버퍼에 저장된 문자 지우기
		if (in == 1) {
			if (priceIn <= 0)		// 음수라면
				printf("양의 실수를 입력해야 합니다.\n");
			else if ((int)point1 - point1 != 0 || (int)point2 - point2 == 0)	// 소수점 두번째의 실수가 아니라면
				printf("소수점 두자리 실수를 입력해야 합니다.\n");
		}
		else	// 숫자가 아니라면
			printf("숫자를 입력하세요.\n");
	} while (priceIn <= 0 || (int)point1 - point1 != 0 || (int)point2 - point2 == 0);	// 소수점 두번째의 실수가 아니거나 음수인 동안 반복

	/*가격 변경을 위함 탐색*/
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(inventory[cnt].author, authorlist[i]) == 0) {
			for (int j = 0; j < bookNum; j++) {
				if (strcmp(titleIn, inventory[j].bookPtr.title) == 0) {
					pricePre = inventory[j].bookPtr.price;	// 가격 바꾸기 전의 재고 저장
					exitOuterLoop = true;					// 바깥쪽 루프도 빠져나가겠음
					inventory[j].bookPtr.price = priceIn;	// 가격 변경
					break;									// 반복문 종료
				}
			}
		}
		if (exitOuterLoop == true)    // 바깥쪽 루프도 빠져나오겠다고 결정했으면
			break;                    // 바깥쪽 루프를 끝냄
	}

	printf("\nPrice will be updated from %.2f to %.2f\n", pricePre, priceIn);
}

// 특정 서적의 재고량을 변경하는 함수
void changeQty(struct person_info inventory[100]) {
	char firstnameIn[100], lastnameIn[100], titleIn[100];	// 입력할 이름, 성, 책의 제목
	int checkAuthor = 0, checkBook = 0, check = 0;			// 입력과 일치하는 정보가 있나 확인
	char firstCap[100], lastCap[100], titleCap[100];		// 각각 문자열을 첫 글자만 대문자로 만들 때 사용
	double qtyIn, qtyPre;			// 입력 후와 전의 재고
	char authorIn[100];				// 입력한 작가의 성+이름
	char authorlist[100][100];		// 프로그램에 존재하는 작가 이름
	int authorNum = 0, bookNum = 0;	// 프로그램에 있는 작가와 책의 수
	int cnt = 0, index = 0, in;
	bool exitOuterLoop = false;		// 바깥쪽 루프를 빠져나올지 결정하는 변수

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		authorNum++;	// 작가의 수 1 증가
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		bookNum++;		// 책의 수 1 증가

	printf("\n작가의 firstname을 적어주세요: ");
	scanf("%s", firstnameIn);
	printf("작가의 lastname을 적어주세요: ");
	scanf("%s", lastnameIn);

	/*입력한 이름을 첫글자만 대문자로 바꿈*/
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

	/*입력한 성을 첫글자만 대문자로 바꿈*/
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

	strcpy(authorIn, lastnameIn);	// 입력받은 작가의 성을 authorIn에 복사
	strcat(authorIn, ", ");
	strcat(authorIn, firstnameIn);	// 입력받은 작가의 이름을 authorIn에 이어붙임

	/*작가의 이름을 "성, 이름" 형식으로 저장*/
	for (int num = 0; num < bookNum; num++) {
		strcpy(authorlist[num], inventory[num].lastname);
		strcat(authorlist[num], ", ");
		strcat(authorlist[num], inventory[num].firstname);
	}

	/*입력한 작가 이름과 일치하는 이름이 프로그램에 존재하는지 검사*/
	for (cnt = 0; cnt < authorNum; cnt++) {
		if (strcmp(inventory[cnt].author, authorIn) == 0)
			break;
		else
			checkAuthor++;
	}

	/*입력한 작가가 프로그램에 있나 확인*/
	if (checkAuthor == authorNum) {
		printf("\nNo such author in your database.\nSo you cannot change the qty.\n");
		return 0;
	}

	printf("책 제목을 적어주세요: ");
	scanf(" %[^\n]s", titleIn);			// 공백 포함 입력

	/*입력한 제목을 첫글자만 대문자로 바꿈*/
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

	/*입력한 책의 제목과 일치하는 제목이 프로그램에 존재하는지 검사*/
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

	/*입력한 제목이 프로그램에 있나 확인*/
	if (checkBook == check) {
		printf("\nNo book with the title %s by %s in inventory\n", titleIn, inventory[cnt].author);
		return 0;
	}

	/*재고를 양의 정수를 입력할 때까지 반복*/
	in = 0;
	do {
		printf("재고 변경: ");
		in = scanf("%lf", &qtyIn);
		while (getchar() != '\n');	// 입력버퍼에 저장된 문자 지우기
		if (in == 1) {
			if (qtyIn <= 0 || (int)qtyIn - qtyIn != 0)	// 입력한 값이 양의 정수가 아니라면
				printf("양의 정수를 입력해야 합니다.\n");
		}
		else
			printf("숫자를 입력하세요.\n");
	} while (qtyIn <= 0 || (int)qtyIn - qtyIn != 0);	// 양의 정수를 입력할 때까지 반복

	/*재고 변경을 위한 탐색*/
	for (int i = 0; i < bookNum; i++) {
		if (strcmp(inventory[cnt].author, authorlist[i]) == 0) {
			for (int j = 0; j < bookNum; j++) {
				if (strcmp(titleIn, inventory[j].bookPtr.title) == 0) {
					qtyPre = inventory[j].bookPtr.qty;	// 재고 바꾸기 전의 재고 저장
					inventory[j].bookPtr.qty = qtyIn;	// 재고 변경
					exitOuterLoop = true;				// 바깥쪽 루프도 빠져나가겠음
					break;								// 반복문 종료
				}
			}
		}
		if (exitOuterLoop == true)		// 바깥쪽 루프도 빠져나오겠다고 결정했으면
			break;						// 바깥쪽 루프를 끝냄
	}

	printf("\nQty will be updated from %d to %d\n", (int)qtyPre, (int)qtyIn);
}

// 재고에 있는 전체 서적의 재고량을 출력하는 함수
void totalQty(struct person_info inventory[100]) {
	int authorNum = 0, bookNum = 0;	// 프로그램에 있는 작가와 책의 수
	int sum = 0;					// 전체 가격을 저장할 변수

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		authorNum++;	// 작가의 수 1 증가
	while (strcmp(inventory[bookNum].lastname, "\0") != 0) 	// bookNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		bookNum++;		// 책의 수 1 증가

	for (int i = 0; i < bookNum; i++)		// 책의 수만큼 반복
		sum += inventory[i].bookPtr.qty;	// 재고 구조체 멤버를 sum에 더함
	printf("\n-------------------------------------------");
	printf("\nThe total number of books is %d", sum);	// 전체 권 수 출력
	printf("\n-------------------------------------------\n");
}

// 재고에 있는 전체 서적의 가격을 출력하는 함수
void calculateTotalAmount(struct person_info inventory[100]) {
	int authorNum = 0, bookNum = 0;	// 프로그램에 있는 작가와 책의 수
	float sum = 0;					// 전체 가격을 저장할 변수

	while (strcmp(inventory[authorNum].author, "\0") != 0) 	// authorNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		authorNum++;	// 작가의 수 1 증가
	while (strcmp(inventory[bookNum].lastname, "\0") != 0)	// bookNum번째 인덱스의 구조체 멤버의 값이 \0일 때까지
		bookNum++;		// 책의 수 1 증가

	for (int i = 0; i < bookNum; i++)		// 책의 수만큼 반복
		sum += inventory[i].bookPtr.price;	// 가격 구조체 멤버를 sum에 더함
	printf("\n-------------------------------------------");
	printf("\nThe total value of the inventory is $%.2f", sum);	// 전체 가격 출력
	printf("\n-------------------------------------------\n");
}
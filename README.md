# 2학년 1학기 과제
---

## 목차
1. 자료구조

    1.1. [2차원 배열](#2차원-배열)
    
    1.2. [재귀호출1](#재귀호출1)
    
    1.3. [재귀호출2](#재귀호출2)
    
    1.4. [ppm 이미지 표현](#ppm-이미지-표현)
    
    1.5. [원형 큐](#원형-큐)
    
    1.6. [서점 재고 관리](#서점-재고-관리)

    1.7. [infix to posfix](#infix-to-posfix)
    
2. 객체지향언어
    
    2.1. [ATM기계](#ATM기계)
    
    2.2. [다형성 활용](#다형성-활용)
    
    2.3. [영화 티켓박스](#영화-티켓박스)
    
---
   
# 1. 자료구조

## 2차원 배열

두 행렬의 곱을 계산하는 프로그램을 작성하시오.

### 개념
    2차원 배열, 동적 할당, 파일 처리

### 조건
    1. 파일로 두 행렬을 입력
    2. fopen 사용
    3. 두 행렬의 곱에 대한 결과 화면 출력

---
    
## 재귀호출1

입력된 정수의 각 자리 수를 더하는 프로그램을 순환방식으로 작성하시오.

### 예시
    결과 : 236 -> 11
    
---
    
## 재귀호출2

두 정수의 LCM을 구하는 프로그램을 순환방식으로 작성하시오.

### 예시
    결과 : 5 2 -> 10
    
---

## ppm 이미지 표현

지표면의 고도를 나타내는 데이터를 입력 받아 이미지로 표현하는 프로그램을 작성하시오.

입력 받은 데이터를 RGB 값으로 계산한 이후 새로운 이미지 파일을 생성하여 이를 출력하는 프로그램으로 플로우는 다음과 같다.

1. Read the data into a 2D array 
2. Find min and max elevation to correspond to darkest and brightest color, respectively 
3. Compute the shade of grey for each cell in the map 
4. Produce the output file in the specified format (PPM) 
5. Use an online free tool to convert your PPM file into a JPG file to visually check your results

1. Step 1 – Read the data into a 2D array 
입력데이터는 텍스트 파일로 지표면의 고도를 나타낸다. 입력데이터에는 3가지 정보가 제공되는데, 
A. Number of rows in the map (height of the image to be produced) 
B. Number of columns in the map (width of the image to be produced) 
C. Name of the file containing the data.

데이터를 입력 받기 전 입력이 정상적인지 아닌지 확인이 필요한데, 만약 입력에 오류가 존재한다면, 다음과 같은 출력을 하면서 프로그램에서 exit 하여야 한다. 
 Error : Problem reading in rows and columns 
 Error : Unable to open file <filename>

데이터 파일은 스페이스로 구별되는 정수들이며 하나의 데이터 집합이다. 480-row by 844-col 데이터는 405,120 (480*844) 정수들을 포함하며, 정수 각각은 한 특정지역(cell)의 평균고도를 나타낸다. 데이터 파일은 row0 에 대해 844 정수들, row 1 에 대한 844 정수들 등 row-major 순서로 만들어졌다.

입력을 받아 프로세스를 하기 전에 파일에 올바른 개수의 정수 데이터가 있는지 확인이 필요하며 만약 오류가 있다면 즉시 필요한 오류를 출력하고 프로그램에서 exit 하여야한다. 
 Error : Read a non-integer value 
 Error : Problem reading the file 
 Error : End of file reached prior to getting all the required data 
 Error : Too many data points

데이터 파일은 line break가 없으며 데이터를 2D array에 넣기 위해서는 파일에서 제공하는 row 외 column 값을 사용하여야 한다. 또한, 오류 없이 데이터가 입력되었는지 확인하기 위하여 제공되는 데이터 파일은 사이즈가 크기 때문에 작은 사이즈의 입력 파일을 만들어 충분한 테스트를 거쳐야 한다. 

2. Step 2 – Find the min and max values 
주어진 입력을 흑백 이미지로 출력하기 위하여 입력된 데이터에서 최소값(min)과 최대값(max)를 찾고 주어진 공식에 대입하면 된다. 이를 위해 먼저, 최소값과 최대값을 찾기 위한 함수 findMaxMin를 작성하여야 한다. 샘플 데이터를 만들어 이 함수가 올바르게 작동되는지 충분히 검토한 후 step 3로 이동하여야 한다. 

3. Step 3 – Compute the color for each part of the map and store 
입력 데이터를 흑백이미지로 출력하기 위하여 입력 데이터 각각에 대한 RGB 값을 계산하여야
한다. 이때 흑백출력임으로 각 데이터에 대하여, 다음 공식을 적용하고 실수로 계산하여 가장
근사한 정수로 변환시키면 된다.

shade of grey = {(elevation – minimumElevation)/(maximumElevation – minimumElevation)}*255

또한, 계산된 정수값을 R, G, B 값으로 동일하게 적용하면 된다. 이때 새로운 2D array를 만들어 계산된 RGB 값을 저장하여야 한다.

위와 같이 고도값(elevation value)에서 흑백 이미지 값으로 변환시키는 프로세스는 loadGreyscale 함수를 만들어 수행해야 한다. 

4. Step 4 – Produce the output file in the PPM format 
RGP 칼라 모델로 이미지를 출력하기 위해서 PPM(portable pixel map의 약자) format으로 output 파일을 만들어야 하며 이를 위해 outputImage 함수를 만들어 PPM 데이터를 output file로 wirte하시오. PPM 포멧으로 output file을 만드는 방법은 output file에 RGB 값을 쓰기 전에 세 가지 정보를 write 하면 되고 output file의 이름을 inputfile name.ppm로 만들면 된다. 즉, 만약 input file 명이 indata.dat라면, input.dat.ppm으로 이름을 만들어야 하며 다음 ppm 파일을 만드는 포멧은 다음과 같다.
 첫번째 줄 : 문자열 “P3” 
 두번째 줄 : width (number of column) 과 height (number of rows) 
 세번째 줄 : max color value (255) 
 나머지 줄 : RGB 값 예

---
   
## 원형 큐
    
1차원 배열을 이용한 원형큐를 구현하시오.

---
    
## 함수
    1. Create : 새로운 empty 큐 생성한다.
    2. Empty : 큐가 empty 인지 확인한다.
    3. Full : 큐가 full 인지 확인한다.
    4. Enqueuer : 새로운 데이터를 queue rear에 삽입한다.
    5. Dequeuer : front에 위치한 데이터 삭제하고 리턴하여 출력한다.
    6. QueueDisplay : 큐에 저장된 모든 데이터 출력한다. 만약 empty일 경우 메시지 출력한다.
    
---
    
## 서점 재고 관리

프로그램은 다음과 같은 기능을 사용자에게 제공하여야 함.

입력기능
1. 서점의 재고는 파일에 저장되어 있으며, 이 파일의 데이터를 입력 받아 프로그램이 동작
사용자 서비스 기능
2. 재고의 데이터를 저자의 이름순으로 정렬하여 출력
3. 특정 작가의 작품을 제목 순으로 출력
4. 새로운 서적 정보 입력
5. 특정 서적의 가격 정보 변경
6. 특정 서적의 재고 숫자 변경
7. 재고에 있는 전체 서적의 재고 숫자 출력
8. 재고에 있는 서적들에 대한 전체 가격 출력

규칙
1. 메인 함수는 아래의 알고리즘으로 작성되어야 함. 작성시 아래 메인함수에 다른 기능이나 파라메타의 변경이 없어야 함.

```
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
```

2. 전체 프로그램에 대해 재고를 저장하기 위한 자료구조(theInventory)는 하나만 선언하여야 하고 메인함수에서 선언하여야 함. theInventory는 구조체 일차원배열로 구조체는 작가의 이름(last name, first name)과 이 작가의 서적정보를 담는 연결리스트의 주조를 저장할 변수를 포함하여야 함. 작가의 이름은 저장하기 전, last name과 first name의 첫번째 알파벳만 대문자이고 나머진 소문자로 나타내어야 함. 서적 정보를 저장할 연결리스트는 서적명, 재고량, 서적당 가격과 다음 노드를 가르킬 포인터 변수를 포함하는 자기 참조 구조체
가 필요함.

3. 함수의 정의는 아래와 같고 매개변수 변경은 불가능함. 아래 함수 외 다른 함수 정의는
가능하나 아래 정의된 함수에서만 호출이 가능하고, 메인에서의 호출은 불가능함. 또한, 전
역변수 사용은 금지함.

함수정의
greeting()
이 함수는 이 프로그램을 사용하여 고맙다는 표현을 출력하는 함수로 샘플 실행의 내용을 포함하여도 괜찮음.

readDatabase (inventory)
이 함수는 사용자에게 입력파일명을 요구하고, 입력파일의 데이터를 2번에 있는 구조로 만드는 함수임. 즉, theInventory를 만드는 함수임.

printMenu()
이 함수는 사용자 메뉴를 출력하는 함수로 사용자의 choice를 린턴함. 샘플 실행을 참조할 것

displayInventory(inventory) 
이 함수는 재고를 출력하는 함수로 저자의 정렬 순으로 출력하며 저자별로는 책 제목 순으로 정렬된 정보를 출력해줌

displayAuthorsWork(inventory)
이 함수는 사용자에게 저자명(last name과 first name)을 요구하고 그 저자의 책 정보를 제목으로 정렬된 순으로 출력해줌. 만약 사용자가 요청한 저자가 정보에 없다면 적절한 출력을 해줘야 함.

addBook(inventory)
이 함수는 사용자에게 저자명, 책 제목, 재고량, 그리고 책 가격을 요구하고 만약 저자가 존재하면, 만약 새 책일 경우 정보를 저장하고 이미 존재한다면, 적절한 출력을 해 줘야 함. 만약 저자가 존재하지 않다면, theInvetory에 새로운 원소(저자명)가 추가되어 그 저자에 대한 정보로 저장되어야 함. 재고량은 정수로 입력되어야 하고, 가격은 양의 실수로 입력되어야 함.

changePrice(inventory)
이 함수는 사용자에게 가격정보를 변경하기 위해 필요한 저자의 이름과 책 제목을 요구하고, 양의 실수로 입력될 때만 가격을 변경해 줌. 만약 저자나 혹은 책제목이 존재 하지 않을 경우 적절한 출력 메시지 필요

changeQty(inventory)
이 함수는 위 changePrice와 같은 기능을 하나 가격이 아닌 재고량을 변경해 주는 기능을 함. 항상 양의 정수를 입력 받아야 함.

totalQty(inventory)
이 함수는 재고에 있는 모든 책의 개수를 계산하여 출력해 줌.

calculateTotalAmount(inventory)
이 함수는 재고에 있는 모든 책의 가격을 합산하여 출력해 줌.

---
    
## infix to posfix
    
중위표기법으로 입력된 수식을 후위표기법으로 변환시켜 수식계산을 하는 프로그램을 작성하시오.

초기알고리즘
1. 수식 문자열을 입력
2. Parsing을 통해 수식문법 확인
3. 중위표기법을 후위표기법으로 스택을 사용하여 변환
4. 후위표기법 계산

설명
키보드를 통해 수식문자열을 입력하면 입력되는 문자열을 저장하여 수식문법에 맞는지 확인한후 틀렸을 경우 에러 메시지를 출력하고 재입력을 요구한다. 문법에 맞는 수식이 입력되었을 경우, 스택을 활용하여 이를 후위표기법을 변환시킨후 이를 이용하여 계산한다.

수식문법
1. 오픈 괄호 " ( " 다음에 반드시 " ( " 나 피연산자, 즉 숫자, " + ", " - "가 온다.
2. 피연산자 다음에 " ) " 나 연산기호 " + ", " - ", " * ", " / ", " ^ "가 온다.
3. " ( " 와 " ) " 개수는 일치하여야 한다
4. " ( ", " ) ", 숫자, " + ", " - ", " * ", " / " , " ^ " 외 다른 기호는 에러로 처리한다.
5. 피연산는 정수 및 실수이며 실수의 경우 소수점이 포함된다.

프로그램 동작
수식 문자열 입력 -> 수식문자열 문법확인 -> 중위-후위표기 변환 -> 후위계산
입력 문자열을 문자별로 읽어 " ( ", " ) ", 숫자, " + ", " - ", " * ", " / " , " ^ "를 구분하여 위 문법을 확인하여야 함. 또한, 중위를 후위로 변환시킬 때 후위표기법을 문자열로 저장하여야 하며 이때 연산자 및 수식을 구분하여 저장하여야 함 (예, 배열을 사용할 경우 토큰 사이에 스페이스를 주어 구분) 후위표기법을 이용하여 계산할 때 피연산자는 atof를 이용하여 문자열을 실수로 변환시킴.    
    
---

# 2. 객체지향언어

## ATM기계
   
아래 기능을 포함하는 ATM기계 프로그램을 작성하시오.
    
### 기능
    1. 계좌 개설 기능
    2. 계좌 조회 기능
    3. 계좌 해지 기능
    4. 업무 종료 기능
    5. 계좌 입금 기능
    6. 계좌 출금 기능
    7. 계좌 이체 기능
    8. 고객 관리 기능 1
       - ATM 잔고, 고객 잔고 총액, 평균, 최고 값 출력
    9. 고객 관리 기능 2
        - 계좌 목록 출력( 잔액 내림차순 정렬 ) - 알고리즘 구현
    
---
    
## 다형성 활용
    
전투용품 샵에서 구매한 전투용 무기를 사용하는 프로그램을 작성하시오.
    
### 조건
    1. Tank, Fighter, Missile 무기는 Weapon 클래스를 상속받는다.
    2. BattleShop은 Shop 클래스를 상속받는다.

---

## 영화 티켓박스

아래 기능을 포함하는 영화 티켓박스 프로그램을 작성하시오.
    
### 기능
    1. 영화 정보 보기
    2. 좌석 예약 현황 보기
    3. 좌석 예약 기능
    4. 좌석 예약 취소
        - 결제 완료 시 예약 취소 불가능
    5. 티켓 결제 기능 
    6. 관리 통계 기능
    
---

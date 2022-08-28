# Assignments_2
1학년 2학기 과제

# 3장 조건문

## 3-1번
사용자에게 한 개의 정수를 입력 받고 아래 메시지 중 적절한 것을 출력하도록 프로그램을 작성하시오.

### - 조건
    1. 0을 입력받을 경우 프로그램을 종료한다.

### - 메시지
    • 입력한 값은 0보다 작습니다.
    • 입력한 값은 0이상 10미만입니다.
    • 입력한 값은 10이상 20미만입니다.
    • 입력한 값은 20이상 30미만입니다.
    • 입력한 값은 30이상입니다.

---

## 3-2번
사용자가 한 개의 정수를 입력하면 그 수를 제곱한 값을 출력하는 코드를 작성하시오.

### - 조건
    1. 조건문으로 음수를 입력할 경우 양수를 입력하도록 요청한다.
    2. 0을 입력할 경우 프로그램을 종료시킨다.

---

## 3-3번
사과는 1000원, 포도는 3000원, 배는 2000원, 귤은 500원에 파는 과일 가게가 있다.
이 가게에서 포도를 3송이 이상 구매할 경우에 다른 과일 값을 포함한 총 결재금액에서
10%를 할인해준다고 할 때, 계산해주는 프로그램을 작성하시오.

### - 예
    사과 2개, 포도 3개, 배 1개를 구매할 경우 11700원 결재(13000원에서 10%할인)

---

## 3-4번
세 개의 양의 정수를 입력 받아 그 합이 짝수이면 가장 큰 수를 출력하고,
    홀수이면 그냥 그 합을 출력하는 프로그램을 작성하시오.

---

# 4장 반복문

## 4-1번
1부터 n까지의 합을 구하되 그 합이 입력 정수를 넘지 않아야 한다는 조건하에 최댓값을 구하시오.

---

## 4-2번
1부터 입력 정수 n까지의 합을 구하되 5의 배수는 제외한 합을 구하시오. 

### 조건
    1. 반드시 continue문을 사용한다.

---

## 4-3번
입력한 자연수의 약수(factors)를 모두 출력하는 프로그램을 작성하시오.

---

## 4-4번
자연수 a, b에 대해 a의 b제곱을 돌려주는 for문을 작성하시오.

### 조건
    1. a, b는 사용자에게 입력 받는다.

---

# 5장 함수 사용과 변수의 수명

## 5-1번
함수는 처리한 결과를 1개 이상 반환(return)할 수 없다. 그러나 함수의 처리결과 중
2개 이상의 값을 프로그램에 반영할 경우, 함수의 리턴 타입을 void로 만들고 전역변수를 사용하여
함수 내에서 처리한 결과를 반영할 수 있다. 사용자에게 세 개의 정수를 입력 받은 후
아래의 함수(min_max)를 호출하여 최댓값과 최솟값을 출력하는 프로그램을 작성하시오.

### 조건
    1. min_max()함수에서의 최댓값과 최솟값 결과를 출력하는 코드는 main()함수에서 작성한다.

---

## 5-2번
음수를 입력하기 전까지 0이나 양수를 입력받고, 입력을 받을 때 마다 현재 입력한 상황에서
최솟값을 출력하는 프로그램을 작성하시오.

### 조건
    1. 프로그램은 루프를 돌면서 반드시 아래와 같은 형태의 함수(current_min)를 호출해야 한다. 
    2. current_min() 함수 내에 정적 변수 min을 선언하고 호출될 때마다 이전에 저장된
       min(최소값)과 전달받은 값을 비교해서 더 작은 값을 반환해야 한다.
    3. 입력 정수의 크기는 100을 넘지 않는 것으로 가정한다.

---

## 5-3번
음수 n을 입력 받은 후 재귀 호출에 의해 n부터 -1까지의 합을 출력하는 프로그램을 작성하시오.

### 조건
    1. 0이나 양수를 입력 받을 경우, 다시 입력을 요청한다.

---

## 5-4번
양수를 입력 받은 후 재귀 호출에 의하여 화면에 입력받은 숫자만큼
asterisk( * )를 출력하는 프로그램을 작성하시오.

### 조건
    1. 0이나 음수를 입력 받을 경우, 다시 입력을 요청한다.

---

## 5-5번
양의 정수 a, b를 입력 받아 a의 b 제곱을 출력하는 프로그램을 작성하되 재귀 함수로 구현하시오.

### 조건
    1. 입력 받은 지수(b)만큼 재귀함수를 호출하여 계산한다.

---

# 6장 배열

## 6-1번
10진수를 계속해서 2로 나누고 몫이 0이 될 때까지 나머지를 배열에 순차적으로 저장할수 있다.
이후 해당 배열을 거꾸로 읽으면서 출력하면 그것이 10진수를 2진수로 변환한 결과가 된다.
이 방법을 사용하여 10진수를 2진수로 변환하는 프로그램을 작성하시오.

### 조건
    1. 입력 값의 범위는 0 ~ 15 이다.

---

## 6-2번
기호 1번, 2번, 3번 세사람이 선거에 출마했다고 가정하자. 당선이 확정되려면 과반수 득표에 성공해야 한다.
예를 들어 10명이 투표를 했는데 결과가 2,2,2,2,2,3,3,3,1,1이 나왔다면 2번이 다수 득표자이지만 당선자는 없다.
과반수가 아니기 때문이다. 8명의 후보(1 ~ 8번)가 출마했을 때 10명의 투표 결과를 입력 받아서
당선된 후보의 번호나 당선인의 유무를 출력하는 프로그램을 작성하시오.

---

# 7장 포인터

## 7-1번
a, b를 더해 * p에 저장하는 add()함수를 작성한 후에 main에서 이 함수를 호출하여
결과를 출력하는 프로그램을 작성하시오.

### 조건
    1. 덧셈의 결과는 main()에서 result 변수 값을 출력한다.

---

## 7-2번
a, b, c가 있을 때 순환 스왑(Cyclic Swap)은 a를 b로, b를 c로, c를 a로 옮기는 스왑을 말한다.
    아래 cyclic_swap()함수를 호출하여 main()에서 a, b, c 값을 출력하시오.

---

## 7-3번
n factorial을 계산하는 재귀 함수를 작성하시오. 

### 조건
    1. 재귀 함수를 호출하여 연산을 완료한 후 main()에서 * p가 가리키는 값을 출력하면 그것이 n factorial 값이다.

---

# 8장 포인터와 배열의 관계

## 8-1번
main()에서 int타입의 num, * p, ** q를 선언하고 아래와 같은 두가지 방식으로 출력하시오.

### 조건
    1. p를 사용하여 num에 5를 저장하고 q를 사용하여 num에 저장된 데이터를 출력한다.
    2. q를 사용하여 num에 10을 저장하고 p를 사용하여 num에 저장된 데이터를 출력한다.
    3. main( )내부에서 5를 입력 후 출력, 10을 입력 후 출력하는 순서대로 진행한다.

---

## 8-2번
아래의 main()함수가 정상적으로 동작할 수 있게 배열의 평균을 구하도록 선언된 두 함수를 작성하시오. 

### 조건
    1. 첫번째 함수는 배열 기호([ ])를 사용하고 두번째 함수는 포인터 산술 연산을 사용한다.
    2. main()는 수정할 수 없다.

---

## 8-3번
음의 정수(음수)가 입력될 때까지 입력받은 양의 정수(양수)를 순서대로 a배열에 저장하고
아래 함수를 호출하여 입력받은 순서와 반대로 b배열에 저장하시오. 또한, 저장된 b배열의 요소는
main()에서 순서대로 출력하시오.

### 조건
    1. 배열에 저장되는 데이터에 음수는 제외한다.
    2. 입력되는 데이터를 띄어쓰기로 구분한다.
    3. 입력되는 정수는 반드시 10개라고 가정한다.

---

## 8-4번
입력 문장을 배열에 저장하고 해당 문자에 모음(a,e,i,o,u)이 몇 번 나오는지 출력하는 프로그램을 작성하시오. 

### 조건
    1. 문장은 알파벳 소문자와 숫자만으로 이루어져 있다고 가정한다.
    2. 아래의 함수를 호출해야 하고 함수 내부에서 포인터 산술 연산을 사용한다.

---

## 8-5번
main()함수에 int타입의 arr1[5], arr2[5]라는 배열을 선언하고 사용자가 각 배열에 임의의 값을 입력하도록
main()의 내부에서 구현하시오.

### 조건
    1. print_array( )함수를 아래와 같이 작성하여 데이터가 저장된 2개의 배열을 출력한다.
    2. 이후에 두 배열을 데이터를 교환하여 저장하는 swap_array()함수를 호출하여 값을 서로 바꾸도록 하고,
       변경되었는지 확인할 수 있도록 main()에서 print_array()함수를 호출하여 아래와 같이 확인한다.
    3. main() 제외한 아래의 두 함수 모두 포인터 기호( * )만 사용하여 작성한다.
    4. 배열의 요소 수와 입력 데이터는 5개로 한다.

---

## 8-6번
음수를 입력 받기 이전까지의 데이터를 배열에 저장하고 아래 함수를 호출하여
입력받은 정수 중에서 최솟값과 최댓값을 출력하시오.

### 조건
    1. 아래 함수는 입력 값이 모두 저장되어 있는 arr 배열을 넘겨받아서 최솟값을 * min에, 최대값을 * max에 저장한다.
    2. main()에서 최솟값과 최대값을 출력한다.
    3. 입력할 정수의 개수를 먼저 입력 받고 해당 개수만큼 정수를 입력받아서 최대/최소값을 출력한다.

---

## 8-7번
행과 열의 개수를 입력 받아서 동적으로 배열을 생성한 후에 배열 데이터를 입력 받고,
해당 데이터를 제곱한 값을 출력하는 프로그램을 작성하시오.

---

# 9장 문자열 다루기

## 9-1번
문자열을 교환하는 프로그램을 작성하시오.

### 조건
    1. 함수를 사용하여 두 개의 문자배열에 저장된 문자열을 서로 바꾸는 프로그램을 작성한다.
        문자열
        ▹char str1[20] = "apple";
        ▹char str2[20] = "banana";
    2. 함수는 문자열을 바꾸는 작업만 수행하며 문자열의 출력은 main 함수에서 수행한다.
    3. swap_string(str1, str2); //함수를 호출하여 문자열을 교환한다.

---

## 9-2번
두 개의 문자 배열에 저장된 문자열 중에서 길이가 긴 문자열을 출력하는 프로그램을 작성하시오.

### 조건
    1. 배열의 선언과 초기화는 아래와 같다.
        ▹char str1[20] = "Long time no see.";
        ▹char str2[20] = "What’s up?";

---

## 9-3번
키보드로부터 성과 이름을 따로 입력 받아서 하나의 문자열로 붙여서 출력하는 프로그램을 작성하시오.

### 조건
    1. 배열은 다음과 같이 세 개를 선언하여 작성한다.
        ▹char last_name[20]; //성을 입력할 배열
        ▹char first_name[20]; //이름을 입력할 배열
        ▹char full_name[20]; //성과 이름을 모두 저장할 배열

---

## 9-4번
strcmp 함수와 동일한 역할을 하는 my_strcmp 함수를 작성하시오. 

### 조건
    1. main()에서 입력 받은 두 개의 문자열을 my_strcmp함수를 통하여 비교하고 출력한다.
    2. 코드 작성시 strcmp함수는 직접 사용하지 않고 동일한 기능을 하는 my_strcmp 함수를 구현한다.
    3. 프로그램은 quit가 입력될 때까지 실행을 반복한다.

---

## 9-5번
strcat 함수와 동일한 역할을 수행하는 my_strcat 함수를 작성하시오.

### 조건
    1. dest가 가리키는 공간은 src 문자열을 이어붙이기에 충분하다고 가정한다.
    2. main()에서 두 개의 문자열을 입력받은 후, 이 함수를 호출하여 결과를 출력한다.
    3. 코드 작성시 strcat함수는 직접 사용하지 않고 동일한 기능을 하는 my_strcat 함수를 구현한다.
    4. 프로그램은 quit가 입력될 때까지 실행을 반복한다.
    5. dest 문자열에 quit가 입력될 때까지 실행을 반복한다.
    6. main()에서 루프를 실행하며 if(strcmp(dest, "quit")==0) break;에서 루프를 빠져나온다.

---

## 9-6번
strcpy 함수와 동일한 동작을 수행하는 my_strcpy 함수를 구현하시오.

### 조건
    1. main()에서 gets로 입력을 받고 문자열 src를 채운 뒤 my_strcpy 함수를 호출하여 복사하고
       main으로 되돌아와서 puts로 dest배열을 출력한다.
    2. gets 함수와 puts 함수의 사용 방법을 스스로 익혀서 사용한다.
    3. dest 배열의 크기는 src 배열과 동일한 크기라고 가정한다.
    4. index는 현재 복사해야 할 문자의 인덱스를 의미한다.
    5. 따라서 src[index]가 ‘\0’이면 문자열의 끝이므로 그것을 복사한 후 빠져나와야 하고,
       그렇지 않다면 복사 후에 계속 index를 증가시켜서 재귀호출을 수행한다.

---

# 10장 구조체

## 10-1번
3명의 이름, 나이, 성별을 키보드로 입력 받고 표시하는 프로그램을 작성하시오.

### 조건
    1. 데이터는 구조체로 저장하고 데이터 입력받는 함수와 출력하는 함수를 각각 구현한다.

---

## 10-2번
앞의 연습문제 1을 활용하여 입력한 나이로 오름차순 정렬하시오.

### 조건
    1. 0미만 120초과되는 숫자를 입력할 경우에는 오류 메시지를 출력하여 다시 입력 받도록 한다.

---

## 10-3번
앞의 연습문제 1을 활용하여 입력한 이름을 비교하여 아스키코드 값에 따라 오름차순으로 출력하시오.

### 조건
    1. 입력되는 모든 이름은 다르다고 가정한다.
    2. 아스키 코드 값을 기준으로 오름차순으로 정렬한다.

---

## 10-4번
앞의 연습문제2,3을 활용하여 3명의 정보를 입력한 후
    사용자에게 나이와 이름 중 원하는 기준을 선택하게 한 후 오름차순 정렬하시오.

---

# 11장 전처리기와 분할 컴파일

## 11-1번
두 개의 숫자와 사칙연산 기호를 입력하면 실행하여 결과를 출력하는 코드를 작성하시오.

### 조건
    1. 입력과 출력을 담당하는 코드는 iofunc.c에 작성한다.
    2. 입출력함수는 각각 myInput(), myOutput() 이다.
    3. 사칙연산에 대한 코드는 myfunc.c에 작성한다.
    4. 필요한 각 함수에 대한 선언은 myheader.h로 구성한다.
    5. main()에서 사칙연산 함수를 호출해서 결과를 확인하는 main.c를 작성한다.
    6. 연산 결과는 소수점 두 번째 자리까지 표기한다.

---

## 11-2번
국어 영어 수학 점수를 입력 받아서 평균과 총점을 계산하고 학점을 표기하는 프로그램을 작성하시오.

### 조건
    1. 프로그램은 score.h score.c main.c로 구성한다.
    2. 입력과 출력(평균, 총점)은 실수로 처리한다.
    3. 출력은 소수점 두 번째 자리까지 표기한다.

### -학점
    ▹A : 100 ~ 90
    ▹B : ~ 80
    ▹C : ~ 70
    ▹D : ~ 60
    ▹F : 나머지

---

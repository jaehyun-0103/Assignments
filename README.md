# 2학년 2학기 과제
---

# 목차
1. 데이터베이스

    1.1. [sql](#sql)
    
2. 자바
    
    2.1. [실습 과제1~5](#실습-과제a)
    
    2.2. [실습 과제6~10](#실습-과제b)
    
    2.3. [실습 과제11~15](#실습-과제c)

    2.4. [실습 과제16~19](#실습-과제d)
    
3. 파이썬프로그래밍

    3.1. [단순선형회귀](#단순선형회귀)

    3.2. [다중선형회귀1](#다중선형회귀1)

    3.3. [다중선형회귀2](#다중선형회귀2)

    3.4. [다중선형회귀3](#다중선형회귀3)

    3.5. [다중선형회귀4](#다중선형회귀4)

    3.6. [KNN](#KNN)
    
---

# 1. 데이터베이스

# sql

요구사항에 맞게 실습 문제를 작성하시오.

## 요구사항

1. 주문(order) 테이블에서 주문제품별 수량의 합계를 검색해보시오.

2. 고객 테이블에서 적립금이 1,000원 이상인 등급에 대해 등급별 고객 수와 적립금 평균을 검색해보시오.

3. 제품 테이블에서 제조업체별로 제조한 제품의 개수와 제품 중 가장 비싼 단가를 검색하되, 제품의 개수는 '제품수'로 출력해 가장 비싼 단가를 '최고가'라고 출력해보시오.

4. 주문 테이블에서 나이가 30세 이상이 고객이 주문한 제품의 주문제품을 검색해 보시오.

5. 주문 테이블에서 '달콤비스킷'을 생산한 제조업체가 만든 제품들의 제품명과 단가를 검색해 보시오. 

6. banana 고객이 주문한 제품의 제품명과 제조업체를 검색해 보시오. 

7. 대한식품이 제조한 모든 제품의 단가보다 비싼 제품의 제품명, 단가, 제조업체를 검색해 보시오.

8. 고객 테이블에 고객 아이디 strawberry, 고객 이름은 '최유경', 나이는 30세, 등급은 vip 직업은 '공무원', 적립금은 100원의 새 레코드를 입력해 보시오.

9. 조금 전 신규 레코드에서 등급만 vip -> gold로 변경해 보시오.

10. 조금 전 신규 레코드를 테이블에서 삭제해 보시오.

---
---

# 2. 자바

# 실습 과제a

## 1번
키보드로 0부터 999 사이의 정수를 입력받아 각 자릿수를 더한 결과를 출력하는 프로그램을 작성하라.

### 설명

1. 프로그램의 첫 행에 import java.util.Scanner;를 추가해 Scanner 클래스의 경로 이름을 컴파일러에 알려 키보드로 데이터를 입력할 수 있도록 한다.
2. 프로그램의 클래스와 메서드를 만들어준다.
3. 실행문 부분에서는 먼저 각 자릿수의 합을 저장할 변수 sum을 선언하고 0으로 초기화해준다.
4. 키보드로 데이터를 입력받기 위해 System.in 객체와 연결된 Scanner 객체를 생성한다.
5. 숫자를 입력해달라는 문구를 출력해주고 num 변수에 키보드로 입력받은 데이터를 저장한다.
6. 각 자릿수의 합을 구하는 알고리즘은 입력한 수를 10으로 나눈 나머지, 즉, 변수 num의 일의 자리 숫자를 sum에 더하고, 10으로 나눈 몫을 다시 num에 저장한다.
7. 이를 num이 0이 될 때까지 반복한다.
8. 결과값을 출력해준다.

## 2번
각 변의 길이 합이 20 이하이며 각 변의 길이가 정수인 직각 삼각형의 모든 변을 구하라.

### 설명

1. 실행문 부분의 첫 줄에서 각 변을 나타내는 변수 a, b, c를 선언한다.
2. for문을 3번 중첩해 조건에 맞는 각 변의 길이를 구한다.
3. 각 변이 정수의 길이이므로 for문의 초기화식에서 각각의 변수를 1로 초기화한다.
4. for문의 조건식에서는 삼각형의 성립 조건이 a + b > c이므로 각 변이 10보다 작은 정수가 되도록 조건을 만든다.
5. for문 내부에는 찾고자 하는 삼각형이 직각 삼각형이므로 피타고라스 정리를 만족하고 각 변의 길이 합이 20 이하인 a, b, c를 찾기 위해 두 조건을 if문의 조건식으로 적는다.
6. 두 조건이 모두 참이여야 하므로 논리 연산자 &&을 사용한다.
7. 모든 조건을 만족하는 a, b, c를 출력한다.

## 3번
3DiceTest
주사위를 나타내는 Dice 클래스를 작성하고, 다음 코드를 사용해 테스트하라.
- Dice 클래스에는 6개의 면이라는 속성과 굴리기라는 동작이 있다. Math.random()이라는 메서드는 0.0이상 1.0 미만의 double 타입의 무작위 실수를 반환한다.

### 설명

1. Dice 클래스를 정의한다.
2. 6개의 면이 속성이므로 face 필드를 선언한다.
3. Dice() 생성자를 선언하고, 클래스 내부에서 자신의 멤버에 접근하기 위해 참조 변수 this를 사용한다.
4. 굴리기가 동작이므로 int가 리턴타입인 roll() 메서드를 선언한다.
5. roll() 메서드는 Math.random() 메서드를 이용해 1 ~ 6의 수를 무작위로 반환한다.
6. 이 메서드는 0.0 이상 1.0 미만의 double 타입의 무작위 실수를 반환하므로 6을 곱한 뒤 int형으로 강제형변환을 하고, 1을 더해서 반환한다.
7. 1 ~ 6의 정수를 무작위로 반환한다.
8. main()에서는 객체 변수 선언과 객체 생성을 해준다.
9. roll() 메서드를 호출해 무작위로 굴린 주사위의 눈 값을 출력한다.

## 4번
0~99 사이의 정수를 키보드에서 10개 입력받아 10단위 간격의 히스토그램을 출력하는 프로그램을 작성하라. 입력된 수가 음수이면 무시하라. 예를 들어 위쪽처럼 10개의 정수가 입력되었을 때는 아래쪽처럼 히스토그램을 출력한다.

### 설명

1. 입력한 숫자 10개를 저장하기 위한 int형 배열을 선언 및 생성한다.
2. 10개의 각 구간에 해당하는 ‘ * ’ 출력을 위해 String 배열도 선언 및 초기화한다.
3. 10번 입력을 확인하기 위한 cnt 변수도 선언 및 0으로 초기화한다.
4. while문을 통해 10번 동안 Scanner로 입력 받는다.
5. if문으로 구간을 나눠 음수는 자동으로 무시하도록 한다.
6. 구간 확인을 for문으로 10번 반복하면서 입력한 수가 어느 구간에 해당하는지 확인한다.
7. 만약 해당하는 구간이라면 그 인덱스의 histo String 배열에 +연산자를 이용해 ‘ * ’을 붙인다.
8. for문을 통해 10번 반복하면서 histo String 배열에 있는 문자열을 출력한다.

## 5번
다음과 같은 지뢰 찾기 게임 프로그램을 작성하시오. 실행 결과는 '5 10 0.3'을 명령행 인수로 사용한 예이다.
- 프로그램은 3개의 명령행 인수(m, n, p)를 받아들이고, m * n 크기의 배열을 생성해 지뢰를 숨긴다.
- 숨긴 지뢰가 있는 원소는 * 로 표시하고 없는 원소는 -로 표시한다. 원소에 지뢰가 있을 확률은 세 번째 명령행 인수인 p이다.
- 지뢰 숨김 여부를 나타내는 2차원 배열을 출력하고, 지뢰를 숨기지 않은 원소를 -대신에 이웃한 지뢰 개수로 채운 2차원 배열도 함께 출력한다.
- 이웃한 지뢰는 상하좌우 및 대각선 원소에 숨긴 지뢰를 의미한다.
- 지뢰 숨긴 지역을 30%로 설정하려면, 난수 발생 정적 함수 Math.random() 값이 0.3보다 적은 원소에 지뢰를 숨긴다.

### 설명

1. 행과 열 그리고 지뢰가 있을 확률 이렇게 총 3가지를 입력받아 각각 변수 M, N, P에 대입한다.
2. 입력받은 행과 열의 크기만한 string 2차원 배열을 선언한다.
3. 2차원 배열에 이중 for문을 이용해 "-"를 대입한다.
4. 지뢰는 while문을 사용해 무작위로 넣을 것인데 이때 입력받은 세 수의 곱을 정수로 형변환한 그 값만큼 반복하도록 하여 지뢰가 있을 확률보다 적은 원소에 지뢰를 숨길 수 있도록 한다.
5. 무작위로 지뢰를 숨길 때에는 난수 발생 정적 함수 Math.random()을 사용한다.
6. 이 함수는 저번과 같이 사용하는데 다른점은 이번에는 난수의 인덱스에 넣어야 하므로 1을 더하지 않는다.
7. 이렇게 무작위로 고른 2차원 배열의 원소를 " * "로 바꾼다.
8. 지뢰 숨김 여부를 나타내는 2차원 배열을 for문을 사용해 출력한다.
9. 이웃한 지뢰 개수로 채운 2차원 배열도 출력하기 위해 이중 for문을 통해 가리키는 원소의 상하좌우대각선을 확인하는 알고리즘을 짠다.
10. 이 알고리즘에서는 switch문을 이용해 만약 이차원배열의 원소가 " * "라면 " * "을 출력하고, 아니라면 상하좌우대각선에 " * "인 원소가 몇개가 있는지 카운트하고 그 값을 출력한다.

---

# 실습 과제b

## 6번
다음 표와 실행 결과를 참고해 자식 클래스인 Circle과 ColoredCircle을 작성하시오. 그리고 Circle과 ColoredCircle 객체의 show() 메서드를 호출하는 테스트 프로그램도 작성하시오.
클래스 : Circle, ColoredCircle
필드 : int radius, String color
메서드 : void show(), void show()
생성자 : Circle(int radius), ColoredCircle(int radius, String color)

### 설명

1. 조건을 위해 Circle 클래스와 ColoredCircle 클래스를 선언한다.
2. ColoredCircle 클래스는 자식 클래스이므로 extends Circle을 추가한다.
3. 각각 클래스에 조건에서 알려준 필드와 메서드를 선언한다.
4. Circle 클래스에서 생성자를 선언하고 this를 통해 필드를 초기화한다.
5. 메서드 show()에서 원의 반지름을 출력한다.
6. ColoredCircle 클래스에서도 생성자를 선언하고 this를 통해 필드를 초기화한다.
7. 부모 클래스의 생성자를 호출하기 위해 super()을 사용한다.
8. 메서드 show()에서 원의 반지름과 원의 색깔을 출력한다.
9. 여기서 자식 클래스의 show()는 오버라이딩 되었다.
10. 메인 함수에서 두 클래스의 객체를 생성 후, 객체의 주소를 참조변수에 저장한다.
11. 메서드 show()를 호출한다.

## 7번
운송 수단과 운송 수단의 하나인 자동차를 다음과 같이 모델링하려고 한다. 각 클래스의 show() 메서드는 필드 값을 출력한다. 두 클래스를 작성하고 아래 테스트 프로그램 OverrideTest를 실행해서 오버 라이딩된 메서드와 다형성 관계를 살펴보시오.

### 모델링

|   | Vehicle | Car |
|:----------:|:----------:|:----------:|
| 필드 | String color;, int speed; | int displacement;, int gears;
| 메서드 | void show() | void show() |
| 생성자 | public Vehicle(String, int) | public Car(String, int, int, int) |

### 설명

1. Car 클래스는 extends로 Vehicle 클래스를 상속받는다.
2. 문제에서 요구하는대로 각 클래스에 필드, 메서드, 생성자를 선언 또는 정의한다.
3. 여기서 자식 클래스의 생성자는 super()를 사용하여 부모 클래스로부터 상속받은 필드 color와 speed를 참조한다.
4. 부모 클래스의 show() 메서드를 자식 클래스에서 재정의하여 오버라이딩한다.
5. main 함수를 보면 하나의 객체가 여러 가지 타입을 가지는 다형성을 사용하여 객체를 선언했다.
6. 오버라이딩을 막기 위해 부모 클래스와 자식 클래스에 있는 필드와 메서드를 정적(static)으로 바꿔 각 클래스의 메서드가 다른 역할을 수행하도록 한다.

## 8번
Talkable 인터페이스는 talk() 메서드 하나만 포함한다. Korean 클래스와 American 클래스는 Talkable 구현 클래스이다. 다음 테스트 프로그램과 실행 결과를 참고해 Talkable 인터페이스와 Korean 클래스, American 클래스를 구현하고, 테스트 프로그램도 완성하라.

### 설명

1. interface 키워드로 Talkable 인터페이스를 정의하고 내부에 추상 메서드 talk()를 선언한다.
2. Talkable 구현 클래스 Korean과 American을 정의한다.
3. 추상 메서드를 자식 클래스인 Korean과 American에서 오버라이딩하여 사용한다.
4. 각각 알맞은 문구를 출력하도록 정의한다.
5. 업캐스팅하여 객체를 선언해주는데 이때 speak() 메서드를 사용한다.

## 9번
다음 프로그램과 실행 결과에 적합한 Student 클래스를 작성하라

### 설명

1. toString() 메서드는 필수 패키지인 Object 클래스가 제공하는 메서드이므로 import 없이 사용할 수 있다.
2. 원래 toString() 메서드는 객체의 문자 정보를 반환한다.
3. Student 클래스에서 toString() 메서드를 오버라이딩하여 사용한다.
4. 오버라이딩한 메서드는 매개변수 있는 생성자를 통해 전달받은 이름을 출력하는 기능을 갖도록 한다.

## 10번
다음 프로그램과 실행 결과를 보고 showTokens() 메서드를 완성하라.

### 설명

1. 예외를 처리하기 위해 try-catch문을 사용한다.
2. try { }에서 예외가 발생할 수 있는 실행문 부분에 showTokens() 메서드를 호출하는 문장을 작성하여 showToken() 메서드를 호출한다.
3. showToken() 메서드는 문자열과 구분자를 매개변수로 한다.
4. 일반 예외 중 하나인 NoSuchElementException은 요구한 원소가 없을 때 발생한다.
5. catch()의 예외클래스로 NoSuchElementException을 적고 참조변수로 e를 선언한다.
6. 예외가 발생하면 예외 객체를 catch 블록의 참조 변수로 전달한다.
7. catch문이 실행되어 “끝”을 출력한다.
8. 메인 클래스에서 showTokens() 메서드는 s를 문자열, p를 구분자로 전달받는다.
9. StringTokenizer 클래스는 하나의 문자열을 여러 개의 토큰으로 분리하는 클래스이고, 이때 p는 구분자이다.
10. Token이라는 참조변수를 선언해주고, 무한반복문에 있는 동안 nextToken() 메서드를 호출해 객체에서 다음 토큰을 출력한다.

---

# 실습 과제c

## 11번
다음과 같은 테스트 프로그램의 일부와 실행 결과가 있다. Wordable 타입의 배열 원소를 람다식으로 구성한 테스트 프로그램을 작성하라.

### 설명

1. Wordable은 추상 메서드가 1개만 있으므로 함수형 인터페이스이다.
2. 복잡한 식을 단순하게 표현하기 위해 람다 표현식을 이용하여 간략하게 구현한다.
3. Wordable 타입의 배열 원소를 () -> System.out.println(“”); 형식의 람다식으로 구현하고 각 원소가 적절한 출력을 하도록 한다.
4. for each 구조로 반복하여 배열 원소에 접근한다.

## 12번
다음은 주어진 숫자에 따라 1이면 숫자와 ‘apple’, 2 이상이면 숫자와 ‘apples’를 나타내는 실행 결과이다. 함수형 인터페이스 Consumer를 이용한 테스트 프로그램을 작성하라.

### 설명

1. Consumer는 매개변수를 사용하고 아무것도 반환하지 않는 인터페이스이다.
2. 이 인터페이스 내부에는 추상 메서드인 accept()가 있다.
3. 주어진 문제의 코드에서 accept() 메서드는 Integer 타입인 한 개의 매개변수 t를 전달받는다.
4. t의 값에 따라 적절한 출력을 하도록 if문으로 나누는 부분을 람다식으로 표현한다.

## 13번
ArrayList를 이용해 ‘갈매기’, ‘나비’, ‘다람쥐’, ‘라마’를 원소로 입력한 후 각 원소에서 문자열 크기가 2인 단어만 출력하는 프로그램을 작성하라.

### 설명

1. Collection 프레임워크에 있는 List 인터페이스 안에 있는 ArrayList 클래스를 사용한다.
2. ArrayList를 사용해 리스트를 생성한다.
3. add(E e) 메서드를 통해 ArrayList 리스트에 갈매기, 나비, 다람쥐, 라마 요소를 추가한다.
4. for-each문으로 리스트에 접근해 if문을 통해 글자 수가 2인 요소를 출력한다.

## 14번
Hashtable을 이용해 4개의 이름과 점수를 저장하라. 그리고 키보드로 이름을 입력하면 대응하는 점수를 알려 주는 프로그램을 작성하라.

### 설명

1. HashMap은 Map 인터페이스가 구현하는 클래스이다.
2. Map 인터페이스는 키와 값, 이렇게 쌍으로 구성된 객체를 저장하는 자료구조이다.
3. 이 코드에서는 Map 인터페이스가 제공하는 메서드 중 put(key, value)와 get(key)를 사용한다.
4. 만들어진 map 객체에 put() 메서드로 4쌍의 키와 값을 넣는다.
5. Scanner 클래스를 통해 입력받은 name을 get() 메서드를 통해 접근한다.
6. 키 값인 name에 대응하는 값 찾아 출력한다.

## 15번
4개의 문자열 (‘갈매기’, ‘나비’, ‘다람쥐’, ‘라마’)을 포함하는 리스트 객체를 스트림으로 생성한 후 크기가 2인 단어만 출력하는 프로그램을 작성하라.

### 설명

1. 4개의 문자열이 있는 리스트 객체를 생성한다.
2. stream() 메서드를 통해 리스트 객체로부터 스트림을 생성한다.
3. toList() 메서드는 Collectors 클래스가 제공하는 정적 메서드로 컬렉트 연산을 수행한다.
4. 이 메서드를 사용해 스트림을 리스트로 변환한다.
5. for-each문을 이용해 그 리스트의 원소에 하나씩 접근하면서 크기가 2인 단어를 찾아 출력한다.

---

# 실습 과제d

## 16번

Nation, nations 리스트에서 육지에 있는 나라 이름을 콤마와 공백(“, ”)으로 연결하여 수집한 후 출력하는 프로그램을 작성하라.

### 설명

1. nations 리스트를 스트림으로 바꾼다.
2. filter() 메서드로 Stream의 요소들을 필터링한다.
3. 필터링의 조건으로 getType() 메서드의 리턴 값인 해당 요소의 타입이 LAND인지 확인하고 만약 같다면 스트림에 넣는다.
4. 마지막으로 필터링한 스트림 값의 나라 이름을 리턴하는 getName() 메서드를 활용하여 육지에 있는 나라 이름을 매핑한다.
5. collet() 메서드로 구분자를 (“, ”)로 연결하여 저장한다.

## 17번
5개의 double 타입 숫자로 구성된 배열을 사용해 다음 작업을 수행하는 프로그램을 작성하라.
- 배열의 모든 원소를 D:\Temp\double.txt 파일에 DataOutputStream을 사용해 저장한다.
- 저장된 숫자를 DataInputStream을 사용해 읽은 후 화면에 출력한다.

### 설명

1. DataInputStream과 DataOutputStream은 직접 키보드에서 데이터를 입력받거나 콘솔 뷰에 데이터를 출력하기에는 부적합하므로
2. FileInputStream이나 FileOutputStream과 연결해서 파이프라인을 구성해 사용한다.
3. 이때 사용하는 FileInputStream과 FileOutputStream은 스트림 객체를 생성할 때 FileNotFouneException 예외 가능성이 있기 때문에 반드시 예외 처리가 필요하다.
4. try-catch문으로 FileNotFouneException을 포함한 IOException 클래스를 예외처리한다.
5. 해당 경로에 있는 파일에 5개의 double 타입 숫자를 write() 메소드로 출력 해주고, flush()로 버퍼를 비워준다.
6. 해당 경로에 있는 파일을 read() 메소드를 5번 실행하여 5개의 double 타입 숫자를 읽고 출력해준다.

## 18번
임의의 시간을 대기한 후 속담을 단어 단위로 출력하는 2개의 스레드를 테스트하는 프로그램을 작성하라. 예를 들어 속담이 ‘Time is money’라면 2개의 스레드를 각각 오른쪽처럼 출력한다.

### 설명

1. 속담 ‘Time is money’를 문자열 prov에 저장하고, 저장한 문자열의 공백을 기준으로 split 해서 provArray 배열에 단어 단위로 저장한다.
2. 람다식을 이용한 익명 Thread 객체화를 통해 스레드 2개를 생성한다.
3. 2개의 스레드 각각 for-each 문으로 단어를 저장한 배열에 접근하여 출력한다.
4. 2개의 스레드는 500ms만큼 대기를 하고 출력한다.

## 19번
오른쪽처럼 나타나도록 05에서 작성한 프로그램을 다음 두 가지 방식으로 동기화하는 프로그램을 작성하라.
① 속담을 출력하는 메서드를 동기화한다.
② run() 메서드 내부에서 코드 영역을 동기화한다.

### 설명

1. synchronized 키워드로 동기화 메서드를 만들어 임계영역을 동기화한다.
2. 동기화 메서드는 띄어쓰기를 구분자로 속담을 split 해서 출력하는 기능이 있다.
3. 스레드 생성은 Thread 클래스의 run() 메소드 오버라이딩하는 방법을 사용한다.
4. 속담 1, 2에 대한 정보는 매개변수가 있는 생성자를 만들고 여기에 객체 생성을 통해 매개변수로 전달한다.

---
---

# 3. 파이썬프로그래밍

# 단순선형회귀

1. 파이썬의 내장 모듈과 라이브러리를 사용하지 않고 구현하기
2. 주어진 데이터를 사용하여 회귀 모델을 학습하고, 회귀 계수를 구하기
3. 모델의 성능을 평가하기

---

# 다중선형회귀1

1. 파이썬의 내장 모듈을 사용하지 않고 넘파이 라이브러리를 사용하여 구현하기
2. 주어진 데이터를 사용하여 회귀 모델을 학습하고, 회귀 계수를 구하기
3. 모델의 성능을 평가하기

---

# 다중선형회귀2

1. 파이썬의 linear_model 모듈과 넘파이 및 판다스 라이브러리를 사용하여 구현하기
2. 주어진 데이터를 사용하여 회귀 모델을 학습하기
3. 모델의 성능을 평가하기

---

# 다중선형회귀3

1. 파이썬의 내장 모듈을 사용하지 않고 넘파이 및 판다스 라이브러리를 사용하여 구현하기
2. 주어진 데이터를 사용하여 회귀 모델을 학습하고, 회귀 계수를 구하기
3. 데이터 병합 과정을 거치기
4. 모델의 성능을 평가하기

---

# 다중선형회귀4

1. 파이썬의 linear_model 모듈과 넘파이 및 판다스 라이브러리를 사용하여 구현하기
2. 주어진 데이터를 사용하여 회귀 모델을 학습하기
3. 데이터 병합 과정을 거치기
4. 모델의 성능을 평가하기

---

# KNN

k 인접

---

# 3학년 2학기 과제
---

# 목차
1. 알고리즘

    1.1. [탈출 문제](#탈출-문제)
    
2. 웹서비스프로그래밍

    2.1. [영상 리뷰 사이트](#영상-리뷰-사이트)

3. 컴퓨터네트워크

    3.1. [패킷 캡처](#패킷-캡처)

---

# 1. 알고리즘

# 탈출 문제

1. 네트워크플로 문제로 변환하여 풀고 다시 탈출문제의 해답으로 변환

2. 입력값 : 입력값 n, 탈출을 위한 정점들 r (좌표로 주어짐. n^2 보다 작아야 함)

3. nxn 그리드 위에 좌측 하단의 점을 (1,1) 이라고 하고, 우측 상단의 좌표가 (n,n) 이 된다고 함

4. 각 정점마다 탈출 경로를 표시해줄 것 (그래픽으로 구현하면 가산점)

## 접근 방법
1. 네트워크 플로우 문제로 변환

    1-1. 인접 행렬에 출발지 노드 S와 목적지 노드 T를 생성
   
    1-2. 각각을 탈출을 위한 정점들과 nxn 그리드의 테두리 정점들에 연결

2. 생성된 인접 행렬을 통해 Ford-Fulkerson 알고리즘을 활용하여 최대 유량을 구함
   
    2-1. 간선의 용량은 전부 1
   
    2-2. 방문한 노드는 제외
   
3. '#'과 '@' 기호를 통해 그래픽으로 구현
 
## 결과
### 탈출 가능
<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/981a87d1-c861-4e9a-b8a4-0577905c43a4" width="90%" height=90%>

<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/fb9bff1e-5b85-4548-8fd0-63f6e3c75cb2" width="90%" height=90%>

### 탈출 불가능
<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/7ab4ebca-a4f7-4b7c-a915-8f6caf8ab70c" width="90%" height=90%>

<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/d80b0419-a82a-4cf1-aef3-2df96e71df43" width="90%" height=90%>

---
---

# 2. 웹서비스프로그래밍

# 영상 리뷰 사이트

1. 하나의 주제를 정해 시나리오를 정하고 정해진 시나리오에서 웹서버 프로젝트를 적용

2. 데이터베이스는 H2를 사용하며, 테이블은 최소 3개 이상 사용하여 시나리오를 표현

3. MVC 모델을 이용한 서버 프로그래밍 구현

## 역할 분담
|이름|역할|
|---|---|
|문가을|ERD 작성, 감상평 목록 구현, PPT 제작|
|유호선|MVC 패턴 설계, 영화 목록 구현, 검색창 구현, 발표|
|원채윤|시나리오 작성, 영화 내용 구현, 감상평 작성 구현|
|조재현|ERD 설계, 시나리오 설계, 회원가입 구현, 로그인 구현, 마이페이지 구현|

## 초기 설계
1. 사전에 작성된 영화 정보를 통해 영화 내용을 확인할 수 있고, 감상평도 남길 수 있는 사이트 구축

2. 검색창을 통한 영화 정보 확인 가능

3. 감상평은 회원만 작성 가능

## 시나리오
<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/f9e47388-a42c-46a0-901a-af6061d3b53" width="85%" height=85%>

## ERD
<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/aee0f03f-afe2-438c-9830-b7993426e059" width="100%" height=100%>

## MVC
<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/9774d8f8-2cc5-4950-b9f3-f47ccf6a2e13" width="80%" height=80%>

## 뷰
- register 페이지 : 회원가입 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/e9143b2c-f774-46b8-ab77-67884df7d8d0" width="35%" height=35%>

- login 페이지 : 로그인 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/e59c63d0-f369-4170-b717-f21bd970282f" width="35%" height=35%>

- moviesList 페이지 : 영화 목록 확인 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/4b538e3c-1eeb-44bc-b48e-87b30e2d5d91" width="80%" height=80%>

- logout 페이지 : 로그아웃 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/71f5ddc6-1b9a-40cd-b519-b3ca9a403a85" width="20%" height=20%>

- profile 페이지 : 회원 정보 수정 및 작성한 감상평 목록 확인 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/b364e29a-caf1-4c41-b57d-23cbbf131984" width="45%" height=45%>

- searchResult 페이지 : 검색 결과 확인 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/0fa75e4c-57e2-4e53-a3b4-04a26b4d924e" width="85%" height=85%>

- search 페이지 : 영화 상세정보 확인 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/990badba-bdd5-4a1b-be1b-0d69a6dc6a1f" width="85%" height=85%>

- writeReview 페이지 : 감상평 작성 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/a7a98473-e912-461b-aba3-2a36311be6bc" width="85%" height=85%>

- reviewList 페이지 : 감상평 목록 확인 가능

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/aa90e24d-f421-4bc0-b965-9594e40928e0" width="85%" height=85%>

---
---

# 3. 컴퓨터네트워크

# 패킷 캡처

1. 네트워크 상에서 전달되는 패켓을 캡처하고 패켓을 분석(송신과 수신을 모두 캡쳐)

2. 캡처링 데이터 : Application 헤더, TCP/UDP 헤더, IP 헤더
    - Application header : TCP 상에서 동작하는 응용서비스, UDP 상에서 동작하는 응용서비스

    - TCP header:  연결설정, 데이터 전송, 연결해제 과정 Source Port, Destination Port, Sequence No, Acknowledgement No 등

    - UDP header : Source Port, Destination Port 등

    - IP header : Source IP Address, Destination IP Address 등

## 역할 분담
|이름|역할|
|---|---|
|송인우|FTP|
|조형준|HTTP|
|조재현|DNS|
|유호선|DHCP|

## 개발 목표
1. 여러 라이브러리를 사용하여 네트워크 상에서 전달되는 패킷을 캡처하고 분석하는 프로그램을 개발

2. 응용계층에서 수행되는 프로토콜의 패킷을 캡처하여 각 프로토콜의 동작 특징을 분석

## 설계 환경
- 윈도우즈 기반의 Visual Studio

- C언어 사용

- WinPcap 라이브러리와 Winsock2 헤더 사용
 
## 설계 내용
1. 메인창

 - 사용자가 분석할 프로토콜을 선택할 수 있는 메뉴를 메인창에 출력

2. 프로토콜 분석

 - 사용자가 메뉴창에서 프로토콜을 선택하면, 해당 프로토콜에 대한 패킷 헤더 정보를 분석

 - 선택한 프로토콜의 패킷 헤더 정보를 캡처하고 출력

 - 지원하는 프로토콜 : FTP, HTTP, DNS, DHCP

 - 헤더 정보 : Application header, TCP header 또는 UDP header, IP header

3. 프로그램 구조

 - 각 프로토콜의 헤더 정보를 분석하는 함수를 모듈화하여 구현

 - 각 함수는 사용자가 선택한 프로토콜에 대한 패킷 헤더 정보를 출력

## 기대효과
1. 다양한 응용 프로토콜과 프로그램의 동작을 캡처하고 분석하여 네트워크 동작을 효과적으로 이해 가능

2. TCP header와 UDP header의 차이점과 그에 따른 여러 응용 프로토콜 사용을 확인하고 이해 가능

3. 송수신되는 패킷 분석을 통해 네트워크 동작에 대한 심층적인 이해 가능

4. 패킷이 어떻게 구성되고 교환되는지 이해함으로써 네트워크의 작동 원리를 파악 가능

## 결과

<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/f1a6c4ed-a567-43d8-8d81-c8ec2f098f20" width="60%" height=60%>

<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/c8b6cfa1-0344-4fe5-bb9d-7a5cedd3c1a2" width="60%" height=60%>

---

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

1. 설계 내용
네트워크플로 문제로 변환하여 풀고 다시 탈출문제의 해답으로 변환하는 과정. 입력값 n, 탈출을 위한 정점들 r개(좌표로 주어짐. n^2 보다 작아야 함). 
nxn 그리드 위에 좌측 하단의 점을 (1,1) 이라고 하고 우측 상단의 좌표가 (n,n) 이 된다고 하고 각 정점마다 탈출 경로를 표시해줄 것. (그래픽으로 구현하면 가점 1점)

1. 개요
탈출 문제는 nxn 크기의 그리드에서 탈출 가능 여부를 판단하는 프로그램이다. n 값을 입력 받고, 탈출을 위한 정점 개수 r을 입력받는다. 그리고 r개의 정점을 입력받는데, 이때 좌측 하단의 점을 (1, 1)이라고 하고 우측 상단의 좌표가 (n, n)이 된다.
탈출 문제는 네트워크 플로우 문제로 변환하여 풀고 다시 탈출 문제의 해답으로 풀어야 한다. 이때 간선의 용량은 전부 1로 하고, 이미 방문한 노드는 재방문이 불가능하다.

1. 접근 방법
먼저 네트워크 플로우 문제로 변환하는 과정은 인접 행렬에 출발지 노드 S와 목적지 노드 T를 생성하고, 각각을 탈출을 위한 정점들과 nxn 그리드의 테두리 정점들에 연결을 하는 과정을 거쳐야 한다. 그리고 생성된 인접 행렬을 통해 Ford-Fulkerson 알고리즘을 활용하여 네트워크 플로우 문제를 푸는데, 방문한 노드는 제외한다는 점이 추가된다.
Ford-Fulkerson 알고리즘은 널리 알려져 있었기 때문에, 인접 행렬을 생성하는 것을 중점적으로 생각했다. 인접 행렬 정보만 잘 저장할 수 있다면, 이후엔 몇 가지 제약을 더 추가하여 최대 유량을 구하면 되는 문제이기 때문이다.
 
1. 결과
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/994c87b3-f0c2-467a-8dc1-86fedc8b9f55.jpg" width="80%" height=80%>
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/ca566bd1-2cb4-46a3-b207-f6518527b2cd.jpg" width="80%" height=80%>
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/d48c8a54-b85c-446f-bb6f-daeb16bdc709.jpg" width="80%" height=80%>
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/42733c8e-5ee0-4930-adf7-8bcbd06ffe35.jpg" width="80%" height=80%>

---
---

# 2. 웹서비스프로그래밍

# 영상 리뷰 사이트

1. 설계 내용
- 프로젝트 주제는 자유
- 프로젝트 개발 문서 및 발표자료 작성
- 개발 문서, 발표자료, 프로젝트 파일 제출
- 개발 문서, 발표자료명 및 프로젝트 압축파일명은 JSP_팀번호
- 하나의 주제를 정해 시나리오를 정하고 정해진 시나리오에서 웹서버 프로젝트를 적용
- 데이터베이스는 H2를 사용하며, 테이블은 최소 3개 이상 사용하여 시나리오를 표현
- MVC 모델을 이용한 서버 프로그래밍 구현

1. 역할 분담
- 문가을
ERD 작성, 감상평 목록 구현, PPT 제작
- 유호선
MVC 패턴 설계, 영화 목록 구현, 검색창 구현, 발표
- 원채윤
시나리오 작성, 영화 내용 구현, 감상평 작성 구현
- 조재현
ERD 설계, 시나리오 설계, 회원가입 구현, 로그인 구현, 마이페이지 구현

1. 개발 목표
 사전에 작성된 영화 정보를 통해 영화 내용을 확인할 수 있고, 감상평도 남길 수 있는 사이트 구축
- 검색창을 통한 영화 정보 확인
- 회원만 작성할 수 있는 감상평

1. 시나리오
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/d34d3a5e-f282-4584-b87c-1fdb9d968b92.jpg" width="65%" height=65%>

1. ERD
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/51d74b90-61b8-445a-8729-b9e9cd2c3377.jpg" width="80%" height=80%>

1. MVC
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/57d83d42-6be0-4db7-8312-a2f3e0467a12.jpg" width="60%" height=60%>

1. 뷰
- login
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/2c1e4f9f-2e81-45fe-aa21-ea9c2e3bbfb3.jpg" width="25%" height=25%>

- profile
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/24d97422-e002-4955-b70f-2e8c102e0bff.jpg" width="40%" height=40%>

- register
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/313305b6-fca8-4ddf-b443-0cf8ff4aa402.jpg" width="30%" height=30%>

- logout
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/5fa42705-0fe2-4787-b59f-06b8ecf3059a.jpg" width="20%" height=20%>

- moviesList
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/7240c0a7-d523-4764-aba0-9c53e92ab961.jpg" width="80%" height=80%>

- searchResult
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/91cde449-3783-4795-9cfc-3f5abee1f4c6.jpg" width="80%" height=80%>

- search
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/b7cc429d-828c-4832-9990-1ef604393959.jpg" width="80%" height=80%>

- writeReview
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/7dc25a1b-f916-463d-b687-3b0e40202364.jpg" width="80%" height=80%>

- reviewList
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/09d1519a-3e4c-436f-8d8a-fb5386d5930d.jpg" width="80%" height=80%>


---
---

# 3. 컴퓨터네트워크

# 패킷 캡처

1. 역할 분담
송인우 : FTP
조형준 : HTTP
조재현 : DNS
유호선 : DHCP

1. 설계 내용 : 네트워크 상에서 전달되는 패켓을 캡처하고 패켓을 분석(단, 송신과 수신을 모두 캡쳐할 것)
가. 환경 : 유닉스(리눅스) 또는 윈도우즈 기반의 raw socket 프로그램
나. 캡처링 데이터 : APP 헤더, TCP(UDP)헤더, IP헤더, 
다. 응용계층에서 수행되는 프로토콜 및 프로그램 : http, dns, e-mail(smtp, pop 또는 IMAP), traceroute 등
라. 세부 내용
    - Application header(TCP 상에서 동작하는 응용서비스, UDP 상에서 동작하는 응용서비스)
    - TCP header: 연결설정, 데이터 전송, 연결해제 과정 Source Port, Destination Port, Sequence No, Acknowledgement No 등
    - UDP header: Source Port, Destination Port 등
    - IP header: Source IP Address, Destination IP Address 등

1. 목표
여러 라이브러리를 사용하여 네트워크 상에서 전달되는 패킷을 캡처하고 분석하는 프로그램을 개발한다.
응용계층에서 수행되는 프로토콜의 패킷을 캡처하여 각 프로토콜의 동작 특징을 분석한다.

1. 설계 환경
윈도우즈 기반의 Visual Studio
C언어 사용
WinPcap 라이브러리와 Winsock2 헤더 사용

1. 설계 방향
응용계층에서 수행되는 프로토콜의 패킷 정보를 출력한다.
 
1. 설계 내용
메인창
 - 사용자가 분석할 프로토콜을 선택할 수 있는 메뉴를 메인창에 출력한다.
프로토콜 분석
 - 사용자가 메뉴창에서 프로토콜을 선택하면, 해당 프로토콜에 대한 패킷 헤더 정보를 분석한다.
 - 선택한 프로토콜의 패킷 헤더 정보를 캡처하고 출력한다.
 - 지원하는 프로토콜 : FTP, HTTP, DNS, DHCP
 - 헤더 정보 : Application header, TCP header 또는 UDP header, IP header
프로그램 구조
 - 각 프로토콜의 헤더 정보를 분석하는 함수를 모듈화하여 구현한다.
 - 각 함수는 사용자가 선택한 프로토콜에 대한 패킷 헤더 정보를 출력한다.

1. 기대효과
다양한 응용 프로토콜과 프로그램의 동작을 캡처하고 분석하여 네트워크 동작을 효과적으로 이해할 수 있다.
TCP header와 UDP header의 차이점과 그에 따른 여러 응용 프로토콜 사용을 확인하고 이해할 수 있다. 
송수신되는 패킷 분석을 통해 네트워크 동작에 대한 심층적인 이해를 얻을 수 있다.
패킷이 어떻게 구성되고 교환되는지 이해함으로써 네트워크의 작동 원리를 파악할 수 있다.

1. 구성
구조체
- IP 헤더, TCP/UDP 헤더, DNS와 DHCP 헤더 등
주요 패킷 처리 함수 목록
- FTP 패킷 처리 : packet_handler_ftp
- HTTP 패킷 처리: packet_handler_http
- DNS 패킷 처리: packet_handler_dns
- DHCP 패킷 처리: packet_handler_dhcp
- TCP/UDP 정보 출력: print_protocol

1. 결과
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/bb830ef4-d6d1-470e-96c9-00f704eb3232.jpg" width="60%" height=60%>
<img src = "https://github.com/jaehyun-0103/Assignments_6/assets/80446951/32dcebba-c9e4-4487-aa5a-e718d4d9e82e.jpg" width="60%" height=60%>


---

# 4학년 1학기 과제
---

# 목차
1. 프레임워크프로그래밍

    1.1. [jaehyun_di](#DI--JDBC)(DI + JDBC)
    
    1.2. [JH_batis](#MVC--MyBatis)(MVC + MyBatis)
   
    1.3. [JH_free](#AOP--Transaction)(AOP + Transaction)

---

# 1. 프레임워크프로그래밍

# DI + JDBC

## 필수 기능

    1. 전체 학생 정보 출력
    2. 개인 학생 정보 출력
    3. 개인 정보 학생 생성
    4. 개인 정보 학생 삭제
    5. 개인 정보 학생 수정
    6. 테스트 케이스 3개 작성

---

# MVC + MyBatis

## 필수 기능

    1. 전체 학생 정보 출력 (/member/list)
    2. 개인 학생 정보 출력 (/member/read?id=hansol)
    3. 학생 정보 수정 (/member/modify?id=hansol)
    4. Junit 단위 테스트 3가지
    5. 개인 정보 삭제
    6. Rest api (/member/rest/{id} 제공 - GET Method (JSON 형식)
    7. Rest api (/member/rest/ 제공 - POST Method (JSON 형식)

---

# AOP + Transaction

기간 : 2024.05.22 ~ 2024.05.28

## 필수 기능

    1. 스프링 MVC 웹 어플리케이션 프로젝트 - MyBatis 프레임워크 사용하여 CRUD 구현
    2. jUnit 테스트 프레임워크 사용(단위 테스트 4가지 적용)
    3. jsp와 CSS 사용
    4. REST API 제공
    5. Lombok - VO에 적용
    6. AOP 사례 적용
    7. 트랜잭션 시나리오 만들어 적용
    8. 발표 자료
    9. 뷰 화면 처리 완성도
    10. 서비스 완성도(컨텐츠, 기능, 테이블 개수) 테이블 2개 기본

# 모임 모집 사이트

## ERD
<img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/28364d0b-c760-4afb-98d4-2221107fcce7" width="90%" height=90%>

## 기능 설계

- 사용자 관리
    - 회원 가입 : 이름, 이메일, 비밀번호 입력
    - 로그인 : 이메일, 비밀번호 입력
    - 마이페이지 : 회원 정보 확인 및 수정, 회원 탈퇴
- 소모임 관리
    - 소모임 생성 : 모임이름, 내용, 카테고리, 지역, 장소, 주기, 정원 입력
    - 소모임 목록 : 모임 이름, 현재 인원수, 정원 확인
    - 소모임 내용 : 모임 정보, 가입/삭제/탈퇴 버튼
        - 가입 : 일반 회원
        - 삭제 : 모임 리더
        - 탈퇴 : 모임 참가자

## REST API

- members
    -  회원가입
    -  로그인
    -  마이페이지 조회
    -  회원정보 수정
    -  회원 탈퇴
- groups
    -  모임 목록 조회
    -  모임 생성
    -  모임 삭제
- memberships
    -  모임 내용 조회
    -  모임 가입
    -  모임 탈퇴

## 뷰

- 로그인 페이지

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/3d6fbe9a-c3a2-449f-92cf-8d3f9aab0627" width="90%" height=90%>

- 회원가입 페이지

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/715b6bce-afcd-4bfc-bcf5-5a379c627a26" width="90%" height=90%>

- 모임 목록 페이지

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/5db93b1b-af27-48cb-a688-5cc83ce78a78" width="90%" height=90%>

- 모임 생성 페이지

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/8395a2d4-a0ce-4060-914e-ca7896cf9ef1" width="90%" height=90%>

- 모임 정보 페이지 (참가 버튼)

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/167a67b7-bd17-4ee7-a892-410f54a0584c" width="90%" height=90%>

- 모임 정보 페이지 (탈퇴 버튼)

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/9f9b8c7f-579e-4725-9d38-87555d8d8d16" width="15%" height=90%>

- 모임 정보 페이지 (삭제 버튼)

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/6ba06606-9ba1-4d1c-9d62-e35fce29859d" width="15%" height=90%>

- 모임 정보 페이지 (초과 버튼)

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/f5217aec-0b5b-42af-8b51-29a37c4730ab" width="15%" height=90%>

- 회원정보 수정 페이지

    <img src = "https://github.com/jaehyun-0103/Assignments/assets/80446951/ce0196c7-d92f-44a9-b49c-067bb6a73cb4" width="90%" height=90%>

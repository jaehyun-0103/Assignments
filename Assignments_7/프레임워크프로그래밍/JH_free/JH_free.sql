-- Members 테이블 생성
CREATE TABLE Members_free (
    memberId INT AUTO_INCREMENT PRIMARY KEY,
    memberName VARCHAR(20) NOT NULL,
    email VARCHAR(40) NOT NULL UNIQUE,
    password VARCHAR(255) NOT NULL
);

-- Clubs 테이블 생성
CREATE TABLE Clubs_free (
    clubId INT AUTO_INCREMENT PRIMARY KEY,
    clubName VARCHAR(20) NOT NULL,
    description TEXT NOT NULL,
    category VARCHAR(20) NOT NULL,
    capacity INT NOT NULL,
    location VARCHAR(30),
    meetingDate VARCHAR(10),
    venue VARCHAR(30),
    leaderId INT
);

-- Memberships 테이블 생성
CREATE TABLE Memberships_free (
    membershipId INT AUTO_INCREMENT PRIMARY KEY,
    memberId INT,
    clubId INT,
    FOREIGN KEY (memberId) REFERENCES Members_free(memberId) ON DELETE CASCADE,
    FOREIGN KEY (clubId) REFERENCES Clubs_free(clubId) ON DELETE CASCADE
);

-- Members 테이블 샘플 데이터 생성
INSERT INTO Members_free (memberId, memberName, email, password) VALUES
(1, '김철수', 'kim@example.com', '1234'),
(2, '이영희', 'lee@example.com', '5678'),
(3, '박지영', 'park@example.com', '9012');

-- Clubs 테이블 샘플 데이터 생성
INSERT INTO Clubs_free (clubId, clubName, description, category, capacity, location, meetingDate, venue, leaderId) VALUES
(1, '요리 동아리', '요리 동아리는 다양한 요리 기술을 배우고 직접 음식을 만들어보는 것을 즐기는 학생들이 모이는 동아리입니다. 주로 요리 레시피를 공유하고, 재료 준비부터 조리, 그리고 플레이팅까지의 전 과정을 함께 경험합니다.', '요리', 7, '경기', '토요일', '음식나라조리학원', 1),
(2, '뮤지컬 동아리', '뮤지컬 동아리는 노래, 춤, 연기를 결합한 종합 예술인 뮤지컬을 제작하고 공연하는 학생들이 활동하는 동아리입니다. 뮤지컬 동아리의 활동은 여러 예술적 요소를 결합하여 공동 작업을 통해 하나의 공연을 완성하는 과정에서 많은 협동과 노력을 필요로 합니다.', '공연', 4, '인천', '금요일', '인천문화예술회관', 2),
(3, '운동 동아리', '운동 동아리는 다양한 스포츠와 운동을 통해 건강을 증진시키고, 팀워크와 스포츠맨십을 배우고자 하는 학생들이 모이는 동아리입니다. 운동 동아리의 종류는 매우 다양하며, 각기 다른 스포츠를 중심으로 활동합니다.', '운동', 3, '서울', '화요일', '충무스포츠센터', 3);

-- Memberships 테이블 샘플 데이터 생성
INSERT INTO Memberships_free (membershipId, memberId, clubId) VALUES
(1, 1, 1),
(2, 1, 2),
(3, 2, 1),
(4, 2, 3),
(5, 3, 2);

-- Memberships 테이블 삭제
DROP TABLE Memberships_free;

-- Clubs 테이블 삭제
DROP TABLE Clubs_free;

-- Members 테이블 삭제
DROP TABLE Members_free;
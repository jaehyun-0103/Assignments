-- create a table
CREATE TABLE member_table (
 cu_ID      	VARCHAR(20) NOT NULL,
 cu_Name     	VARCHAR(10),
 cu_Age    	INT,
 cu_Level   	VARCHAR(10) NOT NULL,
 cu_Job		VARCHAR(20),  
 cu_Point		INT DEFAULT 0,
  PRIMARY KEY(cu_ID)
) ;

-- insert some values
INSERT INTO member_table (cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point) VALUES ('apple', '정소화', 20, 'gold','학생',1000);
INSERT INTO member_table (cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point) VALUES ('banana', '김선우', 25, 'vip','간호사',2500);
INSERT INTO member_table (cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point) VALUES ('carrot', '고명석', 28, 'gold','교사',4500);
INSERT INTO member_table (cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point) VALUES ('orange', '김용욱', 22, 'silver','학생',0);
INSERT INTO member_table (cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point) VALUES ('melon', '성원용', 35, 'gold','회사원',5000);
INSERT INTO member_table (cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point) VALUES ('peach', '오형준', NULL, 'silver','의사',300);
INSERT INTO member_table (cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point) VALUES ('pear', '채광주', 31, 'silver','회사원',500);

-- create a table
CREATE TABLE product_table (
 po_ID		CHAR(3) NOT NULL,
 po_Name	VARCHAR(20),
 po_Stock	INT,
 po_Price	INT,
 po_Company	VARCHAR(20),
 PRIMARY KEY(po_ID),
 CHECK (po_Stock >= 0 AND po_Stock <= 10000)
);

-- insert some values
INSERT INTO product_table ( po_ID, po_Name, po_Stock, po_Price, po_Company) VALUES ('p01','그냥만두',5000,4500, '대한식품');
INSERT INTO product_table ( po_ID, po_Name, po_Stock, po_Price, po_Company) VALUES ('p02','매운쫄면',2500,5500, '민국푸드');
INSERT INTO product_table ( po_ID, po_Name, po_Stock, po_Price, po_Company) VALUES ('p03','쿵떡파이',3600,2600, '한빛제과');
INSERT INTO product_table ( po_ID, po_Name, po_Stock, po_Price, po_Company) VALUES ('p04','맛난초콜릿',1250,2500, '한빛제과');
INSERT INTO product_table ( po_ID, po_Name, po_Stock, po_Price, po_Company) VALUES ('p05','얼큰라면',2200,1200, '대한식품');
INSERT INTO product_table ( po_ID, po_Name, po_Stock, po_Price, po_Company) VALUES ('p06','통통우동',1000,1550, '민국푸드');
INSERT INTO product_table ( po_ID, po_Name, po_Stock, po_Price, po_Company) VALUES ('p07','달콤비스킷',1650,1500, '한빛제과');

-- create a table
CREATE TABLE order_table (
 or_No		CHAR(3),
 or_Customer	VARCHAR(20),
 or_Product	CHAR(3),
 or_Amount	INT,
 or_Address	VARCHAR(30),
  PRIMARY KEY(or_No),
 FOREIGN KEY(or_Customer) REFERENCES member_table(cu_ID),
 FOREIGN KEY(or_Product) REFERENCES product_table(po_ID)
);

-- insert some values
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o01','apple','p03',10, '서울시 마포구');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o02','melon','p01',5, '인천시 계양구');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o03','banana','p06',45, '경기도 부천시');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o04','carrot','p02',8, '부산시 금정구');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o05','melon','p06',36, '경기도 용신시');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o06','banana','p01',19, '충청북도 보은군');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o07','apple','p03',22, '서울시 영등포구');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o08','pear','p02',50, '강원도 춘천시');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o09','banana','p04',15, '전라남도 목포시');
INSERT INTO order_table (or_No, or_Customer, or_Product, or_Amount, or_Address) VALUES ('o10','carrot','p03',20, '경기도 안양시');

-- fetch some values

-- 1번
SELECT or_Product AS '주문제품', SUM(or_Amount) AS '수량의 합계'
FROM order_table
GROUP BY or_Product;

-- 2번
SELECT cu_Level AS '등급', COUNT(cu_Level) AS '등급별 고객수', AVG(cu_Point) AS '적립금 평균'
FROM member_table
WHERE cu_Point>=1000
GROUP BY cu_Level;

-- 3번
SELECT po_Company AS '제조업체', COUNT(po_Name) AS '제품수', MAX(po_Price) AS '최고가'
FROM product_table
GROUP BY po_Company;

-- 4번
SELECT member_table.cu_Name AS '고객', order_table.or_Product AS '주문제품'
FROM order_table, member_table
WHERE order_table.or_Customer = member_table.cu_ID AND member_table.cu_Age >= 30;

-- 5번
SELECT po_Name AS '제품명', po_Price AS '단가'
FROM product_table
WHERE po_Company = (SELECT po_Company FROM product_table WHERE po_Name = '달콤비스킷');

-- 6번
SELECT po_Name AS '제품명', po_Company AS '제조업체'
FROM product_table
WHERE po_ID IN(SELECT or_Product FROM order_table WHERE or_Customer = 'banana');

-- 7번
SELECT po_Name AS '제품명', po_Price AS '단가', po_Company AS '제조업체'
FROM product_table
WHERE po_Price > ALL(SELECT po_Price FROM product_table WHERE po_Company = '대한식품');

-- 8번
INSERT
INTO member_table(cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point)
VALUES('strawberry', '최유경', 30, 'vip', '공무원', 100);
SELECT * FROM member_table;

-- 9번
INSERT
INTO member_table(cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point)
VALUES('strawberry', '최유경', 30, 'vip', '공무원', 100);
UPDATE member_table
SET cu_Level = 'gold'
WHERE cu_ID = 'strawberry' AND cu_Name = '최유경';
SELECT * FROM member_table;

-- 10번
INSERT
INTO member_table(cu_ID, cu_Name, cu_Age, cu_Level, cu_Job, cu_Point)
VALUES('strawberry', '최유경', 30, 'vip', '공무원', 100);
UPDATE member_table
SET cu_Level = 'gold'
WHERE cu_ID = 'strawberry' AND cu_Name = '최유경';
DELETE
FROM  member_table
WHERE cu_ID = 'strawberry' AND cu_Name = '최유경';
SELECT * FROM member_table;
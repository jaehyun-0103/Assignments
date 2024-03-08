-- 테이블 생성
CREATE TABLE member (
    member_id INT PRIMARY KEY AUTO_INCREMENT,
    member_password VARCHAR(255) NOT NULL,
    member_nickname VARCHAR(255) UNIQUE NOT NULL,
    member_name VARCHAR(255) NOT NULL
);

CREATE TABLE movie (
    movie_id INT PRIMARY KEY AUTO_INCREMENT,
    movie_title VARCHAR(255) NOT NULL,
    movie_release_date VARCHAR(255),
    movie_director VARCHAR(255) NOT NULL,
    movie_overview TEXT NOT NULL,
    movie_rate DECIMAL(2, 1) DEFAULT 0.0,
    movie_genre VARCHAR(255) NOT NULL,
    movie_poster VARCHAR(500) NOT NULL
);

CREATE TABLE review (
    review_id INT PRIMARY KEY AUTO_INCREMENT,
    review_title VARCHAR(255) NOT NULL,
    review_content TEXT NOT NULL,
    review_rate INT NOT NULL,
    review_created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP(0),
    member_id INT NOT NULL,
    movie_id INT NOT NULL,
    FOREIGN KEY (member_id) REFERENCES member(member_id),
    FOREIGN KEY (movie_id) REFERENCES movie(movie_id)
);


-- 데이터 삽입
insert into member(member_password, member_nickname, member_name) values('ans1234', 'gal', 'ans1111');
insert into member(member_password, member_nickname, member_name) values('dnjs1234', 'won', 'dnjs2222');
insert into member(member_password, member_nickname, member_name) values('db1234', 'yu', 'yu3333');
insert into member(member_password, member_nickname, member_name) values('wh1234', 'jo', 'jo4444');

insert into movie values(1, '서울의봄', '2023.11.22', '김성수', '1979년 12월 12일, 수도 서울 군사반란 발생 그날, 대한민국의 운명이 바뀌었다.대한민국을 뒤흔든 10월 26일 이후,서울에 새로운 바람이 불어온 것도 잠시 12월 12일, 보안사령관 전두광이 반란을 일으키고 군 내 사조직을 총동원하여 최전선의 전방부대까지 서울로 불러들인다. 권력에 눈이 먼 전두광의 반란군과 이에 맞선 수도경비사령관 이태신을 비롯한 진압군 사이, 일촉즉발의 9시간이 흘러가는데…목숨을 건 두 세력의 팽팽한 대립 오늘 밤, 대한민국 수도에서 가장 치열한 전쟁이 펼쳐진다!', 3.0, '드라마', 'https://img.cgv.co.kr/Movie/Thumbnail/Poster/000087/87554/87554_1000.jpg');
insert into movie values(2, '더 퍼스트 슬램덩크', '2023.01.04',  '이노우에 다케히코', '전국 제패를 꿈꾸는 북산고 농구부 5인방의 꿈과 열정, 멈추지 않는 도전을 그린 영화', 5.0, '애니매이션', 'https://img.cgv.co.kr/Movie/Thumbnail/Poster/000086/86720/86720_1000.jpg');
insert into movie values(3, '괴물', '2023.11.29',  '고레에다 히로카즈', '"우리 동네에는 괴물이 산다” 싱글맘 사오리(안도 사쿠라)는 아들 미나토(쿠로카와 소야)의 행동에서 이상 기운을 감지한다. 용기를 내 찾아간 학교에서 상담을 진행한 날 이후 선생님과 학생들의 분위기가 심상치 않게 흐르기 시작하고. “괴물은 누구인가?” 한편 사오리는 친구들로부터 따돌림을 당하고 있는 미나토의 친구 요리(히이라기 히나타)의 존재를 알게 되고 자신이 아는 아들의 모습과 사람들이 아는 아들의 모습이 다르다는 사실을 어렴풋이 깨닫는데… 태풍이 몰아치던 어느 날, 아무도 몰랐던 진실이 드러난다.', 4.0, '드라마, 스릴러', 'https://img.cgv.co.kr/Movie/Thumbnail/Poster/000087/87716/87716_1000.jpg');
insert into movie values(4, '듄', '2023.12.06', '드니 빌뇌브', '“듄을 지배하는 자가 우주를 지배한다!” 10191년, 아트레이데스 가문의 후계자인 폴(티모시 샬라메)은 시공을 초월한 존재이자 전 우주를 구원할 예지된 자의 운명을 타고났다. 그리고 어떤 계시처럼 매일 꿈에서 아라키스 행성에 있는 한 여인을 만난다. 모래언덕을 뜻하는 ''듄''이라 불리는 아라키스는 물 한 방울 없는 사막이지만 우주에서 가장 비싼 물질인 신성한 환각제 스파이스의 유일한 생산지로 이를 차지하기 위한 전쟁이 치열하다. 황제의 명령으로 폴과 아트레이데스 가문은 죽음이 기다리는 아라키스로 향하는데…위대한 자는 부름에 응답한다, 두려움에 맞서라, 이것은 위대한 시작이다!', 4.0, '모험', 'https://img.cgv.co.kr/Movie/Thumbnail/Poster/000084/84945/84945_1000.jpg');
insert into movie values(5, '나폴레옹', '2023.12.06', '리들리 스콧', '스스로 황제가 된 영웅! 1793년 혁명의 불꽃이 프랑스 전역을 밝히기 시작한다. 코르시카 출신의 장교 ''나폴레옹''(호아킨 피닉스)은 혼란스러운 상황 속 국가를 위해 맞서며 영웅으로 떠오른다. 한편, 사교 파티에서 영웅 ''나폴레옹''을 만난 ''조제핀''(바네사 커비)은 자신의 운명을 바꾸기 위해 ''나폴레옹''을 선택하고 ''나폴레옹''은 마침내 스스로 황제의 자리에 오르게 된다. 하지만, ''조제핀''은 계속해서 ''나폴레옹''을 흔들고, ''나폴레옹''의 야망은 ''조제핀''과 끝없이 충돌하는데… 세상을 정복한 영웅 아무것도 갖지 못한 황제, ''나폴레옹''의 대서사가 펼쳐진다!', 0.0, '전쟁, 드라마', 'https://img.cgv.co.kr/Movie/Thumbnail/Poster/000087/87596/87596_1000.jpg');
insert into movie values(6, '쏘우 X', '2023.12.13', '케빈 그루터트', '1편의 게임을 마친 존 크레이머 일명 ‘직쏘’는 암을 치료하러 멕시코로 떠난다. 그러나 그곳에서 모든 희망은 절망이 되고 모든 것이 사기라는 것을 알게 되는데… 이제 존의 차례이다. 이것은 복수가 아니다. ‘직쏘’의 세계로 초대받은 모든 사람은 자신을 구원할 기회를 가진다. 그들의 게임이 끝나고, 직쏘의 게임이 시작된다.', 0.0, '공포, 스릴러', 'https://img.cgv.co.kr/Movie/Thumbnail/Poster/000087/87753/87753_1000.jpg');
insert into movie values(7, '노 엑시트', '2023.12.13', '프랑스 칼포온', '오늘밤, 보이지 않는 총구가 당신을 노린다! 한밤중 외딴 편의점에 들른 앨리스는 갑자기 총에 맞고 쓰러진다. 누가 어디서 무슨 이유로 쏘는지 알 수 없지만, 탈출을 시도할 때마다 정확히 날아오는 총알! 도움도, 구조도 없다! 밀실 아닌 밀실이 된 이곳에서 반드시 탈출하라!', 0.0, '스릴러', 'https://img.cgv.co.kr/Movie/Thumbnail/Poster/000087/87752/87752_1000.jpg');
insert into movie values(8, '탑건-매버릭', '2022.06.22', '조셉 코신스키', '한순간의 실수도 용납되지 않는 하늘 위, 가장 압도적인 비행이 시작된다! 최고의 파일럿이자 전설적인 인물 매버릭(톰 크루즈)은 자신이 졸업한 훈련학교 교관으로 발탁된다.  그의 명성을 모르던 팀원들은 매버릭의 지시를 무시하지만 실전을 방불케 하는 상공 훈련에서 눈으로 봐도 믿기 힘든 전설적인 조종 실력에 모두가 압도된다.  매버릭의 지휘아래 견고한 팀워크를 쌓아가던 팀원들에게 국경을 뛰어넘는 위험한 임무가 주어지자 매버릭은 자신이 가르친 동료들과 함께 마지막이 될 지 모를 하늘 위 비행에 나서는데… ', 0.0, '액션', 'https://img.cgv.co.kr/Movie/Thumbnail/Poster/000082/82120/82120_1000.jpg');

insert into review(review_title, review_content, review_rate, review_created_at, member_id, movie_id) values('서울의 봄 보고왔습니다.', '언제나 가슴을 먹먹하게 할 만큼 거대한 감정이 몰려드는 김성수 감독의 영화. 정우성을 누구보다 사랑하는 감독답게 방황하는 청춘 정우성, 이정재와 함께하는 정우성, 고려의 무사 정우성, 더러운 척 하지만 못 더러워지는 정우성에 이은 올곧고 단아한 정우성의 매력을 최대로 뽑아 낸다. 황정민의 연기는 후반으로 갈수록 인간이 아닌 듯한 괴기함이 느껴지며, 완전히 먹혀버렸지만 간신히 친구 행서중인 박해준의 미묘함도 일품이다. 모든 상황을 자막으로 대신하는 기묘한 기법을 통해 역사를 전달한다', 3, CURRENT_TIMESTAMP(0), 1, 1);
insert into review(review_title, review_content, review_rate, review_created_at, member_id, movie_id) values('듄 후기', '듄이라는 영화가 나온다고 했을 때, 음.. 그냥 특별한 생각은 없었다. 아주 예전에 듄이라는 RTS게임이 있었다는건 알고 있었다. 그런데 주변에서 들려오는 이야기가 생각보다 좋았다. 결론부터 이야기하자면 기대 이상 그 이상이었다. 분위기는 그냥 제다이만 나오면 스타워즈 시리즈에 넣어도 될 것 같았다. 제다이들의 기술은 마인드트릭 같은 기술들도 나오고 은하제국에, 공작이니 뭐니 나오는 것도 비슷하다. 영화는 꽤 긴 러닝타임을 가졌지만 지루한 부분없이 끝까지 긴장감을 유지한다. 영화를 보고나서 뒤늦게 세계관이나 배경에 대한 지식을 찾아봤는데 영화를 보면서 짐작했던 것들과 크게 어긋나지 않았다. 즉 영화를 사전지식없이 보더라도 충분히 즐길 수 있게 만들어져 있다. 듀니버스라는 말이 있을 정도로 듄의 세계관은 하나의 완성된 형태로 이미 존재하는 듯하다. 개인적으로 스타워즈, 스타트랙에 대해서 관심을 갖고 찾아보곤 했는데 미국의 스페이스 오페라 장르의 새로운 이야기를 알게 돼서 흥미로웠다. 음악도 한스짐머가 작곡했다고 한다. 놀란감독의 테넷을 포기하고 이 영화의 곡을 작곡했다고 한다. 이야기, 영상미, 연출 모든 면에서 올해 최고의 상업영화가 아닐까 생각해본다.', 4, CURRENT_TIMESTAMP(0), 4, 4);
insert into review(review_title, review_content, review_rate, review_created_at, member_id, movie_id) values('영화 괴물 감상평',  '이 작품은 수작이라 평하기에 부족함이 전혀 없으며 명작이라 불리기에도 충분한 그런 작품이라고 생각한다. 만약 다른 고래에다 히로카즈의 작품들의 평균이 이 정도라고 한다면 나는 이 감독의 작품들을 전부 찾아서 볼 생각이다. 정말 너무나 뛰어난 작품이니 본인이 이 감독과 너무 맞지 않는다. 혹은 약간이라도 퀴어 요소가 들어간 영화를 절대로 못 본다. 이런 사람이 아닌 이상 무조건 영화관으로 달려가서 보길 권장한다.', 4.0, CURRENT_TIMESTAMP(0), 3, 3);
insert into review(review_title, review_content, review_rate, review_created_at, member_id, movie_id) values('더 퍼스트 슬램덩크 후기 및 감상평', '요즘 "슬램덩크" 붐이 되살아나고 있다. 이번에 개봉한 영화 "더 퍼스트 슬램덩크" 때문이다. 이에 따라 만화 슬램덩크도 최근 판매량이 급증했다더라.  과거 슬램덩크를 보고 자란 지금의 3040은, 그때의 열광을 다시 느낀다는 기쁨에 극장으로 향하고 있다. 그리고 그들을 보고 자란 1020도 조금은 슬램덩크에 관심을 가지는 듯 하다. 나는 슬램덩크 세대는 아니지만, 슬램덩크라는 만화를 보았다는 같은 추억을 공유하고 있기 때문에 극장을 향하는 3040의 마음이 조금은 이해가 된다. 마음 한 켠에 고이 간직했던 추억을 이제는 다시 꺼낼 수 있다는, 또 그것이 계속된다는 행복일 것이다. 아저씨들의 영광의 시대는 언제였죠? 연재 당시였나요? 나는 지금이라고 생각합니다. 일단 슬램덩크는 농구만화이다. 농구에 대해 아무것도 모르던 주인공 강백호가 여자에게 잘 보이기 위하여 농구를 하게 되지만, 경기를 통해 어엿한 선수로서 성장하는 과정을 그린 작품이다. 작품의 표면적 주인공은 강백호이지만, 사실 슬램덩크의 주인공은 여러명이다. 강백호 외에도 다른 인물들에게도 초점을 맞춘다. 슬램덩크의 중요한 볼거리는 농구 경기도 경기지만, 경기 속 등장인물의 심리를 잘 묘사하는 것이고 그것을 또 경기를 통해서 잘 풀어내는 것이라고 생각한다. 그래서 슬램덩크의 등장인물들은 개성과 매력이 생긴다. 원작에서 산왕공고와의 경기는 북산 선수들 개개인의 심리적 갈등과 그것을 극복함으로써 보이는 성장이 명장면인 에피소드이다. 채치수는 최강의 센터 신현철을 이겨야 한다는 부담감을, 정대만은 헛되게 보낸 불량한 생활을, 서태웅은 국내 최고 선수라는 목표를, 강백호는 부상이라는 장치를 통해 극중 인물에 몰입하게 되고, 그것을 극복해냈을 때 독자는 카타르시스를 느끼게 된다. 그것이 슬램덩크라는 작품의 가장 큰 장점이 아닌가 싶다.', 5.0, CURRENT_TIMESTAMP(0), 2, 2);

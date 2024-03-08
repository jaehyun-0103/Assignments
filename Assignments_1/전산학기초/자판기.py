# 변수나 리스트의 기본값 설정
list_2000 = [4]
list_1500 = [2]
list_1300 = [3]
list_1000 = [5, 8, 9, 10, 11, 12, 13, 16, 17]
list_800 = [6, 7, 18, 19, 20]
list_600 = [1, 14, 15]
water = 0
daily = 4
corn = 8
cantata = 3
trevi = 3
milkis = 9
pepsi = 10
hotsix = 1
cider = 8
mango = 4
lipton = 7
apple = 4
grape = 6
gana = 5
be = 0
latte = 3
cafe = 2
gatorade = 4
coco = 4
rice = 10
coin10000 = 0
coin1000 = 0
coin500 = 0
coin100 = 0
_coin10000 = 0
_coin1000 = 0
_coin500 = 0
_coin100 = 0
coin10000_m = 10
coin1000_m = 10
coin500_m = 0
coin100_m = 10
money = 0
charge = 0
select = 0
menu = 0
       
# 돈과 관련된 함수들이 있는 클래스
class cost:
    def __init__(self):
        self._coin10000 = _coin10000
        self._coin1000 = _coin1000
        self._coin500 = _coin500
        self._coin100 = _coin100
        self.charge = charge
    # 사용자가 돈을 지불하면 그 총합을 계산하는 합수
    def money_(self):
        print("지불할 돈의 개수를 적어주세요.")
        global coin10000_m, coin1000_m, coin500_m, coin100_m
        self.coin10000 = int(input("만원:"))
        coin10000_m += self.coin10000
        self.coin1000 = int(input("천원:"))
        coin1000_m += self.coin1000
        self.coin500 = int(input("오백원:"))
        coin500_m += self.coin500
        self.coin100 = int(input("백원:"))
        coin100_m += self.coin100
        print("==============================================")
        global money
        money = self.coin10000*10000 + self.coin1000*1000 + self.coin500*500 + self.coin100*100
        print("총", money, "원을 지불하셨습니다.")
        customer().start()
    # 사용자가 고른 메뉴를 출력하고 거스름돈 개수와 그 총합을 출력하는 합수
    def end(self, _coin10000, _coin1000, _coin500, _coin100, menu):
        global coin10000_m, coin1000_m, coin500_m, coin100_m
        print("덜컹!...", menu, "가 나왔습니다!")
        print("==================거스름돈====================")
        print("만원:", _coin10000, "개")
        print("천원:", _coin1000, "개")
        print("오백원:", _coin500, "개")
        print("백원:", _coin100, "개")
        coin10000_m -= _coin10000
        coin1000_m -= _coin1000
        coin500_m -= _coin500
        coin100_m -= _coin100
        print("합계:", _coin10000*10000 + _coin1000*1000 + _coin500*500 + _coin100*100, "원")
        print("==============================================")
        customer().bye()
    # 사용자가 낸 돈에서 2000원을 빼고 남은 거스름돈을 계산하는 합수
    def m_2000(self, menu):
        if answer4 == 1:
            global money
            self.charge = money - 2000
            if self.charge < 0:
                print(abs(self.charge), "원 부족합니다. 가격을 다시 확인해주세요.")
                print(money, "원 반환")
                print("==============================================")
                money = 0
                customer().payment()
            else:
                global coin10000_m, coin1000_m, coin500_m, coin100_m
                print(menu, "을(를) 선택하셨습니다.")
                self._coin10000 = self.charge//10000
                if self.coin10000_m - self._coin10000 >= 0:
                    self.charge = self.charge%10000
                self._coin1000 = self.charge//1000
                if self.coin1000_m - self._coin1000 >= 0:
                    self.charge = self.charge%1000
                self._coin500 = self.charge//500
                if self.coin500_m - self._coin500 >= 0:
                    self.charge = self.charge%500         
                self._coin100 = self.charge//100
                if self.coin100_m - self._coin100 >= 0:
                    self.charge = self.charge%100
                cost().end(self._coin10000, self._coin1000, self._coin500, self._coin100, menu)
        else:
            cost.end(0, 0, 0, 0, 0)
    # 사용자가 낸 돈에서 1500원을 빼고 남은 거스름돈을 계산하는 합수
    def m_1500(self, menu):
        if answer4 == 1:
            global money
            self.charge = money - 1500
            if self.charge < 0:
                print(abs(self.charge), "원 부족합니다. 가격을 다시 확인해주세요.")
                print(money, "원 반환")
                money = 0
                customer().payment()
            else:
                global coin10000_m, coin1000_m, coin500_m, coin100_m
                print(menu, "을(를) 선택하셨습니다.")
                self._coin10000 = self.charge//10000
                if coin10000_m - self._coin10000 >= 0:
                    self.charge = self.charge%10000
                self._coin1000 = self.charge//1000
                if coin1000_m - self._coin1000 >= 0:
                    self.charge = self.charge%1000
                self._coin500 = self.charge//500
                if coin500_m - self._coin500 >= 0:
                    self.charge = self.charge%500         
                self._coin100 = self.charge//100
                if coin100_m - self._coin100 >= 0:
                    self.charge = self.charge%100
                cost().end(self._coin10000, self._coin1000, self._coin500, self._coin100, menu)
        else:
            cost().end(0, 0, 0, 0, menu)
    # 사용자가 낸 돈에서 1300원을 빼고 남은 거스름돈을 계산하는 합수
    def m_1300(self, menu):
        if answer4 == 1:
            global money
            self.charge = money - 1300
            if self.charge < 0:
                print(abs(self.charge), "원 부족합니다. 가격을 다시 확인해주세요.")
                print(money, "원 반환")
                money = 0
                customer().payment()
            else:
                global coin10000_m, coin1000_m, coin500_m, coin100_m
                print(menu, "을(를) 선택하셨습니다.")
                self._coin10000 = self.charge//10000
                if coin10000_m - self._coin10000 >= 0:
                    self.charge = self.charge%10000
                self._coin1000 = self.charge//1000
                if coin1000_m - self._coin1000 >= 0:
                    self.charge = self.charge%1000
                self._coin500 = self.charge//500
                if coin500_m - self._coin500 >= 0:
                    self.charge = self.charge%500         
                self._coin100 = self.charge//100
                if coin100_m - self._coin100 >= 0:
                    self.charge = self.charge%100
                cost().end(self._coin10000, self._coin1000, self._coin500, self._coin100, menu)
        else:
            cost().end(0, 0, 0, 0, 0)
    # 사용자가 낸 돈에서 1000원을 빼고 남은 거스름돈을 계산하는 합수
    def m_1000(self, menu):
        if answer4 == 1:
            global money
            self.charge = money - 1000
            if self.charge < 0:
                print(abs(self.charge), "원 부족합니다. 가격을 다시 확인해주세요.")
                print(money, "원 반환")
                money = 0
                customer().payment()
            else:
                global coin10000_m, coin1000_m, coin500_m, coin100_m
                print(menu, "을(를) 선택하셨습니다.")
                self._coin10000 = self.charge//10000
                if coin10000_m - self._coin10000 >= 0:
                    self.charge = self.charge%10000
                self._coin1000 = self.charge//1000
                if coin1000_m - self._coin1000 >= 0:
                    self.charge = self.charge%1000
                self._coin500 = self.charge//500
                if coin500_m - self._coin500 >= 0:
                    self.charge = self.charge%500         
                self._coin100 = self.charge//100
                if coin100_m - self._coin100 >= 0:
                    self.charge = self.charge%100
                cost().end(self._coin10000, self._coin1000, self._coin500, self._coin100, menu)
        else:
            cost().end(0, 0, 0, 0, 0)
    # 사용자가 낸 돈에서 800원을 빼고 남은 거스름돈을 계산하는 합수
    def m_800(self, menu):
        if answer4 == 1:
            global money
            self.charge = money - 800
            if charge < 0:
                print(abs(self.charge), "원 부족합니다. 가격을 다시 확인해주세요.")
                print(money, "원 반환")
                money = 0
                customer().payment()
            else:
                global coin10000_m, coin1000_m, coin500_m, coin100_m
                print(menu, "을(를) 선택하셨습니다.")
                self._coin10000 = self.charge//10000
                if coin10000_m - self._coin10000 >= 0:
                    self.charge = self.charge%10000
                self._coin1000 = self.charge//1000
                if coin1000_m - self._coin1000 >= 0:
                    self.charge = self.charge%1000
                self._coin500 = self.charge//500
                if coin500_m - self._coin500 >= 0:
                    self.charge = self.charge%500         
                self._coin100 = self.charge//100
                if coin100_m - self._coin100 >= 0:
                    self.charge = self.charge%100
                cost().end(self._coin10000, self._coin1000, self._coin500, self._coin100, menu)
        else:
            cost().end(0, 0, 0, 0, 0)
    # 사용자가 낸 돈에서 600원을 빼고 남은 거스름돈을 계산하는 합수
    def m_600(self, menu):
        if answer4 == 1:
            global money
            self.charge = money - 600
            if charge < 0:
                print(abs(charge), "원 부족합니다. 가격을 다시 확인해주세요.")
                print(money, "원 반환")
                money = 0
                customer().payment()
            else:
                global coin10000_m, coin1000_m, coin500_m, coin100_m
                print(menu, "을(를) 선택하셨습니다.")
                self._coin10000 = self.charge//10000
                if coin10000_m - self._coin10000 >= 0:
                    self.charge = self.charge%10000
                self._coin1000 = self.charge//1000
                if coin1000_m - self._coin1000 >= 0:
                    self.charge = self.charge%1000
                self._coin500 = self.charge//500
                if coin500_m - self._coin500 >= 0:
                    self.charge = self.charge%500         
                self._coin100 = self.charge//100
                if coin100_m - self._coin100 >= 0:
                    self.charge = self.charge%100
                cost().end(self._coin10000, self._coin1000, self._coin500, self._coin100, menu)
        else:
            cost().end(0, 0, 0, 0, 0)

# 자판기 주인이 사용하는 기능에 대한 함수들이 있는 클래스
class owner:
    def __init__(self):
        self.password = 1234
        self.answer2 = 0000
    # 재고가 없는 음료가 있는지 주인에게 알려주는 함수
    def manage_d(self):
        if water == 0:
            print('아이시스8.0 재고가 없습니다.')
        if daily == 0:
            print('데일리 C 레몬워터 재고가 없습니다.')
        if corn == 0:
            print('옥수수 수염차재고가 없습니다.')
        if cantata == 0:
            print('칸타타 콘트라베이스 재고가 없습니다.')
        if trevi == 0:
            print('트레비 재고가 없습니다.')
        if milkis == 0:
            print('밀키스 재고가 없습니다.')
        if pepsi == 0:
            print('펩시 재고가 없습니다.')
        if hotsix == 0:
            print('핫식스 재고가 없습니다.')
        if cider == 0:
            print('칠성사이다 재고가 없습니다.')
        if mango == 0:
            print('코코리치망고 재고가 없습니다.')
        if lipton == 0:
            print('립톤 복숭아아이스티 재고가 없습니다.')
        if apple == 0:
            print('트로피카나 스파클링 사과 재고가 없습니다.')
        if grape == 0:
            print('트로피카나 스파클링 포도 재고가 없습니다.')
        if gana == 0:
            print('가나 재고가 없습니다.')
        if be == 0:
            print('레쓰비 재고가 없습니다.')
        if latte == 0:
            print('칸타타 프리미엄 라떼 재고가 없습니다.')
        if cafe == 0:
            print('레쓰비 카페타임 재고가 없습니다.')
        if gatorade == 0:
            print('게토레이 재고가 없습니다.')
        if coco == 0:
            print('코코팜 포도 재고가 없습니다.')
        if rice == 0:
            print('잔치집식혜 재고가 없습니다.')
        print("==============================================")
        owner().stock()
    # 잔돈이 없는 돈이 있는지 주인에게 알려주는 함수
    def manage_m(self):
        global coin10000_m, coin1000_m, coin500_m, coin100_m
        if coin10000_m == 0:
            print('10000원짜리 잔돈이 없습니다.')
        if coin1000_m == 0:
            print('1000원짜리 잔돈이 없습니다.')
        if coin500_m == 0:
            print('500원짜리 잔돈이 없습니다.')
        if coin100_m == 0:
            print('100원짜리 잔돈이 없습니다.')
        print("==============================================")
        owner().balance()
    # 잔돈 확인 혹은 재고 확인 중 무엇을 선택할지 묻는 함수
    def work(self):
            print('1. 잔돈 확인', '2. 재고 확인')
            answer5 = int(input('선택:'))
            print("==============================================")
            if answer5 == 1:
                owner().manage_m()
            elif answer5 == 2:
                owner().manage_d()
            else:
                print('잘못 고르셨습니다.')
                owner().work()
    # 잔돈의 개수를 확인하고 잔돈을 자판기에 추가할지 묻는 함수
    def balance(self):
        global coin10000_m, coin1000_m, coin500_m, coin100_m
        print('10000짜리 개수:', coin10000_m, '개')
        print('1000짜리 개수:', coin1000_m, '개')
        print('500짜리 개수:', coin500_m, '개')
        print('100짜리 개수:', coin100_m, '개')
        print("==============================================")
        print('잔돈을 추가하시겠습니까?')
        print('1. Yes', '2. No')
        answer10 = int(input('선택:'))
        print("==============================================")
        if answer10 == 1:
            owner().add_m()
        else:
            who()
    #  음료의 재고를 확인하고 자판기에 재고를 추가할지 묻는 함수
    def stock(self):
        print("1. 아이시스8.0", water, "개")
        print("2. 데일리 C 레몬워터", daily, "개")
        print("3. 옥수수 수염차", corn, "개")
        print("4. 칸타타 콘트라베이스", cantata, "개")
        print("5. 트레비", trevi, "개")
        print("6. 밀키스", milkis, "개")
        print("7. 펩시", pepsi, "개")
        print("8. 핫식스", hotsix, "개")
        print("9. 칠성사이다", cider, "개")
        print("10. 코코리치망고", mango, "개")
        print("11. 립톤 복숭아아이스티", lipton, "개")
        print("12. 트로피카나 스파클링 사과", apple, "개")
        print("13. 트로피카나 스파클링 포도", grape, "개")
        print("14. 가나", gana, "개")
        print("15. 레쓰비", be, "개")
        print("16. 칸타타 프리미엄 라떼", latte, "개")
        print("17. 레쓰비 카페타임", cafe, "개")
        print("18. 게토레이", gatorade, "개")
        print("19. 코코팜 포도", coco, "개")
        print("20. 잔치집식혜", rice, "개")
        print("==============================================")
        print('재고를 추가하시겠습니까?')
        print('1. Yes', '2. No')
        answer11 = int(input('선택:'))
        print("==============================================")
        if answer11 == 1:
            owner().add_d()
        else:
            who()
    # 주인이 맞는지 확인하기 위해 암호를 입력하는 함수
    def passwd(self, trial = 0):
        while trial <= 2:
            self.answer2 = int(input('암호를 입력하시오:'))
            if self.answer2 == self.password:
                print('정답입니다.')
                print("==============================================")
                owner().work()
            else:
                print('오답입니다. 시도 횟수', 2 - trial, '남았습니다.')
                trial += 1
                print("==============================================")
                if trial == 3:
                    print('암호 입력 횟수를 초과하였습니다.')
    # 음료의 종류를 보여주고 어떤 음료를 얼마나 추가할지 묻는 함수
    def add_d(self):
        print("1. 아이시스8.0")
        print("2. 데일리 C 레몬워터")
        print("3. 옥수수 수염차")
        print("4. 칸타타 콘트라베이스")
        print("5. 트레비")
        print("6. 밀키스")
        print("7. 펩시")
        print("8. 핫식스")
        print("9. 칠성사이다")
        print("10. 코코리치망고")
        print("11. 립톤 복숭아아이스티")
        print("12. 트로피카나 스파클링 사과")
        print("13. 트로피카나 스파클링 포도")
        print("14. 가나")
        print("15. 레쓰비")
        print("16. 칸타타 프리미엄 라떼")
        print("17. 레쓰비 카페타임")
        print("18. 게토레이")
        print("19. 코코팜 포도")
        print("20. 잔치집식혜")
        print("==============================================")
        answer6 = int(input('추가할 음료 번호를 고르시오:'))
        print("==============================================")
        answer7 = int(input('추가할 음료의 개수:'))
        print("==============================================")
        global water, daily, corn, cantata, trevi, milkis, pepsi, hotsix, cider, mango, lipton, apple, grape, gana, be, latte, cafe, gatorade, coco, rice
        if answer6 == 1:
            water += answer7
            who()
        if answer6 == 2:
            daily += answer7
            who()
        if answer6 == 3:
            corn += answer7
            who()
        if answer6 == 4:
            cantata += answer7
            who()
        if answer6 == 5:
            trevi += answer7
            who()
        if answer6 == 6:
            milkis += answer7
            who()
        if answer6 == 7:
            pepsi += answer7
            who()
        if answer6 == 8:
            hotsix += answer7
            who()
        if answer6 == 9:
            cider += answer7
            who()
        if answer6 == 10:
            mango += answer7
            who()
        if answer6 == 11:
            lipton += answer7
            who()
        if answer6 == 12:
            apple += answer7
            who()
        if answer6 == 13:
            grape += answer7
            who()
        if answer6 == 14:
            gana += answer7
            who()
        if answer6 == 15:
            be += answer7
            who()
        if answer6 == 16:
            latte += answer7
            who()
        if answer6 == 17:
            cafe += answer7
            who()
        if answer6 == 18:
            gatorade += answer7
            who()
        if answer6 == 19:
            coco += answer7
            who()
        if answer6 == 20:
            rice += answer7
            who()
    # 잔돈의 종류를 보여주고 어떤 잔돈을 얼마나 추가할지 묻는 함수
    def add_m(self):
        print('1. 10000원짜리')
        print('2. 1000원짜리')
        print('3. 500원짜리')
        print('4. 100원짜리')
        print("==============================================")
        answer8 = int(input('추가할 잔돈을 고르시오:'))
        print("==============================================")
        answer9 = int(input('잔돈의 개수를 고르시오:'))
        print("==============================================")
        global coin10000_m, coin1000_m, coin500_m, coin100_m
        if answer8 == 1:
            coin10000_m += answer9
            who()
        if answer8 == 2:
            coin1000_m += answer9
            who()
        if answer8 == 3:
            coin500_m += answer9
            who()
        if answer8 == 4:
            coin100_m += answer9
            who()

# 손님이 사용하는 기능에 대한 함수들이 있는 클래스
class customer(cost):
    def __init__(self):
        cost.__init__(self)
        self.select = select
    # 계산을 위해 음료 가격을 확인하는 함수
    def find(self, select, menu):
        if select in list_2000:
            cost().m_2000(menu)
        if select in list_1500:
            cost().m_1500(menu)
        if select in list_1300:
            cost().m_1300(menu)
        if select in list_1000:
            cost().m_1000(menu)
        if select in list_800:
            cost().m_800(menu)
        if select in list_600:
            cost().m_600(menu)
    # 선택한 음료의 재고가 있는지 확인하는 함수
    def selection(self,select):
        if select == 1:
            menu = "아이시스8.0"
            global water
            if water < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                water -= 1
                customer().find(select, menu)
        elif select == 2:
            menu = "데일리 C 레몬워터"
            global daily
            if daily < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                daily -= 1
                customer().find(select, menu)
        elif select == 3:
            menu = "옥수수 수염차"
            global corn
            if corn < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                corn -= 1
                customer().find(select, menu)
        elif select == 4:
            menu = "칸타타 콘트라베이스"
            global cantata
            if cantata < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                cantata -= 1
                customer().find(select, menu)
        elif select == 5:
            menu = "트레비"
            global trevi
            if trevi < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                trevi -= 1
                customer().find(select, menu)
        elif select == 6:
            menu = "밀키스"
            global milkis
            if milkis < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                milkis -= 1
                customer().find(select, menu)
        elif select == 7:
            menu = "펩시"
            global pepsi
            if pepsi < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                pepsi -= 1
                customer().find(select, menu)
        elif select == 8:
            menu = "핫식스"
            global hotsix
            if hotsix < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                hotsix -= 1
                customer().find(select, menu)
        elif select == 9:
            menu = "칠성사이다"
            global cider
            if cider < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                cider -= 1
                customer().find(select, menu)
        elif select == 10:
            menu = "코코리치망고"
            global mango
            if mango < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                mango -= 1
                customer().find(select, menu)
        elif select == 11:
            menu = "립톤 복숭아아이스티"
            if water < 1:
                global lipton
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                lipton -= 1
                customer().find(select, menu)
        elif select == 12:
            menu = "트로피카나 스파클링 사과"
            global apple
            if apple < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                apple -= 1
                customer().find(select, menu)
        elif select == 13:
            menu = "트로피카나 스파클링 포도"
            global grape
            if grape < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                grape -= 1
                customer().find(select, menu)
        elif select == 14:
            menu = "가나"
            global gana
            if gana < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                gana -= 1
                customer().find(select, menu)
        elif select == 15:
            menu = "레쓰비"
            global be
            if be < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                be -= 1
                customer().find(select, menu)
        elif select == 16:
            menu = "칸타타 프리미엄 라떼"
            global latte
            if latte < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                latte -= 1
                customer().find(select, menu)
        elif select == 17:
            menu = "레쓰비 카페타임"
            global cafe
            if cafe < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                cafe -= 1
                customer().find(select, menu)
        elif select == 18:
            menu = "게토레이"
            global gatorade
            if gatorade < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                gatorade -= 1
                customer().find(select, menu)
        elif select == 19:
            menu = "코코팜 포도"
            global coco
            if coco < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                coco -= 1
                customer().find(select, menu)
        elif select == 20:
            menu = "잔치집식혜"
            global rice
            if rice < 1:
                print("재고가 없습니다. 다시 골라주세요.")
                customer().start()
            else:
                rice -= 1
                customer().find(select, self.menu)
        else:
            who()
    # 재고 개수를 손님에게 출력하고 어떤 음료를 선택할지 묻는 함수
    def start(self):
        global water, daily, corn, cantata, trevi, milkis, pepsi, hotsix, cider, mango, lipton, apple, grape, gana, be, latte, cafe, gatorade, coco, rice
        print("==============================================")
        print("1. 아이시스8.0", water, "개")
        print("2. 데일리 C 레몬워터", daily, "개")
        print("3. 옥수수 수염차", corn, "개")
        print("4. 칸타타 콘트라베이스", cantata, "개")
        print("5. 트레비", trevi, "개")
        print("6. 밀키스", milkis, "개")
        print("7. 펩시", pepsi, "개")
        print("8. 핫식스", hotsix, "개")
        print("9. 칠성사이다", cider, "개")
        print("10. 코코리치망고", mango, "개")
        print("11. 립톤 복숭아아이스티", lipton, "개")
        print("12. 트로피카나 스파클링 사과", apple, "개")
        print("13. 트로피카나 스파클링 포도", grape, "개")
        print("14. 가나", gana, "개")
        print("15. 레쓰비", be, "개")
        print("16. 칸타타 프리미엄 라떼", latte, "개")
        print("17. 레쓰비 카페타임", cafe, "개")
        print("18. 게토레이", gatorade, "개")
        print("19. 코코팜 포도", coco, "개")
        print("20. 잔치집식혜", rice, "개")
        print("21. 사지않기")
        print("==============================================")
        customer().selection(int(input("선택: ")))
    # 사용자에게 결제 수단을 묻고 음료 가격을 알려주는 함수
    def payment(self):
        global answer4
        print('결제 수단을 선택해주세요.')
        print('1. 현금', '2. 카드')
        answer4 = int(input('선택:'))
        print("=================음료 종류====================")
        print("1. 아이시스8.0 600원")
        print("2. 데일리 C 레몬워터 1500원")
        print("3. 옥수수 수염차 1300원")
        print("4. 칸타타 콘트라베이스 2000원")
        print("5. 트레비 1000원")
        print("6. 밀키스 800원")
        print("7. 펩시 800원")
        print("8. 핫식스 1000원")
        print("9. 칠성사이다 1000원")
        print("10. 코코리치망고 1000원")
        print("11. 립톤 복숭아아이스티 1000원")
        print("12. 트로피카나 스파클링 사과 1000원")
        print("13. 트로피카나 스파클링 포도 1000원")
        print("14. 가나 600원")
        print("15. 레쓰비 600원")
        print("16. 칸타타 프리미엄 라떼 1000원")
        print("17. 레쓰비 카페타임 1000원")
        print("18. 게토레이 800원")
        print("19. 코코팜 포도 800원")
        print("20. 잔치집식혜 800원")
        print("==============================================")
        if answer4 == 1:
            cost().money_()
        else:
            customer().start()
    # 고객이 음료를 고를 것인지 묻는 함수
    def hi(self):
        print("==============================================")
        print("안녕하세요 고객님!")
        print("음료를 고르시겠습니까?")
        print("1. yes", "2. no")
        answer3 = int(input("선택 :"))
        print("==============================================")
        if answer3 == 1:
            customer().payment()
        elif answer3 == 2:
            print("안녕히가세요.")
            print("==============================================")
            who()
        else :
            print("잘못 고르셨습니다.")
            print("==============================================")
            customer().hi()
    # 고객과 작별인사를 하고 재정비를 하는 함수
    def bye(self):
        print("이용해주셔서 감사합니다.\n", "안녕히가세요!")
        print("==============================================")
        print("==============================================")
        print("정리중입니다. 잠시만 기다려주세요.")
        print("==============================================")
        print("==============================================")
        who()

# 맨 처음에 사용자가 주인인지 고객인지 묻는 함수
def who():
    print("==============================================")
    print('당신은 누구십니까?')
    print('1. 주인', '2. 고객')
    answer1 = int(input('선택:'))
    print("==============================================")
    if answer1 == 1:
        owner().passwd()
    else:
        customer().hi()

who()
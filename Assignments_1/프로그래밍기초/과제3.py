class BankAccount:
    def __init__(self, name, number, balance):
        self.__balance = balance
        self.name = name
        self.number = number
    def withdraw1(self, amount):
        self.__balance -= amount
        return self.__balance
    def withdraw2(self, amount):
        self.__balance -= amount
        return self.__balance
    def withdraw3(self, amount):
        self.__balance -= amount
        return self.__balance
    def withdraw4(self, amount):
        self.__balance -= amount
        return self.__balance
    def withdraw5(self, amount):
        self.__balance -= amount
        return self.__balance
    def deposit(self, amount):
        self.__balance += amount
        return self.__balance

class SavingsAccount(BankAccount) :
    def __init__(self, name, number, balance, interest_rate):
        super().__init__( name, number, balance)
        self.__balance = balance
        self.interest_rate =interest_rate        
    def set_interest_rate(self, interest_rate):
        self.interest_rate = interest_rate        
    def get_interest_rate(self):
        return self.interest_rate
    def add_interest1(self):
        self.__balance += self.__balance*self.interest_rate
        print("홍길동의 저축예금의 잔액 =", a1.__balance)
    def add_interest2(self):
        self.__balance += self.__balance*self.interest_rate
        print("세종대왕의 저축예금의 잔액 =", a2.__balance)
    def add_interest3(self):
        self.__balance += self.__balance*self.interest_rate
        print("심사임당의 저축예금의 잔액 =", a3.__balance)        
    def add_interest4(self):
        self.__balance += self.__balance*self.interest_rate
        print("이이의 저축예금의 잔액 =", a4.__balance)        
    def add_interest5(self):
        self.__balance += self.__balance*self.interest_rate
        print("이황의 저축예금의 잔액 =", a5.__balance)
        
        list = [a1.__balance, a2.__balance, a3.__balance, a4.__balance, a5.__balance]
        Max = max(list)
        if Max==a1.__balance:
            print("저축예금자 중 최고액의 잔액 보유자는", a1.name, "\n")
        elif Max==a2.__balance:
            print("저축예금자 중 최고액의 잔액 보유자는", a2.name, "\n")
        elif Max==a3.__balance:
            print("저축예금자 중 최고액의 잔액 보유자는", a3.name, "\n")
        elif Max==a4.__balance:
            print("저축예금자 중 최고액의 잔액 보유자는", a4.name, "\n")
        else:
            print("저축예금자 중 최고액의 잔액 보유자는", a5.name, "\n")
class CheckingAccount(BankAccount) :
    def __init__(self, name, number, balance):
        super().__init__( name, number, balance)
        self.__balance = balance
        self.withdraw_charge = 10000 # 수표 발행 수수료        
    def withdraw1(self, amount):
        a6.__balance = BankAccount.withdraw1(self, amount + self.withdraw_charge)
        print("김철수의 당좌예금의 잔액 =", a6.__balance)        
    def withdraw2(self, amount):
        a7.__balance = BankAccount.withdraw2(self, amount + self.withdraw_charge)
        print("김씨의 당좌예금의 잔액 =", a7.__balance)        
    def withdraw3(self, amount):
        a8.__balance = BankAccount.withdraw3(self, amount + self.withdraw_charge)
        print("이씨의 당좌예금의 잔액 =", a8.__balance)        
    def withdraw4(self, amount):
        a9.__balance = BankAccount.withdraw4(self, amount + self.withdraw_charge)
        print("홍씨의 당좌예금의 잔액 =", a9.__balance)
    def withdraw5(self, amount):
        a10.__balance = BankAccount.withdraw5(self, amount + self.withdraw_charge)
        print("조씨의 당좌예금의 잔액 =", a10.__balance)
        
        list = [a6.__balance, a7.__balance, a8.__balance, a9.__balance, a10.__balance]
        Max = max(list)
        if Max==a6.__balance:
            print("당좌예금자 중 최고액의 잔액 보유자는", a6.name)
        elif Max==a7.__balance:
            print("당좌예금자 중 최고액의 잔액 보유자는", a7.name)
        elif Max==a8.__balance:
            print("당좌예금자 중 최고액의 잔액 보유자는", a8.name)
        elif Max==a9.__balance:
            print("당좌예금자 중 최고액의 잔액 보유자는", a9.name)
        else :
            print("당좌예금자 중 최고액의 잔액 보유자는", a10.name)


a1 = SavingsAccount("홍길동", 111111, 132400, 0.05)
a2 = SavingsAccount("세종대왕", 222222, 54000, 0.05)
a3 = SavingsAccount("심사임당", 333333, 234000, 0.05)
a4 = SavingsAccount("이이", 444444, 567000, 0.05)
a5 = SavingsAccount("이황", 555555, 34000, 0.05)
a1.add_interest1()
a2.add_interest2()
a3.add_interest3()
a4.add_interest4()
a5.add_interest5()

a6 = CheckingAccount("김철수", 666666, 1000000)
a7 = CheckingAccount("김씨", 777777, 2000000)
a8 = CheckingAccount("이씨", 888888, 3000000)
a9 = CheckingAccount("홍씨", 999999, 4000000)
a10 = CheckingAccount("조씨", 000000, 5000000)
a6.withdraw1(90000)
a7.withdraw2(80000)
a8.withdraw3(70000)
a9.withdraw4(60000)
a10.withdraw5(50000)

print('\nprivate 변수로 만들면 외부로부터의 접근이 차단된다.')

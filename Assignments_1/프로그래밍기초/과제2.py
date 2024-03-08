class BankAccount:
    def __init__(self, name, number, balance):
        self.balance = balance
        self.name = name
        self.number = number
    def withdraw(self, amount):
        self.balance -= amount
        return self.balance
    def deposit(self, amount):
        self.balance += amount
        return self.balance
    
class SavingsAccount(BankAccount) :
    def __init__(self, name, number, balance, interest_rate):
        super().__init__( name, number, balance)
        self.interest_rate =interest_rate
    def set_interest_rate(self, interest_rate):
        self.interest_rate = interest_rate
    def get_interest_rate(self):
        return self.interest_rate
    def add_interest(self): # 예금에 이자를 더한다. 
        self.balance += self.balance*self.interest_rate
        
class CheckingAccount(BankAccount) :
    def __init__(self, name, number, balance):
        super().__init__( name, number, balance)
        self.withdraw_charge = 10000 # 수표 발행 수수료
    def withdraw(self, amount):
        return BankAccount.withdraw(self, amount + self.withdraw_charge)

a1 = SavingsAccount("홍길동", 111111, 132400, 0.05)
a1.add_interest()
print("홍길동의 저축예금의 잔액 =", a1.balance)

a2 = SavingsAccount("세종대왕", 222222, 54000, 0.05)
a2.add_interest()
print("세종대왕의 저축예금의 잔액 =", a2.balance)

a3 = SavingsAccount("심사임당", 333333, 234000, 0.05)
a3.add_interest()
print("심사임당의 저축예금의 잔액 =", a3.balance)

a4 = SavingsAccount("이이", 444444, 567000, 0.05)
a4.add_interest()
print("이이의 저축예금의 잔액 =", a4.balance)

a5 = SavingsAccount("이황", 555555, 34000, 0.05)
a5.add_interest()
print("이황의 저축예금의 잔액 =", a5.balance, '\n')

a6 = CheckingAccount("김철수", 666666, 1000000)
a6.withdraw(90000)
print("김철수의 당좌예금의 잔액 =", a6.balance)

a7 = CheckingAccount("김씨", 777777, 2000000)
a7.withdraw(800000)
print("김씨의 당좌예금의 잔액 =", a7.balance)

a8 = CheckingAccount("이씨", 888888, 3000000)
a8.withdraw(70000)
print("이씨의 당좌예금의 잔액 =", a8.balance)

a9 = CheckingAccount("홍씨", 999999, 4000000)
a9.withdraw(60000)
print("홍씨의 당좌예금의 잔액 =", a9.balance)

a10 = CheckingAccount("조씨", 000000, 5000000)
a10.withdraw(50000)
print("조씨의 당좌예금의 잔액 =", a10.balance)

list = [a1.balance, a2.balance, a3.balance, a4.balance, a5.balance, a6.balance, a7.balance, a8.balance, a9.balance, a10.balance]
Max = max(list)
if Max==a1.balance:
    print("\n최고액의 잔액 보유자 :", a1.name)
elif Max==a2.balance:
    print("\n최고액의 잔액 보유자 :", a2.name)
elif Max==a3.balance:
    print("\n최고액의 잔액 보유자 :", a3.name)
elif Max==a4.balance:
    print("\n최고액의 잔액 보유자 :", a4.name)
elif Max==a5.balance:
    print("\n최고액의 잔액 보유자 :", a5.name)
elif Max==a6.balance:
    print("\n최고액의 잔액 보유자 :", a6.name)
elif Max==a7.balance:
    print("\n최고액의 잔액 보유자 :", a7.name)
elif Max==a8.balance:
    print("\n최고액의 잔액 보유자 :", a8.name)
elif Max==a9.balance:
    print("\n최고액의 잔액 보유자 :", a9.name)
else :
    print("\n최고액의 잔액 보유자 :", a10.name)

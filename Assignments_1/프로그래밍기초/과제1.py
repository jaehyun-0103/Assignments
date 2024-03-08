class Person:
    def __init__ (self, name, id):
        self.name = name
        self.id = id

class Student:
    def __init__ (self, classes):
        self.classes = {'kor':None, 'math':None, 'python':None}
        
class Aver(Person, Student):
    def __init__ (self, name, id, classes):
        Person.__init__(self, name, id)
        Student.__init__(self, classes)

list=[]
classes = {'kor':10, 'math':15, 'python':20}
list.append(classes['python'])
classes = {'kor':25, 'math':30, 'python':35}
list.append(classes['python'])
classes = {'kor':40, 'math':45, 'python':50}
list.append(classes['python'])
classes = {'kor':55, 'math':60, 'python':65}
list.append(classes['python'])
classes = {'kor':70, 'math':75, 'python':80}
list.append(classes['python'])

a1 = Aver('김씨', 1, list[0])
a2 = Aver('이씨', 2, list[1])
a3 = Aver('박씨', 3, list[2])
a4 = Aver('최씨', 4, list[3])
a5 = Aver('조씨', 5, list[4])
a = sum(list) / len(list)

print('python 과목 평균 :', a, '점')
print('\npython 과목이 평균 이상인 사람 :')

if a <= list[0]:
    print(a1.name)
if a <= list[1]:
    print(a2.name)
if a <= list[2]:
    print(a3.name)
if a <= list[3]:
    print(a4.name)
if a <= list[4]:
    print(a5.name)

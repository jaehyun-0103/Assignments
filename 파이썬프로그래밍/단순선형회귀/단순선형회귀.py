import math

f = open("./Simple_Linear_Regression_Practice_Data.txt", 'r', encoding='utf-8')
data = f.readlines()
f.close()

x=[]
y=[]

for i in range(1, len(data)):
    (x_data, y_data) = data[i].split('\t', maxsplit = 2)
    y_data = y_data.replace(',','.')
    y_data = y_data.strip('\n').strip('"')
    x.append(x_data)
    y.append(y_data)
    
x = list(map(int, x))
y = list(map(float, y))

data_len = len(x)
tr_len = math.ceil(data_len*0.7)
x_train = x[0:tr_len]
x_test = x[tr_len:data_len]
y_train = y[0:tr_len]
y_test = y[tr_len:data_len]

class MLR:
    def __init__(self):
        self.w1 = 0
        self.w0 = 0
    def fit(self, x, y):
        sum_x = 0
        for i in range(0, tr_len):
            sum_x += x[i]
        aver_x = sum_x / tr_len
        sum_y = 0
        for i in range(0, tr_len):
            sum_y += y[i]
        aver_y = sum_y / tr_len
        a = 0
        for i in range(0, tr_len):
            a += x[i] * y[i]
        b = a - tr_len * aver_x * aver_y
        c = 0
        for i in range(0, tr_len):
           c += x[i] * x[i]
        d = c - tr_len * aver_x * aver_x
        self.w1 = b / d
        self.w1 = round(self.w1, 2)
        self.w0 = aver_y - self.w1 * aver_x
        self.w0 = round(self.w0, 2)
    def predict(self, x, y):
        result = 0
        for i in range(0, data_len-tr_len):
            result += ((self.w1 * x[i] + self.w0) - y[i])**2
        return result

LR = MLR()
LR.fit(x_train, y_train)
test_result = LR.predict(x_test, y_test)
print("잔차의 제곱의 합은 ", test_result)

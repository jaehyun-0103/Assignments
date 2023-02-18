import os
from sklearn.linear_model import LinearRegression as LR
import numpy as np
import pandas as pd

print(os.getcwd())

f = open("./ToyotaCorolla.txt", "r", encoding='utf-8')
data = f.readlines()
f.close()

def train_test_split(X, Y, test_size=0.25, random=False, random_seed=None):
    x=np.array(X)
    y=np.array(Y)
    indices = np.array(range(len(x)))
    
    test_size_len = round(test_size * len(x))+1
    
    if random == True:
        if random_seed != None:
            random_generator = np.random.RandomState(seed = random_seed)
            random_generator.shuffle(indices)
        else:
            np.random.shuffle(indices)
        test_indices = indices[0:test_size_len]
        train_indices = indices[test_size_len:]
        
        x_train = x[train_indices, :]
        x_test = x[test_indices, :]
        y_train = y[train_indices]
        y_test = y[test_indices]
    else:
        test_indices = indices[0:test_size_len]
        train_indices = indices[test_size_len:]
        
        x_train = x[train_indices, :]
        x_test = x[test_indices, :]
        y_train = y[train_indices]
        y_test = y[test_indices]
    return x_train, x_test, y_train, y_test

class Metric:
    def __init__(self):
        self.mse_result = 0
        self.mape_result = 0
    def MSE(self, true_y, pred_y):
        residual = true_y - pred_y
        self.mse_result = np.mean(residual**2)
        return self.mse_result
    def MAPE(self, true_y, pred_y):
        residual = true_y - pred_y
        result = (np.abs(residual)/true_y)*100
        self.mape_result = np.mean(result)
        return self.mape_result

x = []
for i in range(1, len(data)):
    data[i] = data[i].strip('\n')
    x_data = data[i].split('\t')
    x.append(x_data)
data = np.array(x, dtype ='float64')

data = pd.DataFrame(data)

data.drop([0],axis=1,inplace=True)

x = data[[2, 3, 4, 5, 6]]
y = data[1]
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random=True, random_seed = 3)

sklr = LR()
sklr.fit(x_train, y_train)
skpred = sklr.predict(x_test)
evaluator = Metric()
mse = evaluator.MSE(y_test, skpred)
mape = evaluator.MAPE(y_test, skpred)

print('MSE 결과: {:.1f}, MAPE 결과: {:.1f}'.format(mse, mape))
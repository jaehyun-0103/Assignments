import os
import numpy as np

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

class MLR:
    def __init__(self, intercept = True):
        self.coef_ = None
        self.intercept = intercept
    def fit(self, input_x, output_y):
        if self.intercept == True:
            new_input_x = self.intercept_add(input_x)
        else:
            new_input_x = input_x
        trans_x = np.transpose(new_input_x)
        inverse_x = np.linalg.inv(trans_x@new_input_x)
        self.coef_ = inverse_x@trans_x@output_y
    def intercept_add(self, input_x):
        ones = np.ones(input_x.shape[0]).reshape(-1, 1)
        result = np.concatenate([input_x, ones], axis=1)
        return result
    def predict(self, x_test):
        if self.intercept:
            new_x_test = self.intercept_add(x_test)
        else:
            new_x_test = x_test
        pred_test = new_x_test@self.coef_.reshape(-1, 1)
        return pred_test.reshape(-1)
    
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
new_data = np.array(x, dtype='float64')

y = new_data[:,1]
x = new_data[:, 2:7]
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random=True, random_seed = 3)
LR = MLR()
LR.fit(x_train, y_train)

pred = LR.predict(x_test)
evaluator = Metric()
mse = evaluator.MSE(y_test, pred)
mape = evaluator.MAPE(y_test, pred)

print('MSE 결과: {:.1f}, MAPE 결과: {:.1f}'.format(mse, mape))
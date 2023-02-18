import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression as LR

print(os.getcwd())

data1 = pd.read_csv('./wine_quality_1.csv', sep=';')
data2 = pd.read_csv('./wine_quality_2.csv', sep=';')

# merge
data = pd.merge(data1, data2, on='key', how = 'inner')
data.shape # (6767, 14)

# duplicated data 확인
data.duplicated(keep='first').sum() # 중복 확인
non_dupli_data = data.drop_duplicates(keep='first') # 중복 안된 애들
data.shape[0] - non_dupli_data.shape[0] # 몇개가 삭제되었는지 확인

# missing value 확인
non_dupli_data.isna().any() # missing value 확인
non_dupli_data.loc[:, non_dupli_data.isna().any()].isna().mean() # missing value 개수 확인 -> mean으로 평균을 냈으므로 곱하기 10의 퍼센트만큼이 missing value
non_dupli_data2 = non_dupli_data.drop(['chlorides'], axis=1) # 약 10%의 missing value가 있는 값을 삭제
non_dupli_data2.fillna(method = 'ffill',inplace=True) # missing value를 채워 넣음
non_dupli_data.isna().any() # missing value 확인 -> 모두 False

## 머신러닝 모델을 위한 데이터 셋 구성
# 변수 유형 확인 및 변경
non_dupli_data2.drop(['key'], axis=1, inplace=True) # merge할 때만 필요
non_dupli_data2['category'].unique()
non_dupli_data3 = pd.get_dummies(non_dupli_data2)

## 다중선형회귀를 위한 MLR Class, 평가지표 설정
# X, Y 나누기
Y = non_dupli_data3['quality']
X = non_dupli_data3.drop(['quality'], axis=1)
Y = Y.astype(float)

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

x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size=0.3, random=True, random_seed = 3)

sklr = LR()
sklr.fit(x_train, y_train)

# 학습된 가중치 확인
plt.figure(figsize=[18, 5])
plt.bar(x=X.columns.values, height = sklr.coef_);

skpred = sklr.predict(x_test)
evaluator = Metric()
mse = evaluator.MSE(y_test, skpred)
mape = evaluator.MAPE(y_test, skpred)

print('MSE 결과: {:.1f}, MAPE 결과: {:.1f}'.format(mse, mape))

plt.figure(figsize=[30, 5])
plt.plot(y_test, 'ko-', label='real', alpha=0.3)
plt.plot(skpred, 'bo-', label='pred', alpha=0.3)
plt.legend(loc='best')
plt.ylabel('quality')
plt.xlabel('bas')
plt.title('best')

'''
- 두 개가 차이나는 이유
    - 변수 간의 상관성이 높을 때 (x_trans@x)^-1 계산이 불안정
'''
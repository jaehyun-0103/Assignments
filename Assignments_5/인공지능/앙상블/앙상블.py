import os
import numpy as np
import pandas as pd

from sklearn.ensemble import BaggingRegressor
from sklearn.tree import DecisionTreeRegressor
from sklearn.linear_model import LinearRegression

from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score

import matplotlib.pyplot as plt
import seaborn as sns

# load data
data = pd.read_csv("./house regression.csv")
data.head()

# target variable: price
y = data['price'].values
x = data.drop('price', axis=1)
x = x.values

# train-test split
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.20, random_state=2023)

########## Fit model1 ##########
tree = DecisionTreeRegressor()
tree.fit(x_train, y_train)
y_tree = tree.predict(x_test)

#################################

########## Fit model2 ##########
treeBagging = BaggingRegressor(base_estimator=DecisionTreeRegressor(), n_estimators=100)
treeBagging.fit(x_train, y_train)
y_treeBagging = treeBagging.predict(x_test)

#################################

########## Fit model3 ##########
lr = LinearRegression()
lr.fit(x_train, y_train)
y_lr = lr.predict(x_test)

#################################

########## Fit model4 ##########
lrBagging = BaggingRegressor(base_estimator=LinearRegression(), n_estimators=100)
lrBagging.fit(x_train, y_train)
y_lrBagging = lrBagging.predict(x_test)

#################################

mse_tree = mean_squared_error(y_true=y_test, y_pred=y_tree)
mse_treeBagging = mean_squared_error(y_true=y_test, y_pred=y_treeBagging)
mse_lr = mean_squared_error(y_true=y_test, y_pred=y_lr)
mse_lrBagging = mean_squared_error(y_true=y_test, y_pred=y_lrBagging)

r2_tree = r2_score(y_test, y_tree)
r2_treeBagging = r2_score(y_test, y_treeBagging)
r2_lr = r2_score(y_test, y_lr)
r2_lrBagging = r2_score(y_test, y_lrBagging)

print('[Tree   - vanila ] R-square = {:.2f} | MSE = {:.2f}'.format(r2_tree, mse_tree))
print('[Tree   - Bagging] R-square = {:.2f} | MSE = {:.2f}'.format(r2_treeBagging, mse_treeBagging))
print('[Linear - vanila ] R-square = {:.2f} | MSE = {:.2f}'.format(r2_lr, mse_lr))
print('[Linear - Bagging] R-square = {:.2f} | MSE = {:.2f}'.format(r2_lrBagging, mse_lrBagging))


# 실제 값과 Fit model 1과 2의 예측값 비교
plt.figure(figsize=(8, 6))
plt.scatter(y_test, y_tree, s=15, alpha=0.3, color='blue', label='tree-vanila')
plt.scatter(y_test, y_treeBagging, s=15, alpha=0.3, color='red', label='tree-bagging')
plt.plot(y_test, y_test, alpha=1.0, lw=2, color='black', label='true')
plt.xlabel('true', fontsize=12)
plt.ylabel('predict', fontsize=12)
plt.legend()
plt.show()

# 실제 값과 Fit model 3과 4의 예측값 비교
plt.figure(figsize=(8, 6))
plt.scatter(y_test, y_lr, s=15, alpha=0.3, color='blue', label='linear-vanila')
plt.scatter(y_test, y_lrBagging, s=15, alpha=0.3, color='red', label='linear-bagging')
plt.plot(y_test, y_test, alpha=1.0, lw=2, color='black', label='true')
plt.xlabel('true', fontsize=12)
plt.ylabel('predict', fontsize=12)
plt.legend()
plt.show()

# 정렬된 실제 값과 Fit model 1과 2의 예측값 비교
idx = y_test.argsort()
plt.figure(figsize=(10, 6))
plt.plot(y_test[idx], color='black', alpha=1.0, label='true')
plt.plot(y_tree[idx], color='blue', alpha=0.5, label='tree-vanila')
plt.plot(y_treeBagging[idx], color='red', alpha=0.5, label='tree-bagging')
plt.legend()
plt.show()

# 정렬된 실제 값과 Fit model 3과 4의 예측값 비교
idx = y_test.argsort()
plt.figure(figsize=(10, 6))
plt.plot(y_test[idx], color='black', alpha=1.0, label='true')
plt.plot(y_lr[idx], color='blue', alpha=0.5, label='linear-vanila')
plt.plot(y_lrBagging[idx], color='red', alpha=0.5, label='linear-bagging')
plt.legend()
plt.show()
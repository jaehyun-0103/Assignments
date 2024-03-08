from sklearn.datasets import load_breast_cancer
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

dataset = load_breast_cancer(as_frame=True) # DataFrame 형태로 테이터 로드
print(dataset.DESCR) # 유방암 진단 결과 데이터셋에 대한 간략한 정보를 출력
data = dataset.frame

########## 첫 번째 데이터 분할 방식 ##########
count = int(data.shape[0]*.7)
train_data = data[:count]
test_data = data[count:]

train_x = train_data.drop(["target"], axis=1)
train_y = train_data["target"]
test_x = test_data.drop(["target"], axis=1)
test_y = test_data["target"]

############################################

########## 두 번째 데이터 분할 방식 ##########
train_data = data.sample(n=count) # 데이터프레임에서 무작위로 count 개수만큼 행을 추출
# train_data = data.sample(frac=.7, random_state=10) # 같은 의미
test_data = data.drop(train_data.index)

train_x = train_data.drop(["target"], axis=1)
train_y = train_data["target"]
test_x = test_data.drop(["target"], axis=1)
test_y = test_data["target"]

############################################

########## 세 번째 데이터 분할 방식 ##########
from sklearn.model_selection import train_test_split

train_data, test_data = train_test_split(data, test_size=.3, stratify=data["target"])
# stratify는 target의 결과가 0과 1인데, 이 0과 1의 비율을 유지

train_x, test_x, train_y, test_y = train_test_split(data.drop(["target"], axis=1), data["target"], test_size=.3, stratify=data["target"], random_state=20)

############################################

## 의사결정트리
from sklearn.tree import DecisionTreeClassifier as DT

decision_tree = DT(max_depth=3)
decision_tree.fit(train_x, train_y) # fit()은 모델을 학습시키는 메서드
pred_y = decision_tree.predict(test_x) # predict()는 모델의 예측값을 저장하는 메서드

from sklearn.metrics import classification_report, f1_score, accuracy_score, recall_score, precision_score, confusion_matrix

print(confusion_matrix(y_true=test_y, y_pred=pred_y))
print(accuracy_score(y_true=test_y, y_pred=pred_y))
print(recall_score(y_true=test_y, y_pred=pred_y))
print(f1_score(y_true=test_y, y_pred=pred_y))
print(classification_report(y_true=test_y, y_pred=pred_y))

decision_tree1 = DT(max_depth=3)
decision_tree2 = DT(max_depth=5)
decision_tree3 = DT(max_depth=10)
decision_tree4 = DT(max_depth=None)

decision_tree1.fit(train_x, train_y)
decision_tree2.fit(train_x, train_y)
decision_tree3.fit(train_x, train_y)
decision_tree4.fit(train_x, train_y)

# test_x의 예측값
pred_y1 = decision_tree1.predict(test_x)
pred_y2 = decision_tree2.predict(test_x)
pred_y3 = decision_tree3.predict(test_x)
pred_y4 = decision_tree4.predict(test_x)

# train_x의 예측값
pred_y1_train = decision_tree1.predict(train_x)
pred_y2_train = decision_tree2.predict(train_x)
pred_y3_train = decision_tree3.predict(train_x)
pred_y4_train = decision_tree4.predict(train_x)

print(classification_report(y_true=test_y, y_pred=pred_y1))
print(classification_report(y_true=train_y, y_pred=pred_y1_train))

print(classification_report(y_true=test_y, y_pred=pred_y2))
print(classification_report(y_true=train_y, y_pred=pred_y2_train))

print(classification_report(y_true=test_y, y_pred=pred_y3))
print(classification_report(y_true=train_y, y_pred=pred_y3_train))

print(classification_report(y_true=test_y, y_pred=pred_y4))
print(classification_report(y_true=train_y, y_pred=pred_y4_train))

f1_test1 = f1_score(y_true=test_y, y_pred=pred_y1)
f1_test2 = f1_score(y_true=test_y, y_pred=pred_y2)
f1_test3 = f1_score(y_true=test_y, y_pred=pred_y3)
f1_test4 = f1_score(y_true=test_y, y_pred=pred_y4)

f1_train1 = f1_score(y_true=train_y, y_pred=pred_y1_train)
f1_train2 = f1_score(y_true=train_y, y_pred=pred_y2_train)
f1_train3 = f1_score(y_true=train_y, y_pred=pred_y3_train)
f1_train4 = f1_score(y_true=train_y, y_pred=pred_y4_train)

f1_test = [f1_test1, f1_test2, f1_test3, f1_test4]
f1_train = [f1_train1, f1_train2, f1_train3, f1_train4]

plt.plot(f1_test, 'ob')
plt.plot(f1_train, 'or')
plt.show()

decision_tree3.feature_importances_ # 전체 값의 합이 1

columns = np.array(train_x.columns)
for i in decision_tree3.feature_importances_.nonzero()[0]:
  print(f"{columns[i]}: {decision_tree3.feature_importances_[i]}")
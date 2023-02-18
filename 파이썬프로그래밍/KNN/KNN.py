import numpy as np
import pandas as pd

from matplotlib import pyplot as plt

data = pd.read_csv("./iris.csv", sep=',') # 파일 읽기

def Euclidean_dist(obs1, obs2):
    dist = np.sqrt(np.sum((obs1-obs2)**2))
    return round(dist, 2)

def search_neighbors(x_train, test_sample, k = 5):
    dists_info = list()
    for index, train_sample in enumerate(x_train):
        dist = Euclidean_dist(train_sample,test_sample)
        dists_info.append([train_sample, dist, index])
    dists_info.sort(key = lambda tupe:tupe[1]) # 오름차순
    neighbors = dists_info[:k]
    return neighbors

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

Y = data['class']
X = data.drop(['class'], axis=1)

x_train, x_test, y_train, y_test = train_test_split(X, Y, test_size=0.3, random=True, random_seed = 3)

A = [6, 3.4, 4, 2]

pred=search_neighbors(x_train, A, k=5)
for i in range(5):
    print(Y[pred[i][2]])
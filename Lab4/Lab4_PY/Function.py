from abc import ABC, abstractmethod
import random

class TNumb:
    @abstractmethod
    def getSumNum(self):
        pass
    @abstractmethod
    def getFirstNum(self):
        pass
    @abstractmethod
    def getLastNum(self):
        pass

class TIntNumb(TNumb):
    def __init__(self, num):
        self.number = num

    def getFirstNum(self):
        string = str(self.number)
        if string[0] == '-':
            return int(string[1]) * -1
        else:
            return int(string[0])

    def getLastNum(self):
        string = str(self.number)
        return int(string[len(string) - 1])

    def getSumNum(self):
        string = str(self.number)
        summa = 0
        for i in range(len(string)):
            summa = summa + int(string[i])
        return summa
    def getNum(self):
        return self.number

class TRealNumb(TNumb):
    def __init__(self, num):
        self.number = num

    def getFirstNum(self):
        string = str(self.number)
        if string[0] == '-':
            return int(string[1]) * -1
        else:
            return int(string[0])

    def getLastNum(self):
        string = str(self.number)
        return int(string[len(string)-1])

    def getSumNum(self):
        string = str(self.number)
        summa = 0
        for i in range(len(string)):
            summa = summa + int(string[i])
        return summa

    def getNum(self):
        return self.number

def makeIntVec(size):
    arr = []
    for i in range(size):
        temp = TIntNumb(random.randint(-100,100))
        arr.append(temp)
    return arr

def makeRealVec(size):
    arr = []
    for i in range(size):
        num = random.uniform(-100,100)
        num = float('{:.1f}'.format(num))
        temp = TRealNumb(num)
        arr.append(temp)
    return arr

def printVec(arr):
    for i in range(len(arr)):
        print(arr[i].getNum(), end = ' ')
    print()

def findLastNumSum(arr):
    summ = 0
    for i in range(len(arr)):
        summ = summ + arr[i].getLastNum()
    return summ

def findFirstNumSum(arr):
    summ = 0
    for i in range(len(arr)):
        summ = summ + arr[i].getFirstNum()
    return summ

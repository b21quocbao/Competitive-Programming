from __future__ import print_function
import sys
import os.path
import math
import collections
import random
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
#ntest = int(input())
typeCard = ["S", "H", "C", "D"]
numCard = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
valCard = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
Card = [[], [], [], [], []]
cnt = [0, 0, 0, 0, 0]
Sum = [0, 0, 0, 0, 0]
cur = 0
l = list(range(52))
for i in range (52):
    j = random.randint(0, i + 1)
    l[i], l[j] = l[j], l[i]

def Code (x):
    print (numCard[x % 13], end = "")
    print (typeCard[x // 13], end = "")

def Add (id):
    global cur
    if (not l[cur]):
        cnt[id] += 1
    Sum[id] += valCard[l[cur] % 13]
    Card[id].append(l[cur])
    cur += 1

def Init():
    for i in range (5):
        Add (i)
        Add (i)

def printS():
    print ("Each player hand")
    for i in range (5):
        print (s[i] + "'s hand: ", end = "")
        for j in range (len(Card[i])):
            Code (Card[i][j])
            if (j < len(Card[i]) - 1):
                print (", ", end = "")
        print()
    

def Ranking():
    for i in range (5):
        while (Sum[i] + 10 <= 21 and cnt[i]):
            Sum[i] += 10
            cnt[i] -= 1
        if (Sum[i] > 21):
            Sum[i] = 21 - Sum[i]
    id = list(range(5))
    id = sorted(id, key = lambda x: Sum[x], reverse=True)
    print ("Standing:")
    for j in range (5):
        print (str(j + 1) + "." + str(s[id[j]]) + " " + str(Sum[id[j]]))
    
for itest in erange(1, ntest):
    s = []
    for i in range (5):
        s.append(input ("Enter player " + str(i + 1) + " Name: "))
    for i in range (100):
        print()
    Init()
    print ("Deal 2 initial cards for each player:")
    for i in range(5):
        picktiep = 1
        while (Sum[i] <= 21 and picktiep):
            printS()
            print (s[i] + ", do you want to pick a card, Y or N: ", end = "")
            while (1):
                c = input()
                if (c.lower() == "y"):
                    Add (i)
                    for I in range (100):
                        print()
                    break
                elif (c.lower() == "n"):
                    picktiep = 0
                    for I in range (100):
                        print()
                    break
                else:
                    print("Wrong format, Please input Y or N only: ", end = "")
    Ranking()

    



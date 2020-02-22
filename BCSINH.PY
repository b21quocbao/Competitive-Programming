import os.path
import sys
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BCSINH.inp"):
    sys.stdin = open("BCSINH.inp", "r")
    sys.stdin = open("BCSINH.out", "w")
n = int(input())
a = list()
def gen (t):
    if (t == n):
        for i in a:
            print (i, end = "")
        print()
        return
    for i in range (2):
        if (len(a) <= t):
            a.append(i)
        else:
            a[t] = i
        gen (t + 1)
gen (0)
    




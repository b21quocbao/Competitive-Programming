import os.path
import sys
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BCPERMU.inp"):
    sys.stdin = open("BCPERMU.inp", "r")
    sys.stdin = open("BCPERMU.out", "w")
n = int(input())
ok = [False] * (n + 1)
def gen (t, a):
    if (t == n):
        print(a)
    for i in range (1, n + 1):
        if not ok[i]:
            ok[i] = 1
            gen (t + 1, a * 10 + i)
            ok[i] = 0
gen (0, 0)
        
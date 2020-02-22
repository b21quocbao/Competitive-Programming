import os.path
import sys
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BCFACT.inp"):
    sys.stdin = open("BCFACT.inp", "r")
    sys.stdin = open("BCFACT.out", "w")
while (1):
    n = int(input())
    if not n:
        sys.exit()
    s = 1
    for i in range(1, n + 1):
        s *= i
    print(s)

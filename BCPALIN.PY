import os.path
import sys
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BCPALIN.inp"):
    sys.stdin = open("BCPALIN.inp", "r")
    sys.stdin = open("BCPALIN.out", "w")
test = int(input())
for i in range(test):
    s = input()
    print ("YES" if s == s[::-1] else "NO")
import os.path
import sys
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("bcvtab.inp"):
    sys.stdin = open("bcvtab.inp", "r")
    sys.stdin = open("bcvtab.out", "w")
a,b = list(map(int, input().split()))
print(a+b)

from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("coviu.inp"):
    sys.stdin = open("coviu.inp", "r")
    sys.stdin = open("coviu.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 1
#ntest = int(input())
def orderIntegerQ4b(arrInt):
    for i in arrInt:
        if i.isalpha():
            return "Khong hop le"
    if (len(arrInt) > 4):
        return "So phan tu > 4 so"
    else:
        v = []
        arrInt.sort()
        arrInt.reverse()
        for i in arrInt:
            i = str (round (float(i) * 100))
            i = i[:len(i)-2] + "." + i[len(i) - 2::]
            v.append(i)
        return " ".join(v)
for itest in erange(1, ntest):
    
    orderIntegerQ4b(["1","3","4","2"])
        
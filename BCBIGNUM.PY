from __future__ import print_function
import sys
import os.path
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BCBIGNUM.inp"):
    sys.stdin = open("BCBIGNUM.inp", "r")
    sys.stdin = open("BCBIGNUM.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
#ntest = int(input())
a = int(input())
b = int(input())
print (a + b)
print (a - b)
print (a * b)

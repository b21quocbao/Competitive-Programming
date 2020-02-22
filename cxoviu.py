from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("cxoviu.inp"):
    sys.stdin = open("cxoviu.inp", "r")
    sys.stdin = open("cxoviu.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    for i in erange (0, 100000, 500):
        print (i, end = ", ")
    print(100010)
    print (len (erange (0, 100000, 500)))
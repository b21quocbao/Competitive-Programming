from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("xcvoiu.inp"):
    sys.stdin = open("xcvoiu.inp", "r")
    sys.stdin = open("xcvoiu.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    for i in range (22):
        s = input()
        s1 = ""
        for c in s:
            if c == "\"":
                s1 += "\\"
            s1 += c
        print ("\"" + s1 + "\",")
        
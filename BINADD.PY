from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BINADD.inp"):
    sys.stdin = open("BINADD.inp", "r")
    sys.stdin = open("BINADD.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 1
ntest = int(input())
for itest in erange(1, ntest):
    s1 = input()
    s2 = input()
    v1 = []
    v2 = []
    for i in range (max (len (s2) - len (s1), 0)):
        v1.append(False)
    for i in range (max (len (s1) - len (s2), 0)):
        v2.append(False)
    v1.append(False)
    v2.append(False)
    for i in s1:
        v1.append(i == '1')
    for c in s2:
        v2.append(c == '1')
    sol = 0
    for i in range (len (v1)):
        if (v2[i]):
            for j in range(i, -1, - 1):
                v1[j] = not v1[j]
                if (v1[j]):
                    sol = max (sol, i - j + 1)
                    break
    print (sol)
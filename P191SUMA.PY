from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("P191SUMA.inp"):
    sys.stdin = open("P191SUMA.inp", "r")
    sys.stdin = open("P191SUMA.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    n = int(input())
    l = list()
    l.append(0)
    l.extend(list (map(int, input().split())))
    ok = [0] * (n + 1)
    cn = 0
    sol = 0
    for i in erange (1,n):
        if (l[i] <= i):
            cn += 1
        else:
            ok[l[i]] += 1
        cn += ok[i]
        if (cn == i):
            sol += 1
    print(sol)
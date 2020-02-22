from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BCTOHOP.inp"):
    sys.stdin = open("BCTOHOP.inp", "r")
    sys.stdin = open("BCTOHOP.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    n, k = list(map(int, input().split()))
    a = [0] * (k + 1)
    def sinh (t):
        if (t > k):
            for i in erange(1,k):
                print(a[i], end = " ")
            print()
            return
        for i in erange (a[t - 1] + 1, n):
            a[t] = i
            sinh (t + 1)
    sinh (1)
    
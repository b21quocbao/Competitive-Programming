from __future__ import print_function
import sys
import os.path
import math
import collections
import bisect
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("test_bisect.inp"):
    sys.stdin = open("test_bisect.inp", "r")
    sys.stdin = open("test_bisect.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    v = [1, 1, 1, 3, 3, 3, 4, 4, 4]
    print (bisect.bisect_right(v, 3))
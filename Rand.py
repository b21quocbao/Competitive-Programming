from __future__ import print_function
import random
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("Rand.inp"):
    sys.stdin = open("Rand.inp", "r")
    sys.stdin = open("Rand.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    n = random.randint(50, 100)
    m = random.randint(50, 100)
    for i in range (n):
        print (random.randint(0, 1), end = "")
    print()
    for i in range (m):
        print (random.randint(0, 1), end = "")

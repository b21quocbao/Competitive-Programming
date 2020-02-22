from __future__ import print_function
import sys
import os.path
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("SUMDIV.inp"):
    sys.stdin = open("SUMDIV.inp", "r")
    sys.stdin = open("SUMDIV.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
ntest = int(input())
for itest in range (1, ntest + 1):
    n = int (input())
    sol = 0
    i = 1
    x = math.trunc(math.sqrt(n))
    while (i <= x):
        if (n % i == 0):
            sol += i
            if (i != n // i):
                sol += n // i
        i += 1
    print (sol)
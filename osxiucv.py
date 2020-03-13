from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("osxiucv.inp"):
    sys.stdin = open("osxiucv.inp", "r")
    sys.stdin = open("osxiucv.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    print(400000)
    for i in range (400000):
        print(1, end = ' ');
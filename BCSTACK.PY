from __future__ import print_function
import sys
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
import os.path
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BCSTACK.inp"):
    sys.stdin = open("BCSTACK.inp", "r")
    sys.stdin = open("BCSTACK.out", "w")
v = list()
def process(s):
    if s == "init":
        v.clear()
    elif s[0:4] == "push":
        x = int (s[5::])
        v.append(x)
    elif s == "pop":
        if (len(v)):
            v.pop()
    elif s == "top":
        if (len (v)):
            print(v[len(v) - 1])
        else:
            print(-1)
    elif s == "size":
        print(len(v))
    elif s == "empty":
        print(0 if len (v) else 1)
    else:
        sys.exit()
while (1):
    process (input())
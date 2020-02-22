from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BCQUEUE.inp"):
    sys.stdin = open("BCQUEUE.inp", "r")
    sys.stdin = open("BCQUEUE.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    qu = collections.deque()
    n = int (input())
    for i in range(n):
        l = list(map(int, input().split()))
        if (l[0] == 1):
            print(len(qu))
        elif (l[0] == 2):
            print("NO" if len(qu) else "YES")
        elif (l[0] == 3):
            qu.append(l[1])
        elif (l[0] == 4):
            if (len(qu)):
                qu.popleft()
        elif (l[0] == 5):
            if (len(qu)):
                print(qu[0])
            else:
                print(-1)
        else:
            if (len(qu)):
                print(qu[len(qu) - 1])
            else:
                print(-1)


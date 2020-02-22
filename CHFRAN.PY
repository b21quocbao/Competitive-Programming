from __future__ import print_function
import sys
import os.path
import math
import collections
import bisect
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("CHFRAN.inp"):
    sys.stdin = open("CHFRAN.inp", "r")
    sys.stdin = open("CHFRAN.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    n = int(input())
    l = []
    r = []
    v = []
    for i in range (n):
        a, b = list(map(int, input().split()))
        l.append(a)
        r.append(b)
        v.append (a)
        v.append(b)
    v.sort()
    v = list (set(v))
    for i in l:
        i = bisect.bisect_left(v, i) + 1
    for i in r:
        i = bisect.bisect_left(v, i) + 1
    id = list (range (1, n + 1))
    id.sort (lambda i : l[i], reversed = True)
    f = [-1] * (2 * n)
    def mi (a, b, x):
        if (a == - 1 and b == - 1):
            return - 1
        if (a == - 1):
            return b + x
        if (b == - 1):
            return a + x
        return min (a + x, b + x)
    for i in range (n):
        if (not i): 
            f[l[id[i]]][1] = 0
            f[l[id[i]]][0] = - 1
            continue
        else:
            f[l[id[i]]][0] = mi (f[l[id[i - 1]]][0], f[l[id - 1]][1], 1)
            if (r[id[i]] >= l[id[i - 1]]):
                f[l[id[i]]][1] = f[l[id - 1]][1]
            else:
                f[l[id[i]]][1] = i
    
    

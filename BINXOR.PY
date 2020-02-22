from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BINXOR.inp"):
    sys.stdin = open("BINXOR.inp", "r")
    sys.stdin = open("BINXOR.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
ntest = int(input())
for itest in erange(1, ntest):
    n = int(input())
    s1 = input()
    s2 = input()
    a1 = s1.count ('1')
    a0 = s1.count ('0')
    b1 = s2.count ('1')
    b0 = s2.count ('0')
    ma = min (a0, b1) + min (a1, b0)
    mi = ma - 2 * min (min (a0, b1), min (a1, b0))
    sol = 0
    mod = int(1e9) + 7
    gt = [1]
    for i in range (1, n + 1):
        gt.append((gt[-1] * i) % mod)
    def C (n, k):
        return (gt[n] * pow (gt[k], mod - 2, mod) * pow (gt[n - k], mod - 2, mod)) % mod
    for i in range (ma, mi - 1, -2):
        sol += C (n, i)
        if (sol >= mod):
            sol -= mod
    print(sol % mod)
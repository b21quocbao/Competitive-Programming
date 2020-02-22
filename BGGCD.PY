from __future__ import print_function
import sys
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
import os.path
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("BGGCD.inp"):
    sys.stdin = open("BGGCD.inp", "r")
    sys.stdin = open("BGGCD.out", "w")
while (1):
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        sys.exit()
    print (math.gcd(a, b), a * b // math.gcd (a, b))


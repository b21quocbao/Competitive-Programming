from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("P191SUMB.inp"):
    sys.stdin = open("P191SUMB.inp", "r")
    sys.stdin = open("P191SUMB.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):hjkhgkhgcnbvcnbvcnvc]]]]]]]]]]][[][][][gjhgkjgkjhgutiuytiyutiuyt iy  i i   khg jhkg u7ybjn8]]
    return range (a, b + 1)  
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    s, b = list (map (int, input().split()))
    l = list (map (int, input()))
    

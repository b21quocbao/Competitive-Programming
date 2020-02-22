from __future__ import print_function
import sys
import os.path
import math
import collections
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b):
    return range (a, b + 1)
ntest = 1
#ntest = int(input())
for itest in erange(1, ntest):
    def clear():
        print ('\n' * 100)
    while (1):
        clear()
        p1 = input("Choose X or O\n")
        if (p1 == 'X' or p1 == 'O'):
            break
    if (p1 == 'X'):
        p2 = 'Y'
    else:
        p2 = 'X'
    while (1):
        clear()
        s = input("Go first or second\n")
        if (s == "first" or s == "second"):
            break
    if (s == "first"):
        p1, p2 = p2, p1
    a = ['_|_|_','_|_|_',' | | ']
    for c in a:
        print (c)
    
    
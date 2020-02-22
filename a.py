from __future__ import print_function
import sys
import os.path
import math
import collections
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("a.inp"):
    sys.stdin = open("a.inp", "r")
    sys.stdin = open("a.out", "w")
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 1
#ntest = int(input())
def textToNumber(word):
    so = ['khong', 'mot', 'hai', 'ba', 'bon', 'nam', 'sau', 'bay', 'tam']
    donvi = ['nghin', 'tram', 'chuc', 'don vi']
    s = 0
    cn = 0
    for y in word.split(', '):
        ok = 0
        if (len(y.split()) == 3 and y.split()[1] == 'don' and y.split()[2] == 'vi'):
            ok = 1
        for x in y.split():
            if (x == "don" and ok):
                break;
            cn += 1
            if (cn % 2):
                if (not x.lower() in so):
                    return "Khong hop le"
                s = s * 10 + so.index(x.lower())
            if (cn % 2 == 0):
                if (not x.lower() in donvi):
                    return "Khong hop le"
                if (cn == 2):
                    i = donvi.index(x.lower())
                else:
                    i += 1
                    if (i >= 4 or x.lower() != donvi[i]):
                        return "Khong hop le"
    return s
for itest in erange(1, ntest):
    print (textToNumber("Mot tram, hai chuc, ba don vi"))

    

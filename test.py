import os.path
import sys
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("abc.inp"):
    sys.stdin = open("abc.inp", "r")
    sys.stdout = open("abc.out", "w")
import os.path
import sys
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("HELLOPOJ.inp"):
    sys.stdin = open("HELLOPOJ.inp", "r")
    sys.stdin = open("HELLOPOJ.out", "w")
print("Hello PTIT OJ.")
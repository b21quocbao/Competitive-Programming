import os.path
import sys
import math
if os.path.isfile("test.inp"):
    sys.stdin = open("test.inp", "r")
    sys.stdout = open("test.out", "w")
elif os.path.isfile("bcprime.inp"):
    sys.stdin = open("bcprime.inp", "r")
    sys.stdin = open("bcprime.out", "w")
n = int(input())
if (n < 2):
    print("NO");
    sys.exit()
for i in range(2,int(math.trunc(math.sqrt(n)) + 1)):
    if (n % i == 0):
        print("NO")
        sys.exit()
print("YES")

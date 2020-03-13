from __future__ import print_function
def Ran(a, b):
    return random.randint(a, b)

# PHAI KHAI BAO TRUOC KHI SINH TEST
# Check answer in trau file in test.ans
# Check answer in original file in test.out

fn = "1312e"
TimeLimit = 1  #second
python = 0
python_trau = 0
checker = 0

def work():
    n = Ran (1, 10)
    print (n)
    for i in range (n):
        print (Ran (1, 5), end = ' ')

def Checker():
    pass


#KET THUC KHAI BAO








import os
import timeit
import random
import sys
import filecmp
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)   

def chfile(s):
    return "\"" + s + "\""
def run():
    if (python_trau):
        os.system ("python " + fn + "_trau" + ".PY")
    else:
        os.system(fn + "_trau.exe")
    start = timeit.default_timer()
    if (python):
        os.system("python " + fn + ".PY")
    else:
        os.system(fn + ".exe")
    stop = timeit.default_timer()
    return stop - start
def cmp_lines(path_1, path_2):
    l1 = l2 = True
    with open(path_1, 'r') as f1, open(path_2, 'r') as f2:
        while l1 and l2:
            l1 = f1.readline()
            l2 = f2.readline()
            l1 = l1.rstrip('\n')
            l2 = l2.rstrip('\n')
            if l1 != l2:
                return False
    return True

out = os.path.dirname(os.path.realpath(__file__)) + "\\" + "test.out"
inp = os.path.dirname(os.path.realpath(__file__)) + "\\" + "test.inp"
ans = os.path.dirname(os.path.realpath(__file__)) + "\\" + "test.ans"


def gen():
    cn = 0
    while (1):
        sys.stdout = open(inp, "w")
        work()
        sys.stdout.close()
        x = run()
        if (x > TimeLimit):
            eprint("TLE")
            sys.exit()
        if ((checker and (not Checker())) or ((not checker) and (not cmp_lines(out, ans)))):
            eprint("WA")
            sys.exit()
        cn += 1
        if (cn % 25 == 0):
            eprint (cn)
gen()
# print(inp)


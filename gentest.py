from __future__ import print_function
import os
import timeit
import random
import sys
import filecmp
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)   
def Ran(a, b):
    return random.randint(a, b)
def chfile(s):
    return "\"" + s + "\""
def run():
    if (python_trau):
        os.system ("python " + chfile(trau + ".PY"))
    else:
        os.system(chfile(trau + ".exe"))
    start = timeit.default_timer()
    if (python):
        os.system("python " + chfile(filename + ".PY"))
    else:
        os.system(chfile(filename + ".exe"))
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
filename = os.path.dirname(os.path.realpath(__file__)) + "\\" + os.path.dirname(os.path.realpath(__file__)).split("\\")[len(os.path.dirname(os.path.realpath(__file__)).split("\\")) - 1]
trau = os.path.dirname(os.path.realpath(__file__)) + "\\" + os.path.dirname(os.path.realpath(__file__)).split("\\")[len(os.path.dirname(os.path.realpath(__file__)).split("\\")) - 1] + "_trau"
out = os.path.dirname(os.path.realpath(__file__)) + "\\" + "test.out"
inp = os.path.dirname(os.path.realpath(__file__)) + "\\" + "test.inp"
ans = os.path.dirname(os.path.realpath(__file__)) + "\\" + "test.ans"





# PHAI KHAI BAO TRUOC KHI SINH TEST
TimeLimit = 1  #giay
python = 0
python_trau = 1
checker = 0

def work():
    pass

def Checker():
    pass


#KET THUC KHAI BAO




def gen():
    cn = 0
    while (1):
        sys.stdout = open(inp, "w")
        work()
        sys.stdout.close()
        if (run() > TimeLimit):
            eprint("TLE")
            sys.exit()
        if ((checker and (not Checker())) or ((not checker) and (not cmp_lines(out, ans)))):
            eprint("WA")
            sys.exit()
        cn += 1
        if (cn % 25 == 0):
            eprint (cn)
gen()


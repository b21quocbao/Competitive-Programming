from __future__ import print_function
import sys
import os.path
import math
import collections
def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)
def erange (a, b, x = 1):
    return range (a, b + 1, x)
ntest = 100000
win = 0
#ntest = int(input())
 
ok = [[0] * 10 for i in range (2)]

def reset():
    for i in range (100):
        print()

def Winner (s):
    printS()
    print ("Congrat " + s + ", you are the winner!")
    while (1):
        print ("DO YOU WANT TO REPLAY? PRESS Y TO REPLAY OR N TO EXIT: ", end = "")
        s = input()
        if (s.upper() == "Y"): 
            return 1
        if (s.upper() == "N"): 
            sys.exit()

def check(id, s):
    #Row check
    if (ok[id][1] and ok[id][2] and ok[id][3]) or (ok[id][4] and ok[id][5] and ok[id][6]) or (ok[id][7] and ok[id][8] and ok[id][9]):
        if (Winner (s)):
            return 1
    #Col check
    if (ok[id][1] and ok[id][4] and ok[id][7]) or (ok[id][2] and ok[id][5] and ok[id][8]) or (ok[id][3] and ok[id][6] and ok[id][9]):
        if (Winner(s)):
            return 1
    #diagonal check
    if (ok[id][1] and ok[id][5] and ok[id][9]) or (ok[id][3] and ok[id][5] and ok[id][7]):
        if (Winner (s)):
            return 1
    return 0

pos = [(0, 0), (4, 3), (4, 9), (4, 15), (8, 3), (8, 9), (8, 15), (12, 3), (12, 9), (12, 15)]
S = []
S.append("  Available move   ")
S.append("")
S.append(" ----------------- ")
S.append("|     |     |     |")
S.append("|  1  |  2  |  3  |")
S.append("|     |     |     |")
S.append("|-----------------|")
S.append("|     |     |     |")
S.append("|  4  |  5  |  6  |")
S.append("|     |     |     |")
S.append("|-----------------|")
S.append("|     |     |     |")
S.append("|  7  |  8  |  9  |")
S.append("|     |     |     |")
S.append(" ----------------- ")
h = []
h.append("  TIC - TAC - TOE  ")
h.append("")
h.append(" ----------------- ")
h.append("|     |     |     |")
h.append("|     |     |     |")
h.append("|     |     |     |")
h.append("|-----------------|")
h.append("|     |     |     |")
h.append("|     |     |     |")
h.append("|     |     |     |")
h.append("|-----------------|")
h.append("|     |     |     |")
h.append("|     |     |     |")
h.append("|     |     |     |")
h.append(" ----------------- ")
S1 = S.copy()
h1 = h.copy()

def printS ():
    reset()
    for i in range (len(S)):
        print (S[i] + "          " + h[i])

def turn (id, s1, s2):
    printS()
    print(s1 + ", " + "please choose where to place " + s2 + ": ", end = "")
    n = 1
    while (1):
        s = input()
        if (not s.isdigit()):
            print("Please enter a number !: ", end = "")
            continue
        n = int (s)
        if (not (n >= 1 and n <= 9)):
            print ("Please enter a number between 1 and 9: ", end = "")
            continue
        if (ok[0][n] or ok[1][n]):
            print("The cell have already occupied, please choose another cell: ", end = "")
            continue
        break
    ok[id][n] = 1
    S[pos[n][0]] = S[pos[n][0]][:pos[n][1]] + " " + S[pos[n][0]][pos[n][1] + 1:]
    h[pos[n][0]] = h[pos[n][0]][:pos[n][1]] + s2 + h[pos[n][0]][pos[n][1] + 1:]
    return check(id, s1)

while (1):
    reset()
    S = S1.copy()
    h = h1.copy()
    first = ""
    second = ""
    for i in range (2):
        for j in range (10):
            ok[i][j] = 0
    while (1):
        c = input("Please pick a marker 'X' or 'O': ")
        if (c == "X" or c == "O"):
            if (c == "X"):
                second = "P2"
                first = "P1"
            else:
                first = "P2"
                second = "P1"
            break
        else:
            print("Please enter only X or O!")
    Ok = 0
    cn = 0
    for i in range (9):
        cn += 1
        if (turn (0, first, "X")):
            Ok = 1
            break
        if (cn == 9):
            break
        cn += 1
        if (turn (1, second, "O")):
            Ok = 1
            break
    if (not Ok):
        reset()
        print ("Draw")
        while (1):
            print ("DO YOU WANT TO REPLAY? PRESS Y TO REPLAY: ", end = "")
            s = input()
            if (s == "Y"): 
                break
    Ok =0
    
    

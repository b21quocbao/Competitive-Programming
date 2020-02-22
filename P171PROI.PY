import sys
import os.path
fn = ''
if os.path.isfile('test.inp'):
    sys.stdin = open('test.inp', 'r') 
    sys.stdout = open('test.out', 'w')
elif os.path.isfile(fn + '.inp'):
    sys.stdin = open(fn + '.inp', 'r') 
    sys.stdout = open(fn + '.out', 'w') 
def combinations1(n):
    fibs = []
    a, b, index = 1, 2, 1
    while a <= n:
        fibs.append((index, a))
        a, b, index = b, a + b, index + 1

    indices = []
    for index, fib in reversed(fibs):
        if n >= fib:
            n -= fib
            indices.append(index)
    indices = indices[::-1]
    # for i in indices:
    #     print (i)
    signature = [i2 - i1 for i1, i2 in zip([-1] + indices[:-1], indices)]
    # print()
    total, top_set = 1, 1
    signature[0] -= 1
    for l in signature:
        print (l)
        total, top_set = ((l + 2) // 2 * total - (l + 1) % 2 * top_set, total)
        # print (total, top_set)
    # print()
    return total 
ntest = int(input())
# print(ntest, "**")
for _ in range(ntest):
    n = int(input())
    # print (n, "****")
    print (combinations1 (n))   
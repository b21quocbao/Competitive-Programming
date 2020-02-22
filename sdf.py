import sys
import os.path
fn = ''
if os.path.isfile('test.inp'):
    sys.stdin = open('test.inp', 'r') 
    sys.stdout = open('test.out', 'w')
elif os.path.isfile(fn + '.inp'):
    sys.stdin = open(fn + '.inp', 'r') 
    sys.stdout = open(fn + '.out', 'w')    
def combinations(n):
    """Number of ways to write n as a sum of positive
    Fibonacci numbers with distinct indices.
    """
    # Find Fibonacci numbers not exceeding n.
    fibs = []
    fib, next_fib = 0, 1
    while fib <= n:
        fibs.append(fib)
        fib, next_fib = next_fib, fib + next_fib

    # Compute greedy representation, most significant bit first.
    greedy = []
    for fib in reversed(fibs):
        greedy.append(fib <= n)
        if greedy[-1]:
            n -= fib
    # greedy = reversed(greedy)
    # Iterate to compute number of rewrites.
    print(greedy)
    x, y, z = 1, 0, 0
    for bit in reversed(greedy):
        x, y, z = (0, y + z, x) if bit else (x + z, z, y)
        print (bit, x, y, z)
    print()    
    return y + z
ntest = int(input())
# print(ntest, "**")
for _ in range(ntest):
    n = int(input())
    # print (n, "****")
    print (combinations (n))
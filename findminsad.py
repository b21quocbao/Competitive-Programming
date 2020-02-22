def findMinSadness(n, a):
    for i in range(len(a)):
        a[i] -= i + 1
    a.sort()
    s = 0
    for i in a:
        s += i - a[len(a) / 2]
    return s

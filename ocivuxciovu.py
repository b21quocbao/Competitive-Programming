f = [[-1 for i in range(100)] for j in range (100)]
def dp (n, k):
    if (k < 0):
        return 0
    if (n == 0):
        return (k == 0)
    if (f[n][k] != - 1):
        return f[n][k]
    f[n][k] = 0
    for i in range (0, 10):
        f[n][k] += dp (n - 1, k - i)
    return f[n][k]
def findKeyNumber(nN, nK):
    if (nK > 90):
        return 0
    return dp (nN, nK)
print (dp(3, 2))
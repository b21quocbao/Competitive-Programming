#include<iostream>
#include<cstring>
#include <vector>

using namespace std;
int tt, ntest = 1;
int f[(1 << 20)];

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > d (n, vector<int> (1 << n, (int)(1e9)));
    vector<vector<int> > a (n, vector<int> (n));
    vector<int> lo (1 << (n - 1));
    vector<int> f (1 << n, (int)(1e9));
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> a[i][j];
    int sol = f[0];
    f[(1 << n) - 1] = 0;
    for (int i = 0; i < n; ++ i)
    lo[1 << i] = i;
    for (int i = 1; i < (1 << n); ++ i)
    for (int j = 0; j < n; ++ j)
    d[j][i] = min (d[j][i - (i & - i)], a[j][lo[i & - i]]);
    for (int i = (1 << n) - 1; i >= 0; -- i)
    {
        if (__builtin_popcount (i) <= k) 
        {
            if (__builtin_popcount (i) == k)
            sol = min (sol, f[i]);
            continue;
        }
        for (int j = i; j; j -= j & - j)
        {
            int k = lo[j & - j];
            f[i ^ (1 << k)] = min (f[i ^ (1 << k)], f[i] + d[k][i ^ (1 << k)]);
        }
    }
    cout << sol;
}
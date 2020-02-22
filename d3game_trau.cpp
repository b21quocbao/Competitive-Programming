#include<bits/stdc++.h>
#define taskname "d3game"
using namespace std;

int f[51][51][51][3][3];

int dp(int m0, int m1, int m2, int r1, int r2)
{
    int &ret = f[m0][m1][m2][r1][r2];
    if (~ret) return ret;
    if (!m0 && !m1 && !m2)
    {
        if (!r1 && r2) return ret = 1;
        if (r1 && !r2) return ret = 2;
        return ret = 0;
    }
    int ok0 = 0, ok1 = 0, ok2 = 0;
    if (m0) ok0 = dp(m0 - 1, m1, m2, r2, r1);
    if (m1) ok1 = dp(m0, m1 - 1, m2, r2, (r1 + 1) % 3);
    if (m2) ok2 = dp(m0, m1, m2 - 1, r2, (r1 + 2) % 3);
    if (ok0 == 2 || ok1 == 2 || ok2 == 2) return ret = 1;
    if (!ok0 || !ok1 || !ok2) return ret = 0;
    return ret = 2;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);	cout.tie(nullptr);
freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
    int n;
    while (cin >> n)
    {
        vector<int> m(3, 0);
        for (int i = 1; i <= n; ++i)
        {
            int x;  cin >> x;
            x %= 3;
            if (x < 0) x += 3;
            ++m[x];
        }
        fill(&f[0][0][0][0][0], &f[m[0]][m[1]][m[2]][2][2] + 1, -1);
        int ans = dp(m[0], m[1], m[2], 0, 0);
        if (!ans) cout << "DRAW\n";
        else if (ans == 1) cout << "FIRST\n";
        else cout << "SECOND\n";
    }
}

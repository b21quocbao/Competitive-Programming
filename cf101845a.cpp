#include<bits/stdc++.h>
#define taskname "VirtualACM"
#define sz(a) static_cast<int>(a.size())
#define int long long
using namespace std;

const int MOD = 1e9 + 7;
typedef vector< vector<int> > matrix;
matrix p = {
    {16, 9, 4, 1, 0},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0}
};
matrix r = {
    {1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};
int n, ans;

matrix operator *(matrix a, matrix b)
{
    matrix c;
    c.resize(5, vector<int>(5, 0));
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
        {
            c[i][j] = 0;
            for (int k = 0; k < 5; ++k)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
        }
    return c;
}

matrix pow(int n)
{
    if (n == 1) return p;
    matrix t = pow(n / 2);
    t = t * t;
    if (n & 1) return t * p;
    return t;
}

void Enter()
{
    cin>>n;
}

void Init()
{
    if (n / 10) r = pow(n / 10) * r;
    ans = 0;
}

void Solve()
{
    for (int i = 0; i < 4; ++i)
        ans += r[i][0];
    if (n % 10 < 5) ans += r[4][0];
}

void PrintRes()
{
    cout<<ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
    Enter();
    Init();
    Solve();
    PrintRes();
}
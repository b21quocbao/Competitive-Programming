#include <bits/stdc++.h>

#define fn "test"
#define fn1 "COW"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int h[30];
vector<int> e[30], s[30];
int lo[(1 << 20) + 10];
long long f[(1 << 20) + 10];
int Vt[30][mn];

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
void write (T a)
{
    if (a < 0)
    {
        putchar ('-');
        write (-a);
        return;
    }
    if (a < 10)
    {
        putchar ('0' + a);
        return;
    }
    write (a / 10);
    putchar ((char)('0' + (a % 10)));
}

long long Tg (int a, int b)
{
    return 1ll * (a + b) * (b - a + 1) / 2;
}

void enter()
{
    int m, n, k;
    read (m); read (n); read (k);  
    for (int i = 0; i < k; ++ i)
    read (h[i]); 
    for (int i = 0; i < n; ++ i)
    {
        int c, g;
        read (c); read (g); 
        -- g; -- c;
        e[g].emplace_back(c);
    }
    for (int i = 0; i < k; ++ i)
    {
        sort (e[i].begin(), e[i].end());
        int t = 0;
        for (int j = 0; j < e[i].size(); ++ j)
        {
            s[i].emplace_back ((j ? s[i][j - 1] : 0) + e[i][j]);
            e[i][j] -= j;
            for (; t <= e[i][j]; ++ t)
            Vt[i][t] = j;
        }
        for (; t <= n; ++ t)
        Vt[i][t] = e[i].size();
    }
    for (int i = 1; i <= 20; ++ i)
    lo[1 << i]  = i;
    f[0] = 0;
    for (int i = 1; i < (1 << k); ++ i)
    {
        f[i] = LLONG_MAX;
        int S = 0;
        for (int j = i; j; j -= j & - j)
        S += e[lo[j & - j]].size();
        for (int t = i; t; t -= t & - t)
        {
            int j = lo[t & - t];
            int k = e[j].size();
            S -= k;
            long long r = 0;
            int vt = Vt[j][S];
            if (vt)
            r = 1ll * (Tg (S, S + vt - 1) - s[j][vt - 1]) * h[j];
            if (vt != k)
            r += 1ll * (s[j].back() - (!vt ? 0 : s[j][vt - 1]) - Tg (S + vt, S + k - 1)) * h[j];
            f[i] = min (f[i], f[i ^ (1 << j)] + r);
            S += k;
        }   
    }
    cout << f[(1 << k) - 1];
}

void solve()
{

}

void print_result()
{

}

main()
{
    docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}   
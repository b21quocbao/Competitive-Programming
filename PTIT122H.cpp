#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = (int)(1e9);
int cnt[110];
int k, l, r;
int g[110][110];
int sol = 0;

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

void F (int id, long long l, long long r, bool ok1, bool ok2, int cn)
{
    if (id < 0) 
    {
        sol += (cnt[cn] + 1 == k ? 1 : 0);
        return;
    }
    int d = (l >> id) & 1;
    int c = (r >> id) & 1;
    if (ok1) d = 0;
    if (ok2) c = 1;
    if (ok1 && ok2) 
    {
        for (int i = 63; i >= cn; -- i)
        if (cnt[i] + 1 == k)
        sol += g[id + 1][i - cn];
        return;
    }
    if (d == c) 
    {
        F (id - 1, l, r, ok1, ok2, cn + d);
        return;
    }
    for (int i = 0; i < 2; ++ i)
    F (id - 1, l, r, ok1 | (i > d), ok2 | (i < c), cn + i);
}

void enter()
{
    sol = 0;
    cin >> l >> r >> k;
    if (r == 1)
    {
        cout << (!k ? 1 : 0) << "\n";
        return;
    }
    if (!l) exit(0);
    if (!k)
    {
        cout << (l == 1 ? 1 : 0) << "\n";
        return; 
    }
    if (l == 1) ++ l;
    F (60, l, r, 0, 0, 0);
    cout << sol << "\n";
}

void solve()
{

}

void print_result()
{

}

int32_t main()
{
    docfile();
    for (int i = 2; i <= 63; ++ i)
    cnt[i] = cnt[__builtin_popcountll(i)] + 1;
    g[0][0] = 1;
    for (int i = 1; i <= 60; ++ i)
    for (int j = 0; j <= i; ++ j)
    {
        g[i][j] = g[i - 1][j];
        if (j) g[i][j] += g[i - 1][j - 1];
    }
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
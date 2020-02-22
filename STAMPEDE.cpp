#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

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

int mi (int a, int b)
{
    if (b == - 1) return a;
    if (a == - 2) return b;
    return min (a, b);
}

int n, k;
int p[12], s[12], st[12], ct[12];
int f[1110][1110][12];

int F (int k, int t, int u)
{   
    if (t < 0) return - 2;
    if (k < 0) return - 2;
    if (!k) return 0;
    if (f[k][t][u] != - 1) return f[k][t][u];
    f[k][t][u] = - 2;
    for (int i = 0; i < n; ++ i)
    {
        if (k < p[i]) continue;
        if (t < st[i]) continue;
        if (i == u) continue;
        if ((k - p[i]) != (s[i] * (t - st[i]))) continue;
        for (int j = 1; (j <= ct[i] && k - s[i] * j >= p[i]); ++ j)
        f[k][t][u] = mi (f[k][t][u], F (k - s[i] * j, t - j, i) + 1);
    }
    return f[k][t][u];
}   

void enter()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++ i) cin >> p[i];
    for (int i = 0; i < n; ++ i) cin >> s[i];
    for (int i = 0; i < n; ++ i) cin >> st[i];
    for (int i = 0; i < n; ++ i) cin >> ct[i];
    int sol = - 1;
    memset (f, - 1, sizeof (f));
    for (int i = 0; i < 100; ++ k, ++ i)
    for (int i = 0; i <= 1000; ++ i)
    if (F (k, i, n) != - 2)
    if (sol == - 1) sol = F (k, i, n);
    else sol = min (sol, F (k, i, n));
    if (sol != - 1) -- sol;
    cout << sol << "\n";
}

void solve()
{

}

void print_result()
{

}

int main()
{
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
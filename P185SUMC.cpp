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
int it[4 * mn];

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

void initit (int id, int l, int r)
{
    if (l == r)
    {
        ++ it[id];
        return;
    }
    int m = (l + r) >> 1;
    initit (id << 1, l, m);
    initit ((id << 1) ^ 1, m + 1, r);
    it[id] = it[id << 1] + it[(id << 1) ^ 1];
}

void ud (int id, int l, int r, int x)
{
    if (l > x || r < x) return;
    if (l == r)
    {
        -- it[id];
        return;
    }
    int m = (l + r) >> 1;
    ud (id << 1, l, m, x);
    ud ((id << 1) ^ 1, m + 1, r, x);
    it[id] = it[id << 1] + it[(id << 1) ^ 1];
}

int qu (int id, int l, int r, int x)
{
    if (l == r) return l;
    int m = (l + r) >> 1;
    if (it[id << 1] >= x) qu (id << 1, l, m, x);
    else return qu ((id << 1) ^ 1, m + 1, r, x - it[id << 1]);   
}

void enter()
{
    int n;
    long long m;
    cin >> n >> m;
    initit (1, 1, n);
    for (int i = 1; i <= n; ++ i)
    {
        int j = max (m - 1ll * (n - i - 1) * (n - i) / 2 + 1, 1ll);
        int x = qu (1, 1, n, j);
        cout << x << " ";
        ud (1, 1, n, x);
        m -= j - 1;
    }
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
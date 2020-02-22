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
long long f[210][210][210];

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

long long F (int id, int m, int a)
{
    if (a < 0) return 0;
    //if (id >= 110 || m >= 110 || a >= 110) return 0;
    if (id < 0 || m < 0 || a < 0) return 0;
    if (id == 1) return ((a == m) ? 1 : 0);
    if (f[id][m][a] != - 1) return f[id][m][a];
    f[id][m][a] = 0;
    for (int i = m + 1; i <= a - m; ++ i)
    f[id][m][a] += F (id - 1, i, a - m);
    if (!m) f[id][m][a] += F (id - 1, 0, a - m);
    return f[id][m][a];
}

void enter()
{
    int a, m;
    long long sol = 0;
    cin >> a >> m;
    for (int i = 0; i <= a; ++ i)
    sol += F (m, i, a);
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
    memset (f, - 1, sizeof (f));
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
#include <bits/stdc++.h>

#define fn "test"
#define fn1 "POKEMON"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, m, k;
int f[mn][510];

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

int F (int i, int s)
{
    if (s < 0) return 0;
    if (i > n) return (s >= 0 ? 1 : 0);
    f[i][s] = 0;
    for (int j = 0; j <= m; ++ j)
    f[i][s] += F (i + 1, s - j * i);
    return f[i][s];
}

void enter()
{
    cin >> n >> m >> k;
    int cn = 0; 
    memset (f, - 1, sizeof (f));
    int s = 0;
    int sol = 0;
    while (inf <= sup)
    {
        memset (f, 0, sizeof (f));
        int mid = (inf + sup) >> 1;
        if (F (0, mid))
    }
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
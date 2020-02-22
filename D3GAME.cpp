#include <bits/stdc++.h>

#define fn "test"
#define fn1 "D3GAME"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;

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

int mo (int d)
{
    return (d < 0 ? d + 3 : d);
}

int f[60][60][60][3][2];

int F (int cn0, int cn1, int cn2, int d, bool ok)
{
    if (!cn0 && !cn1 && !cn2) 
    {
        if (ok) return (d == 0 ? 1 : 0);
        return (!d ? 0 : 1);
    }
    if (f[cn0][cn1][cn2][d][ok] != - 1) return f[cn0][cn1][cn2][d][ok];
    if (ok)
    {
        if (cn0 && !F (cn0 - 1, cn1, cn2, d, ok ^ 1)) return f[cn0][cn1][cn2][d][ok] = 1;
        if (cn1 && !F (cn0, cn1 - 1, cn2, mo (d - 1), ok ^ 1)) return f[cn0][cn1][cn2][d][ok] = 1;
        if (cn2 && !F (cn0, cn1, cn2 - 1, mo (d - 2), ok ^ 1)) return f[cn0][cn1][cn2][d][ok] = 1;
        return f[cn0][cn1][cn2][d][ok] = 0;
    }
    if (cn0 && !F (cn0 - 1, cn1, cn2, d, ok ^ 1)) return f[cn0][cn1][cn2][d][ok] = 1;
    if (cn1 && !F (cn0, cn1 - 1, cn2, d, ok ^ 1)) return f[cn0][cn1][cn2][d][ok] = 1;
    if (cn2 && !F (cn0, cn1, cn2 - 1, d, ok ^ 1)) return f[cn0][cn1][cn2][d][ok] = 1;
    return f[cn0][cn1][cn2][d][ok] = 0;
}

void enter()
{
    int n;
    if (!(cin >> n)) exit (0);
    int s = 0;
    memset (f, - 1, sizeof (f));
    int cn0 = 0, cn1 = 0, cn2 = 0;
    vector<int> a (n + 2);
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        a[i] %= 3;
        if (a[i] < 0) a[i] += 3;
        if (!a[i]) ++ cn0;
        else if (a[i] == 1) ++ cn1;
        else ++ cn2;
        s += a[i];
    }
    if (s % 3 == 0)
    {
        cout << "DRAW";
        return;
    }
    if (F (cn0, cn1, cn2, 0, 1))
    {
        cout << "FIRST";
        return;
    }
    if (F (cn0, cn1, cn2, 3 - s % 3, 1))
    {
        cout << "DRAW";
        return;
    }
    cout << "SECOND";
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
{
    docfile();
    // cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
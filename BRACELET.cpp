#include <bits/stdc++.h>

#define fn "test"
#define fn1 "BRACELET"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
string s[13];
int n;
int f[(1 << 11) + 10][12][10][10];
int a[10];

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

void mi (int& x, int y, int v)
{
    if (y == - 1) return;
    if (x == - 1)
    {
        x = y + v;
        return;
    }
    x = min (x, y + v);
}

void enter()
{
    cin >> n;
    if (!n) exit (0);
    for (int i = 0; i < 8; ++ i)
    cin >> a[i];
    cin.ignore();
    for (int i = 0; i < n; ++ i)
    getline (cin, s[i]);
    memset (f, - 1, sizeof (f));
    int sol = - 1;
    for (int i = 0; i < (1 << n); ++ i)
    {
        if (!i)
        {
            for (int k = 0; k < 8; ++ k)
            mi (f[1 << 0][0][k][k], 0, a[s[0][k] - 'A']);
            continue; 
        }
        for (int k1 = 0; k1 < 8; ++ k1)
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        for (int k = 0; k < 8; ++ k)
        if (f[i][j][k][k1] != - 1)
        {
            if (i == (1 << n) - 1)
            {
                if (s[j][(k + 4) % 8] == s[0][k1])
                mi (sol, f[i][j][k][k1], 0);
                continue;
            }
            for (int t = 0; t < n; ++ t)
            if (((i >> t) & 1) == 0)
            for (int l = 0; l < 8; ++ l)
            if (s[j][(k + 4) % 8] == s[t][l])
            mi (f[i ^ (1 << t)][t][l][k1], f[i][j][k][k1], a[s[t][l] - 'A']);
        }
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
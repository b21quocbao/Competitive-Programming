#include <bits/stdc++.h>

#define fn "test"
#define fn1 "JUMP"

using namespace std;

typedef vector<vector<int> > vii;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 4 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int k, n, m;
int ch[mm][mm];
int b[mm][mm], c[mm][mm];

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

void F (int a[][], int b[][], int c[][])
{
    for (int i = 0; i < a.size(); ++ i)
    for (int j = 0; j < b[0].size(); ++ j)
    for (int k = 0; k < b.size(); ++ k)
    {
        c[i][j] += ((1ll * a[i][k] * b[k][j]) % m);
        c[i][j] %= m;
    }
}

vii po (const vii& a, int n)
{
    if (n == 1) return a;
    b = po (a, n >> 1);
    b = b * b;
    if (n & 1) return b * a;
    return b;
}

void enter()
{
    cin >> n >> k >> m;
    vii ch (n, vector<int> (n));
    c.resize (n, vector<int> (n));
    for (int i = 1; i < n; ++ i)
    ch[i][i - 1] = 1;
    ch[0][n - 1] = 1;
    for (int i = 0; i < n - 1; ++ i)
    ch[i][i + 1] = 1;
    ch[n - 1][0] = 1;
    ch = po (ch, k - 1);
    cout << ch[0][1] + ch[0][n - 1];
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
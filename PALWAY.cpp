#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PALWAY"

using namespace std;

const int mn = 1 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, a[mn][mn];
int f[mn][mn][mn];

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

int F (int i, int j, int k, int l)
{
    if (f[i][j][k] != - 1) return f[i][j][k];
    if (i > k || j > l) return 0;
    if (i == k && j == l) return 1;
    if (a[i][j] != a[k][l]) return 0;
    return f[i][j][k] = 
    (F (i + 1, j, k - 1, l) + F (i + 1, j, k, l - 1) +
    F (i, j + 1, k - 1, l) + F (i, j + 1, k, l - 1)) % 101;
}

void enter()
{
    cin >> n;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> a[i][j];
    memset (f, - 1, sizeof (f));
    cout << F (0, 0, n - 1, n - 1) << "\n";
    // cout << F (0, 1, n - 2, n - 1) + F (1, 0, n - 1, n - 2);
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
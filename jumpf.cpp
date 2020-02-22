#include <bits/stdc++.h>

#define fn "test"
#define fn1 "jumpf"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[mn][mn];
int n, a[mn];

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

int F (int u, int k)
{
    if (!(u >= 1 && u <= n)) return - 2;
    if (u == n) return 0;
    if (f[u][k] != - 1) return f[u][k];     
    f[u][k] = int(1e8);
    if (k && (F(u - k, k) != - 2)) f[u][k] = F (u - k, k) + a[u - k];
    if (F(u + k + 1, k + 1) != - 2) f[u][k] = min (f[u][k], F (u + k + 1, k + 1) + a[u + k + 1]);
    if (f[u][k] == int(1e8)) f[u][k] = - 2;
    return f[u][k];
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    memset (f, - 1, sizeof (f));
    cout << F (1, 0);
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
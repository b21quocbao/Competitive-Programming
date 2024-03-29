#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1000000;
int a[mn][2];
bool ok[mn][2];

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

void enter()
{
    int n;
    cin >> n;
    if (!n) exit(0);
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < 2; ++ j)
    cin >> a[i][j];
    int m;
    cin >> m;
    
    for (int i = 0; i < m; ++ i)
    {
        int x, y;
        cin >> x >> y;
        -- x; --y;
        swap (a[x], a[y]);
        memset (ok, 0, sizeof (ok));
        ok[0][0] = ok[0][1] = 1;
        for (int i = 1; i < n; ++ i)
        for (int j = 0; j < 2; ++ j)
        for (int k = 0; k < 2; ++ k)
        ok[i][j] |= (ok[i - 1][k] && (a[i][j] >= a[i - 1][k]));
        cout << (ok[n - 1][0] || ok[n - 1][1]) << "\n";
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
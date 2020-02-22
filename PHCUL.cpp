/*
Code by b21
Time: 13:38 Tue 05/11/2019
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mn = 5 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("PHCUL.inp"))
    {
        freopen("PHCUL.inp", "r", stdin);
        freopen("PHCUL.out", "w", stdout);
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

double D (int x, int y, int a, int b)
{
    return sqrt (1ll * (a - x) * (a - x) + 1ll * (b - y) * (b - y));
}

int a[mn], b[mn], c[mn], d[mn], e[mn], f[mn];
double mi1[mn], mi2[mn];

void enter()
{
    int n, m, k, x, y;
    cin >> x >> y;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i] >> b[i];
    for (int i = 1; i <= m; ++ i)
    cin >> c[i] >> d[i];
    for (int i = 1; i <= k; ++ i)
    cin >> e[i] >> f[i];
    fill_n (mi1 + 1, m, 1e15);
    fill_n (mi2 + 1, n, 1e15);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= k; ++ j)
    mi1[i] = min (mi1[i], D (c[i], d[i], e[j], f[j]));
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= k; ++ j)
    mi2[i] = min (mi2[i], D (a[i], b[i], e[j], f[j]));
    double sol = 1e15;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= m; ++ j)
    sol = min (sol, D (x, y, a[i], b[i]) + D (a[i], b[i], c[j], d[j]) + mi1[j]);
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= m; ++ j)
    sol = min (sol, D (x, y, c[j], d[j]) + D (a[i], b[i], c[j], d[j]) + mi2[i]);
    cout << fixed << setprecision(10) << sol << "\n";
}

void solve()
{

}

void print_result()
{

}

main()
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
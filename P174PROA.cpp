#include <bits/stdc++.h>
 
#define fn "test"
#define fn1 ""
 
using namespace std;
 
const int mn = 5 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e6) + 10;
const int base = 1 * (int)(1e9);
 
int tt, ntest = 1;
int n, k, a[mn];
int s[mm];
pair<int, int>ok[mm][5], v[5];
 
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        freopen(fn".out", "w", stdout);
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
    cin >> n >> k;
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    sort (a, a + n);
    n = unique (a, a + n) - a;
    vector<int> d (30);
    d[1] = 1;
    d[2] = d[3] = 2;
    d[4] = d[5] = d[6] = 3;
    for (int i = 7; i <= 10; ++ i)
    d[i] = 4;
    for (int i = 11; i <= 15; ++ i)
    d[i] = 5;
    for (int i = 16; i <= 21; ++ i)
    d[i] = 6;
    for (int i = 22; i <= 28; ++ i)
    d[i] = 7;
    int ma = 0, cn = 0;
    memset (ok, - 1, sizeof (ok));
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < i; ++ j)
    {
        int x = a[i] - a[j];
        ma = max (ma, x);
        if (s[x] > k) continue;
        bool Ok = 0;
        int k = a[i] % x;
        int l = 0;
        for (; ok[x][l].first != - 1; ++ l)
        {
            ++ cn;
            if (ok[x][l].first == k)
            {
                s[x] = s[x] - d[ok[x][l].second] + d[++ ok[x][l].second];
                Ok = 1;
                break;
            }
        }
        if (Ok) continue;
        ok[x][l] = {k, 1};
        ++ s[x];
    }
    int sol = ma + 1;
    // for (int u = ma; u >= max (1, n - k); -- u)
    // {
    //     for (int j = 0; j < 5; ++ j)
    //     {
    //         v[j] = ok[u][j];
    //     }
    //     for (int i = 2 * u; i <= ma; i += u)
    //     {
    //         if (s[u] > k) break;
    //         if (s[i] > k)
    //         {
    //             s[u] = k + 1;
    //             break;
    //         }
    //         for (int t = 0; ok[i][t].first != - 1; ++ t)
    //         {
    //             auto x = ok[i][t];
    //             if (s[u] > k) break;
    //             bool Ok = 0;
    //             auto k = x.first % u;
    //             int j = 0;
    //             for (; v[j].first != - 1; ++ j)
    //             if (v[j].first == k)
    //             {
    //                 Ok = 1;
    //                 s[u] = s[u] - d[v[j].second] + d[v[j].second += x.second];
    //                 break;
    //             }
    //             if (Ok) continue;
    //             v[j] = {k, x.second};
    //             s[u] += d[x.second];
    //         }
    //     }
    //     if (s[u] <= k)
    //     sol = u;
    // }
    cout << sol;
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
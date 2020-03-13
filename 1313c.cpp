/*
Code by b21
Time: 16:27 Sun 23/02/2020
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mn = 5 * (int)(1e5) + 10;
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
   else if (ifstream("1313c.inp"))
    {
        freopen("1313c.inp", "r", stdin);
        freopen("1313c.out", "w", stdout);
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

int f[mn], g[mn], a[mn], m[mn];

void enter()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    cin >> m[i];
    vector<int> v;
    v.emplace_back(0);
    for (int i = 1; i <= n; ++ i) {
        while (m[i] <= m[v.back()]) v.pop_back();
        f[i] = f[v.back()] + m[i] * (i - v.back());
        v.emplace_back(i);
    }
    v.clear();
    v.emplace_back(n + 1);
    long long sol = 0, I = 0;
    for (int i = n; i >= 1; -- i) {
        while (m[i] <= m[v.back()]) v.pop_back();
        g[i] = g[v.back()] + m[i] * (v.back() - i);
        if (g[i] + f[i] - m[i] > sol) {
            sol = g[i] + f[i] - m[i];
            I = i;
        }
        v.emplace_back(i);
    }
    int mi = INT_MAX;
    for (int i = I; i >= 1; -- i) {
        mi = min (mi, m[i]);
        a[i] = mi;
    }
    mi = INT_MAX;
    for (int i = I; i <= n; ++ i) {
        mi = min (mi, m[i]);
        a[i] = mi;
    }
    for (int i = 1; i <= n; ++ i)
    cout << a[i] << " ";
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
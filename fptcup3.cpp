/*
Code by b21
Time: 21:29 Wed 13/11/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
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
   else if (ifstream("fptcup3.inp"))
    {
        freopen("fptcup3.inp", "r", stdin);
        freopen("fptcup3.out", "w", stdout);
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

int a[mn], f[mn];

void enter()
{
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        v.emplace_back(a[i]);
    }
    sort (v.begin(), v.end());
    for (int i = 1; i <= n; ++ i)
    {
        a[i] = (lower_bound(v.begin(), v.end(), a[i]) - v.begin()) / k + 1;
    }
    int ma = 0;
    for (int i = 1; i <= n; ++ i)
    {
        f[i] = 1;
        for (int j = 1; j < i ; ++ j)
        if (a[i] >= a[j])
        f[i] = max (f[i], f[j] + 1);
        ma = max (ma, f[i]);
    }
    cout << n - ma;
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
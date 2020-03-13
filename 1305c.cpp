/*
Code by b21
Time: 21:41 Tue 03/03/2020
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mn = 2 * (int)(1e5) + 10;
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
   else if (ifstream("1305c.inp"))
    {
        freopen("1305c.inp", "r", stdin);
        freopen("1305c.out", "w", stdout);
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

int a[mn];

void enter()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    if (n > m) {
        cout << 0;
        return;
    }
    long long sol = 1;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < i; ++ j)
    {
        sol *= (abs (a[i] - a[j]) % m);
        sol %= m;
    }
    cout << sol;
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
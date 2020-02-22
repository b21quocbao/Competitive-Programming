/*
Code by b21
Time: 20:49 Thu 20/06/2019
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
   else if (ifstream("985h.inp"))
    {
        freopen("985h.inp", "r", stdin);
        freopen("985h.out", "w", stdout);
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

int a[mn], b[mn], c[mn];

void enter()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    long long s1 = 0, s2 = 0;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> b[i];
        s1 += (b[i] - a[i]) * (b[i] - a[i]);
    }
    for (int i = 1; i <= n; ++ i)
    {
        cin >> c[i];
        s2 += (c[i] - a[i]) * (c[i] - a[i]);
    }
    cout << (s1 <= s2 ? "Yan" : "MaratonIME");
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
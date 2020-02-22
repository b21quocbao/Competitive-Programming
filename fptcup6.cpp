/*
Code by b21
Time: 20:31 Wed 13/11/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
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
   else if (ifstream("fptcup6.inp"))
    {
        freopen("fptcup6.inp", "r", stdin);
        freopen("fptcup6.out", "w", stdout);
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

int x[mn], y[mn], id[mn];

void enter()
{
    int n;
    read (n);
    for (int i = 0; i < n; ++ i)
    {
        read (x[i]); read (y[i]);
        x[i] /= 2; y[i] /= 2;
        id[i] = i;
    }
    sort (id, id + n, [](int i, int j)
         {
             return x[i] < x[j];
         });
    id[n] = n;
    int ma = 0;
    long long sol = 0;
    for (int j = n - 1; j >= 0; -- j)
    {
        if (y[id[j]] <= ma) continue;
        sol += 1ll * (y[id[j]] - ma) * x[id[j]];
        ma = y[id[j]];
    }
    cout << sol * 4;
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
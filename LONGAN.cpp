#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LONGAN"

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
    read (n); read (m);
    for (int i = 0; i < m; ++ i)
    {
        read (l[i]); read (r[i]);
        id[i] = i;
        d = max (d, r[i]);
        v1.emplace_back(i);
    }
    sort (id, id + m, [](int i, int j)
         {
             return l[i] < l[j];
         });
    sort (v1.begin(), v1.end(), [](int i, int j)
         {
             return 
         })
    int cur = m - 1;
    for (int i = n; i >= 1; -- i)
    {
        f[i] = - 1;
        while (cur >= 0 && l[id[cur]] > x)
        {
            ok[id[cur]] = 1;
            v2.emplace_back(id[cur]);
            -- cur;
        }
        while ()
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
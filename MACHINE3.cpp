#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MACHINE3"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int id[mn], s[mn], t[mn];
int f[3 * mn][4];

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
    int n, k;
    read (n); read (k);
    for (int i = 0; i < n; ++ i)
    {
        read (s[i]); read (t[i]);   
        id[i] = i;
    }
    sort (id, id + n, [](int i, int j)
         {
             return t[i] < t[j];
         });
    int j = 0;
    for (int j = 1; j <= k; ++ j)
    f[0][j] = - 1;
    for (int i = 1; i <= 3000000; ++ i)
    {   
        for (int j = 1; j <= k; ++ j)
        f[i][j] = f[i - 1][j];
        while (j < n && t[id[j]] == i)
        {
            for (int l = 1; l <= k; ++ l)
            if (f[s[id[j]] - 1][l - 1] != - 1)
            f[i][l] = max (f[i][l], f[s[id[j]] - 1][l - 1] + t[id[j]] - s[id[j]]);
            ++ j;
        }
    }
    cout << f[3000000][k];
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
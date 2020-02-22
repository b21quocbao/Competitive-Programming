#include <bits/stdc++.h>

#define fn "test"
#define fn1 "INVERSE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 5 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mm][mm], b[mm][mm];

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
    int m, n, x;
    read (m); read (n);
    char c;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        c = getchar();
        while (!isdigit (c)) c = getchar();
        a[i][j] = (c - '0');
        // cerr << a[i][j] << " ";
    }
    for (int i = 1; i <= m; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        {
            c = getchar();
            while (!isdigit (c)) c = getchar();
            x = (c - '0');
            if (a[i][j] != x) a[i][j] = 1;
            else a[i][j] = 0;
            // cerr << a[i][j] << " ";
        } 
        // cerr << "\n";
    }     
    for (int k = 0; k <= 1; ++ k)
    {
        vector<int> v;
        if (k)
        {
            for (int j = 1; j <= n; ++ j)
            b[1][j] = k;
            v.push_back(1);
        }
        for (int j = 1; j <= n; ++ j)
        {
            if (a[1][j] != b[1][j])
            {
                for (int i = 1; i <= m; ++ i)
                b[i][j] = 1 - b[i][j];
                v.push_back(-j);
            }
        }
        for (int i = 2; i <= m; ++ i)
        if (b[i][1] != a[i][1])
        {
            for (int j = 1; j <= n; ++ j)
            b[i][j] = 1 - b[i][j];
            v.push_back(i);
        }
        bool ok = 1;
        for (int i = 1; i <= m; ++ i)
        for (int j = 1; j <= n; ++ j)
        if (a[i][j] != b[i][j]) ok = 0;
        if (ok)
        {
            cout << v.size() << "\n";
            for (int i : v)
            cout << i << " ";
            return;
        }
    }
    cout << -1;
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
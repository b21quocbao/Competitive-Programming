#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

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
    cin >> n >> m;
    for (int i = 0; i < n; ++ i)
    {
        cin >> x[i] >> y[i];
        id[i] = i;
    }
    for (int i = 0; i < m; ++ i)
    {
        cin >> X[i] >> Y[i];
        Id[i] = i;
    }
    sort (id1, id1 + n, [] (int i, int j)
         {
             return y[i] - x[i] < y[j] - x[j];
         });
    sort (id2, id2 + n, [] (int i, int j)
         {
             return y[i] + x[i] > y[j] + x[j];
         });
    sort (Id1, Id1 + m, [] (int i, int j)
         {
             return Y[i] - X[i] < Y[j] - X[j];
         });
    sort (Id2, Id2 + m, [](int i, int j)
         {
             return Y[i] + X[i] > Y[j] + X[j];
         })
    for (int i = 0, j = 0; i < n; ++ i)
    {
        while (j < m && y[id1[i]] - x[id1[i]] >= Y[Id1[j]] - X[Id1[j]]) ++ j;
        h[id1[i]] = j - 1;
    }
    for (int i = 0, j = 0; i < n; ++ i)
    {
        while (j < m && y[id2[i]] + x[id2[i]] <= Y[Id2[j]] + X[Id2[j]]) ++ j;
        c[id2[i]] = j - 1;
    }
    sort (id1, id1 + n, [](int i, int j)
         {
             if (h[i] == h[j])
             return c[i] < c[j];
             return h[i] > h[j];
         });
    int mi = INT_MAX;
    int ma = m;
    for (int i = 0; i < m; ++ i)
    cn[i] = 2;
    for (int i = n - 1; i >= 0; -- i)
    {
        int j = id[i];
        if (c[j] > mi)
        {
            ++ sol;
            continue;
        }
        mi = c[j];
        for (int d = ma; d > h[j]; -- d)
        if (-- cn[d] == 0) 
    }
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
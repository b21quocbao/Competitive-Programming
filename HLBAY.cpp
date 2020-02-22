#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "HLBAY"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int x[mn], y[mn], h[mn], id[mn];
double r[mn], l[mn], mi[mn];

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
    int n, m;
    read (n); read (m);
    for (int i = 1; i <= n; ++ i)
    read (h[i]);
    for (int i = 1; i <= m; ++ i)
    {
        id[i] = i;
        read (x[i]); read (y[i]);
    }
    sort (h + 1, h + n + 1);
    long long inf = 0, sup = 2 * (long long)(1e10), sol = 2 * (long long)(1e10);
    // inf = 0, sup = 0;
    while (inf <= sup)
    {
        long long mid = (inf + sup) >> 1;
        for (int i = 1; i <= m; ++ i)
        {
            if (mid < y[i] * y[i])
            {
                l[i] = r[i] = - 1;
                continue;
            }
            r[i] = 1. * x[i] + sqrt (mid - y[i] * y[i]);
            l[i] = 1. * x[i] - sqrt (mid - y[i] * y[i]);
        }
        sort (id + 1, id + m + 1, [](int i, int j)
             {
                 return r[i] < r[j];
             });
        int k = 1;
        bool ok = 1;
        for (int j = m; j >= 1; -- j)
        if (j == m)
        mi[j] = l[id[j]];
        else
        mi[j] = min (l[id[j]], mi[j + 1]);
        for (int j = 1; j <= m; ++ j)
        {
            if (k == n + 1) break;
            int i = id[j];
            if (j == 1)
            {
                if (h[k] < mi[j]) 
                {
                    ok = 0;
                    break;
                }
            }
            else
            {
                int i1 = id[j - 1];
                if (h[k] > r[i1] && h[k] < mi[j]) 
                {
                    ok = 0;
                    break;
                }
            }
            while (k <= n && h[k] <= r[i]) ++ k;
        }
        if (ok && k == n + 1)
        {
            sol = mid;
            sup = mid - 1;
        }
        else inf = mid + 1;
    }
    cout << fixed << setprecision(5) << sqrt (sol);
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
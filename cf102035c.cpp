#include <bits/stdc++.h>
#define int long long

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

int t[mn], T[mn], a[mn], id[mn];

void enter()
{
    int n, k, x;
    cin >> n >> k >> x;
    int inf = 0, sup = k;
    int mi = 1;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        if (a[i] < a[mi]) mi = i;
    }
    while (inf <= sup)
    {
        t[mi] = (inf + sup) >> 1;
        int s = a[mi] + x * t[mi];
        for (int i = 1; i <= n; ++ i)
        if (i != mi)
        {
            t[i] = max (0ll, (s + x - a[i] - 1) / x);
        }
        int S = 0;
        for (int i = 1; i <= n; ++ i)
        S += t[i]; 
        if (S >= k)
        {
            sup = t[mi] - 1;
            swap (T, t);
        }
        else inf = t[mi] + 1;
    }
    for (int i = 1; i <= n; ++ i)
    id[i] = i;
    swap (t, T);
    sort (id + 1, id + n + 1, [&](int i, int j)
         {
             return a[i] + t[i] * x > a[j] + t[j] * x;
         });
    int sol = 0;
    for (int i = 1; i <= n; ++ i)
    sol += t[i];
    for (int i = 1; i <= n; ++ i)
    {
        if (sol > k && t[id[i]]) 
        {
            -- t[id[i]];
            -- sol;
        }
    }
    for (int i = 1; i <= n; ++ i)
    cout << t[i] << " ";
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
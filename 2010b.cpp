/*
Code by b21
Time: 10:07 Sun 20/10/2019
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
   else if (ifstream("2010b.inp"))
    {
        freopen("2010b.inp", "r", stdin);
        freopen("2010b.out", "w", stdout);
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
bool f[(int)(1e8) + 2];

void enter()
{
    int n;
    cin >> n;
    vector<int> v;
    int s = 0, N = n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        s += a[i];
        if (a[i] % 2 == 0)
        {
            a[++ N] = a[i] / 2;
            a[i] /= 2;
        }
    }
    if (s % 2) ++ s;
    int sol = 0;
    s /= 2;
    n = N;
    int mi = INT_MAX;
    v.emplace_back(0);
    f[0] = 1;
    // sort (a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= n; ++ i)
    {
        vector<int> l;
        for (const int& x : v)
        {
            if (!f[x + a[i]])
            {
                if (x + a[i] <= s)
                l.emplace_back(x + a[i]);
                f[x + a[i]] = 1;
                if (x + a[i] >= s && x + a[i] - s < mi) 
                {
                    mi = x + a[i] - s;
                    sol = x + a[i];
                }
            }
        }
        for (int x : l)
        v.emplace_back (x);
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
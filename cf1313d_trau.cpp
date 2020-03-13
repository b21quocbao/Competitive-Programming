/*
Code by b21
Time: 16:46 Fri 28/02/2020
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

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
   else if (ifstream("cf1313d_trau.inp"))
    {
        freopen("cf1313d_trau.inp", "r", stdin);
        freopen("cf1313d_trau.out", "w", stdout);
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

int l[mn], r[mn], s[110];

void enter()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v;
    for (int i = 0; i < n; ++ i) 
    {
        cin >> l[i] >> r[i];
    }
    int sol = 0;
    for (int i = 0; i < (1 << n); ++ i) {
        memset (s, 0, sizeof (s));
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        {
            ++ s[l[j]];
            -- s[r[j] + 1];
        }
        int ma = 0;
        for (int i = 1; i <= m + 1; ++ i)
        {
            s[i] += s[i - 1];
            if (s[i] % 2) ++ ma;
        }
        // if (ma == 86)
        // {
        //     for (int j = 0; j < n; ++ j)
        //     if ((i >> j) & 1) cout << j << "\n";
        // }
        sol = max (sol, ma);
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
/*
Code by b21
Time: 19:29 Tue 05/11/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 8 * (int)(1e7) + 1000000 + 10;
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
   else if (ifstream("LSTBTF.inp"))
    {
        freopen("LSTBTF.inp", "r", stdin);
        freopen("LSTBTF.out", "w", stdout);
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

int f[mn], cn[mn], r[mn];
vector<int> V;

bool operator < (vector<int> a, vector<int> b)
{
    if (!b.size()) return 1;
    if (a.size() != b.size()) return (a.size() < b.size());
    for (int i = 0; i < a.size(); ++ i)
    if (a[i] != b[i]) return (a[i] < b[i]);
    return 0;
}

void init()
{
    f[0] = 1;
    for (int i = 1; i < mn; ++ i)
    {
        int mi = INT_MAX;
        for (int j = 9; j >= 2; -- j)
        if (i - j * j + 1 >= 0 && f[i - j * j + 1] && cn[i - j * j + 1] <= mi)
        {
            f[i] = j;
            cn[i] = cn[i - j * j + 1] + 1;
            mi = cn[i] - 1;
        }
    }
    for (int i = 1; i * i < mn; ++ i)
    V.emplace_back(i * i);
}

int a[(int)(1e6) + 10];

void enter()
{
    int n;
    read (n);
    fill_n (a + 1, n, 1);
    int re = n, mi = - 1;
    vector<int> v;
    for (auto it = lower_bound(V.begin(), V.end(), n); it < V.end(); ++ it)
    if (f[(*it) - n] && cn[(*it) - n] <= n)
    {
        if (mi == - 1 || cn[*it - n] <= mi)
        {
            vector<int> v1;
            mi = cn[*it - n];
            int x = (*it) - n;
            if (!x)
            {
                for (int i = 1; i <= n; ++ i)
                cout << a[i];
                cout << "\n";
                return;
            }
            while (x)
            {
                int res = f[x] * f[x] - 1;
                v1.emplace_back(f[x]);
                x -= res;
            }
            sort (v1.begin(), v1.end());
            if (v1 < v)
            v = v1;
        }
    }
    if (v.size())
    {
        for (int i = 0; i < v.size(); ++ i)
        a[n + 1 - v.size() + i] = v[i];
        for (int i = 1; i <= n; ++ i)
        cout << a[i];
        cout << "\n";
        return;
    }
    cout << - 1 << "\n";
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
    read(ntest);
    init();
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
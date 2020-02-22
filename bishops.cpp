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
int x[mn], y[mn], p[mn], id[mn];
vector<int> v1[2 * mn], v2[2 * mn];

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
    if (ifstream ("bishops.in"))
    freopen ("bishops.in", "r", stdin);
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
    int n, m, c;
    read (n); read (m); read (c);
    for (int i = 1; i <= 2 * n - 1; ++ i)
    v1[i].clear();
    for (int i = 0; i < 2 * n - 1; ++ i)
    v2[i].clear();
    for (int i = 0; i < m; ++ i)
    {
        id[i] = i;
        read (x[i]); read (y[i]); read (p[i]);
        -- x[i]; -- y[i];
        
    }
    vector<int> v;
    sort (id, id + m, [](int i, int j)
         {
             return x[i] < x[j];
         });
    for (int j = 0; j < m; ++ j)
    {
        int i = id[j];
        v1[x[i] - y[i] + n].emplace_back(i);
        v2[x[i] + y[i]].emplace_back(i);
    }
    #define ii pair<int, int>
    int sol = 0;
    for (int i = 1; i <= 2 * n - 1; ++ i)
    {
        vector<ii > v;
        int cn = 0;
        for (int j : v1[i])
        {
            auto r1 = p[j] * p[j] - x[j];
            auto r2 = p[j] * p[j] + x[j];
            int x = lower_bound (v.begin(), v.end(), ii (1 - c - r1, cn), greater<ii>()) - v.begin();
            if (x != v.size())
            sol = max (sol, cn - v[x].second + 1);
            if (!v.size() || v.back().first > r2)
            v.emplace_back(r2, cn);
            ++ cn;
        }
    }
    for (int i = 0; i < 2 * n - 1; ++ i)
    {
        vector<ii > v;
        int cn = 0;
        for (int j : v2[i])
        {
            auto r1 = p[j] * p[j] - x[j];
            auto r2 = p[j] * p[j] + x[j];
            int x = lower_bound (v.begin(), v.end(), ii (1 - c - r1, cn), greater<ii>()) - v.begin();
            if (x != v.size())
            sol = max (sol, cn - v[x].second + 1);
            if (!v.size() || v.back().first > r2)
            v.emplace_back(r2, cn);
            ++ cn;
        }
    }
    cout << sol << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
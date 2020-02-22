#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
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

void read(int& x)
{
    x = 0; int f = 1;
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

vector<pair<int, int>> f[mn];
vector<int> e[mn];
int p[mn];
int sol;
int id[mn];
int l[mn];

void Dfs (int u)
{
    int k = 1;
    for (const int& v : e[u])
    {
        Dfs (v);
        for (auto i : f[v])
        f[u].emplace_back(i.first, 0);
    }
    f[u].emplace_back(p[u], 0);
    sort (f[u].begin(), f[u].end());
    f[u].resize(unique(f[u].begin(), f[u].end()) - f[u].begin());
    for (int i = 0; i < f[u].size(); ++ i)
    id[f[u][i].first] = i;
    for (const int& v : e[u])
    {
        int ma = 0;
        int s = 0;
        for (int i = 0; i < f[v].size(); ++ i)
        {
            f[v][i].second -= s;
            s += f[v][i].second;
            f[u][id[f[v][i].first]].second += f[v][i].second;
        }
        f[v].clear();
    }
    for (int i = 1; i < f[u].size(); ++ i)
    f[u][i].second += f[u][i - 1].second;
    f[u][id[p[u]]].second = max (f[u][id[p[u]]].second, (id[p[u]] ? f[u][id[p[u]] - 1].second : 0) + 1);
    for (int i = 0; i < f[u].size(); ++ i)
    sol = max (sol, f[u][i].second);
}

void enter()
{
    int n;
    read (n);
    vector<int> v;
    for (int i = 1; i <= n; ++ i)
    {
        int u;
        read (p[i]); read (u);
        e[u].emplace_back(i);
        v.emplace_back(p[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++ i)
    p[i] = lower_bound(v.begin(), v.end(), p[i]) - v.begin();
    Dfs (1);
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
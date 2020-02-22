#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SKILEVEL"

using namespace std;

const int mn = 3 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm =  5 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int m, n, t;
int a[mm][mm];
bool b[mn], ok[mm][mm];
vector<int> v;
int fa[mn];
long long sol = 0;
vector<int> e1[mn];
vector<pair<int, int> > e[2 * mn];

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

inline int id (int i, int j)
{
    return i * n + j;
}

void uni (int u, int v, int x)
{
    if (u == v) return;
    if (fa[v] < fa[u]) swap (u, v);
    if (-fa[u] < t && -(fa[u] + fa[v]) >= t)
    {
        for (int k : e1[u])
        if (b[k]) sol += x;
        for (int k : e1[v])
        if (b[k]) sol += x;
    }
    if (-fa[v] < t && -fa[u] >= t)
    {
        for (int k : e1[v])
        if (b[k]) sol += x;
    }
    fa[u] += fa[v];
    fa[v] = u;
    for (int k : e1[v])
    e1[u].push_back(k);
}

int Fa (int u)
{
    return (fa[u] < 0 ? u : fa[u] = Fa (fa[u]));
}

int Id (int x)
{
    return lower_bound (v.begin(), v.end(), x) - v.begin();
}

void enter()
{
    read (m); read (n); read (t);
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        read (a[i][j]);
        fa[id (i, j)] = - 1;
        e1[id (i, j)].push_back(id (i, j));
        if (i)
        v.push_back(abs (a[i][j] - a[i - 1][j]));
        if (j)
        v.push_back(abs (a[i][j] - a[i][j - 1]));
    }
    v.push_back(0);
    sort (v.begin(), v.end());
    v.resize(unique (v.begin(), v.end()) - v.begin());
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        if (i)
        e[Id (abs (a[i][j] - a[i - 1][j]))].push_back({id (i, j), id (i - 1, j)});
        if (j)
        e[Id (abs (a[i][j] - a[i][j - 1]))].push_back({id (i, j), id (i, j - 1)});
    }
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        int x;
        read (x);
        if (x) b[id (i, j)] = 1;
    }
    for (int i = 0; i < v.size(); ++ i)
    { 
        for (auto x : e[i])
        uni (Fa (x.first), Fa (x.second), v[i]);
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
#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 3 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int cnt, num[mn], low[mn];
int n, m;
vector<int> e[mn];
int sol;
int fa[mn];
int smax[mn];

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

void dfs (int u)
{
    low[u] = num[u] = ++ cnt;
    int ma1 = 0, ma2 = 0;
    for (int v : e[u])
    if (num[v] && fa[u] != v)
    {
        low[u] = min (low[u], low[v]);   
    }
    else if (v != fa[u])
    {
        fa[v] = u;
        dfs (v);
        int res = 0;
        low[u] = min (low[u], low[v]);
        if (low[v] > num[u]) res = 1;
        smax[u] = max (smax[u], smax[v] + res);
        if (smax[v] + res > ma1) 
        {
            ma2 = ma1;
            ma1 = smax[v] + res;
        }
        else if (smax[v] + res > ma2) ma2 = smax[v] + res;
    }
    sol = max (sol, ma1 + ma2);
}

void enter()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }  
    dfs (1);
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
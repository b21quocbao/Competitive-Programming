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
int n, m;
vector<int> e[mn];
int fa[mn], U[mn], V[mn], low[mn], num[mn], cnt, X[mn], Y[mn];
bool ct[mn];
int va[mn][2], ra[mn][2];

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
    num[u] = low[u] = ++ cnt;
    for (int i = 0; i < e[u].size(); ++ i)
    {
        int v = e[u][i];
        if (v != fa[u])
        {
            if (!num[v])
            {
                fa[v] = u;
                dfs (v);
            }
            low[u] = min (low[u], low[v]);
            if (low[v] <= num[u]) ok[u].push_back(1);
            else ok[u].push_back(0);
        }
    }
    
}   

int F (int u, int o, int k)
{
    if (o < 0) return 0;
    if (f[u][o] != - 1) return f[u][o];
    for (int v : e[u])
    if (v != k)
}

void enter()
{
    read (n); read (m);
    for (int i = 1; i <= n; ++ i)
    {
        e[i].clear();
        low[i] = 0;
    }
    cnt = 0;
    for (int i = 1; i <= m; ++ i)
    {
        read (u); read (v); 
        e[u].push_back(v);
    }
    dfs (1);
    memset (va, - 1, sizeof (va));
    memset (ra, - 1, sizeof (ra));
    for (int i = 1; i <= m; ++ i)
    {
        cerr << Ra (Y[i], 1) << "\n";
        cout << Va (X[i], 1 - ct[i]) * Ra (Y[i], 1 - ct[i]) << "\n";
    }
    cerr << Ra (5, 0) << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
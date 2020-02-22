#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<int> e[mn], g[mn];
bool ok[mn], a[mn][mn];

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
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        g[v].push_back(u);
    }   
    for (int i = 0; i < k; ++ i)
    {
        char id;
        cin >> id;
        if (id == 'X')
        {
            int u;
            cin >> u;
            if (ok[u]) continue;
            ok[u] = 1;
            for (int v : e[u])
            a[u][v] = 1;
            for (int v : g[u])
            a[v][u] = 1;
            a[u][u] = 1;
            for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j)
            if (a[i][u] && a[u][j])
            a[i][j] = 1;
        }
        else
        {
            int s, t;
            cin >> s >> t;
            if (!ok[s]) continue;
            if (!ok[t]) continue;
            cout << (a[s][t] ? "Y" : "N");
        }
    }
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
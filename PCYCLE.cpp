#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, m, s, c[mn];
bool ok[mn];
vector<pair<int, int> > e[mn];
vector<int> sol;
int cnt = 0;

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

void dfs (int u, int d)
{
    if (s < 0) return;
    if ((u == d) && (cnt == m))
    {
        for (int i : sol) cout << i << " ";
        exit(0);
    }
    for (auto x : e[u])
    {
        int i = x.first, v = x.second;
        if (ok[i]) continue;
        s += c[i];
        ok[i] = 1;
        sol.push_back(v);
        ++ cnt;
        dfs (v, d);
        -- cnt;
        sol.pop_back();
        s -= c[i];
        ok[i] = 0;
    }
}

void enter()
{
    cin >> n >> m;
    int k;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v >> c[i];
        k = u;
        e[u].push_back({i, v});
        e[v].push_back({i, u});
    }   
    for (int i = k; i <= k; ++ i)
    {
        sol.push_back(i);
        dfs (i, i);
        sol.pop_back();
    }
    cout << - 1;
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
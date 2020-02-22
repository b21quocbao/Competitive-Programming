#include <bits/stdc++.h>

#define fn "test"
#define fn1 "FOOTBALL"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<int> e[mn];
int ok[mn], tr[mn];

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

int dfs (int u, int l, int r)
{
    if (ok[u]) return ok[u];
    tr[u] = 0;
    ok[u] = 1;
    int s = 0;
    for (int v : e[u])
    if (v >= l && v <= r)
    if (dfs (v, l, r) > s)
    {
        s = dfs (v, l, r);
        tr[u] = v;
    }
    ok[u] += s;
    return ok[u];
}

void enter()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        int x;
        cin >> x;
        if (x) e[i].push_back(j);
    }
    for (int i = 1; i <= k; ++ i)
    {
        int u, v, res = 0, ru;
        cin >> u >> v;
        memset (ok, 0, sizeof (ok));
        for (int j = u; j <= v; ++ j)
        if (dfs (j, u, v) > res)
        {
            res = dfs (j, u, v);
            ru = j;
        }
        cout << res << " ";
        for (; ru; ru = tr[ru])
        cout << ru << " ";
        cout << "\n";
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
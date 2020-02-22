/*
Code by b21
Time: 22:05 Thu 07/11/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
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
   else if (ifstream("FAILURE.inp"))
    {
        freopen("FAILURE.inp", "r", stdin);
        freopen("FAILURE.out", "w", stdout);
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

int cycle, h[mn], n, m, fa[mn];
vector<int> e[mn];
vector<int> V;
bool ld = 0;
int U;

int dfs (int u, int w)
{
    int s = 0;
    for (int v : e[u])
    if (v != U)
    {
        if (!h[v])
        {
            fa[v] = u;
            h[v] = h[u] + 1;
            s += dfs (v, u);
        }
        if (h[v] < h[u] && v != w)
        {
            ++ s;
            if (ld) V.emplace_back(v);
            if (ld) V.emplace_back(u);
        }
    }
    return s;
}

void Init()
{
    cycle = 0;
    V.clear();
    ld = 0;
    U = 0;
    for (int i = 1; i <= n; ++ i)
    {
        h[i] = 0;
        e[i].clear();
    }
}


void enter()
{
    cin >> n >> m;
    // cin >> n; m = n - 1;
    Init();
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int u;
    ld = 1;
    for (int i = 1; i <= n; ++ i)
    if (!h[i])
    {
        h[i] = 1;
        int x = dfs (i, 0);
        if (x)
        {
            if (cycle)
            {
                cout << - 1;
                return;
            }
            u = i;
            cycle += x;
        }
    }
    if (!cycle)
    {
        cout << - 1;
        return;
    }
    int mi = INT_MAX;
    if (cycle == 1)
    {
        if (h[V[0]] < h[V[1]]) swap (V[0], V[1]);
        for (; V[0] != fa[V[1]]; V[0] = fa[V[0]])
        mi = min (mi, V[0]);
        cout << mi;
        return;
    }
    ld = 0;
    if (V.size() == 4)
    {
        int Mi = INT_MAX, cn = 0;
        for (int i : V)
        Mi = min (Mi, h[i]);
        for (int i : V)
        if (h[i] == Mi) ++ cn;
        if (cn == 2)
        {
            vector<int> l;
            for (int i : V)
            if (h[i] != Mi)
            l.emplace_back(i);
            assert (l[0] != l[1]);
            while (h[l[0]] != h[l[1]])
            if (h[l[0]] > h[l[1]]) l[0] = fa[l[0]];
            else l[1] = fa[l[1]];
            while (l[0] != l[1]) l[0] = fa[l[0]], l[1] = fa[l[1]];
            V.emplace_back(l[0]);
        }
    }
    for (int i = 0; i < min (5, (int)V.size()); ++ i)
    {
        U = V[i];
        fill_n (h + 1, n, 0);        
        if (U == u) u = e[u][0];
        h[u] = 1;
        if (!dfs (u, 0))
        mi = min (mi, V[i]);
    }
    if (mi == INT_MAX) mi = - 1;
    cout << mi;
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

main()
{
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
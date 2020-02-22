#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

struct Z
{
    int v, c, f;
    vector<Z>:: iterator t;
    Z(){};
    Z (int V, int C, int F)
    {
        v = V; c = C; f = F;
    }
};
vector<Z>::iterator cur[mn];

int n, m, s, t, h[mn];
int ex[mn];
int cn[2 * mn];
vector<Z> e[mn];

queue<int> qu;

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
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; ++ i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        e[u].emplace_back(v, c, 0);
        e[v].emplace_back(u, 0, 0);
        e[u].back().t = prev (e[v].end());
        e[v].back().t = prev (e[u].end());
    }
    for (int i = 1; i <= n; ++ i)
    cur[i] = e[i].begin();
}

void init ()
{
    for (auto& u : e[s])    
    {
        u.f = u.c;
        cerr << u.v << " " << u.t->v << "\n";
        u.t->f = - u.c;
        ex[u.v] += u.c;
        ex[s] -= u.c;
    }
    fill_n (h + 1, n, 1);
    h[s] = n;
    h[t] = 0;
    cn[n] = cn[0] = 1;
    cn[1] = n - 2;
    for (int i = 1; i <= n; ++ i)
    if (i != s && i != t && ex[i] > 0)
    {
        // cerr << i << "\n";
        qu.push (i);
    }
}

void Set (int u, int H)
{
    -- cn[h[u]];
    h[u] = H;
    ++ cn[H];
}

void gap (int H)
{
    if (H <= 0 || H >= n || cn[H]) return;
    for (int u = 1; u <= n; ++ u)
    if (u != s && H < h[u] && h[u] <= n)
    {
        Set (u, n + 1);
        cur[u] = e[u].begin();
    }
}   

void Lift (int u)
{
    int mi = 2 * n;
    for (auto v : e[u])
    if (v.c > v.f)
    mi = min (mi, h[v.v]);
    int r = h[u];
    Set (u, mi + 1);
    gap (r);
}

void Push (int u, vector<Z>::iterator v)
{
    int d = min ((v->c) - (v->f), ex[u]);
    v->f += d;
    (v->t)->f -= d;
    ex[v->v] += d;   
    ex[u] -= d;
}

void preflow()
{
    while (qu.size())
    {
        int u = qu.front(); qu.pop();
        cerr << u << "\n";
        for (;cur[u] != e[u].end(); ++ cur[u])
        {
            if (cur[u]->c > cur[u]->f && h[u] > h[cur[u]->v])
            {
                if (cur[u]->v != s && cur[u]->v != t && !ex[cur[u]->v])
                qu.push (cur[u]->v);
                Push (u, cur[u]);
                if (!ex[u]) break;
            }
        }
        if (ex[u])
        {
            Lift (u);
            cur[u] = e[u].begin();
            qu.push (u);
        }
    }
    cout << ex[t];
}

void solve()
{
    init();
    preflow();
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
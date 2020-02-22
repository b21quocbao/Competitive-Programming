#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MAYTAP"

using namespace std;

const int mn = 5 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 2 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

struct Z
{
    int v, c, f, t;
    Z (){}
    Z (int V, int C, int F, int T)
    {
        v = V; c = C; f = F; t = T;
    }
};
int n, r, c, s, t;
bool ok[mn];
int h[mn], cn[2 * mn];
int ex[mn];
int de[mm][mm];
vector<Z> e[mn];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
queue<int> qu;
vector<Z>::iterator cur[mn];


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

void ae (int u, int v)
{
    e[u].emplace_back(v, 1, 0, e[v].size());
    e[v].emplace_back(u, 0, 0, e[u].size() - 1);
}

bool kt (int x, int y)
{
    return (x >= 1 && x <= r && y >= 1 && y <= c);
}

void enter()
{
    cin >> n >> r >> c;
    for (int i = 1; i <= n; ++ i)
    {
        int x, y;
        cin >> x >> y;
        de[x][y] = i;
        ok[i] = ((x + y) & 1);
    }
    for (int i = 1; i <= r; ++ i)
    for (int j = 1; j <= c; ++ j)
    if (de[i][j])
    if (ok[de[i][j]])
    for (int h = 0; h < 4; ++ h)
    {
        int x = i + hx[h], y = j + hy[h];
        if (!kt (x, y)) continue;
        if (!de[x][y]) continue;
        ae (de[i][j], de[x][y]);
    }
    for (int i = 1; i <= n; ++ i)
    if (ok[i])
    ae (n + 1, i);
    else
    ae (i, n + 2);
    s = n + 1;
    t = n + 2;
}

void init()
{
    for (auto& u : e[s])
    {
        u.f = u.c;
        e[u.v][u.t].f = - u.c;
        ex[u.v] += u.c;
        ex[s] -= u.c;
        qu.push (u.v);
    }
    fill_n (h + 1, n, 1);
    h[s] = n; h[t] = 0; 
    cn[1] = n;
    cn[n] = cn[0] = 1;
}

void Push (const int& u, vector<Z>::iterator v)
{
    int d = min (ex[u], v->c - v->f);
    ex[u] -= d;
    ex[v->v] += d;
    v->f += d;
    e[v->v][v->t].f -= d;
}

inline void Set (int u, int H)
{
    -- cn[h[u]];
    ++ cn[h[u] = H];
}

void Gap (int H)
{
    if (H <= 0 || H >= n || cn[H]) return;
    for (int i = 1; i <= n + 2; ++ i)
    if (i != s && h[i] <= n && h[i] > H)
    {
        Set (i, n + 1);
        cur[i] = e[i].begin();  
    }
}

void Lift (int u)
{
    int mi = (int)(1e8);
    for (auto v : e[u])
    if (v.c > v.f)
    mi = min (mi, h[v.v]);
    int r = h[u];
    Set (u, mi + 1);
    Gap (r);
}

inline bool Kt (const int& u)
{
    return (u != t && u != s && !ex[u]);
}

void preflow()
{
    for (int u = 1; u <= n; ++ u)
    cur[u] = e[u].begin();
    while (qu.size())
    {
        int u = qu.front(); qu.pop();
        for (; cur[u] != e[u].end(); ++ cur[u])
        if (cur[u]->c > cur[u]->f && h[u] > h[cur[u]->v])
        {
            if (Kt (cur[u]->v)) qu.push (cur[u]->v);
            Push (u, cur[u]);
        }
        if (ex[u])
        {
            Lift (u);
            cur[u] = e[u].begin();
            qu.push (u);
        }
    }
    cout << n - ex[t];
}

void solve()
{
    init();
    preflow ();
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
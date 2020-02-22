#include <bits/stdc++.h>

#define fn "test"
#define fn1 "STAR"

using namespace std;

const int mn = 2 * (int)(1e2) + 10;
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


struct Z
{
    int x, y, d, c;
    Z (){}
    Z (int X, int Y, int D, int C)
    {
        x = X; y = Y; d = D; c = C;
    }
};

class MaxFlow
{
    public:
    
    int n, s, t, r = 0;
    queue<int> qu;
    vector<int> cn, h, ex;
    struct Z
    {
        int v,  f,  c,  t;
        Z () {}
        Z (int V, int F, int C, int T) : v (V), f (F), c (C), t (T) {}
    };
    vector<vector<Z>::iterator > cur; 
    vector<Z> e[mn];
    void AddE (int u, int v, int c, bool ok = 0)
    {
        if (u == s) r += c;
        e[u].emplace_back(v, 0, c, e[v].size());
        if (!ok)
        e[v].emplace_back(u, 0, 0, e[u].size() - 1);
        else
        e[v].emplace_back(u, 0, c, e[u].size() - 1);
    }
    MaxFlow (int N, int S, int T) : 
    n (N), s (S), t (T) 
    {
        cn.resize (2 * n + 2);
        h.resize(n + 2, 1);
        ex.resize(n + 2);
        cur.resize(n + 2);
    }

    void Argue (int u, Z& v, int c)
    {
        ex[u] -= c;
        ex[v.v] += c;
        v.f += c;
        e[v.v][v.t].f -= c;
    }

    void Init()
    {
        for (auto& u : e[s])
        {
            Argue (s, u, u.c);
            if (u.v != t)
            qu.emplace (u.v);
        }
        for (int i = 1; i <= n; ++ i)
        cur[i] = e[i].begin();
        h[s] = n;
        h[t] = 0;
        cn[1] = n - 2;
        cn[n] = cn[0] = 1;
    }

    void UdH (int u, int H)
    {
        -- cn[h[u]];
        h[u] = H;
        ++ cn[H];
    }

    void Gap (int H)
    {
        if (H <= 0 || H >= n || cn[H]) return;
        for (int u = 1; u <= n; ++ u)
        if (h[u] > H && h[u] <= n && u != s)
        {
            UdH (u, n + 1);
            cur[u] = e[u].begin();
        }
    }

    void Lift (int u)
    {
        int minH = 2 * n;
        for (auto v : e[u])
        if (v.c > v.f)
        minH = min (minH, h[v.v] + 1);
        int r = h[u];
        UdH (u, minH);
        Gap (r);
    }

    void Push (int u, vector<Z>::iterator r)
    {
        int mi = min (r->c - r->f, ex[u]);
        Argue (u, *r, mi);
    }

    void process ()
    {
        while (qu.size())
        {
            int u = qu.front(); qu.pop();
            for (; cur[u] != e[u].end(); ++ cur[u])
            {
                auto r = cur[u];
                if (r->f == r->c) continue;
                if (h[u] <= h[r->v]) continue;
                if (!ex[r->v] && r->v != s && r->v != t) qu.emplace (r->v);
                Push (u, r);
                if (!ex[u]) break;
            }
            if (ex[u])
            {
                Lift (u);
                cur[u] = e[u].begin();
                qu.push (u);
            }
        }
    }

    bool Sol ()
    {
        Init();
        process();
        return (r == ex[t]);
    }

};

int r[mn], c[mn];
vector<int> e[mn];
int in[mn], out[mn];


void enter()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        char d;
        cin >> d;
        if (d != '0') 
        {
            ++ r[i];
            ++ c[j];
            if (d == '*')
            e[i].emplace_back(j);
        }
    }
    int inf = 0, sup = max (m, n), Sol = - 1;
    // inf = sup = 0;
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        vector<Z> v;
        bool ok = 0;
        for (int j = 1; j <= n; ++ j)
        {
            if (2 * c[j] < m - mid) ok = 1;
            v.emplace_back(m + j, n + m + 2, max (0, (2 * c[j] - m - mid + 1) / 2), (2 * c[j] - m + mid) / 2);
        }
        for (int i = 1; i <= m; ++ i)
        {
            if (2 * r[i] < n - mid) ok = 1;
            for (int j : e[i])
            v.emplace_back(i, j + m, 0, 1);
            v.emplace_back(n + m + 1, i, max (0, (2 * r[i] - n - mid + 1) / 2), (2 * r[i] - n + mid) / 2);
        }
        for (const auto& x: v)
        if (x.d > x.c) ok = 1;
        if (ok)
        {
            inf = mid + 1;
            continue;
        }
        memset (in, 0, sizeof (in));
        memset (out, 0, sizeof (out));
        // for (auto x : v)
        // cerr << x.x << " " << x.y << " " << x.d << " " << x.c << "\n";
        for (auto& x : v)
        {
            in[x.y] += x.d;
            out[x.x] += x.d;
            x.c -= x.d;
        }
        for (int i = 1; i <= n + m + 2; ++ i)
        {
            v.emplace_back (n + m + 3, i, 0, in[i]);
            v.emplace_back (i, n + m + 4, 0, out[i]);
        }
        v.emplace_back (n + m + 2, n + m + 1, 0, base);
        MaxFlow sol (n + m + 4, n + m + 3, n + m + 4);
        for (const auto& x : v)
        sol.AddE (x.x, x.y, x.c);
        if (sol.Sol ())
        {
            Sol = mid;
            sup = mid - 1;
        }
        else inf = mid + 1;
    }
    cout << Sol;
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
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
    int u, c, w;
    Z (){}
    Z (int U, int C, int W)
    {
        u = U; c = C; w = W;
    }
    bool operator < (const Z& a) const
    {
        return c < a.c;
    }
};
vector<Z> e[110];
map<int, int, greater<int> > d[110];
int sol[110];

bool check (int v, int c, int w)
{
    auto it = d[v].lower_bound(c);
    cerr << v << " " << c << " " << w << " " << c * w << "\n";
    if (sol[v] == - 1)
    sol[v] = c * w;
    else
    sol[v] = min (sol[v], c * w);
    if (it == d[v].end() || it -> second > w)
    {
        d[v][c] = w;
        return 1;
    }
    return 0;
}

void enter()
{
    int n, m;
    cin >> n >> m;
    memset (sol, - 1, sizeof (sol));
    for (int i = 0; i < m; ++ i)
    {
        int u, v, c, w;
        cin >> u >> v >> c >> w;
        e[u].emplace_back(v, c, w);
        e[v].emplace_back(u, c, w);
    }
    priority_queue<Z> qu;
    qu.emplace (1, 0, 0);
    while (qu.size())
    {
        int u = qu.top().u, c = qu.top().c, w = qu.top().w;
        qu.pop();
        for (auto v : e[u])
        if (check (v.u, c + v.c, w + v.w))
        qu.emplace(v.u, c + v.c, w + v.w);
    }
    for (int i = 2; i <= n; ++ i)
    cout << sol[i] << "\n";
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
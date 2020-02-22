#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LAMPS"

using namespace std;

const int mn = 3 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[mn], h[mn];
int f[mn][2];
int tr[mn][2];
bool ok[mn], oks[mn];
vector<int> e[mn];
vector<int> sv;

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
    ok[u] = 1;
    for (int v : e[u])
    if (!h[v])
    {
        ok[u] = 0;
        h[v] = h[u] + 1;
        dfs (v);
    }
}

int F (int u, int k, int c)
{
    if (f[u][k][c] != - 1) return f[u][k][c];
    if (c == 1)
    {
        int r = d[]
        for (int v : e[u])

    }
    return f[u][k];
}

void enter()
{
    int n, t;
    cin >> n >> t;
    for (int i = 1; i < n; ++ i)
    {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    h[1] = 1;  
    dfs (1);
    for (int i = 0; i < t; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
        cin >> d[j];
        memset (f, - 1, sizeof (f));
        cerr << F (3, 1) << "\n";
        if (F (1, 1) == - 2)
        {
            cout << - 1 << "\n";
            continue;
        }
        else
        {
            vector<pair<int, int> > v;
            v.push_back({1, 1});
            if (f[1][1]) sv.push_back(1);
            while (v.size())
            {
                auto u = v.back();
                v.pop_back();
                for (int x : e[u.first])
                if (h[x] > h[u.first])
                {
                    if (f[x][tr[u.first][u.second]] == 1) 
                    sv.push_back(x);
                    v.push_back({x, tr[u.first][u.second]});
                }
            }
            cout << sv.size() << " ";
            for (int i : sv) cout << i << " ";
            cout << "\n";
            sv.clear();
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
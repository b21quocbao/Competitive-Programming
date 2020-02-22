#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
int a[mn], te, n;
vector<int> v, e[mn];
int tr[mn], ok[mn], fa[mn];
int h[mn];

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

bool bfs ()
{
    queue<int> qu;
    fill_n (h + 1, n, 0);
    for (int i : v)
    for (int j : e[i])
    if (!h[j])
    {
        h[j] = 1;
        qu.push (j);
    }
    bool Ok = 0;
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();
        if (!fa[u]) 
        {
            Ok = 1;
            continue;
        }
        for (int v : e[fa[u]])
        if (!h[v])
        {
            h[v] = h[u] + 1;
            qu.push (v);
        }
    }
    return Ok;
}

bool dfs (int u, int lv)
{
    for (int v : e[fa[u]])
    if (h[v] == lv && ok[v] != te)
    {
        ok[v] = te;
        if (!fa[v] || dfs (fa[v], lv + 1)) 
        {
            fa[u] = v;
            fa[v] = u;
            return 1;
        }
    }
    return 0;
}

void enter()
{
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        for (int j = 1; j < i; ++ j)
        if (a[j] != a[i])
        {
           e[i].push_back(j);
           e[j].push_back(i);
           if (!fa[j] && !fa[i])
           {
               fa[j] = i;
               fa[i] = j;
           }
        }
    }
    for (int i = 1; i <= n; ++ i)
    if (!fa[i]) v.push_back(i);
    while (bfs ())
    {
        ++ te;
        for (int i = 0; i < v.size(); ++ i)
        {
            if (!dfs (v[i], 1)) continue;
            swap (v[i], v.back());
            v.pop_back();
        }
    }
    int sol = 0;
    for (int i = 1; i <= n; ++ i)
    if (fa[i]) ++ sol;
    cout << sol;
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
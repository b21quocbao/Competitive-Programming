#include <bits/stdc++.h>

#define fn "test"
#define fn1 "GRIDMORPH"

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int r, c;
vector<int> e[mn], e1[mn], ve[mn], ve1[mn];
int deg[mn], deg1[mn];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};

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

bool kt (int x, int y)
{
    return (x >= 1 && x <= r && y >= 1 && y <= c);
}

int Id (int x, int y)
{
    return (x - 1) * c + y;
}

#define vi vector<int>
bool operator < (const vi& a, const vi& b)
{
    if (a.size() != b.size()) return (a.size() < b.size());
    for (int i = 0; i < a.size(); ++ i)
    if (a[i] != b[i]) return (a[i] < b[i]);
}

void enter()
{
    read (r); read (c); 
    int m = r * (c - 1) + (r - 1) * c;
    int n = r * c;
    int ma = 0;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        read (u); read (v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
        ma = max (ma, u);
        ma = max (ma, v);
        if (u > n || v > n)
        {
            cout << "No";
            return;
        }
        ++ deg[u];
        ++ deg[v];
        if (deg[u] > 4 || deg[v] > 4)
        {
            cout << "No";
            return;
        }
    }
    if (ma < n)
    {
        cout << "No";
        return;
    }
    for (int u = 1; u <= n; ++ u)
    sort (e[u].begin (), e[u].end(), [](int i, int j)
         {
             return deg[i] < deg[j];
         });
    for (int u = 1; u <= n; ++ u)
    {
        ve[u].emplace_back(deg[u]);
        for (int v : e[u])
        {
            ve[u].emplace_back(deg[v]);
            // for (int k : e[v])
            // ve[u].emplace_back(deg[k]);
        }
    }
    for (int i = 1; i <= r; ++ i)
    for (int j = 1; j <= c; ++ j)
    for (int h = 0; h < 4; ++ h)
    {
        int x = i + hx[h];
        int y = j + hy[h];
        if (!kt (x, y)) continue;
        int u = Id (i, j), v = Id (x, y);
        e1[u].emplace_back(v);
        ++ deg1[u];
    }
    for (int u = 1; u <= n; ++ u)
    sort (e1[u].begin (), e1[u].end(), [](int i, int j)
         {
             return deg1[i] < deg1[j];
         });
    for (int u = 1; u <= n; ++ u)
    {
        ve1[u].emplace_back(deg1[u]);
        for (int v : e1[u])
        {
            ve1[u].emplace_back(deg1[v]);
            // for (int k : e[v])
            // ve1[u].emplace_back(deg1[k]);
        }
    }
    sort (ve + 1, ve + n + 1);
    sort (ve1 + 1, ve1 + n + 1);
    for (int i = 1; i <= n; ++ i)
    if (ve[i] != ve1[i])
    {
        cout << "No";
        return;
    }
    cout << "Yes";
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
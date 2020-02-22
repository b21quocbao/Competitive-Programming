#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SWAP2S"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int sol = 0;
vector<int> vt[2][mn];
int a[2][mn];
int ok[mn], id[mn], con[mn];
vector<int> V;

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

void sw (int u)
{
    cerr << u << "\n";
    ++ sol;
    ok[u] = 0;
    for (int j = 0; j < vt[0][a[0][u]].size(); ++ j)
    if (vt[0][a[0][u]][j] == u)
    vt[0][a[0][u]].erase (vt[0][a[0][u]].begin() + j);
    for (int j = 0; j < vt[1][a[1][u]].size(); ++ j)
    if (vt[1][a[1][u]][j] == u)
    vt[1][a[1][u]].erase (vt[1][a[1][u]].begin() + j);
    swap (a[0][u], a[1][u]);
    vt[0][a[0][u]].emplace_back(u);
    vt[1][a[1][u]].emplace_back(u);
}

int dfs (int u)
{
    if (ok[u]) return ok[u];
    if (vt[ud][a[1 - ud][u]].empty()) return ok[u];
    con[u] = vt[ud][a[1 - ud][u]][0];
    return ok[u] = dfs (vt[ud][a[1 - ud][u]][0]) + ok[u];
}

bool operator > (pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    return a.first > b.first;
    return a.second < b.second;
}

void enter()
{
    int n;
    cin >> n;
    int ma = 1;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[0][i];
        vt[0][a[0][i]].emplace_back(i);
        ma = max (ma, a[0][i]);
    }
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[1][i];
        vt[1][a[1][i]].emplace_back(i);
        ma = max (ma, a[1][i]);
        id[i] = i;
    }
    // for (int i = 1; i <= n; ++ i)
    // if (vt[0][a[0][i]].size() == 2 && vt[1][a[1][i]].size() == 2)
    // sw (i);
    for (int i = 1; i <= n; ++ i)
    {
        if (vt[0][a[0][i]].size() == 2)
        ++ ok[i];
        if (vt[1][a[1][i]].size() == 2)
        ++ ok[i];
        dfs (i);
    }
    sort (id + 1, id + n + 1, [](int i, int j)
         {
             return ok[i] > ok[j];
         });
    for (int j = 1; j <= n; ++ j)
    {
        int i = id[j];
        if (ok[i]) 
        {
            while (i) 
            {
                sw (i);
                i = con[i];
            }
        }
    }
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
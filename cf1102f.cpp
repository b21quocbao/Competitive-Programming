//b21
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
int m, n;

int a[18][10010];
vector<int> e[18];
bool ok[18][18];
bool f[1 << 16][18][18];

bool kt (int i, int j, int k)
{
    for (int l = 0; l < n; ++ l)
    if (abs (a[i][l] - a[j][l]) < k) return 0;
    return 1;
}

bool ktd (int i, int j, int k)
{
    for (int l = 0; l < n - 1; ++ l)
    if (abs (a[j][l] - a[i][l + 1]) < k) return 0;
    return 1;
}

void enter()
{
    cin >> m >> n;
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> a[i][j];
    if (m == 1)
    {
        int sol = INT_MAX;
        for (int j = 1; j < n; ++ j)
        sol = min (sol, abs (a[0][j - 1] - a[0][j]));
        cout << sol;
        return;
    }
    int inf = 0, sup = base, sol = - 1;
    while (inf <= sup)
    {
        int k = (inf + sup) >> 1;
        for (int i = 0; i < m; ++ i)
        e[i].clear();
        for (int i = 0; i < m; ++ i)
        for (int j = 0; j < m; ++ j)
        if (i != j)
        {
            if (kt (i, j, k))
            e[i].emplace_back(j);
            ok[i][j] = ktd (i, j, k);
        }
        memset (f, 0, sizeof (f));
        for (int t = 0; t < m; ++ t)
        f[1 << t][t][t] = 1;
        bool Ok = 0;
        for (int i = 0; i < (1 << m); ++ i)
        for (int t = 0; t < m; ++ t)
        if ((i >> t) & 1)
        for (int l = 0; l < m; ++ l)
        if ((i >> l) & 1)
        if (f[i][t][l])
        {
            if (i == (1 << m) - 1 && ok[t][l]) Ok = 1;
            for (int v : e[l])
            if (((i >> v) & 1) == 0)
            f[i + (1 << v)][t][v] = 1;
        }
        if (Ok)
        {
            sol = k;
            inf = k + 1;
        }
        else sup = k - 1;
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
#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DIVSET"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, a[mn];
vector<int> e[mn];
pair<int, int> b[mn];
int m;
int sol = 0;

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

void dfs (int u, int s, int a)
{
    for (int v : e[u])
    if (v != a)
    dfs (v, s + b[v].second, u);
    sol = max (sol, s);
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        e[0].push_back(i);
    }   
    sort (a + 1, a + n + 1);
    int s = 1;
    for (int j = 1; j <= n; ++ j)
    if (a[j] == a[j + 1]) ++ s;
    else
    {
        b[++ m] = {a[j], s};
        s = 1;
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= m; ++ j)
    if (j != i)
    if (b[i].first % b[j].first == 0)
    e[j].push_back(i);
    // cout << m << "\n";
    // for (int i = 1; i <= m; ++ i)
    // {
    //     cout << b[i].first << " " << b[i].second << "\n";
    //     cout << "ok ";
    //     for (int j : e[i])
    //     cout << j << " ";
    //     cout << "\n";
    // }
    dfs (0, 0, 0);
}

void solve()
{
    cout << sol;
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
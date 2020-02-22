#include <bits/stdc++.h>
 
#define FOR(i, a, b) for (int i = a; i < b; ++ i)
#define ROR(i, b, a) for (int i = b; i > a; -- i)
#define FOE(i, a, b) for (int i = a; i <= b; ++ i)
#define ROE(i, b, a) for (int i = b; i >= a; -- i)
#define X first
#define Y second
#define fn "test"
#define fn1 "ROADS"
 
using namespace std;
struct z
{
    int a, b, c;
    z(){}
    z(int _a, int _b, int _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
};
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<ii> vii;
typedef vector<pl> vll;
 
const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e5) + 10;
const int base = 1 * (int)(1e4);
 
int tt, ntest = 1;
int f[205][20005];
int n, k, m;
vector<z> e[205];
 
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        freopen(fn".out", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}
 
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
 
void write(int a)
{
    int i = 0;
    char S[20];
    if (a == 0) {putchar('0'); return;}
    while(a > 0)
    {
        S[i++] = a % 10 + '0';
        a /= 10;
    }
    --i;
    while(i >= 0) putchar(S[i--]);
}
 
void enter()
{
    cin >> n >> m >> k;
    int u, v, w, t;
    FOE (i, 1, n) e[i].clear();
    FOR (i, 0, m)
    {
        cin >> u >> v >> w >> t;
        //e[u].push_back(z(v, w, t));
        e[v]    .push_back(z(u, w, t));
    }
}
 
int fu (int n, int k)
{
    if (k < 0) return - 1;
    if (n == 1) return 0;
    if (f[n][k] != - 2) return f[n][k];
    f[n][k] = - 1;
    FOR (i, 0, e[n].size())
    {
        int v = e[n][i].a;
        int w = e[n][i].b;
        int t = e[n][i].c;
        if (k - t < 0) continue;
        if (fu(v, k - t) == - 1) continue;
        f[n][k] = f[n][k] == - 1 ? fu (v, k - t) + w : min(f[n][k], fu(v, k - t) + w);
    }
    return f[n][k];
}
 
void solve()
{
    fill (f[0], f[n + 1], - 2);
    cout << fu (n, k) << "\n" ;
}
 
void print_result()
{
 
}
 
main()
{
    docfile();
    // cin >> ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
 
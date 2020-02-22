#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TRANS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, m, ok[mn];
long long k;
vector<int> sv;
long long sol = 0;
vector<int> e[mn];

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

void bfs ()
{
    queue<int> qu;
    qu.push (1);
    ok[1] = 1;
    while (qu.size())
    {
        int u = qu.front();
        qu.pop();
        for (int v : e[u])
        if (!ok[v])
        {
            ok[v] = ok[u] + 1;
            sv.push_back(ok[v] - 1);
            qu.push (v);
        }
    }
}

void enter()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs ();
}

void solve()
{
    long long inf = 0, sup = (long long)(1e15);
    while (inf <= sup)
    {
        long long mid = (inf + sup) >> 1;
        long long res = 0;
        for (int x : sv)
        {
            res += (mid / x);
            if (res >= k) break;
        }
        if (res >= k)
        {
            sol = mid;
            sup = mid - 1;
        }
        else inf = mid + 1;
    }
}

void print_result()
{
    cout << sol;
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
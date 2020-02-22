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
long long sol;
int fa[mn];
string s;

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

int Fa (int u)
{
    return (fa[u] < 0 ? u : fa[u] = Fa (fa[u]));
}

void uni (int x, int y)
{
    x = Fa (x); y = Fa (y);
    if (x == y) return;
    if (fa[x] > fa[y]) swap (x, y);
    if (s[x] != s[y] && s[x] != '?' && s[y] != '?')
    sol = 0;
    if (s[y] != '?') 
    s[x] = s[y];
    fa[x] += fa[y];
    fa[y] = x;
}

void enter()
{
    int n, m;
    read (n); read (m);
    sol = 1;
    s.clear();
    // s.reserve(n);
    for (char c = getchar(); isalpha(c) || c == '?'; c = getchar())
        s.push_back(c);
    for (int i = 0; i < n; ++ i)
    fa[i] = - 1;
    for (int i = 0; i < n; ++ i)
    uni (i, n - 1 - i);
    for (int i = 0; i < m; ++ i)
    {
        int x, y;
        read (x); read (y);
        -- x; -- y;
        uni (x, y);
    }
    for (int i = 0; i < n; ++ i)
    if (Fa (i) == i && s[i] == '?')
    sol = (sol * 26) % mod;
    cout << sol << "\n";
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
    read (ntest);
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
#include <bits/stdc++.h>

#define fn "test"
#define fn1 "STRCHG"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n;
string s, t;
int d[mn][30], h[mn][30];

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

int D (char c, int a, int b)
{
    return d[b][c - 'a'] - d[a - 1][c - 'a'];
}

int H (char c, int a, int b)
{
    return h[b][c - 'a'] - h[a - 1][c - 'a'];
}

bool Ok (int a, int b, int x, int y)
{
    for (char c = 'a'; c <= 'z'; ++ c)
    if (D (c, a, b) != H(c, x, y)) return 0;
    return 1;
}

void pre (string s, int d[mn][30])
{
    for (int i = 1; i <= n; ++ i)
    for (char c = 'a'; c <= 'z'; ++ c)
    if (c == s[i])
    d[i][c - 'a'] = d[i - 1][c - 'a'] + 1;
    else 
    d[i][c - 'a'] = d[i - 1][c - 'a'];
    
}

bool check (int a, int b, int x, int y)
{
    if (a > b) return 1;
    if (a == b) return 1;
    if (!Ok (a, b, x, y)) return 0;
    int k = (b - a + 1) >> 1;
    return ((check (a, a + k - 1, x, x + k - 1) && check (a + k, b, x + k, y)) || (check (a, a + k - 1, x + k, y) && check (a + k, b, x, x + k - 1)));
}

void enter()
{
    string s, t;
    getline (cin, s);
    getline (cin, t);
    n = s.size();
    s = ' ' + s;
    t = ' ' + t;
    pre (s, d);
    pre (t, h);
    cout << (check (1, n, 1, n) ? "Yes" : "No") << "\n";
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
    cin>>ntest;
    cin.ignore();
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
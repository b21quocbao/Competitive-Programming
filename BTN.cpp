#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 "BTN"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[mm][mm][mm][2], n, k;
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

int da (int a, int b)
{
    if (s[a] == ')' || s[a] == ']' || s[a] == '}') return 0;
    if (s[b] == '(' || s[b] == '[' || s[b] == '{') return 0;
    if (s[a] == '?' && s[b] == '?') return 3; 
    if (s[a] == '?' || s[b] == '?') return 1;
    if (s[a] == '(' && s[b] != ')') return 0;
    if (s[a] == '[' && s[b] != ']') return 0;
    if (s[a] == '{' && s[b] != '}') return 0;
    return 1;
}

int F (int a, int b, int k, bool ok)
{
    if (((b - a) & 1) == 0) return 0;
    if (k < 0) return 0;
    if (a > b) return (k == 0 ? 1 : 0);
    if (s[b] == '(' || s[b] == '[' || s[b] == '{') return 0;
    if (s[a] == ')' || s[a] == ']' || s[a] == '}') return 0;
    if (f[a][b][k][ok] != - 1) return f[a][b][k][ok];
    f[a][b][k][ok] = da(a, b) * F (a + 1, b - 1, k - 1, 0);
    if (ok) return f[a][b][k][ok];
    for (int d = a + 1; d <= b - 2; ++ d)
    {
        for (int l = 1; l < k; ++ l)
        {
            f[a][b][k][ok] += F (a, d, l, 0) * F (d + 1, b, k, 1);
            f[a][b][k][ok] += F (a, d, k, 0) * F (d + 1, b, l, 1);
        }
        f[a][b][k][ok] += F (a, d, k, 0) * F (d + 1, b, k, 1);
    }
    return f[a][b][k][ok];
}  

void enter()
{
    cin >> n >> k;
    cin >> s;
    memset (f, - 1, sizeof (f));
    cout << F (0, n - 1, k, 0);
}

void solve()
{

}

void print_result()
{

}

int32_t main()
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
#include <bits/stdc++.h>

#define fn "test"
#define fn1 "NUMSET"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
string s, a, b;
int f[1010][1010][2][2];

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

int F (int i, int j, bool lh, bool bd)
{
    if (j == ma) return 1;
    if (i == ma) return 0;
    int ma = (lh ? 9: a[i] - '0');
    if (bd)
    f[i][j][lh][bd] = F (ne[i][0], j, lh, bd);
    else
    f[i][j][lh][bd] = F (i, j + 1, lh, bd);
    for (int k = 1; k <= ma; ++ k)
    f[i][j][lh][bd] += F (ne[i][k], j + 1, lh, bd);
    return f[i][j][lh][bd];
}

void ch (string& s, int ma)
{
    reverse (s.begin(), s.end());
    while (s.size() < ma) s.e
}

void enter()
{
    cin >> s >> a >> b;
    auto ma = max (s.size(), max (a.size(), b.size()));
    ch (s, ma);
    ch (a, ma);
    ch (b, ma);
    memset (f - 1, sizeof (f));
    auto r = F (0, 0, 0, 0);
    swap (a, b);
    memset (f - 1, sizeof (f));
    cout << F (0, 0, 0, 0) - r;
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
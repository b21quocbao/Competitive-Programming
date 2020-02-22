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

int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int N;
int f[20][2010];

int F (int l, int m, int k)
{
    if (m < 0) return 0;
    // cerr << l << " " << m << "\n";
    if (!l) return 1;
    if (f[l][m] != - 1) return f[l][m];
    f[l][m] = 0;
    for (int i = k; i < 10; ++ i)
    f[l][m] += F (l - 1, m - a[i], k + 1);
    if (!f[l][m]) f[l][m] = 1;
    return f[l][m];
}

void enter()
{
    int l, m;
    cin >> l >> m;
    N = 0;
    // l <<= 1;
    memset (f, - 1, sizeof (f));
    m /= 7;
    cout << F (l, m, 0) << "\n";
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
    sort (a, a + 10);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
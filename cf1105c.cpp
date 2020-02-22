#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
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

int n, l, r;
long long f[mn][3];
long long sl[3];

long long F (int N, int D)
{
    if (N == n) return (!D ? 1 : 0);
    if (f[N][D] != - 1) return f[N][D];
    f[N][D] = 0;
    for (int i = 0; i < 3; ++ i)
    {
        f[N][D] += F (N + 1, (D + i) % 3) * sl[i];
        f[N][D] %= mod;
    }
    return f[N][D];
}

void enter()
{
    cin >> n >> l >> r;
    sl[0] = r / 3 - (l - 1) / 3; 
    sl[1] = (r - 1) / 3 - (l == 1 ? - 1 : (l - 2) / 3);
    sl[2] = (r - l + 1) - sl[0] - sl[1];
    memset (f, - 1, sizeof (f));
    cout << F (0, 0);
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
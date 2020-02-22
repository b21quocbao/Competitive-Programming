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

int n, k, a[110], s[mn][110], f[mn][110];

int F (int K, int N);


int S (int K, int N)
{
    if (K < 0) return 0;
    if (N == n) return (K >= k);
    cout << K << " " << N << "\n";
    if (s[K][N] != - 1) return s[K][N];
    s[K][N] = S (K - 1, N) + F (K, N);
    if (s[K][N] >= mod) s[K][N] -= mod;
    return s[K][N];
} 

int F (int K, int N)
{
    if (K > k) return 0;
    if (K < 0) return 0;
    if (N == n) return (K == k);
    if (f[K][N] != - 1) return f[K][N];
    f[K][N] = S (min (K + a[N], k), N + 1) - S (K - 1, N + 1);
    if (f[K][N] < 0) f[K][N] += mod;
    return f[K][N];
}

void enter()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    memset (f, - 1, sizeof (f));
    memset (s, - 1, sizeof (s));
    cout << S (100000, 13);
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
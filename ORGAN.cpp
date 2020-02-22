#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "ORGAN"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, a[mn], gt[mn];;

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

int po (int n, int k)
{
    if (!k) return 1ll;
    int n1 = po (n, k >> 1);
    n1 = (n1 * n1) % mod;
    return ((k & 1) ? (n1 * n) % mod : n1);
}

int C (int n, int k)
{
    if (n < k) return 0;
    return ((gt[n] * po (gt[n - k], mod - 2)) % mod * po (gt[k], mod - 2)) % mod; 
}

void enter()
{
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    sort (a + 1, a + n + 1);
    gt[0] = 1ll;
    for (int i = 1; i <= n; ++ i)
    gt[i] = (gt[i - 1] * i) % mod;
    long long sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        sol = (sol + C (i - 1, k - 1) * a[i]) % mod;
        // cerr << C (i - 1, k - 1) << " " << a[i] << "\n";
    }
    cout << sol; 
}

void solve()
{

}

void print_result()
{

}

main()
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
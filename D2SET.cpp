#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 "D2SET"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, mod;
int a[mn];
bool ok[mn];

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

int lo2 (int n)
{
    int cn = 0;
    for (int i = 2; i <= n; i <<= 1)
    ++ cn;
    return cn;
}

long long po (int n, int k)
{
    if (!k) return 1ll;
    int N = po (n, k >> 1);
    N = (N * N) % mod;
    return ((k & 1) ? N * n : N);
}

void enter()
{
    read (n); read (mod);
    long long sol = 0, sol2 = 1;
    if (n <= 0)
    {
        for (int i = 1; i <= n; ++ i)
        read (a[i]);
        sort (a + 1, a + n + 1);
        for (int i = 1; i <= n; ++ i)
        if (!ok[i])
        {
            int r = 0;
            for (int k = a[i]; k <= (int(1e9)); k <<= 1)
            {
                int j = lower_bound (a + 1, a + n + 1, k) - a;
                if (j == n + 1 || a[j] != k) break;
                ok[j] = 1;
                ++ r;
            }
            sol += ((r + 1) >> 1);
            if (r % 2 == 0) 
            sol2 = (sol2 * (r / 2 + 1)) % mod;
        }
        cout << sol << " " << sol2 << "\n";
    }
    else
    {
        for (int i = 1; i <= n; i += 2)
        {
            int l1 = i, l2 = n, re;
            while (l1 <= l2)
            {
                int mid = (l1 + l2) >> 1;
                if (lo2 (n / mid) == lo2 (n / i))
                {
                    re = mid;
                    l1 = mid + 1;
                }
                else l2 = mid - 1;
            }
            if (re % 2 == 0) -- re;
            int cn = (re - i) / 2 + 1;
            int l = lo2 (n / i) + 1;
            sol += cn * ((l + 1) >> 1);
            if (l % 2 == 0) 
            sol2 = (sol2 * po (l / 2 + 1, cn)) % mod;
            i = re;
        }
        cout << sol << " " << sol2 << "\n";
    }
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
#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
bool ok[mn];
long long mu[200];
vector<int> v;

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

long long po (long long a, long long n, long long mo)
{
    if (!n) return 1ll;
    long long a1 = po (a, n >> 1, mo);
    a1 %= mo;
    a1 = (a1 * a1) % mo;
    return ((n & 1) ? (a1 * a) % mo : a1); 
}

void eros (int n)
{
    for (int i = 2; i <= trunc(sqrt(n)); ++ i)
    if (!ok[i])
    for (int j = i * i; j <= n; j += i)
    ok[j] = 1;
    for (int i = 2; i <= n; ++ i)
    if (!ok[i])
    v.push_back(i);
}

void enter()
{
    long long a, b, n;
    cin >> a >> b >> n;
    auto c = a - b;
    if (!c)
    {
        cout << (po (a, n, mod) + po (b, n, mod)) % mod << "\n";
        return; 
    }
    long long sol = 1;
    for (int i : v)
    {
        if (c == 1) break;
        int cn = 0;
        mu[cn ++] = 1;
        while (c % i == 0) 
        {
            c /= i;
            mu[cn] = mu[cn - 1] * i;
            ++ cn;
        }
        int inf = 0, sup = cn - 1;
        long long res;
        while (inf <= sup)
        {
            int mid = (inf + sup) >> 1;
            if ((po (a, n, mu[mid]) + po (b, n, mu[mid])) % mu[mid] == 0)
            {
                res = mu[mid] % mod;
                inf = mid + 1;
            }
            else sup = mid - 1;
        }
        sol = (sol * res) % mod;
    }
    if ((a % c == 0) && (b % c == 0)) sol = (sol * (c % mod)) % mod;
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
    eros (1000000);
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
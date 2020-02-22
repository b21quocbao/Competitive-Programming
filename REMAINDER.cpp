#include <bits/stdc++.h>

#define fn "test"
#define fn1 "REMAINDER"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mm = 1 * (int)(1e3) + 10;

const int base = 1 * (int)(1e9);
const bool aNs = 0;
typedef unsigned long long ull;
const ull rm = RAND_MAX + 1;

int tt, ntest = 1;
long long x, n, mod;

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

ull mul (ull a, ull n)
{
    if (!n) return 0ull;
    auto A = mul (a, n >> 1);
    A = (A + A) % mod;
    return ((n & 1) ? (A + a) % mod : A);
}

ull F (ull x, ull n)
{
    if (n == 1ull) return (1ull % mod);
    if (n & 1)
    return (1 + mul (x, F (x, n - 1))) % mod;
    return (mul (x + 1, F (mul (x, x), n >> 1)));
}

void enter()
{
    cin >> x >> n >> mod;   
    auto x1 = x;
    ull d = 1;
    while (d <= x)
    d *= 10;
    d %= mod;
    x %= mod;
    cout << mul (x, F (d, n)) << "\n";
}

ull Ran (ull a, ull b)
{
    ull x = a + ((ull)rand() * rm * rm * rm + (ull)rand() * rm * rm + (ull)rand() * rm + (ull)rand()) % (b - a + 1);
    return x;
}

void solve()
{
    cerr << Ran (100000, 999999) << "\n";
}

void print_result()
{

}

int main()
{
    srand(time(nullptr));
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
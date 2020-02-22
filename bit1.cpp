#include <bits/stdc++.h>

#define fn "test"
#define fn1 "bit1"

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

#define pll pair<long long, long long>
const long long bas = (long long)(1e18);
void operator += (pll& a, const pll& b)
{
    a.first += b.first + (a.second + b.second) / bas;
    a.second = (a.second + b.second) % bas;
} 

void enter()
{
    long long n;
    pll s;
    cin >> n;
    ++ n;
    for (int i = 1; (1ll << (i - 1)) <= (n - 1); ++ i)
    {
        s += make_pair (0, n / (1ll << i) * (1ll << (i - 1)));
        if ((n / (1ll << i)) % 2 == 1) s += make_pair (0, n % (1ll << i));
    }
    if (!s.first)
    cout << s.second;
    else 
    cout << s.first << setfill('0') << setw(18) << s.second;
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
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

unsigned long long C (int n, int k)
{
    vector<int> v;
    for (int i = 1; i <= n; ++ i)
    v.push_back(i);
    for (int i = 1; i <= k; ++ i)
    for (int& j : v)
    if ((j % i) == 0)
    {
        j /= i;
        break;
    }
    for (int i = 1; i <= n - k; ++ i)
    {
        int k = i;
        for (int& j : v)
        {
            int r = __gcd (k, j);
            j /= r;
            k /= r;
        }
    }
    unsigned long long s = 1;
    for (int j : v)
    s *= (unsigned long long)j;
    return s;
}

void enter()
{
    int n, m, t;
    cin >> n >> m >> t;
    unsigned long long sol = 0;
    for (int i = 4; i < t; ++ i)
    if (i <= n && t - i <= m)
    {
        sol += C (n, i) * C (m, t - i);
    }
    cout << sol;
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
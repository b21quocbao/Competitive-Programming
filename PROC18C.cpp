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
long long f[22][210][2][2];
long long s[220];

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

long long F (int i, int s, vector<int> v, bool ok, bool ok1)
{
    if (s < 0) return 0;
    if (i == v.size()) return (!s ? 1 : 0);
    if (f[i][s][ok][ok1] != - 1) return f[i][s][ok][ok1];
    f[i][s][ok][ok1] = 0;
    for (int j = 0; j <= (ok1 ? 9 : v[i]); ++ j)
    f[i][s][ok][ok1] = (f[i][s][ok][ok1] + F (i + 1, s - j, v, ok, ok1 | (j < v[i]))) % mod;
    return f[i][s][ok][ok1];
}

void enter()
{
    long long l, r;
    cin >> l >> r;
    -- l;
    memset (f, - 1, sizeof (f));
    memset (s, 0, sizeof (s));
    vector<int> v1, v2;
    while (l)
    {
        v1.push_back(l % 10);
        l /= 10;
    }
    while (r)
    {
        v2.push_back(r % 10);
        r /= 10;
    }
    while (v1.size() < 20) v1.push_back(0);
    while (v2.size() < 20) v2.push_back(0);
    reverse (v1.begin(), v1.end());
    reverse (v2.begin(), v2.end());
    
    long long sol = 0;
    for (int i = 1; i <= 200; ++ i)
    {

        s[i] = (F (0, i, v2, 0, 0) - F (0, i, v1, 1, 0)) % mod;
        if (s[i] < 0) s[i] += mod;
        for (int j = 1; j < i; ++ j)
        if (__gcd (i, j) == 1)
        sol = (sol + (s[i] * s[j]) % mod) % mod;
    }
    sol += s[1] * (s[1] - 1) / 2;
    sol %= mod;
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
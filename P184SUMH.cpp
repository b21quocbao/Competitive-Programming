#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e1) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 200;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long l, r;
int n, a[mn];
long long cs[20][mm];
long long f[mm];

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

long long CS (int n, int s)
{
    if (!n) return (!s ? 1 : 0);
    if (n < 0 || s < 0) return 0;
    if (cs[n][s] != - 1) return cs[n][s];
    cs[n][s] = 0;
    for (int i = 0; i <= 9; ++ i)
    cs[n][s] += CS (n - 1, s - i);
    return cs[n][s];
}

long long F (long long s)
{
    vector<int> v;
    memset (f, 0, sizeof (f));
    int t = 0;
    while (s)
    {
        v.push_back(s % 10);
        t += s % 10;
        s /= 10;
    }
    f[t] = 1;
    int su = 0;
    for (int i = v.size() - 1; i >= 0; -- i)
    {
        for (int j = 0; j < v[i]; ++ j)
        for (int k = 0; k < mm; ++ k)
        f[k] += CS (i, k - su - j);
        su += v[i];
    }
    f[0] = 0;
    long long sol = 0;
    for (int k = 0; k < mm; ++ k)
    {
        bool ok = 0;
        for (int i = 0; i < n; ++ i)
        if (k % a[i] == 0) ok = 1;
        if (ok) sol += f[k];
    }
    return sol;
}   

void enter()
{
    cin >> l >> r;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
    }
    cout << F (r) - F (l - 1) << "\n";
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
    memset (cs, - 1, sizeof (cs));
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
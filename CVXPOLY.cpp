#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1234567;
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

pair<int, int> operator - (pair<int, int> x, pair<int, int> y)
{
    return {x.first - y.first, x.second - y.second};
}

long long operator * (pair<int, int> x, pair<int, int> y)
{
    return x.first * y.second - x.second * y.first;
}

pair<int, int> a[110];
int id[110];
int f[110][110][110];
int n;
bool ok[110];

int F (int i, int j, int I)
{
    if (ok[id[i]]) return 0;
    if (ok[id[j]]) return 0;
    if (f[i][j][I] != - 1) return f[i][j][I];
    if (i == 1) return 1;
    f[i][j][I] = 0;
    for (int k = i - 1; k >= 1; -- k)
    if ((a[id[i]] - a[id[k]]) * (a[id[j]] - a[id[i]]) > 0)
    {
        f[i][j][I] += F (k, i, I);
        if (f[i][j][I] >= mod) f[i][j][I] -= mod;
    }
    return f[i][j][I];
}

void enter()
{
    cin >> n;
    memset (f, - 1, sizeof (f));
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i].first >> a[i].second;
        id[i] = i;
    }
    int sol = 0;
    for (int I = 1; I <= n; ++ I)
    {
        for (int i = 1; i <= n; ++ i)
        if (a[i].second < a[I].second || (a[i].second == a[I].second && a[i].first < a[I].first)) 
        ok[i] = 1;
        else ok[i] = 0;
        sort (id + 1, id + n + 1, [&](int i, int j)
             {
                 if (i == I) return true;
                 if (j == I) return false;
                 return (a[i] - a[I]) * (a[j] - a[I]) > 0;
             });
        for (int j = 2; j <= n; ++ j)
        {
            sol += F (j, 1, I);
            if (sol >= mod) sol -= mod;
        }
    }
    sol %= mod;
    if (sol < 0) sol += mod;
    cout << sol << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
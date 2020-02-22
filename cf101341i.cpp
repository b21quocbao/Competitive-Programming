#include <bits/stdc++.h>
#define int long long

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

int a[mm][mm], row[mm], col[mm], rowadd[mm], coladd[mm], b[mm][mm], c[mm][mm], rowb[mm], colb[mm], d[mm][mm];

void enter()
{
    srand (time(nullptr));
    int n;
    cin >> n;
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> a[i][j];
        row[i] += a[i][j];
        col[j] += a[i][j];
        row[i] %= mod;
        col[j] %= mod;
        v.emplace_back(i, j);
    }
    int s = 0, sum = 0;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> b[i][j];
        rowb[i] += b[i][j];
        colb[j] += b[i][j];
        rowb[i] %= mod;
        colb[j] %= mod;
        sum += b[i][j];
        sum %= mod;
    }
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> c[i][j];
        rowadd[i] += c[i][j];
        // rowmul[i] *= c[i][j];
        rowadd[i] %= mod;
        // rowmul[i] %= mod;
        coladd[j] += c[i][j];
        // colmul[j] *= c[i][j];
        coladd[j] %= mod;
        // colmul[j] %= mod;
    }
    if (n <= 400)
    {
        for (int k = 1; k <= n; ++ k)
        for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
        {
            d[i][j] += a[i][k] * b[k][j];
            d[i][j] %= mod;
        }
        for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
        if (d[i][j] != c[i][j])
        {
            cout << "NO";
            return;
        }
        cout << "YES";
        return;
    }
    random_shuffle (v.begin(), v.end());
    for (int i = 0; i < min (50000ll, (int)v.size()); ++ i)
    {
        int x = v[i].first, y = v[i].second;
        int s = 0;
        for (int k = 1; k <= n; ++ k)
        {
            s += a[x][k] * b[k][y];
            s %= mod;
        }
        if (s != c[x][y])
        {
            cout << "NO";
            return;
        }
    }
    for (int i = 1; i <= n; ++ i)
    {
        int s = 0;
        for (int j = 1; j <= n; ++ j)
        {
            s += a[i][j] * rowb[j];
            s %= mod;
        }
        if (s != rowadd[i]) 
        {
            cout << "NO";
            return;
        }
        s = 0;
        for (int j = 1; j <= n; ++ j)
        {
            s += col[j] * b[j][i];
            s %= mod;
        }
        if (s != coladd[i])
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
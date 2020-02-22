#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MAXEXP"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 52;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
const int nd = 18;
const long long R = (long long)(1e18);
const int nc = 3;
#define ar array<long long, nc> 

int tt, ntest = 1;
int hx[2] = {0, 1};
int hy[2] = {1, 0};
string s[mm];
int m, n;
int a[mm][mm];
ar f[mm][mm];
ar d[mm][mm][mm][mm];

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

inline bool kt (int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n);
}

inline bool operator < (const ar& a, const ar& b)
{
    for (int i = 0; i < nc; ++ i)
    if (a[i] != b[i]) return (a[i] < b[i]);
    return 0;
}

inline ar operator * (ar a, const int& b)
{
    long long r = 0;
    for (int i = nc - 1; i >= 0; -- i)
    {
        a[i] = a[i] * b + r;
        r = a[i] / R;
        a[i] %= R;
    }
    return a;
}

inline ar operator + (ar a, const ar& b)
{
    bool r = 0;
    for (int i = nc - 1; i >= 0; -- i)
    {
        a[i] += b[i] + r;
        if (a[i] >= R)
        {
            a[i] -= R;
            r = 1;
        }
    }
    return a;
}

inline ostream& operator << (ostream& out, const ar& a)
{
    int ok = 0;
    for (int i = 0; i < nc; ++ i)
    {
        if (a[i]) ++ ok;
        if (ok)
        {
            if (ok > 1)
            cout << setfill ('0') << setw (nd) << a[i];
            else
            cout << a[i];
        }
    }
    if (!ok) cout << 0;
    return cout;
}

void premul ()
{
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    if (a[i][j] > 0)
    for (int k = i; k < m; ++ k)
    for (int l = j; l < n; ++ l)
    if (a[k][l] > 0)
    {
        if (i == k && j == l)
        {
            d[i][j][k][l][nc - 1] = a[i][j];
            continue;
        }
        d[i][j][k][l][0] = - 1;
        for (int h = 0; h < 2; ++ h)
        {
            int k1 = k - hx[h], l1 = l - hy[h];
            if (!kt (k1, l1)) continue;
            if (a[k1][l1] == - 2) continue;
            for (int h = 0; h < 2; ++ h)
            {
                int k2 = k1 - hx[h], l2 = l1 - hy[h];
                if (!kt (k2, l2)) continue;
                if (d[i][j][k2][l2][0] == - 1) continue;
                d[i][j][k][l] = max (d[i][j][k][l], d[i][j][k2][l2] * a[k][l]);
            }
        }
    }
}

ar F (int i, int j)
{
    if (i == m && j == n) return {0, 0, 0};
    if (f[i][j][0] != - 1) return f[i][j];
    f[i][j].fill (0);
    for (int k = i; k < m; ++ k)
    for (int l = j; l < n; ++ l)
    {
        if (d[i][j][k][l][0] == - 1) continue;
        if (k == m - 1 && l == n - 1)
        {
            f[i][j] = max (f[i][j], d[i][j][k][l] + F (m, n));
            continue;
        }
        for (int h = 0; h < 2; ++ h)
        {
            int k1 = k + hx[h], l1 = l + hy[h];
            if (!kt (k1, l1)) continue;
            if (a[k1][l1] == - 1) continue;
            for (int h = 0; h < 2; ++ h)
            {
                int k2 = k1 + hx[h], l2 = l1 + hy[h];
                if (!kt (k2, l2)) continue;
                f[i][j] = max (f[i][j] , d[i][j][k][l] + F (k2, l2));
            }
        }
    }
    return f[i][j];
}

void enter()
{
    cin >> m >> n;
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        char c;
        cin >> c;
        if (c == '*')
        a[i][j] = - 1;
        else if (c == '+')
        a[i][j] = - 2;
        else
        a[i][j] = c - '0';
    }
    premul ();
    memset (f, - 1, sizeof (f));
    cout << F (0, 0);
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
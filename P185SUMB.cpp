#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 4 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[mm][mm];
long double s[mm], sb[mm];

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

void enter()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
        sb[i] = sb[i - 1] + x * x;
        for (int j = 1; j <= 4000; ++ j)
        {
            f[i][j] = f[i - 1][j];
            if (j > x) ++ f[i][j];
        }
    }
    for (int i = 0; i < q; ++ i)
    {
        int l, r;
        cin >> l >> r;
        long double sol1 = (s[r] - s[l - 1]) / (r - l + 1);
        int ll = 1, rr = 4000, resl, resr;
        while (ll <= rr)
        {
            int mid = (ll + rr) >> 1;
            if (f[r][mid] - f[l - 1][mid] <= ((r - l) >> 1))
            {
                resl = mid;
                ll = mid + 1;
            }
            else
            rr = mid - 1;
        }
        ll = 1; rr = 4000;
        while (ll <= rr)
        {
            int mid = (ll + rr) >> 1;
            if (f[r][mid] - f[l - 1][mid] <= ((r - l + 1) >> 1))
            {
                resr = mid;
                ll = mid + 1;
            }
            else 
            rr = mid - 1;
        }
        long double sol2 = (resl + resr) / 2.;
        long double sol3 = (sb[r] - sb[l - 1] - 2 * (s[r] - s[l - 1]) * sol1) / (r - l + 1) + sol1 * sol1;
        cout << fixed << setprecision  (6) << sol1 << " " << sol2 << " " << sol3 << " " << sqrt (sol3) << "\n";
    }
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
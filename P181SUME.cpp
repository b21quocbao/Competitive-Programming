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
int n, a[mn], f[mn], tr[mn];

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

void cnh (int i, int j, int d)
{
    if (f[i] <= f[j] + d) return;
    tr[i] = j;
    f[i] = f[j] + d;
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; -- i)
    {
        int j;
        f[i] = INT_MAX;
        j = upper_bound (a + i + 1, a + n + 1, a[i] + 1440) - a;
        cnh (i, j, 40);
        j = upper_bound (a + i + 1, a + n + 1, a[i] + 120) - a;
        cnh (i, j, 15);
        cnh (i, i + 1, 6);
        cerr << i << " " << tr[i] << "\n";
    }
    int i = 1;
    while (i <= n)
    {
        int j = tr[i];
        int s;
        if (j == i + 1) s = 6;
        else if (a[j - 1] - a[i] <= 120) s = 15;
        else s = 40;
        for (; s; ++ i)
        {
            cout << min (s, 6) << "000\n";
            s -= min (s, 6);
        }
        for (; i < j; ++ i)
        cout << "0\n";
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
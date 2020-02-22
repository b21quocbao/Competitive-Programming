#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mn], s[mn], f[mn], it[4 * mn], d[mn], n;

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

void ud (int id, int ca, int cb, int i, int j, int k)
{
    if (cb < i || ca > k || (cb < j && ca >= i) || (cb <= k && ca > j)) return;
    if (ca == cb)
    {
        it[id] = a[j];
        return;
    }
    if (ca >= i && cb <= k) it[id] = a[j];
    int m = (ca + cb) >> 1;
    ud (id << 1, ca, m, i, j, k);
    ud ((id << 1) | 1, m + 1, cb, i, j, k);
}

int que (int id, int a, int b, int x, int y)
{
    if (a > y || b < x) return 0;
    if (x >= a && b <= y) return 0;
    int m = (a + b) >> 1;
    return max (it[id], max (que (id << 1, a, m, x, y), que ((id << 1) ^ 1, m + 1, b, x, y)));
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        s[i] = d[a[i]] + 1;
        d[a[i]] = i;
    }
    for (int i = 1; i <= n; ++ i)
    d[a[i]] = n + 1;
    for (int i = n; i >= 1; -- i)
    {
        f[i] = d[a[i]] - 1;
        d[a[i]] = i;
        ud (1, 1, n, s[i], i, f[i]);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++ i)
    {
        
        int x, y;
        cin >> x >> y;
        cout << que (1, 1, n, x, y) << "\n";
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
#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "PLANTNK"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
int s[mn], a[mn];

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
    int n, l;
    read (n); read (l);
    if (!n && !l) exit(0);
    for (int i = 1; i <= n; ++ i)
    read (a[i]);
    sort (a + 1, a + n + 1, greater<int>());
    s[n + 1] = 0;
    for (int i = n; i >= 1; -- i)
    s[i] = s[i + 1] + a[i];
    int inf = 1, sup = (long long)(1e10), K, r;
    // inf = 7, sup = 7;
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        int k = upper_bound (a + 1, a + n + 1, mid, greater<int>()) - a;
        int k1 = lower_bound (a + 1, a + n + 1, mid, greater<int>()) - a;
        -- k1;
        k1 += min (n - k + 1, s[k] - (l - k + 1) * mid);
        if (s[k] >= (l - k + 1) * mid)
        {
            K = mid;
            r = k1;
            inf = mid + 1;
        }
        else
        sup = mid - 1;
    }
    cout << K * l + r << "\n";
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
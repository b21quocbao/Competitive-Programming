#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int s[mn], ma[mn], mi[mn], a[mn], g[mn];

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
    int ok = 0;
    int Ma = 0;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        if (a[i - 1] && a[i] != a[i - 1] && s[a[i]])
        {
            cout << "NO";
            return;
        }
        if (!a[i]) 
        {
            a[i] = a[i - 1];
            ok = i;
        }
        s[a[i]] = 1;
        if (a[i] && !a[i - 1])
        {
            for (int j = 1; j < i; ++ j)
            a[j] = a[i];
        }
        Ma = max (Ma, a[i]);
    }
    if (Ma < q && !ok)
    {
        cout << "NO";
        return;
    }
    if (!a[1])
    {
        for (int j = 1; j <= n; ++ j)
        a[j] = q;
    }
    if (Ma < q) a[ok] = q;
    cout << "YES\n";
    for (int i = 1; i <= n; ++ i)
    cout << a[i] << " ";
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
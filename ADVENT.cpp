#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ADVENT"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
pair<int, int> a[mn];
int f[mn];

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
    int n, d, sol = 0, s = 0;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i].first >> a[i].second;
        s += a[i].first;
    }
    cin >> d;
    sort (a, a + n, [](pair<int, int> a, pair<int, int> b)
         {
             return a.first + a.second < b.first + b.second;
         });
    memset (f, - 1, sizeof (f));
    f[0] = s;
    for (int i = n - 1; i >= 0; -- i)
    {
        for (int j = i; j >= 0; -- j)
        if (f[j] != - 1)
        if (f[j] + a[i].first + a[i].second >= d)
        f[j + 1] = max (f[j + 1], f[j] - a[i].first);
    }
    for (int i = n; i >= 0; -- i)
    if (f[i] != - 1)
    {
        cout << i;
        return;
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
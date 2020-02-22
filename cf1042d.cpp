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
int bi[mn];
long long s[mn];

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

void ub (int x)
{
    for (; x >= 1; x -= x & - x)
    ++ bi[x];
}

int db (int x)
{
    int r = 0;
    if (!x) return 0;
    for (; x < mn; x += x & - x)
    r += bi[x];
    return r;
}

void enter()
{
    int n;
    long long t;
    cin >> n >> t;
    vector<long long > v;
    v.emplace_back(0);
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
        v.emplace_back(s[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    long long sol = 0;
    for (int i = 0; i <= n; ++ i)
    {
        sol += db ((int)(upper_bound(v.begin(), v.end(), s[i] - t) - v.begin()) + 1);
        ub ((int)(lower_bound(v.begin(), v.end(), s[i]) - v.begin()) + 1);
    }
    cout << sol;
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
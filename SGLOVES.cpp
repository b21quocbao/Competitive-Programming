#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SGLOVES"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[30], b[30];

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
    int n;
    cin >> n;
    int s = 0, s2 = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 0; i < n; ++ i)
    {
        cin >> b[i];
        s2 += b[i];
    }
    int sol = INT_MAX, R, R2;
    vector<pair<int, int> > v;
    for (int i = 1; i < (1 << n); ++ i)
    {
        int r = 0, r2 = 0;
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        {
            r = max (r, s - a[j] + 1);
            r2 += b[j];
        }
        r2 = s2 - r2 + 1;
        if (r + r2 < sol)
        {
            sol = r + r2;
            R = r;
            R2 = r2;
            v.clear();
            v.emplace_back(r, r2);
        }
        else if (r + r2 == sol)
        v.emplace_back(r, r2);
    }
    swap (a, b);
    swap (s, s2);
    for (int i = 1; i < (1 << n); ++ i)
    {
        int r = 0, r2 = 0;
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        {
            r = max (r, s - a[j] + 1);
            r2 += b[j];
        }
        r2 = s2 - r2 + 1;
        if (r + r2 < sol)
        {
            sol = r + r2;
            v.clear();
            v.emplace_back(r2, r);
        }
        else if (r + r2 == sol)
        v.emplace_back(r2, r);
    }
    for (auto i : v)
    cout << i.first << " " << i.second << "\n";
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
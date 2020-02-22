#include <bits/stdc++.h>

#define fn "test"
#define fn1 "BEADS"

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

void enter()
{
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
    }
    vector<int> v1, v2;
    v1.emplace_back(0);
    v2.emplace_back(INT_MAX);
    int sol = 0;
    for (int i = n - 1; i >= 0; -- i)
    {
        int x = (int)(lower_bound (v1.begin(), v1.end(), a[i]) - v1.begin());
        int y = (int)(lower_bound (v2.begin(), v2.end(), a[i], greater<int>()) - v2.begin());
        sol = max (sol, x + y - 1);
        if (x == v1.size()) v1.emplace_back(a[i]); else v1[x] = a[i];
        if (y == v2.size()) v2.emplace_back(a[i]); else v2[y] = a[i];
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
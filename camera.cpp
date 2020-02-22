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
int d[mn], sol[mn], a[mn], e[mn];

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
    string s;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
    }   
    vector<int> v;
    cin >> s;
    for (int i = 0; i < n; ++ i)
    {
        while (v.size() && a[v.back()] <= a[i]) v.pop_back();
        if (v.size())
        ++ d[v.back()];
        else
        ++ d[0];
        -- d[i];
        v.emplace_back(i);
    }
    v.clear();
    for (int i = n - 1; i >= 0; -- i)
    {
        while (v.size() && a[v.back()] <= a[i]) v.pop_back();
        if (v.size())
        ++ e[v.back()];
        else
        ++ e[n - 1];
        -- e[i];
        v.emplace_back(i);
    }
    int r = 0;
    for (int i = 0; i < n; ++ i)
    {
        r += d[i];
        if (s[i] == 'E') sol[i] = r;
    }
    for (int i = n - 1; i >= 0; -- i)
    {
        r += e[i];
        if (s[i] == 'W') sol[i] = r;
    }
    for (int i = 0; i < n; ++ i)
    cout << sol[i] << " ";
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
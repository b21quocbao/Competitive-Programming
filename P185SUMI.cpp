#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 4 * (int)(1e4) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<int> v;
bool pr[mn];

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

void eros (int n)
{
    for (int i = 2; i <= trunc (sqrt (n)); ++ i)
    if (!pr[i])
    for (int j = i * i; j <= n; j += i)
    pr[j] = 1;
    for (int i = 2; i <= n; ++ i)
    if (!pr[i]) v.push_back(i);
}

void enter()
{
    int sol = 1, c;
    cin >> c;
    for (int i : v)
    {
        if (i * i > c) break;
        if (c % i) continue;
        bool ok = 1;
        while (c % i == 0)
        {
            c /= i;
            ok ^= 1;
            if (ok) sol *= i;
        }
        if (!ok) c *= i;
    }
    cout << sol << " " << c << "\n";
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
    cin>>ntest;
    eros (32000);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
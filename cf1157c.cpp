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

int a[2 * mn];

void enter()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    int sol = 0;
    int d = 1, c = n, cur = 0, D = 0, C;
    string s;
    while (1)
    {
        if (D && d != D) s.push_back('L');
        else if (D) s.push_back('R');
        D = d;
        if (d > c) break;
        if (a[d] <= cur && a[c] <= cur) break;
        if (a[d] <= cur) 
        {
            cur = a[c --];
            continue;
        }
        if (a[c] <= cur) 
        {
            cur = a[d ++];
            continue;
        }
        if (a[d] > a[c]) 
        {
            cur = a[c --];
            continue;
        }
        if (a[c] > a[d]) 
        {
            cur = a[d ++];
            continue;
        }
        int r1 = 0, r2 = 0;
        for (int j = d + 1; j <= c; ++ j)
        if (a[j] > a[j - 1]) ++ r1;
        else break;
        for (int j = c; j > d; -- j)
        if (a[j] < a[j - 1]) ++ r2;
        else break;
        if (r1 < r2) cur = a[c --];
        else cur = a[d ++];
    }
    cout << s.size() << "\n";
    cout << s;
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
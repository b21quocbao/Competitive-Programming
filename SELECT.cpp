#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SELECT"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[3 * mn];
int res[3 * mn];

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
    cin.ignore();
    getline (cin, s);
    s = s + s;
    s = ' ' + s;
    d[1000000] = 1;
    long long sol = 0;
    for (int i = 1; i <= 2 * n; ++ i)
    {
        if (s[i] == '+')
        {
            res[i] = res[i - 1] + 1;
        }
        else
        res[i] = res[i - 1];
        if (i == n + 1)
        -- d[i - n - 1 - 2 * res[i - n - 1] + 1000000];
        if (i > n && i != 2 * n)
        -- d[i - n - 2 * res[i - n] + 1000000];
        sol += d[i - 2 * res[i] + 1000000];
        if (i < n)
        ++ d[i - 2 * res[i] + 1000000];
        // cerr << sol << "\n";
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
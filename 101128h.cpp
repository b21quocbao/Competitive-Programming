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
string a[100], b[100];

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

long long ch (string s)
{
    long long x = 0;
    for (char c : s)
    x = (x << 1) + c - '0';
    return x;
}

void enter()
{
    long long x, y;
    cin >> x >> y;
    for (int i = 1; i <= 63; ++ i)
    a[i] = a[i - 1] + '1';
    for (int i = 1; i <= 63; ++ i)
    b[i] = b[i - 1] + '0';
    vector<long long > v;
    for (int i = 1; i <= 63; ++ i)
    for (int j = 0; j <= 63; ++ j)
    {
        string s = a[i];
        int k = 0;
        while (s.size() <= 63)
        {
            v.emplace_back(ch (s));
            k ^= 1;
            if (k) s += b[j];
            else s += a[i];
        }
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    cout << (int)(upper_bound (v.begin(), v.end(), y) - lower_bound (v.begin(), v.end(), x));
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
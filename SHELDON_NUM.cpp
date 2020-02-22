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

void enter()
{
    vector<long long > v;
    for (int i = 1; i <= 63; ++ i)
    for (int j = 1; j <= 63; ++ j)
    {
        int cn = 0;
        for (int t = 1; t <= 63; ++ t)
        {
            if (t % 2) cn += i;
            else cn += j;
            if (cn > 63) continue;
            long long x = 0;
            for (int l = 0; l < t; ++ l)
            if (l & 1)
            {
                for (int k = 0; k < i; ++ k)
                x = (x << 1) | 1;
            }
            else
            {
                for (int k = 0; k < j; ++ k)
                x <<= 1;
            }
            v.emplace_back(x);
            cerr << x << "\n";
        }
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    long long x, y;
    cin >> x >> y;
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
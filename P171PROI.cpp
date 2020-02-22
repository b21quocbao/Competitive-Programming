#include <bits/stdc++.h>
#define int long long 

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int ok[mn];
vector<long long > f, s;

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
    long long n;
    read (n);
    int j = 0;
    vector<int> v;
    while (n)
    {
        int i = upper_bound (f.begin(), f.end(), n) - f.begin() - 1;
        n -= f[i];
        if (j)
        v.emplace_back(j - i);
        j = i;
    }
    v.emplace_back(j);
    int res = 1, sol = 1;
    for (int j = v.size() - 1; j >= 0; -- j)
    {
        int i = v[j];
        // cerr << i << "\n";
        int r = sol;
        sol = (((i + 2) >> 1) * sox l - ((i + 1) & 1) * res);
        res = r;
    }
    write (sol);
    putchar('\n');
}

void solve()
{

}

void print_result()
{

}

main()
{
    docfile();
    f.emplace_back(1);
    s.emplace_back(1);
    f.emplace_back(1);
    s.emplace_back(2);
    for (int i = 3; i <= 1000; ++ i)
    {
        f.emplace_back(f[f.size() - 1] + f[f.size() - 2]);
        s.emplace_back(s.back() + f.back()); 
        // s.emplace_back(s.back() + f.back())
        if (f.back() > (long long ) (1e18)) 
        {
            // cout << i - 1;
            f.pop_back();
            s.pop_back();
            break;
        }
    }
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
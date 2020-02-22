#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DANCE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mn];

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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    sort (a, a + n);
    long long sol = LLONG_MAX;
    if (n <= 10)
    {
        for (int i = 0; i < (1 << n); ++ i)
        if (__builtin_popcount (i) == k * 2)
        {
            vector<int> v;
            for (int j = 0; j < n; ++ j)
            if ((i >> j) & 1)
            v.emplace_back(a[j]);
            long long r = 0;
            for (int i = 0; i < v.size(); ++ i)
            if (i & 1)
            r += v[i] - v[i - 1];
            sol = min (sol, r);
        }
    }
    else if (k == n / 2)
    {
        long long r = 0;
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; ++ i)
            if (i & 1)
            r += a[i] - a[i - 1];
            sol = min (sol, r);
        }
        else
        {
            for (int k = 0; k < n; ++ k)
            {
                int cn = 0; r = 0;
                for (int i = 0; i < n; ++ i)
                if (i != k)
                {
                    ++ cn;
                    if (cn % 2 == 0)
                    {
                        if (i - 1 == k)
                        r += a[i] - a[i - 2];
                        else
                        r += a[i] - a[i - 1];
                    }
                }
                sol = min (sol, r);
            }
        }
    }
    else
    {
        for (int j = 0; j <= n - 2 * k; ++ j)
        {
            long long r = 0;
            for (int i = j; i < j + k * 2; ++ i)
            if (i % 2 != j % 2)
            r += a[i] - a[i - 1];
            sol = min (sol, r);
        }
        
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
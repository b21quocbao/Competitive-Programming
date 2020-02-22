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
int gt[15];
bool ok[16];

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

bool is_lucky(int n)
{
    while (n)
    {
        if (n % 10 != 4 && n % 10 != 7) return 0;
        n /= 10;
    }
    return 1;
}

int Id (int x)
{
    int cn = 0;
    for (int i = 0; i < 15; ++ i)
    if (!ok[i])
    if (++ cn == x) 
    {
        ok[i] = 1;
        return i; 
    }
}

void enter()
{
    int n, k, sol = 0;
    cin >> n >> k;
    gt[0] = 1;
    for (int i = 1; i <= 12; ++ i)
    gt[i] = gt[i - 1] * i;
    if (n <= 12 && k > gt[n])
    {
        cout << - 1;
        return;
    }
    -- k;
    for (int i = max (n - 12, 1); i <= n; ++ i)
    {
        int x = 1;
        while (k >= gt[n - i])
        {
            k -= gt[n - i];
            ++ x;
        }
        x = max (n - 12, 1) + Id (x);
        if (is_lucky (x) && is_lucky (i))
        ++ sol;
    }
    n = max (n - 12, 1) - 1;
    vector<long long > v;
    v.emplace_back(4);
    v.emplace_back(7);
    while (v.size())
    {
        long long x = v.back();
        v.pop_back();
        if (x > n) continue;
        ++ sol;
        v.emplace_back(x * 10 + 4);
        v.emplace_back(x * 10 + 7);
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
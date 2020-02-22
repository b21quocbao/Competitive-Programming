#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
int ok[mn];
vector<long long > f;

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
    memset (ok, 0, sizeof (ok));
    ok[0] = 1;
    for (int i : f)
    if (i > n) break;
    else
    {
        for (int j = n; j >= i; -- j)
        ok[j] += ok[j - i];
    }
    cout << ok[n] << "\n";
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
    f.emplace_back(1);
    f.emplace_back(2);
    for (int i = 3; i <= 1000; ++ i)
    {
        f.emplace_back(f[f.size() - 1] + f[f.size() - 2]);
        // s.emplace_back(s.back() + f.back())
        if (f.back() > (long long ) (1e18)) 
        {
            // cout << i - 1;
            break;
        }
    }
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
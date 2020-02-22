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
bool ok[mn];
vector<int> pr;

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
    for (int i = 2; i * i <= n; ++ i)
    if (!ok[i])
    for (int j = i * i; j <= n; j += i)
    ok[j] = 1;
    for (int i = 2; i <= n; ++ i)
    if (!ok[i])
    pr.emplace_back(i);
}

void enter()
{
    int n;
    cin >> n;
    if (n % 2)
    {
        cout << 0;
        return;
    }
    n >>= 1;
    int sol = 1;
    int x = trunc(sqrt (n));
    for (int i : pr)
    {
        int cn = 1;
        if (n == 1) break;
        if (i > x) break;
        while (n % i == 0)
        {
            ++ cn;
            n /= i;
        }
        sol *= cn;
    }
    if (n != 1) sol *= 2;
    cout << sol;
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
{
    docfile();
    cin>>ntest;
    eros (31623);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
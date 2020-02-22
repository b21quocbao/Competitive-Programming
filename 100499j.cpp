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
int f[10010];

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
    int n, m, k, x;
    read (n); read (m); read (k);
    memset (f, 0, sizeof (f));
    f[0] = 1;
    vector<int> v;
    for (int i = m; i >= 0; -- i)
    v.emplace_back(i);
    bool ok = 0;
    for (int i = 0; i < n; ++ i)
    {
        read (x);
        if (ok) continue;
        vector<int> v1;        
        for (const int& i : v)
        {
            if (i < x) 
            {
                v1.emplace_back(i);
                continue;
            }
            if (f[i] + f[i - x] >= k)
            continue;
            f[i] += f[i - x];
            v1.emplace_back(i);
        }
        v = v1;
        if (v.empty() || v[0] != m) ok = 1;
    }
    if (ok)
    cout << "ENOUGH";
    else
    cout << f[m];
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
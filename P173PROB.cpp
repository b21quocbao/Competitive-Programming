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
vector<int> e[30];

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
    int n, h;
    cin >> n >> h;
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        char c;
        cin >> c;
        if (c == '1')
        e[i].emplace_back(j);
    }
    vector<int> a (n + 1);
    a[1] = 1;
    long long s = 0;
    map<vector<int>, int > mu, vt;
    for (int j = 1; j <= h; ++ j)
    {
        vector<int> b (n + 1);
        if (mu.find (a) != mu.end())
        {
            int d = s - mu[a];
            int kc = j - vt[a];
            int r = (h - j) / kc;
            j += r * kc;
            s += r * d;
        }
        vt[a] = j;
        mu[a] = s;
        for (int i = 1; i <= n; ++ i)
        {
            for (int k : e[i])
            if (a[i] & 1)
            ++ b[k];
            else 
            b[k] += 2;
            if (i == 1 && j == 1) break;
        }
        int d = 0;
        for (int i = 1; i <= n; ++ i)
        {
            s += b[i];
            d += b[i];
        }
        a = b;
    }
    cout << s;
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
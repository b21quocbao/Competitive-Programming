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

int x[15], y[15], X[15], Y[15], c[15], n, t[15], d[15], f[1 << 15];
vector<int> v, s[15];

int F (int x)
{
    if (x == (1 << n) - 1) return 0;
    if (f[x] != - 1) return f[x];
    f[x] = n;
    for (int i = 0; i < v.size(); ++ i)
    {
        int r = 0;
        for (int j : s[i])
        {
            if ((x >> j) & 1) r |= (1 << j);
            else 
            if ((d[j] & x) == d[j] && (t[j] & r) == t[j]) r |= (1 << j);
        }
        if (r)
        f[x] = min (f[x], F (x | r) + 1);
    }
    return f[x];
}

void enter()
{
    cin >> n;
    memset (f, - 1, sizeof (f));
    v.clear();
    for (int i = 0; i < n; ++ i)
    {
        d[i] = 0;
        t[i] = 0;
        s[i].clear();
        cin >> y[i] >> x[i] >> Y[i] >> X[i] >> c[i];
        v.emplace_back(c[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique (v.begin(), v.end()) - v.begin());
    for (int i = 0; i < n; ++ i)
    {
        c[i] = lower_bound(v.begin(), v.end(), c[i]) - v.begin();
        s[c[i]].emplace_back(i);
    }
    for (int i = 0; i < v.size(); ++ i)
    sort (s[i].begin(), s[i].end(), [](int i, int j)
         {
             return y[i] < y[j];
         });
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    if (y[i] == Y[j] && ((x[j] >= x[i] && x[j] < X[i]) || (X[j] > x[i] && X[j] <= X[i])))
    {
        if (c[i] != c[j])
        d[i] ^= (1 << j);
        else
        t[i] ^= (1 << j);
    }
    cout << F (0) << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
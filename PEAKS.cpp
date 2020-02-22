#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PEAKS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 239;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[mn][40];
int k;
long long n;
vector<int> ok[mod + 5][mod + 5];

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

int F (int n, int k)
{
    if (k < 0) return 0;
    if (!n) return (!k ? 1 : 0);
    if (n <= 2 * (k - 1)) return 0;
    if (f[n][k] != - 1) return f[n][k];
    return f[n][k] = (2 * k * F (n - 1, k) + (n - 2 * (k - 1)) * F (n - 1, k - 1)) % mod;
}

void enter()
{
    int a, b = 0, d = 0;
    // long long n;
    // cin >> n >> k;
    memset (f, - 1, sizeof (f));
    vector<int> v;
    int ma = 0;
    for (int i = 0; i < mod + 5; ++ i)
    for (int j = 0; j < mod + 5; ++ j)
    ok[i][j].clear();
    vector<pair<int, int> > V;
    for (int i = 1; i < mn; ++ i)
    {
        a = b;
        b = F (i, k);
        if (i == n)
        {
            cout << b;
            return;
        }
        for (int j = V.size() - 1; j >= 0; -- j)
        {
            if (F (V[j].first + 1, k) == b) ++ V[j].first, ++ V[j].second;
            else 
            {
                V[j] = V.back();
                V.pop_back();
            }
        }
        for (int i : ok[a][b])
        V.emplace_back(i, 1);
        bool Ok = 0;
        for (auto t : V)
        if (t.second == mod)
        {
            for (int j = t.first; j < i; ++ j)
            {
                v.emplace_back (F (j, k));
                Ok = 1;
            }
            cout << tt << " " << t.first << " " << i - 1 << "\n";
            // cout << v[(n - t.first) % v.size()];
            return;
        }
        else ma = max (ma, t.second);
        if (Ok) break;
        ok[a][b].emplace_back(i);
    }
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
        k = tt;
        n = INT_MAX;
        enter();
        solve();
        print_result();
    }
}
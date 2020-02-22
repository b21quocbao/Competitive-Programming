#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 "SHOTGUN"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int sl[4 * mn];
long long it[4 * mn];
int b[3][mn];
vector<pair<long long, int> > a;


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

long long qu (int id, int l, int r, int x)
{
    if (l == r)
    {
        -- sl[id];
        return it[id];
    }
    int m = (l + r) >> 1;
    int res;
    if (x <= sl[id << 1]) res = qu (id << 1, l, m, x);
    else
    res = qu ((id << 1) ^ 1, m + 1, r, x - sl[id << 1]);
    sl[id] = sl[id << 1] + sl[(id << 1) ^ 1];
    return res;
}

void initit (int id, int l, int r)
{
    if (l == r)
    {
        it[id] = a[l].first;
        sl[id] = a[l].second;
        return;
    }
    int m = (l + r) >> 1;
    initit (id << 1, l, m);
    initit ((id << 1) ^ 1, m + 1, r);
    it[id] = it[id << 1] + it[(id << 1) ^ 1];
    sl[id] = sl[id << 1] + sl[(id << 1) ^ 1]; 
}

void enter()
{
    int n;
    read (n);
    vector<pair<int, int> > v;
    vector<int> f (3);
    f[0] = 1; f[1] = 2; f[2] = 5;
    for (int i = 0; i < 3; ++ i)
    for (int j = 0; j < n; ++ j)
    read (b[i][j]);
    for (int i = 0; i < n; ++ i)
    {
        int d = 3;
        // read (d);
        int x = 1, Q = 0;
        for (int j = 0; j < 3; ++ j)
        {
            int p, q;
            p = b[j][i], q = f[j];
            // cerr << i << " " << p << " " << q << "\n";
            v.push_back({x, q - Q});
            x += p;
            Q = q;
        }
        v.push_back({x, - Q});
    }
    sort (v.begin(), v.end());
    int cur = 1;
    long long s = 0;
    for (auto x : v)
    {
        if (x.first != cur)
        {
            a.push_back({s, x.first - cur});
            cur = x.first;
        }
        s += x.second;
    }
        a.push_back({0, 1000000});
    initit (1, 0, a.size() - 1);
    int q;
    read (q);
    for (int i = 0; i < q; ++ i)
    {
        int x;
        read (x);
        // cerr << x << "\n";
        cout << qu (1, 0, a.size() - 1, x) << "\n";
    }
}

void solve()
{

}

void print_result()
{

}

int32_t main()
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
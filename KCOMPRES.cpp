#include <bits/stdc++.h>

#define int long long
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int it[4 * mn];
int id[mn], a[mn];
int fa[mn];
int n, s;
int f[mn];

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

void ud (int id, int l, int r, int x, int k)
{
    if (l > x || r < x) return;
    if (l == r)
    {
        it[id] = k;
        return;
    }
    int m = (l + r) >> 1;
    ud (id << 1, l, m, x, k);
    ud ((id << 1) ^ 1, m + 1, r, x, k);
    it[id] = max (it[id << 1], it[(id << 1) ^ 1]);
}

void initit (int id, int l, int r)
{
    it[id] = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    initit (id << 1, l, m);
    initit ((id << 1) ^ 1, m + 1, r);
}

int qu (int id, int l, int r, int x, int y)
{
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return it[id];
    int m = (l + r) >> 1;
    return max (qu (id << 1, l, m, x, y), qu ((id << 1) ^ 1, m + 1, r, x, y));
}

bool kt (int k)
{
    int sol = 0;
    initit (1, 1, n);
    int x = 1;
    fill_n (f + 1, n, 0);
    for (int j = 1; j <= n; ++ j)
    {
        fa[id[j]] = id[j];
        if (j == 1) continue;
        if (a[id[j]] == a[id[j - 1]] && id[j] - id[j - 1] <= k)
        fa[id[j]] = fa[id[j - 1]];
    }
    for (int j = 1; j <= n + 1; ++ j)
    {
        if ((j == n + 1) || (j != 1 && a[id[j]] != a[id[j - 1]]))
        {
            for (int l = x; l < j; ++ l)
            {
                int i = id[l];
                ud (1, 1, n, i, f[fa[i]]);
            }
            for (int l = x; l < j; ++ l)
            {
                int i = id[l];
                ud (1, 1, n, i, f[fa[i]]);
                sol += f[fa [i]];
                if (sol > s) return 1;
            }
            x = j;
        }
        if (j == n + 1) continue;
        int i = id[j];
        int res = qu (1, 1, n, max (i - k, 1ll), min (i + k, n)) + 1;
        f[fa [i]] = max (f[fa [i]], res);
    }
    return 0;
}

void enter()
{
    read (n); read (s);
    for (int i = 1; i <= n; ++ i)
    {
        read (a[i]);
        id[i] = i;
    }
    sort (id + 1, id + n + 1, [](int i, int j)
         {
             if (a[i] != a[j])
             return a[i] < a[j];
             return i < j;
         });
    int inf = 0, sup = n, sol = n + 1;
    while (inf <= sup)
    {
        int k = (inf + sup) >> 1;
        if (kt (k))
        {
            sol = k;
            sup = k - 1;
        }
        else inf = k + 1;
    }
    cout << sol << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
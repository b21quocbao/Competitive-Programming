#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PILLARS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e4) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mn], b[mn], h[mn], id[mn], it[4 * mm];

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

void ud (int id, int x, int y, int h, int a, int b)
{
    if (y < a || x > b) return;
    if (x >= a && y <= b)
    {
        it[id] = max (it[id], h);
        return;
    }
    int m = (x + y) >> 1;
    ud (id << 1, x, m, h, a, b);
    ud ((id << 1) | 1, m + 1, y, h, a, b);
}

int que (int id, int x, int y, int a)
{
    if (x > a || y < a) return 0;
    if (x == y) return it[id];
    int m = (x + y) >> 1;
    return max (max (que (id << 1, x, m, a), que ((id << 1) | 1, m + 1, y, a)), it[id]);
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> h[i] >> a[i] >> b[i];
        -- b[i];
        id[i] = i;
    }
    sort (id, id + n, [](int i, int j)
         {
             return h[i] < h[j];
         });
    int sol = 0;
    for (int j = 0; j < n; ++ j)
    {
        int i= id[j];
        sol += h[i] - que (1, 1, 10000, a[i]);
        sol += h[i] - que (1, 1, 10000, b[i]);
        ud (1, 1, 10000, h[i], a[i], b[i]);
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
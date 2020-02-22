#include <bits/stdc++.h>

#define fn "test"
#define fn1 "CARDFLIP"

using namespace std;

const int mn = (1 << 18) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);

int tt, ntest = 1000000000;
int a[mn][2], N, n;
int it[2 * mn][4];
int lo[mn];

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        freopen(fn".out", "w", stdout);
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

inline int Id (int i, int j)
{
    return (i << 1) + j;
}

void ad (int d)
{
    int kc = (1 << (lo[N] - lo[d]));
    int x = kc * (d - (1 << lo[d])); int y = x + kc - 1; int m = (x + y) / 2;
    for (int i = 0; i < 2; ++ i)
    for (int j = 0; j < 2; ++ j)
    {
        it[d][Id (i, j)] = 0;
        for (int k = 0; k < 2; ++ k)
        for (int l = 0; l < 2; ++ l)
        it[d][Id (i, j)] |= (it[(d << 1) | 1][Id (i, k)] && it[(d << 1)][Id (l, j)] && (a[m + 1][k] >= a[m][l]));
    }
}

void initit (int i, int x, int y)
{
    if (x == y)
    {
        memset (it[i], 0, sizeof (it[i]));
        for (int k = 0; k < 2; ++ k)
        for (int l = 0; l < 2; ++ l)
        if (a[x][k] >= a[x][l])
        it[i][Id (k, l)] = 1;
        return;
    }
    int m = (x + y) >> 1;
    initit (i << 1, x, m);
    initit ((i << 1) | 1, m + 1, y);
    ad (i);
}

inline bool check ()
{
    return (it[1][0] || it[1][1] || it[1][2] || it[1][3]);
}

void enter()
{
    read (n);
    if (!n) exit (0);
    N = 1 << (lo[n] + 1);
    if ((n << 1) == N) N = n;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < 2; ++ j)
    read (a[i][j]);
    for (int i = n; i < N; ++ i)
    for (int j = 0; j < 2; ++ j)
    a[i][j] = (int)(1e9) + 1;
    initit (1, 0, N - 1);
    int m;
    read (m);
    for (int i = 0; i < m; ++ i)
    {
        int x, y;
        read (x); read (y);
        -- x; -- y;
        if (x > y) swap (x, y);
        if (x == y) continue;
        swap (a[x], a[y]);
        swap (it[x + N], it[y + N]);
        for (int i = (x + N) >> 1; i; i >>= 1)
        ad (i);
        for (int i = (y + N) >> 1; i > lo[y - x]; i >>= 1)
        ad (i);
        if (check ()) putchar ('1');
        else putchar ('0');
        putchar ('\n');
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
    //cin>>ntest;
    lo[1] = 0;
    int k = 1;
    for (int i = 0; i < mn; ++ i)     
    if (i == (1 << k))
    lo[i] = k ++;
    else lo[i] = k - 1;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
#include <bits/stdc++.h>

#define fn "test"
#define fn1 "BALL"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, m;
long long a, b, c, w;
long long g[3][11][11];
long long l[11][11][11];
long long f[1100000];
long long sol = 0;

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

long long F (int i, int id)
{
    if (!id) return 0;
    if (f[id] != - 1) return f[id];
    int Id = id;
    for (int j = 0; j < n; ++ j)
    if ((id >> j) & 1)
    for (int k = 0; k < n; ++ k)
    if ((id >> (n + k)) & 1)
    {
        id ^= (1 << (j));
        id ^= (1 << (n + k));
        f[Id] = max (f[Id], F (i - 1, id) + l[i][j][k]);
        id ^= (1 << (j));
        id ^= (1 << (n + k));
    }
    return f[Id];
}

void enter()
{
    memset (f, - 1, sizeof (f));
    cin >> n >> a >> b >> c >> w;
    for (int k = 0; k < 3; ++ k)
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> g[k][i][j];
    m = (n >> 1);
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    for (int k = 0; k < n; ++ k)
    {
        cin >> l[i][j][k];
        l[i][j][k] = l[i][j][k] * w + g[0][i][j] * a + g[1][i][k] * b + g[2][j][k] * c;
    }
    cout << F (n - 1, (1 << (2 * n)) - 1);
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
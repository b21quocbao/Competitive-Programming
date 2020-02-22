#include <bits/stdc++.h>

#define fn "test"
#define fn1 "STOCK"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int q[3];
int n, k, d;
long long f[32][102][102][102][2];
int a[32][4];
int l[3];

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

void ma (long long* x, long long y, int a)
{
    if (y == - 2) return;
    if (y + a < 0) return;
    *x = max (*x, y + a);
}

long long F (int id, int l[], bool ok)
{
    for (int i = 0; i < 3; ++ i)
    if (l[i] < 0 || l[i] > q[i]) return - 2;
    if (id == d) return k;
    long long* x = &f[id][l[0]][l[1]][l[2]][ok];
    if (*x != - 1) return *x; 
    *x = - 2;
    if (!ok)
    {
        for (int j = 0; j < 3; ++ j)
        {
            -- l[j];
            ma (x, F (id, l, 0), a[id][j] - 1);
            ++ l[j];
        }
        ma (x, F (id, l, 1), 0);
    }
    else 
    {
        for (int j = 0; j < 3; ++ j)
        {
            ++ l[j];      
            ma (x, F (id, l, 1), - a[id][j] - 1);
            -- l[j];
        }
    }
    ma (x, F (id + 1, l, 0), 0);
    return (*x);
}

void enter()
{
    cin >> n >> k >> d;
    for (int i = 0; i < n; ++ i)
    cin >> q[i];
    for (int t = 1; t <= d; ++ t)
    for (int i = 0; i < n; ++ i)
    cin >> a[t][i];
    queue<pair<int, int*> > qu;
    qu.emplace(0, l);
    f[0][0][0][0][0] = k;
    while (qu.size())
    {
        int id = qu.front().first;
        int* d = qu.front().second;
        qu.pop();
        int x = f[id][d[0]][d[1]][d[2]];
        ma (x, id + 1, h, 0);
        if (!x) continue;
        for (int i = - 1; i <= 1; i += 2)
        for (int j = 0; j < 3; ++ j)
        {
            h[j] += i;
            ma (x, id, h, - i * a[id][j] - 1);
            h[j] -= i;
        }
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
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
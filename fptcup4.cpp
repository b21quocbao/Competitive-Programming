/*
Code by b21
Time: 20:18 Wed 13/11/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("fptcup4.inp"))
    {
        freopen("fptcup4.inp", "r", stdin);
        freopen("fptcup4.out", "w", stdout);
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

int a[1010][1010], n, k;
int f[101][101][101][101];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};

bool kt (int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

struct Z
{
    int k, x, y;
    Z (){}
    Z (int K, int X, int Y)
    {
        k = K, x = X, y = Y;
    }
};


void enter()
{
    cin >> n >> k;
    if (n == - 1 && k == - 1) exit (0); 
    if (k <= 0)
    {
        cout << 0;
        return;
    }
    queue<pair<pair<int, int>, Z> > qu;
    memset (f, - 1, sizeof (f));
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cin >> a[i][j];
    }
    qu.emplace(pair<int, int> (1, 1), Z (a[1][1], 0, 0));
    f[1][1][0][0] = a[1][1];
    int sol = 0;
    int cn = 0;
    while (qu.size() && cn <= 10000000)
    {
        ++ cn;
        int x = qu.front().first.first, y = qu.front().first.second;
        Z z = qu.front().second;
        sol = max (sol, z.k);
        qu.pop();
        for (int h = 0; h < 4; ++ h)
        {
            int X = x + hx[h], Y = y + hy[h];
            if (!kt (X, Y)) continue;
            if (a[X][Y] <= a[x][y]) continue;
            int Zx = z.x + abs (hx[h]), Zy = z.y + abs (hy[h]), res = z.k + a[X][Y];
            if (Zx > k || Zy > k) continue;
            if (f[X][Y][Zx][Zy] > res) continue;
            f[X][Y][Zx][Zy] = res;
            qu.emplace(pair<int, int> (X, Y), Z (f[X][Y][Zx][Zy], Zx, Zy));
        }
    }
    cout << sol;
}

void solve()
{
    cout << "\n";
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
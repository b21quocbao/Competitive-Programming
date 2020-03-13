/*
Code by b21
Time: 11:59 Tue 03/03/2020
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("1314d.inp"))
    {
        freopen("1314d.inp", "r", stdin);
        freopen("1314d.out", "w", stdout);
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

int a[100][100];
int f[90][90][5];

void mi (int& a, int b) {
    if (a == - 1) a = b;
    else a = min (a, b);
}

void enter()
{
    int n, k;
    cin >> n >> k;
    -- k;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> a[i][j];
    memset (f, - 1, sizeof (f));
    for (int i = 0; i < n; ++ i) 
    f[i][i][0] = 0;
    for (int j = 1; j <= 3; ++ j)
    for (int u = 0; u < n; ++ u)
    for (int v = 0; v < n; ++ v)
    for (int i = 0; i < n; ++ i)
    if (i != v)
    if (f[u][i][j - 1] != - 1 && (!(u == v && j % 2)))
    mi (f[u][v][j], f[u][i][j - 1] + a[i][v]);
    int sol = - 1;
    if (k == 1) {
        sol =  f[0][0][2];
    }
    if (k == 3) {
        for (int i = 0; i < n; ++ i) 
        if (f[0][i][3] != - 1)
        if (i)
        mi (sol, f[0][i][3] + a[i][0]);
    }
    if (k == 5) {
        for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
        if (f[0][i][3] != - 1)
        if (f[i][j][2] != - 1)
        if (j)
        mi (sol, f[0][i][3] + f[i][j][2] + a[j][0]);
    }
    if (k == 7) {
        for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
        for (int k = 0; k < n; ++ k)
        if (f[0][i][3] != - 1)
        if (f[i][j][3] != - 1)
        if (f[j][k][1] != - 1)
        if (k)
        mi (sol, f[0][i][3] + f[i][j][3] + f[j][k][1] + a[k][0]);
    }
    if (k == 9 ) {
        for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
        for (int k = 0; k < n; ++ k)
        if (f[0][i][3] != - 1)
        if (f[i][j][3] != - 1)
        if (f[j][k][3] != - 1)
        if (k)
        mi (sol, f[0][i][3] + f[i][j][3] + f[j][k][3] + a[k][0]);
    }
    cout << sol;

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
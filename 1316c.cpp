/*
Code by b21
Time: 21:34 Wed 04/03/2020
*/

#include <bits/stdc++.h>

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("1316c.inp"))
    {
        freopen("1316c.inp", "r", stdin);
        freopen("1316c.out", "w", stdout);
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

pair<int, int> en[mm][mm];
char c[mm][mm];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
char ch[4] = {'L', 'R', 'U', 'D'};
char ch1[4] = {'R', 'L', 'D', 'U'};
int n;

void dfs (pair<int, int> x) {
    for (int h = 0; h < 4; ++ h) {
        int U = x.first + hx[h];
        int V = x.second + hy[h];
        if (!(U >= 1 && U <= n && V >= 1 && V <= n)) continue;
        if (en[U][V] != make_pair(- 1, - 1)) continue;
        c[x.first][x.second] = ch1[h];
        if (c[U][V] == '.') c[U][V] = ch[h];
    }
}

void enter()
{
    read (n);
    queue<pair<int, int> > qu;
    vector<pair<int, int> > v; 
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j) {
        read (en[i][j].first);
        read(en[i][j].second);
        if (make_pair(i, j) == en[i][j]) {
            c[i][j] = 'X';
            qu.emplace(i, j);
        } else if (en[i][j] == make_pair(- 1, - 1)) {
            v.emplace_back(i, j);
            c[i][j] = '.';
        } else c[i][j] = '.';
    }
    for (auto x : v)
    if (c[x.first][x.second] == '.')
    {
        dfs (x);
    }
    while(qu.size()) {
        int u = qu.front().first;
        int v = qu.front().second;
        qu.pop();
        for (int h = 0; h < 4; ++ h) {
            int U = u + hx[h], V = v + hy[h];
            if (!(U >= 1 && U <= n && V >= 1 && V <= n)) continue;
            if (en[U][V] != en[u][v]) continue;
            if (c[U][V] != '.') continue;
            c[U][V] = ch[h];
            qu.emplace(U, V);
        }
    }
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    if (c[i][j] == '.') {
        cout << "INVALID";
        return;
    }
    cout << "VALID\n";
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    cout << c[i][j] << (j == n ? "\n" : "");
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
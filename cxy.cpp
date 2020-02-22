#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
typedef vector<vector<int> > vii; 
const bool aNs = 0;

int tt, ntest = 1;
int n;
struct cmp
{
    bool operator () (pair<vii, int> a, pair<vii, int> b)
    {
        return a.second > b.second;
    }
};
struct node
{
    int id, a, b, x, y;
};
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
char s[4] = {'E', 'W', 'S', 'N'};
vii a, b;
int ok[mm][mm], te;
int k;
pair<int, int> tr[mm][mm];
pair<int, int> d[mm];

void docfile()
{
    ios::sync_with_stdio(false);
- C:\Users\R.I.Z.E.N.O\vimfiles\plugged\syntastic\
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

void enter()
{
    cin >> n >> k;
    a.resize(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> a[i][j];
    b.resize(n, vector<int> (n, 0));
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> b[i][j];
}

char Hg (int x, int y, int a, int b)
{
    for (int h = 0; h < 4; ++ h)
    {
        int X = x + hx[h], Y = y + hy[h];
        if (X == a && Y == b) return s[h];
    }
}

bool kt (int x, int y)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void sol1()
{
    map<vii , int> ok;
    map<vii, node> tr;
    priority_queue<pair<vii, int>, vector<pair<vii, int> >, cmp> qu; 
    ok[a] = 0;
    qu.push ({a, 0});
    while (qu.size())
    {
        vii c = qu.top().first; int d = qu.top().second;
        qu.pop();
        if (c == b) break;
        if (ok[c] != qu.top().second) continue;
        auto A = c;
        int xi, xj;
        for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
        if (!c[i][j]) xi = i, xj = j;
        for (int h = 0; h < 4; ++ h)
        {
            int i = xi + hx[h], j = xj + hy[h];
            if (!kt(i, j)) continue;
            swap (A[i][j], A[xi][xj]);
            if (ok.find (A) == ok.end() || ok[A] > ok[c] + 1)
            {
                ok[A] = ok[c] + 1;
                qu.push ({A, ok[A]});
                tr[A] = {1, i, j, xi, xj};
            }
            swap (A[i][j], A[xi][xj]);
        }
        for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
        if (a[i][j] != - 1 && a[i][j])
        {
            swap (A[i][j], A[xi][xj]);
            if (ok.find (A) == ok.end() || ok[A] > ok[c] + k)
            {
                ok[A] = ok[c] + k;
                qu.push ({A, ok[A]});
                tr[A] = {2, i, j, xi, xj};
            }
            swap (A[i][j], A[xi][xj]);
        }
    }
    cerr << "ok\n";
    vector<node> v;
    while (b != a)
    {
        v.push_back(tr[b]);
        swap (b[tr[b].a], b[tr[b].b]);
    }
    reverse (v.begin(), v.end());
    for (auto x : v)
    if (x.id == 1)
    {
        cout << x.id << " " << x.a << " " << x.b << " " << Hg (x.a, x.b, x.x, x.y) << "\n";
    }
    else
    {
        cout << x.id << " " << x.a << " " << x.b << " " << x.x << " " << x.y << "\n";   
    }
}
void R (int &x, int &y, int u, int v)
{
    swap (a[x][y], a[u][v]);
    cout << 1 << " " << x + 1 << " " << y + 1 << " " << Hg (x, y, u, v) << "\n";
    x = u; y = v;
}

void fin (int u, int v)
{
    int U = u; int V = v;
    ok[u][v] = ++ te;
    queue<pair<int, int> > qu;
    qu.push ({u, v});
    while (qu.size())
    {
        int u = qu.front().first;
        int v = qu.front().second;
        qu.pop();
        if (!a[u][v])
        {
            while (u != U && v != V)
            {
                vector<node> E;
                E.push_back({1, u, v, tr[u][v].first, tr[u][v].second});
                reverse (E.begin(), E.end());
                for (auto x : E)
                R (x.x, x.y, x.a, x.b);
                return;
            }
        }
        for (int h = 0; h < 4; ++ h)
        {
            int x = u + hx[h];
            int y = v + hy[h];
            if (!kt (x, y)) continue;
            if (a[x][y] == - 1) continue;
            if (ok[x][y] == te) continue;
            tr[x][y] = {u, v};
            ok[x][y] = te;
            qu.push ({x, y});
        }
    }
    cerr << "dmm\n";
}

void dc (int u, int v, int x, int y)
{
    while (x > u)
    {
        int x = a[u][v];
        a[u][v] = - 1;
        fin (u + 1, v);
        a[u][v] = x;
        R (u, v, u + 1, v);
    }
    while (x < u)
    {
        int x = a[u][v];
        a[u][v] = - 1;
        fin (u - 1, v);
        a[u][v] = x;
        R (u, v, u - 1, v);
    }
    while (y > v)
    {
        int x = a[u][v];
        a[u][v] = - 1;
        fin (u, v + 1);
        a[u][v] = x;
        R (u, v, u, v + 1);
    }
    while (y < v)
    {
        int x = a[u][v];
        a[u][v] = - 1;
        fin (u, v - 1);
        a[u][v] = x;
        R (u, v, u, v - 1);
    }
    cerr << u << " " << v << "  " << a[u][v] << "\n";
    a[u][v] = - 1;
}

void sol2 ()
{
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    if (b[i][j] != - 1 && b[i][j])
    {
        for (int u = 0; u < n; ++ u)
        for (int v = 0; v < n; ++ v)
        {
            if (a[u][v] == b[i][j])
            dc (u, v, i, j);
        }
    }
}

void solve()
{
    sol2();
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

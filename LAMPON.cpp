#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LAMPON"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 5 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
int m, n;
int hx[4] = {- 1, - 1, 1, 1};
int hy[4] = {- 1, 1, - 1, 1};
int hx2[4] = {- 1, - 1, 0, 0};
int hy2[4] = {- 1, 0, - 1, 0};
string s[510];
int d[mm][mm];
bool ok[mm][mm];

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

bool kt (int x, int y)
{
    return (x >= 0 && x <= m && y >= 0 && y <= n);
}

void enter()
{
    if (!(cin >> m >> n)) exit (0);
    cin.ignore();
    string s1;
    s1.push_back('\\');
    s1.push_back('/');
    s1.push_back('/');
    s1.push_back('\\');
    for (int i = 0; i < m; ++ i)
    getline (cin, s[i]);
    memset (d, - 1, sizeof (d));
    memset (ok, 0, sizeof (ok));
    d[0][0] = 0;
    deque<pair<int, int> > qu;
    qu.emplace_back(0, 0);
    while (qu.size())
    {
        int x = qu.front().first, y = qu.front().second;
        qu.pop_front();
        if (ok[x][y]) continue;
        ok[x][y] = 1;
        for (int i = 0; i < 4; ++ i)
        {
            int X = x + hx[i], Y = y + hy[i];
            int X2 = x + hx2[i], Y2 = y + hy2[i];
            int D = 0;
            if (!kt (X, Y)) continue;
            if (s[X2][Y2] != s1[i]) D = 1;
            if (d[X][Y] == - 1 || d[x][y] + D < d[X][Y])
            {
                d[X][Y] = d[x][y] + D;
                if (D) qu.emplace_back(X, Y);
                else qu.emplace_front(X, Y);
            }  
        }
    }
    if (d[m][n] == - 1)
    cout << "NO SOLUTION";
    else 
    cout << d[m][n];
}

void solve()
{
    cout << "\n";
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
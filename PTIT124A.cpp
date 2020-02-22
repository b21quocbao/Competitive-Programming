#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[30][30];
bool ok[30][30];
int n, m; string s;
int hx[4] = {0, 1, 0, - 1};
int hy[4] = {1, 0, - 1, 0};

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
    return (x >= 0 && x < m && y >= 0 && y < n && ok[x][y]);
}

void enter()
{
    read (m); read (n);
    s.clear();
    for (char c = getchar(); isalpha(c) || (c == ' '); c = getchar())
    s.push_back(c);
    memset (a, 0, sizeof (a));
    memset (ok, 1, sizeof (ok));
    int x = 0, y = 0, h = 0;
    for (char c : s)
    {
        int k = (c - 'A') + 1;
        if (c == ' ') k = 0;
        for (int i = 4; i >= 0; -- i)
        {
            a[x][y] = ((k >> i) & 1);
            ok[x][y] = 0;
            if (!kt (x + hx[h], y + hy[h])) h = (h + 1) % 4;
            x += hx[h]; y += hy[h];
        }
    }    
    cout << tt << " ";
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    cout << a[i][j];
    cout << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
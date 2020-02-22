#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PARIGAME"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 5 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[mm][mm];
bool row[mm][mm], col[mm][mm], CurCol[mm][2], CurRow[mm][2];

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

int F (int m, int n)
{
    if (f[m][n] != - 1) return f[m][n];
    f[m][n] = 0;
    for (int k = 0; k < n; ++ k)
    if (!(row[m][n] ^ row[m][k]))
    if (!F (m, k)) return f[m][n] = 1;
    for (int k = 0; k < m; ++ k)
    if (!(col[m][n] ^ col[k][n]))
    if (!F (k, n)) return f[m][n] = 1;
    return f[m][n];
}

void enter()
{
    int m, n;
    read (m); read (n);
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    f[i][j] = - 1;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        int x;
        read (x);
        x &= 1;
        row[i][j] = row[i - 1][j] ^ x;
        col[i][j] = col[i][j - 1] ^ x;
    }
    for (int i = 1; i <= m; ++ i)
    {
        CurRow[i][0] = 1;
        CurRow[i][1] = 0;
    }
    for (int j = 1; j <= n; ++ j)
    {
        CurCol[j][0] = 1;
        CurCol[j][1] = 0;
    }
    int x;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        row[i][j] ^= row[i][j - 1];
        col[i][j] ^= col[i - 1][j];
        x = 0;
        if (CurRow[i][row[i][j]] | CurCol[j][col[i][j]]) 
        {
            x = 1;
        }
        else
        {
            CurRow[i][row[i][j]] = 1;
            CurCol[j][col[i][j]] = 1;
        }
    }
    cout << (x ? "TRUE" : "FALSE") << "\n";
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
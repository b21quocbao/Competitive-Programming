#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 5 * (int)(1e3) + 200 + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

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

string s[16];
int a[mm][mm];

bool Kt (int x, int y, int m, int n)
{
    return (a[m][n] - a[m][y - 1] - a[x - 1][n] + a[x - 1][y - 1] == 0 || a[m][n] - a[m][y - 1] - a[x - 1][n] + a[x - 1][y - 1] == (m - x + 1) * (n - y + 1));
}

void enter()
{
    int n;
    read (n);
    int ok = 0;
    s[0] = "0000";
    s[1] = "0001";
    s[2] = "0010";
    s[3] = "0011";
    s[4] = "0100";
    s[5] = "0101";
    s[6] = "0110";
    s[7] = "0111";
    s[8] = "1000";
    s[9] = "1001";
    s[10] = "1010";
    s[11] = "1011";
    s[12] = "1100";
    s[13] = "1101";
    s[14] = "1110";
    s[15] = "1111";
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; j += 4)
    {
        int x;
        char c = getchar();
        while (!isdigit(c) && !isalpha(c)) c = getchar();
        if (isdigit (c)) x = c - '0';
        else x = c - 'A' + 10;
        for (int k = j; k < j + 4; ++ k)
        a[i][k] = s[x][k - j] - '0';
    }
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    int sol = 1;
    for (int mid = n; mid >= 2; -- mid)
    if (n % mid == 0)
    {
        bool Ok = 1;
        for (int i = 0; i + mid <= n; i += mid)
        for (int j = 0; j + mid <= n; j += mid)
        if (!Kt (i + 1, j + 1, i + mid, j + mid))
        Ok = 0;
        if (Ok)
        {
            cout << mid;
            return;
        }
    }
    cerr << sol;
    cout << sol;
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
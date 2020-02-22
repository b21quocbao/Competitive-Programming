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
string s[40];
int n;
int hx[4][3] = {{0, 0, 0}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
int hy[4][3] = {{- 2, - 1, 0}, {0, 0, 0}, {0, 1, 2}, {0, - 1, - 2}};

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
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void enter()
{
    cin >> n;
    for (int i = 0; i < n; ++ i)
    cin >> s[i];
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    if (s[i][j] != '.') 
    for (int h = 0; h < 4; ++ h)
    {
        int cn = 0;
        for (int k = 0; k < 3; ++ k)
        {
            int x = i + hx[h][k], y = j + hy[h][k];
            if (!kt (x, y)) continue;
            if (s[x][y] == s[i][j]) ++ cn;
        }
        if (cn == 3) 
        {
            cout << s[i][j];
            exit (0);
        }
    }
    cout << "ongoing";
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
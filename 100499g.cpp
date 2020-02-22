#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 2 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n;
bool a[mm][mm];

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
    return (x >= 0 && x < 2 * n + 1 && y >= 0 && y < 2 * n + 1);
}

void enter()
{
    cin >> n;
    int d = 0;
    memset (a, 0, sizeof (a));
    while (1)
    {
        int o = 1;
        int j = 0;
        bool ok = 0;
        for (int i = n - d; i <= n + d; ++ i)
        {
            if (kt (i, n - j))
            {
                a[i][n - j] = 1;
                ok = 1;
            }
            if (kt (i, n + j))
            {
                a[i][n + j] = 1;
                ok = 1;
            }
            if (i == n) o = - 1;
            j += o;
        }
        if (!ok) break;
        d += 3;
    }
    for (int i = 0; i < 2 * n + 1; ++ i)
    {
        for (int j = 0; j < 2 * n + 1; ++ j)
        cout << (!a[i][j] ? 'w' : 'b');
        cout << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
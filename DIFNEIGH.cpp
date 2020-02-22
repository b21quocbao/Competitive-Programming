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

int a[52][52];

void enter()
{
    int m, n;
    cin >> m >> n;
    int sol = 0;
    if (m == 1 && n >= 3)
    {
        sol = 2;
        int cn = 1;
        for (int i = 1; i <= n; i += 2)
        {
            a[1][i] = cn;
            a[1][i + 1] = cn;
            cn = 3 - cn;
        }
    }
    else if (n == 1 && m >= 3)
    {
        sol = 2;
        int cn = 1;
        for (int i = 1; i <= m; i += 2)
        {
            a[i][1] = cn;
            a[i + 1][1] = cn;
            cn = 3 - cn;
        }
    }
    else if (n == 2 && m >= 3)
    {
        sol = 3;
        int cn = 1;
        for (int i = 1; i <= m; ++ i)
        {
            a[i][1] = a[i][2] = cn;
            ++ cn;
            if (cn == 4) cn = 1;
        }
    }
    else if (m == 2 && n >= 3)
    {
        sol = 3;
        int cn = 1;
        for (int i = 1; i <= n; ++ i)
        {
            a[1][i] = a[2][i] = cn;
            ++ cn;
            if (cn == 4) cn = 1;
        }
    }
    else
    {
        for (int t = 1; t <= m + n; ++ t)
        for (int i = max (t - n, 1); i <= min (m, t - 1); ++ i)
        {
            unordered_set<int> mu;
            int j = t - i;
            if (i > 2)
            mu.insert (a[i - 2][j]);
            if (j > 2)
            mu.insert (a[i][j - 2]);
            if (i > 1 && j > 1)
            mu.insert (a[i - 1][j - 1]);
            if (i > 1 && j + 1 <= n)
            mu.insert (a[i - 1][j + 1]);
            if (i + 1 <= m && j - 3 >= 1 && !mu.count (a[i + 1][j - 3]))
            {
                a[i][j] = a[i + 1][j - 3];
                sol = max (sol, a[i][j]);
                continue;
            }
            for (int l = 1; l <= 4; ++ l)
            if (!mu.count (l))
            {
                a[i][j] = l;
                break;
            }
            sol = max (sol, a[i][j]);
        }
    }
    cout << sol << "\n";
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    cout << a[i][j] << (j == n ? "\n" : " ");
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
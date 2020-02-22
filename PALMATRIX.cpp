#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PALMATRIX"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
char a[mn];
int ok[mn], cn[100];
bool dx[mn];
int id[mn];
int m, n, k;

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

inline int Id (int x, int y)
{
    return x * n + y;
}

bool kt (int l)
{
    for (int i = 0; i < n / 2; ++ i)
    if (((l >> i) & 1) != ((l >> (n - 1 - i)) & 1))
    return 0;
    return 1;
}

void enter()
{
    cin >> m >> n >> k;
    char c;
    cin >> c;
    while (!isalpha(c)) cin >> c;
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        a[Id (i, j)] = c;
        cin >> c;
    }
    if (m <= 10 && n <= 10)
    {
        int sol = INT_MAX;
        if (n % 2 == 0)
        if (k & 1) ++ k; 
        for (int l = 0; l < (1 << n); ++ l)
        if (__builtin_popcount (l) == k)
        if (kt (l))
        {
            int re = 0;
            for (int i = 0; i < m / 2; ++ i)
            for (int j = 0; j < n / 2; ++ j)
            if ((l >> j) & 1)
            {
                vector<int> e;
                int x, y, r = 0;
                for (int k = 0; k < 4; ++ k)
                {
                    if (k & 1) x = i; else x = m - 1 - i;
                    if (k >= 2) y = j; else y = n - 1 - j;
                    e.emplace_back (a[Id (x, y)] - 'a');
                    r = max (r, ++ cn[a[Id (x, y)] - 'a']);
                }
                re += (4 - r);
                for (int i : e)
                cn[i] = 0;
            }
            if (m & 1)
            for (int j = 0; j < n / 2; ++ j)
            if ((l >> j) & 1)
            if (a[Id (m / 2, j)] != a[Id (m / 2, n - 1 - j)])
            ++ re;
            for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n / 2; ++ j)
            if ((l >> j) % 2 == 0)
            if (a[Id (i, j)] != a[Id (i, n - 1 - j)])
            ++ re;
            sol = min (sol, re);
        }
        cout << sol;
        return;
    }
    int sol = 0;
    for (int i = 0; i < m / 2; ++ i)
    for (int j = 0; j < n / 2; ++ j)
    {
        vector<int> e;
        int x, y, r = 0;
        for (int k = 0; k < 4; ++ k)
        {
            if (k & 1) x = i; else x = m - 1 - i;
            if (k >= 2) y = j; else y = n - 1 - j;
            e.emplace_back (a[Id (x, y)] - 'a');
            r = max (r, ++ cn[a[Id (x, y)] - 'a']);
        }
        ok[j] += (4 - r);
        if (a[i][j] != a[i][n - 1 - j]) ++ ok1[j];
        if (a[m - 1 - i][j] != a[m - 1 - i][n - 1 - j])
        ++ ok2[j];
        id[j] = j;
        for (int i : e)
        cn[i] = 0;
    }
    sort (id,id + n / 2, [](int i, int j)
         {
             return ok[i] - ok1[i] < ok[j] - ok1[j];
         });
    int re = 0;
    if ((k & 1) && (n & 1))
    {
        for (int i = 0; i < m / 2; ++ i)
        if (a[Id (i, n / 2)] != a[Id (m - 1 - i, n / 2)])
        ++ re;
    }
    if ((n % 2 == 0) && (k & 1))
    ++ k;
    for (int i = 0; i < k / 2; ++ i)
    sol += ok[id[i]];
    if (k & 1 && k != n && ok[id[k / 2]] <= re)
    {
        dx[id[k / 2]] = 1;
        sol += ok[id[k / 2]];
    }
    else sol += re;
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n / 2; ++ j)
    if (a[Id (i, j)] != a[Id (i, n - 1 - j)] && !dx[j])
    ++ sol;
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
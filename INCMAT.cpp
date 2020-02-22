#include <bits/stdc++.h>

#define fn "test"
#define fn1 "INCMAT"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int X[mn], Y[mn], U[mn], V[mn], C[mn];

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

void Ma (int& x, int y, int z, int t)
{
    x = max (y, max (z, t));
}

bool Kt (int x, int y, int u, int v, int X, int Y)
{
    return (X >= x && X <= u && Y >= y && Y <= v);
}

void enter()
{
    int m, n;
    read (m); read (n);
    vector<vector<int> > x (m + 2, vector<int> (n + 2));
    vector<vector<int> > s (m + 2, vector<int> (n + 2));
    vector<vector<int> > ma1 (m + 2, vector<int> (n + 2));
    vector<vector<int> > ma2 (m + 2, vector<int> (n + 2));
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    read (x[i][j]);
    int q;
    read (q);
    for (int i = 0; i < q; ++ i)
    {
        read (X[i]); read (Y[i]); read (U[i]); read (V[i]); read (C[i]);
        s[X[i]][Y[i]] += C[i];
        s[X[i]][V[i] + 1] -= C[i];
        s[U[i] + 1][V[i] + 1] += C[i]; 
        s[U[i] + 1][Y[i]] -= C[i];
    }
    int sol = - 1, soli, solj;
    for (int i = 1; i <= m; ++ i)
    {
        int d = 0;
        for (int j = 1; j <= n; ++ j)
        {
            s[i][j] += s[i - 1][j];
            d += s[i][j];
            x[i][j] += d;
            if (x[i][j] > sol) 
            {
                sol = x[i][j];
                soli = i; solj = j;
            }
        }
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    Ma (ma1[i][j], ma1[i - 1][j], ma1[i][j - 1], x[i][j]);
    for (int i = m; i >= 1; -- i)
    for (int j = n; j >= 1; -- j)
    Ma (ma2[i][j], ma2[i + 1][j], ma2[i][j + 1], x[i][j]);
    for (int i = 0; i < q; ++ i)
    {
        if (!Kt (X[i], Y[i], U[i], V[i], soli, solj)) continue;
        int d = x[soli][solj] - C[i];
        d = max (d, max (ma1[X[i] - 1][n], ma1[m][Y[i] - 1]));
        d = max (d, max (ma2[1][V[i] + 1], ma2[U[i] + 1][1]));
        sol = min (sol, d);
    }
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
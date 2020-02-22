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


struct mat
{
    vector<vector<int> > a;
    mat (int m, int n)
    {
        a.resize(m, vector<int> (n, 0));
    }
} g (2, 1), ch (2, 2);

mat operator * (mat a, mat b)
{
    mat c (a.a.size(), b.a[0].size());
    for (int i = 0; i < a.a.size(); ++ i)
    for (int j = 0; j < b.a[0].size(); ++ j)
    for (int k = 0; k < a.a[0].size(); ++ k)
    {
        c.a[i][j] += a.a[i][k] * b.a[k][j];
        c.a[i][j] %= 100;
        if (c.a[i][j] < 0) c.a[i][j] += 100;
    }
    return c;
}

mat po (mat a, int n)
{
    if (n == 1) return a;
    mat A = po (a, n >> 1);
    A = A * A;
    return (n & 1 ? A * a : A);
}

void enter()
{
    g.a[0][0] = 4;
    g.a[1][0] = 2;
    ch.a[0][0] = 4;
    ch.a[0][1] = - 1;
    ch.a[1][0] = 1;
    int n;
    cin >> n;
    if (n <= 1)
    {
        if (n == 1) cout << "03\n";
        else cout << "02\n";
        return;
    }
    g = po (ch, n - 1) * g;
    -- g.a[0][0];
    if (g.a[0][0] == - 1) g.a[0][0] = 99;
    cout << setfill('0') << setw(2) << g.a[0][0] << "\n";
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
    g.a[0][0] = 4;
    g.a[1][0] = 2;
    ch.a[0][0] = 4;
    ch.a[0][1] = - 1;
    ch.a[1][0] = 1;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
/*
Code by b21
Time: 22:15 Sun 16/06/2019
*/

#include <bits/stdc++.h>

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("808d.inp"))
    {
        freopen("808d.inp", "r", stdin);
        freopen("808d.out", "w", stdout);
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

int n;
double p;

int T (int n)
{
    int cn = 0;
    while (n & 1) 
    {
        ++ cn;
        n >>= 1;
    }
    return cn;
}

int S (int n)
{
    int k = 4, s = 0;
    while (n & 1)
    {
        n >>= 1;
        s += k;
        k *= 2;
    }
    return s;
}

double sol;

// map<int, int> f[1<<18][18][18];

double F (int tt, int N, double l, int s)
{
    if (N == n) return l * s;
    double res = 0;
    res += F (tt + 1, N - T (tt) + 1, l * (1 - p), s + S (tt));
    if (tt & 1) res += F (2, N + 1, l * p, s);
    else if (tt & 2) res += F (tt + 2, N - T (tt >> 1) + 1, l * p, s + 2 * S (tt >> 1));
    else res += F (tt | 2, N + 1, l * p, s);
    return res;
}

void enter()
{
    sol = 0;
    cin >> n >> p;
    p = p / 100.;
    cout << fixed << setprecision(6) << F (0, 0, 1, 0) << "\n";
}

void solve()
{

}

void print_result()
{

}

main()
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
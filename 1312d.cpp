/**
 *	 Code by b21
 *	 Time: 21:55 Mon 09/03/2020
**/

#include <bits/stdc++.h>

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const long long mod = 998244353;
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
   else if (ifstream("1312d.inp"))
    {
        freopen("1312d.inp", "r", stdin);
        freopen("1312d.out", "w", stdout);
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

#define int long long

int gt[mn];

int Mu (int a, int b) {
    return ((a * b) % mod);
}

int po (int a, int n) {
    if (!n) return 1;
    int A = po (a, n >> 1);
    A = Mu (A, A);
    return (n % 2 ? Mu (A, a) : A);
}

int C (int n, int k) {
    return Mu (gt[n], po (Mu (gt[k], gt[n - k]), mod - 2));
}

void enter()
{
    int n, m;
    cin >> n >> m;
    gt[0] = 1;
    for (int i = 1; i <= m; ++ i)
    gt[i] = Mu (gt[i - 1], i);
    int sol = 0;
    for (int i = 1; i <= n - 2; ++ i)
    {
        sol += Mu (Mu (C (n - 2, i), C (m, n - 1)), i);
        sol %= mod;
    }
    cout << sol;
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
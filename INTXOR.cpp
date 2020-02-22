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
int a[mn];

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

int get (int i, int j, int k)
{
    cout << 1 << " " << i << " " << j << " " << k << endl;
    int x;
    cin >> x;
    return x;
}

void enter()
{
    int n;
    cin >> n;   
    int x1 = get (1, 2, 3), x2 = get (2, 3, 4);
    int x = x1 ^ x2;
    for (int i = 5; i <= 6; ++ i)
    a[i] = x ^ get (1, 4, i);
    for (int i = 7; i <= n; ++ i)
    a[i] = a[i - 1] ^ a[i - 2] ^ get (i - 1, i - 2, i);
    a[2] = get (n - 1, n, 2) ^ a[n - 1] ^ a[n];
    a[3] = get (5, n, 3) ^ a[5] ^ a[n];
    a[1] = x1 ^ a[2] ^ a[3];
    a[4] = x2 ^ a[2] ^ a[3];
    cout << 2 << " ";
    for (int i = 1; i <= n; ++ i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    int X;
    cin >> X;
    if (X == - 1) exit (0);
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
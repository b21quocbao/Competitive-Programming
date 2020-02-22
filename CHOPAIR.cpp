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

void enter()
{
    int n, k;
    read (n); read (k);
    long long cn = 0;
    for (int i = 0; i < n; ++ i)
    {
        read (a[i]);
        if ((k % 2 == 0) && (a[i] == (k >> 1))) ++ cn;
    }
    long long sol = 0;
    sol += (cn * (cn - 1) / 2);
    sort (a, a + n);
    int j = n - 1;
    for (int i = 0; i < n; ++ i)
    {
        if ((k % 2 == 0) && (a[i] >= (k >> 1))) break;
        if (a[i] > (k >> 1)) break;
        while (a[i] + a[j] > k) -- j; 
        if (a[i] + a[j] < k) continue;
        int c = j;
        int d = i;
        while (a[i] + a[c - 1] == k) -- c;
        while (a[d + 1] + a[c] == k) ++ d;
        sol += 1ll * (d - i + 1) * (j - c + 1);
        i = d;
        j = c;
    }
    cout << sol << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
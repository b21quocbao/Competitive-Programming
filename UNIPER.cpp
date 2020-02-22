#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "UNIPER"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int e[30], vt1[30], vt2[30];
int d[(1 << 20) + 10];

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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        int x;
        cin >> x;
        -- x;
        vt1[x] = i;
    }
    for (int i = 0; i < n; ++ i)
    {
        int x;
        cin >> x;
        -- x;
        vt2[x] = i;
    }
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    if (vt1[i] > vt1[j] && vt2[i] > vt2[j])
    e[i] |= (1 << j);
    d[0] = 1;
    for (int i = 0; i < (1 << n) - 1; ++ i)
    {
        for (int k = 0; k < n; ++ k)
        if (((i >> k) & 1) == 0)
        if ((e[k] & i) == e[k])
        d[i ^ (1 << k)] += d[i];
    }
    cout << d[(1 << n) - 1];
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
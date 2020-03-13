/*
Code by b21
Time: 16:48 Sat 29/02/2020
*/

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
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
   else if (ifstream("1315d.inp"))
    {
        freopen("1315d.inp", "r", stdin);
        freopen("1315d.out", "w", stdout);
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
    
}

int a[mn], t[mn], id[mn];
map<int, int> fa;
int Fa (int n) {
    return (fa.count (n) ? fa[n] = Fa (fa[n]) : n);
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    {
        cin >> t[i];
        id[i] = i;
    }
    sort (id + 1, id + n + 1, [](int i, int j) {
        return t[i] > t[j];
    });
    long long sol = 0;
    for (int j = 1; j <= n; ++ j) {
        int i = id[j];
        int x = Fa (a[i]);
        assert (x >= a[i]);
        sol += 1ll * t[i] * (x - a[i]);
        a[i] = x;
        fa[a[i]] = Fa (a[i] + 1);
    }
    cout << sol;
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
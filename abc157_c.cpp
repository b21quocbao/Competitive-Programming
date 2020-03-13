/*
Code by b21
Time: 19:08 Sun 01/03/2020
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
   else if (ifstream("abc157_c.inp"))
    {
        freopen("abc157_c.inp", "r", stdin);
        freopen("abc157_c.out", "w", stdout);
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

int ok[7];

void enter()
{
    int n, m;
    cin >> n >> m;
    memset (ok, - 1, sizeof (ok));
    for (int i = 0; i < m; ++ i) {
        int x, y;
        cin >> x >> y;
        -- x;
        if (ok[x] != - 1 && ok[x] != y) {
            cout << - 1;
            return;
        }
        ok[x] = y;
    }
    for (int i = 0; i < 1000; ++ i) {
        int x = i;
        vector<int> v;
        if (!x) v.emplace_back(0);
        while (x) {
            v.emplace_back(x % 10);
            x /= 10;
        }
        if (v.size() != n) continue;
        bool Ok = 1;
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++ i)
        if (ok[i] != - 1 && v[i] != ok[i]) Ok = 0;
        if (Ok) {
            cout << i;
            return;
        }
    }
    cout << - 1;
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
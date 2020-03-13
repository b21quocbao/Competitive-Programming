/*
Code by b21
Time: 16:35 Sat 29/02/2020
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
   else if (ifstream("1315c.inp"))
    {
        freopen("1315c.inp", "r", stdin);
        freopen("1315c.out", "w", stdout);
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

bool ok[210];
int b[210], a[210];

void enter()
{
    int n;
    cin >> n;
    memset (ok, 0, sizeof (ok));
    for (int i = 1; i <= n; ++ i)
    {
        cin >> b[i];
        ok[b[i]] = 1;
    }
    for (int i = 1; i <= n; ++ i) {
        a[2 * i - 1] = b[i];
        bool Ok = 0;
        for (int j = b[i]; j <= 2 * n; ++ j)
        if (!ok[j]) {
            Ok = 1;
            ok[j] = 1;
            a[2 * i] = j;
            break;
        }
        if (!Ok) 
        {
            cout << - 1;
            return;
        }
    }
    for (int i = 1; i <= 2 * n; ++ i)
    cout << a[i] << " ";
}

void solve()
{
    cout << "\n";
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
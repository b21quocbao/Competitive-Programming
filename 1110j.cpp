/*
Code by b21
Time: 14:08 Sun 10/11/2019
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
   else if (ifstream("1110j.inp"))
    {
        freopen("1110j.inp", "r", stdin);
        freopen("1110j.out", "w", stdout);
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

void printfail()
{
    cout << "impossible";
    exit (0);
}

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int sl0 = (int)ceil(sqrt(2 * a));
    int sl1 = (int)ceil(sqrt(2 * d));
    if (!sl0 && (b || c)) ++ sl0;
    if (!sl1 && (b || c)) ++ sl1;
    if (sl0 * (sl0 - 1) != 2 * a) printfail(); 
    if (sl1 * (sl1 - 1) != 2 * d) printfail();
    if ((b + c) != (sl0 * sl1)) printfail();
    if (!sl0)
    {
        if (!sl1)
        {
            cout << 1;
            return;
        }
        for (int i = 0; i < sl1; ++ i)
        cout << 1;
        return;
    }
    int dau = c / sl0;
    c %= sl0;
    int res = sl0 + sl1;
    if (!res) printfail();
    for (int i = 1; i <= res; ++ i)
    {
        if (i <= dau) cout << 1;
        else if (!sl0) cout << 1;
        else if (c && sl0 == c) 
        {
            cout << 1;
            c = 0;
        }
        else 
        {
            cout << 0;
            -- sl0;
        }
    }
    assert (!sl0);
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
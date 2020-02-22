/*
Code by b21
Time: 18:00 Sat 20/07/2019
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
   else if (ifstream("102279a.inp"))
    {
        freopen("102279a.inp", "r", stdin);
        freopen("102279a.out", "w", stdout);
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

int d[100010];

void enter()
{
    
}

void F (int s)
{
    cout << s;
    exit (0);
}

void solve()
{
    int n, s, b, l;
    cin >> n >> s >> b >> l;
    -- s; -- b; -- l; ++ n;
    int curl = 1, curs = 1, curb = 1;
    int sol = 0;
    while (sol <= 5 * n)
    {
        ++ sol;
        curs = (curs + s) % n + 1;
        if (curs != 1)
        {
            if (!d[curs]) d[curs] = 1;
            else if (d[curs] != 1) F (sol);
        }
        ++ sol;
        curb = (curb + b) % n + 1;
        if (curb != 1)
        {
            if (!d[curb]) d[curb] = 2;
            else if (d[curb] != 2) F (sol);
        }
        ++ sol;
        curl = (curl + l) % n + 1;
        if (curl != 1)
        {
            if (!d[curl]) d[curl] = 3;
            else if (d[curl] != 3) F (sol);
        }
    }
    cout << 3000000000;
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
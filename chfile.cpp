/*
Code by b21
Time: 12:51 Tue 25/02/2020
*/

#include <bits/stdc++.h>
// #include<windows.h>

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
   else if (ifstream("chfile.inp"))
    {
        freopen("chfile.inp", "r", stdin);
        freopen("chfile.out", "w", stdout);
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
    system("cd \"C:\\Users\\Quoc Bao\\Downloads\\Others\\north-2014-tests\\north-2014-tests\\expression\\tests\\\"");
    for (int i = 2; i <= 69; ++ i) {
        string s = to_string(i);
        if (s.size() == 1)
        s = "0" + s;
        string s0 = "mkdir TEST" + s;
        string s1 = "move " + s + " TEST" + s + "\\" + "E.inp";
        string s2 = "move " + s + ".a TEST" + s + "\\" + "E.out";
        system(s0.c_str());
        system(s1.c_str());
        system(s2.c_str());
        // system("mv ")
    }
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
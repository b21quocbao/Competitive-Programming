/*
Code by b21
Time: 21:34 Wed 04/03/2020
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
   else if (ifstream("1316b.inp"))
    {
        freopen("1316b.inp", "r", stdin);
        freopen("1316b.out", "w", stdout);
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

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    string sol = s;
    string s1 = s;
    int k = 1;
    for (int i = 1; i <= n; ++ i)
    {
        int cn = (n - i) + 1;
        string S;
        if (cn % 2 == 0)
        S = s.substr(i - 1, n - i + 1) + s.substr(0, i - 1);
        else
        {
            string s1 = s.substr(0, i - 1);
            reverse(s1.begin(), s1.end());
            S = s.substr(i - 1, n - i + 1) + s1;
        }
        if (S < sol) {
            sol = S;
            k = i;
        }
    }
    cout << sol << "\n";
    cout << k << "\n";
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
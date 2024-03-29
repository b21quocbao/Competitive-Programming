/*
Code by b21
Time: 16:31 Sat 29/02/2020
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
   else if (ifstream("1315b.inp"))
    {
        freopen("1315b.inp", "r", stdin);
        freopen("1315b.out", "w", stdout);
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
    int a, b, p;
    cin >> a >> b >> p;
    cin.ignore();
    string s;
    getline (cin, s);
    int t = 0;
    for (int i = s.size() - 2; i >= 0; -- i) 
    {
        if (s[i] != s[i + 1] || i == s.size() - 2) 
        t += (s[i] == 'A' ? a : b);
        if (t > p) 
        {
            cout << i + 2;
            return;
        }
    }
    cout << 1;
}

void print_result()
{
    cout << "\n";
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
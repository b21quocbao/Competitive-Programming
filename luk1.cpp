/*
Code by b21
Time: 14:40 Thu 07/11/2019
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
   else if (ifstream("luk1.inp"))
    {
        freopen("luk1.inp", "r", stdin);
        freopen("luk1.out", "w", stdout);
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
    string s;
    vector<string> sol;
    int cn = 0;
    while (getline (cin, s))
    {
        for (char& c : s)
        c = toupper(c);
        ++ cn;
        bool ok = 0;
        if (cn == 229)
        {
            int x = 1; 
        }
        for (int i = 0; i + 7 < s.size(); ++ i)
        {
            if (s[i] == 'H' && (s[i + 1] == 'E' || s[i + 1] == 'S' || s[i + 1] == 'A') && s[i + 2] == '1')
            {
                sol.emplace_back(s.substr(i,8));
                ok = 1;
            }
        }
        if (!ok) 
        cerr << cn << "\n";
    }
    for (int i : l)
    
    for (auto s : sol)
    cout << s << "\n";
}

void solve()
{
    for (int i = 0; i < n; ++ i)
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
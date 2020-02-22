/*
Code by b21
Time: 08:10 Sun 13/10/2019
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
   else if (ifstream("acmb.inp"))
    {
        freopen("acmb.inp", "r", stdin);
        freopen("acmb.out", "w", stdout);
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

int res, cn = 1;
int nex[mn][2];
int cnt[mn];

void add (string s)
{
    int r = 1;
    bool ok = 0;
    for (char c : s)
    {
        if (!nex[r][c - '0']) 
        {
            nex[r][c - '0'] = ++ cn;
            ok = 1;
        }
        r = nex[r][c - '0'];
    }
    if (!ok) return;
    ++ cnt[1];
    r = 1;
    for (char c : s)
    {
        r = nex[r][c - '0'];
        ++ cnt[r];
    }
}

void find()
{
    if (cnt[1] == (1 << res)) return;
    int r = 1;
    for (int i = res - 1; i >= 0; -- i)
    {
        if (cnt[nex[r][0]] != (1 << i)) 
        {
            r = nex[r][0];
            cout << 0;
        }
        else 
        {
            r = nex[r][1];
            cout << 1;
        }
    }
    exit (0);
}

void reset(int r) 
{
    if (!r) return;
    reset (nex[r][0]);
    reset (nex[r][1]);
    nex[r][0] = 0;
    nex[r][1] = 0;
    cnt[r] = 0;
}

void enter()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 1; i <= 11; ++ i)
    {
        res = i;
        for (int j = 0; j + i - 1 < s1.size(); ++ j)
        add (s1.substr(j, i));
        for (int j = 0; j + i - 1 < s2.size(); ++ j)
        add (s2.substr(j, i));
        find();
        reset(1);
        cn = 1;
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
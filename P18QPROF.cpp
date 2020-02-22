#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e4) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int F[mn][30];

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
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
    char c = getchar ();
    string s;
    s.reserve (mn);
    while (!isalpha(c)) c = getchar();
    while (isalpha (c))
    {
        s.push_back(c);
        c = getchar();
    }
    int n = s.size();
    s = ' ' + s;
    for (int i = 1; i <= n; ++ i)
    for (char c = 'a'; c <= 'z'; ++ c)
    F[i][c - 'a'] = F[i - 1][c - 'a'] + (s[i] == c);
    int q;
    read (q);
    for (int i = 0; i < q; ++ i)
    {
        int a, b, c, d;
        bool ok = 1;
        read (a); read (b); read (c); read (d);
        for (int i = 0; i <= ('z' - 'a'); ++ i)
        ok &= (F[b][i] - F[a - 1][i] == F[d][i] - F[c - 1][i]);
        if (ok)
        puts ("YES");
        else 
        puts ("NO");
    }
}

void solve()
{

}

void print_result()
{

}

int main()
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
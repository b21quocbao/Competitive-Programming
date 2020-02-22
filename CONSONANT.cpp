#include <bits/stdc++.h>

#define fn "test"
#define fn1 "CONSONANT"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int ok[30];
int d[30][30];
int po[(1 << 19) + 2];
int t[1 << 19];
int f[1 << 19][19];
int ho[30];

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".in"))
    {
        freopen(fn1".in", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
    else if (ifstream(fn1".inp"))
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
    string s;
    getline (cin, s);
    int cn = 0;
    string s1 = "aeiouwy";
    for (char c = 'a'; c <= 'z'; ++ c)
    {
        bool ok1 = 1;
        for (char d : s1)
        if (c == d) 
        {
            ok1 = 0;
            break;
        }
        if (ok1)
        ok[c - 'a'] = ++ cn;
    }
    for (int i = 0; i < s.size() - 1; ++ i)
    {
        int c = (s[i] - 'a'), e = (s[i + 1] - 'a');
        if (ok[c] && ok[e] && ok[c] != ok[e]) 
        {
            ++ d[ok[c] - 1][ok[e] - 1];
            ++ d[ok[e] - 1][ok[c] - 1];
        }
    }
    for (int i = 0; i < 19; ++ i)
    po[1 << i] = i;
    for (int i = 1; i < (1 << 19); ++ i)
    for (int j = 0; j < 19; ++ j)
    {
        int l = (i - (i & - i));
        int k = po[i & - i];
        f[i][j] = f[l][j] + d[j][k];
    }
    int sol = 0;
    int soli = 0;
    for (int i = 1; i < (1 << 19); ++ i)
    {
        int l = (i - (i & - i));
        int k = po[i & - i];
        t[i] = t[l] - f[l][k] + f[((1 << 19) - 1) ^ l][k];
        if (t[i] > sol)
        {
            sol = t[i];
            soli = i;
        }
    }
    for (int i = 0; i < 19; ++ i)
    {
        if ((soli >> i) & 1) ho[i] = 1;
    }
    for (char& c : s)
    {
        if (ok[c - 'a'])
        if (ho[ok[c - 'a'] - 1])
        c = toupper(c);
        cout << c;
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
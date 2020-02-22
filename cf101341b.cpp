#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

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
    string s;
    int cn = 0;
    srand (time (nullptr));
    getline (cin, s);
    int sol1, sol2;
    for (int i = 0; i + 9 - 1 < s.size(); ++ i)
    {
        if (s.substr (i, 9) != "happiness") continue;
        ++ cn;
        if (cn == 1)
        {
            sol1 = i + 1; sol2 = i + 2;
        }
        if (cn == 2)
        {
            sol2 = i + 2;
        }
    }
    cout << (cn <= 2 ? "YES\n" : "NO");
    if (cn == 1 || cn == 2)
    cout << sol1 + 1 << " " << sol2 + 1;
    if (!cn)
    {
        int n = s.size(), a, b;
        int cn1 = - 1, cn2 = - 1;
        for (int i = 0; i < s.size(); ++ i)
        if (s[i] == 'p')
        {
            if (cn1 == - 1) cn1 = i;
            else if (cn2 == - 1) cn2 = i; 
        }
        if (cn2 == - 1)
        cout << 1 << " " << 2;
        else
        cout << cn1 + 1 << " " << cn2 + 1;
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
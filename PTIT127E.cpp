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
    int n, sol = 0, soli;
    read (n);
    int Cn1, Cn2, A1 = - 1, A2 = - 1;
    for (int i = 0; i < n; ++ i)
    {
        int a1, a2, cn1 = 1, cn2 = 1;
        read (a1); read (a2);
        if (a1 == A1) cn1 = max (cn1, Cn1 + 1);
        if (a1 == A2) cn1 = max (cn1, Cn2 + 1);
        if (a2 == A1) cn2 = max (cn2, Cn1 + 1);
        if (a2 == A2) cn2 = max (cn2, Cn2 + 1); 
        if (cn1 > sol) 
        {
            sol = cn1;
            soli = a1;
        }
        if (cn2 > sol)
        {
            sol = cn2;
            soli = a2;
        }
        if (cn1 == sol) soli = min (soli, a1);
        if (cn2 == sol) soli = min (soli, a2);
        A1 = a1; A2 = a2; Cn1 = cn1; Cn2 = cn2;
    }
    cout << sol << " " << soli;
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
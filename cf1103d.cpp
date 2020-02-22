#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // if (ifstream(fn".inp"))
    // {
    //     freopen(fn".inp", "r", stdin);
    //     if (!aNs) freopen(fn".out", "w", stdout);
	// 	else freopen (fn".ans", "w", stdout);
    // }else if (ifstream(fn1".inp"))
    // {
    //     freopen(fn1".inp", "r", stdin);
    //     freopen(fn1".out", "w", stdout);
    // }
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

bool Ask (int x, int y)
{
    cout << "? " << x << " " << y << endl;
    char d;
    cin >> d;
    return (d == 'x');
}

void Write (int x)
{
    cout << "! " << x << endl;
}

void enter()
{
    string s;
    cin >> s;
    if (s != "start") exit (0);
    int sup = base, inf;
    while (sup >= 1)
    {
        int mid1 = max (sup / 3, 1), mid2 = 2 * mid1;
        if (Ask (mid1, mid2))
        {
            inf = mid1;
            sup = mid2;
            break;
        }
        else if (Ask (mid2, sup))
        {
            inf = mid2; 
            break;
        }
        sup = mid1 - 1;
    }
    int sol = inf;
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        if (!Ask (inf, mid))
        {
            inf = mid;
        }
        else
        sup = mid - 1;
    }
    sol = inf + 1;
    int l = sol;
    for (int i = 2; i * i <= l; ++ i)
    {
        while (sol % i == 0 && Ask (0, sol / i)) sol /= i;
        while (l % i == 0)
        {
            l /= i;
        }
    }
    if (Ask (0, sol / l)) sol /= l;
    Write(sol);
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
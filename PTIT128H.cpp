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
int a[12][12];
int cn[12];

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
    for (int i = 0; i < 9; ++ i)
    for (int j = 0; j < 9; ++ j)
    {
        char c;
        cin >> c;
        a[i][j] = c - '0';    
    }
    int sol = 0;
    for (int k = 0, ok = 1; k < 5; ++ k, ok = 1)
    for (int i = 0; i < 9 && ok; ++ i)
    for (int j = 0; j < 9 && ok; ++ j)
    if (!a[i][j])
    {
        if (!ok) continue;
        memset (cn, 0, sizeof (cn));
        for (int k = 0; k < 9; ++ k)
        {
            ++ cn[a[k][j]];
            ++ cn[a[i][k]];
        }
        for (int k = i / 3 * 3; k < i / 3 * 3 + 3; ++ k)
        for (int l = j / 3 * 3; l < j / 3 * 3 + 3; ++ l)
        ++ cn[a[k][l]];
        int t = 0, x = 0;
        for (int k = 1; k <= 9; ++ k)
        if (!cn[k])
        {
            ++ t;
            x = k;
        }
        if (t != 1) continue;
        a[i][j] = x;
        ok = 0;
        ++ sol;
    }
    if (sol != 5)
    {
        cout << "Could not complete this grid.\n";
        return;
    }
    for (int i = 0; i < 9; ++ i)
    for (int j = 0; j < 9; ++ j)
    {
        memset (cn, 0, sizeof (cn));
        for (int k = 0; k < 9; ++ k)
        {
            ++ cn[a[k][j]];
            ++ cn[a[i][k]];
        }
        for (int k = i / 3 * 3; k < i / 3 * 3 + 3; ++ k)
        for (int l = j / 3 * 3; l < j / 3 * 3 + 3; ++ l)
        ++ cn[a[k][l]];
        for (int k = 1; k <= 9; ++ k)
        if (cn[k] != 3)
        {
            cout << "Could not complete this grid.\n";
            return;
        }
    }
    for (int i = 0; i < 9; ++ i)
    {   
        for (int j = 0; j < 9; ++ j)
        cout << a[i][j];
        cout << "\n";
    }
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
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
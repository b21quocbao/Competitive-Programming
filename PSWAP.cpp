#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PSWAP"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mn], b[mn], n;

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
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i] >> b[i];
    } 
    sort (a, a + n);
    sort (b, b + n);
    for (int i = 0; i < n; ++ i)
    if (a[i] == b[i])
    {
        if (!i) 
        {
            swap (a[i], a[i + 1]);
            continue;
        }
        if (i == n - 1)
        {
            swap (a[i], a[i - 1]);
            continue;
        }    
        if (abs (a[i + 1] - b[i]) + abs (a[i] - b[i + 1]) < abs (a[i - 1] - b[i]) + abs (a[i] - b[i - 1]))
        swap (a[i], a[i + 1]);
        else
        swap (a[i], a[i - 1]);
    }
    int sol = 0;
    for (int i = 0; i < n; ++ i)
    {
        sol += abs (a[i] - b[i]);
    }
    cout << sol;
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
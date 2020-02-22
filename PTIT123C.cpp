#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
int a[mn], id[mn];

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
    int n, k1, k2;
    read (n); read (k1); read (k2);
    if (!n && !k1 && !k2) exit (0);
    for (int i = 0; i < n; ++ i)
    {
        read (a[i]);
        id[i] = i;
    }   
    sort (id, id + n, [](int i, int j)
         {
             if (a[i] != a[j])
             return a[i] < a[j];
             return i < j;
         });
    cout << "Case " << tt << "\n";
    sort (id, id + k1);
    for (int i = 0; i < k1; ++ i)
    cout << id[i] + 1 << " ";
    cout << "\n";
    sort (id + n - k2, id + n);
    for (int i = n - 1; i >= n - k2; -- i)
    cout << id[i] + 1 << " ";
    cout << "\n";
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
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
long long a[mn];

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
    int n;
    long long z1, z2;
    cin >> n >> z1 >> z2;
    bool sol1 = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        if (a[i] == z1) sol1 = 1;
        if (a[i] == z2) sol1 = 1;
        if (a[i] == - z1) sol1 = 1;
        if (a[i] == - z2) sol1 = 1;
    }
    if (sol1) 
    {
        cout << 1 << "\n";
        return;
    }
    cout << 1 << "\n";
    
    
    
    ios::sync_with_stdio(0);
    bool sol = 1;
    for (int i = 0; i < n; ++ i)
    {
        bool ok1 = 0, ok2 = 0;
        long long k1 = a[i];
        for (int j = 0; j < n; ++ j)
        {
            if (a[i] + a[j] == z1 || a[i] + a[j] == z2) ok1 = 1;
            if (a[i] - a[j] == z1 || a[i] - a[j] == z2) ok1 = 1;
            if (- a[i] + a[j] == z1 || - a[i] + a[j] == z2) ok2 = 1;
            if (- a[i] - a[j] == z1 || - a[i] - a[j] == z2) ok2 = 1;
        }
        if (!(ok1 && ok2)) sol = 0;
    }
    
    if (sol)
    {
        cout << 2 << "\n";
        return;
    }
    cout << 0 << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
#include <bits/stdc++.h>
 
#define fn "test"
#define fn1 ""
 
using namespace std;
 
const int mn = 5 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e6) + 10;
const int base = 1 * (int)(1e9);
 
int tt, ntest = 1;
int n, k, a[mn];
int pr[mm];
int cn[mm];
int s[mm];
int t[mm];
vector<pair<int, int> > ok[mm];
 
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        freopen(fn".ans", "w", stdout);
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
 
void eros (int N)
{
    for (int i = 2; i * i <= N; ++ i)
    if (!pr[i])
    for (int j = i * i; j <= N; j += i)
    pr[j] = i;
    for (int i = 1; i <= N; ++ i)
    if (!pr[i])
    pr[i] = i;
}
 
void enter()
{
    cin >> n >> k;
    vector<int> a (n);
    for (int &i : a)
    cin >> i;
    sort (a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin()); 
    for (int i = 1; ; ++ i)
    {
        vector<int> v (i);
        int s = 0;
        for (const int& x : a)
        ++ v[x % i];
        for (int i : v)
        s += max (i - 1, 0);
        if (s <= k)
        {
            cout << i;
            return;
        }
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
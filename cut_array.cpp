#include <bits/stdc++.h>
    
#define fn "test"
#define fn1 ""
    
using namespace std;
    
const int mn = 1 * (int)(1e7) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 2 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
    
int tt, ntest = 1;
int pr[mn], ok[mn], n, k, cid;
int id[mm];
int v[mm];
int t[mn];
pair<int, int> a[mm];
vector<int> sv;
    
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
    
void eros (int n)
{
    for (int i = 2; i <= trunc(sqrt(n)); ++ i)
    if (!pr[i])
    for (int j = i * i; j <= n; j += i)
    pr[j] = i;
    for (int i = 2; i <= n; ++ i)
    if (!pr[i])
    pr[i] = i;
}
    
int C (int s)
{
    int cv = 0;
    int sol = 1;
    int r = s;
    if (t[r]) return t[r];
    while (s != 1)
    {
        int x = pr[s];
        ++ ok[x];
        sol = sol / ok[x] * (ok[x] + 1);
        if (ok[x] == 1) v[cv ++] = x;
        s /= x;
    }
    for (int i = 0; i < cv; ++ i)
    ok[v[i]] = 0;
    return (t[r] = sol);
}

void enter()
{
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i].first;
        a[i].second = i;
        s += a[i].first;
    }
    int l = n;
    eros (s);
    cin >> k;
    while (n > k + 1)
    {
        int ma = INT_MAX, vt;
        for (int i = 0; i < n - 1; ++ i)
        if (C (a[i].first + a[i + 1].first) - C (a[i].first) - C (a[i + 1].first) < ma)
        {
            ma = C (a[i].first + a[i + 1].first) - C (a[i].first) - C (a[i + 1].first);
            vt = i;
        }
        a[vt].first += a[vt + 1].first;
        for (int j = vt + 1; j < n - 1; ++ j)
        a[j] = a[j + 1];
        -- n;
    }
    for (int i = 1; i < n; ++ i)
    {
        cout << a[i].second << " ";
    }
    for (int i = 1; i <= k; ++ i)
    {
        for (int i = x + 1; i <=n - k + i - 1; ++ i)

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
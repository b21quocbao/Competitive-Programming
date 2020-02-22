#include <bits/stdc++.h>
#define int long long 

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e5) + 10;
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

bool ok (int b)
{
    while (b % 2 == 0) b /= 2;
    while (b % 5 == 0) b /= 5;
    return (b == 1);
}

void enter()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    long double re = 0;
    bool Ok = 1;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i] >> b[i];
        re += (1. * a[i] / b[i]);
        int r = __gcd (a[i], b[i]);
        a[i] /= r;
        b[i] /= r;
        if (!ok (b[i])) Ok = 0;
    }
    if (abs (re - round (re)) <= 1e-4)
    {
        cout << round (re);
        return; 
    }
    vector<int> v[n];
    int sol1 = 0;
    for (int i = 0; i < n; ++ i)
    {
        v[i].reserve (mn);
        int r = a[i] % b[i];
        sol1 += (a[i] / b[i]);
        while (r && v[i].size() < mn)
        {
            r *= 10;
            v[i].push_back(r / b[i]);
            r %= b[i];
        }
        while (v[i].size() < mn) v[i].push_back(0);
    }
    int r = 0;
    vector<int> sol2 (mn, 0);
    for (int i = mn - 1; i >= 0; -- i)
    {
        for (int j = 0; j < n; ++ j)
        r += v[j][i];
        sol2[i] = r % 10;
        r /= 10;
    }
    sol1 += r;
    if (Ok) 
    {
        while (sol2.size() && sol2.back() == 0) sol2.pop_back();
    }
    cout << sol1 << ".";
    if (sol2[40000] >= 5) ++ sol2[39999];
    for (int i = 39999; i >= 1; -- i)
    {
        if (sol2[i] >= 10) 
        {
            ++ sol2[i - 1];
            sol2[i] -= 10;
        }
    }
    if (sol2[0] >= 10)
    {
        ++ sol1;
        sol2[0] -= 10;
    }
    for (int i = 0; i < min ((int)sol2.size(), 40000ll); ++ i)
    cout << sol2[i];
}

void solve()
{

}
        
void print_result()
{

}

main()
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
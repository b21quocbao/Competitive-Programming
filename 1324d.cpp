/**
 *	 Code by b21
 *	 Time: 20:43 Thu 12/03/2020
**/

#include <bits/stdc++.h>

using namespace std;

const int mn = 4 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("1324d.inp"))
    {
        freopen("1324d.inp", "r", stdin);
        freopen("1324d.out", "w", stdout);
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

int bi[mn], a[mn], b[mn];

int db (int x) {
    int s = 0;
    for (; x >= 1; x -= x & - x)
    s += bi[x];
    return s;
}

void ub (int x) {
    for (; x < mn; x += x & - x)
    ++ bi[x];
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    for (int i = 0; i < n; ++ i)
    cin >> b[i];
    vector<int> v;
    for (int i = 0; i < n; ++ i)
    {
        v.emplace_back(a[i] - b[i]);
        v.emplace_back(b[i] - a[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    long long sol = 0;
    for (int i = 0; i < n; ++ i) {
        sol += db (lower_bound(v.begin(), v.end(), a[i] - b[i]) - v.begin());
        ub (lower_bound(v.begin(), v.end(), b[i] - a[i]) - v.begin() + 1);
    }
    cout << sol;
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
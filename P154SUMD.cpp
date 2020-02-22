#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int k[mn], d[mn], c[mn];
int a[mn][mn];

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
    cin >> n;
    int su = 0;
    vector<int> v;
    int sol1 = 0, sol2 = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++ j)
        {
            cin >> a[i][j];
            a[i][j] += a[i][j - 1];
            ++ su;
        }
        if (k[i] & 1) v.emplace_back(i);
        else 
        {
            sol1 += a[i][k[i] / 2];
            sol2 += a[i][k[i]] - a[i][k[i] / 2];
        }
    }
    sort (v.begin(), v.end(), [](int i, int j)
         {
             return a[i][k[i] / 2 + 1] - a[i][k[i] / 2] > a[j][k[j] / 2 + 1] - a[j][k[j] / 2];
         });
    int cn = 0;
    for (int i : v)
    {
        if ((cn ++) & 1)
        {
            sol1 += a[i][k[i] / 2];
            sol2 += a[i][k[i]] - a[i][k[i] / 2];
        }
        else
        {
            sol1 += a[i][k[i] / 2 + 1];
            sol2 += a[i][k[i]] - a[i][k[i] / 2 + 1];
        }
    }
    cout << sol1 << " " << sol2 << "\n"; 
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
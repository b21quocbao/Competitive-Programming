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
    vector<int> a (n);
    bool Ok = 0;
    int s = 0;
    for (int i = 0; i < n; ++ i)
   {
        char c;
        cin >> c;
        while (!isdigit(c)) cin >> c;
        a[i] = (c - '0');
        if (a[i]) Ok = 1;
        s += a[i];
    }
    if (!Ok)
    {
        cout << "YES";
        return;
    }
    for (int k = 1; k < s; ++ k)
    {
        int cur = 0;
        bool ok = 1;
        for (int i = 0; i < n; ++ i)
        {
            cur += a[i];
            if (cur > k)
            {
                ok = 0;
                break;
            }
            if (cur == k) cur = 0;
        }
        if (cur && cur != k)
        {
            ok = 0;
        }
        if (ok)
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
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
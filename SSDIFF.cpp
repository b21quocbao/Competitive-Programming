#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SSDIFF"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 3 * (int)(1e7);
const bool aNs = 0;

int tt, ntest = 1;
int d[30];

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
    cin.ignore();
    string s;
    getline (cin, s);
    int sol = 0;
    if (1)
    {
        for (int i = 0; i < min (base / n, n); ++ i)
        {
            memset (d, 0, sizeof (d));
            for (int j = i; j < n; ++ j)
            {
                ++ d[s[j] - 'a'];
                int ma = 0, mi = n;
                for (int i = 0; i <= 'z' - 'a'; ++ i)
                if (d[i])
                {
                    ma = max (ma, d[i]);
                    mi = min (mi, d[i]);
                }
                sol = max (sol, ma - mi);
            }
        }   
        cout << sol;
        return;
    }
    for (const char& c : s)
    {
        ++ d[c - 'a'];
        int ma = 0, mi = n;
        for (int i = 0; i <= 'z' - 'a'; ++ i)
        if (d[i])
        {
            ma = max (ma, d[i]);
            mi = min (mi, d[i]);
        }
        sol = max (sol, ma - mi);
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
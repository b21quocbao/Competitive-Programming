#include <bits/stdc++.h>

#define fn "test"
#define fn1 "WORDS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[mn];

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

class Kmp
{
    public:
    vector<int> km;
    Kmp (string s)
    {
        km.resize(s.size() + 2);
        int r = 0;
        for (int i = 2; i < s.size(); ++ i)
        {
            while (r && s[r + 1] != s[i]) r = km[r];
            if (s[r + 1] == s[i]) ++ r;
            km[i] = r;
        }
    } 
};

void enter()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
    s = ' ' + s;
    Kmp R (s);
    vector<int> v;
    for (int i = 1; i < s.size(); ++ i)
    if (!R.km[i]) v.emplace_back(i);
    f[s.size() - 1] = 1;
    for (int i = s.size() - 1; i < n; ++ i)
    for (int j : v)
    if (i + j <= n)
    {
        f[i + j] += f[i];
        if (f[i + j] >= mod) f[i + j] -= mod;
    }
    cout << f[n];
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
#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int v[mn], a[mn];

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
    int n; string s;
    cin >> n >> s;
    map<char, int> d;
    d['A'] = 0;
    d['H'] = 1;
    d['I'] = 2;
    d['M'] = 3;
    d['O'] = 4;
    d['T'] = 5;
    d['U'] = 6;
    d['V'] = 7;
    d['W'] = 8;
    d['X'] = 9;
    d['Y'] = 10;
    string c = "AHIMOTUVWXY";
    memset (v, 0, sizeof (v));
    memset (a, 0, sizeof (a));
    for (int i = s.size() - 1; i >= 0; -- i)
    a[(int)(s.size()) - 1 - i] = d[s[i]];
    int cv = 0;
    while (n)
    {
        if (cv >= s.size()) -- n;
        v[cv ++] = n % 11;
        n /= 11;
        //cerr << v[cv - 1] << "\n";
    }
    string sol;
    int r = 0;
    for (int i = 0; i < mn; ++ i)
    {
        if (i >= cv && i >= s.size() && !r) break;
        a[i] += (v[i] + r);
        r = a[i] / 11;
        a[i] %=  11;
        if (i >= cv && i >= s.size()) -- a[i];
        sol.push_back(c[a[i]]);
    }
    reverse(sol.begin(), sol.end());
    cout << sol << "\n" ;
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
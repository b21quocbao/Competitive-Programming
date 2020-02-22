#include <bits/stdc++.h>

#define fn "test"
#define fn1 "DIFSHIFT"

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

inline bool operator < (string a, string b)
{
    if (a.size() != b.size()) return (a.size() < b.size());
    for (int i = 0; i < a.size(); ++ i)
    if (a[i] != b[i]) return (a[i] < b[i]);
    return 0;
}

string operator - (string a, string b)
{
    while (b.size() < a.size()) b = '0' + b;
    int r = 0;
    for (int i = b.size() - 1; i >= 0; -- i)
    {
        int r1 = a[i] - '0', r2 = b[i] - '0';
        int c = r1 - r2;
        if (r) -- c;
        if (c < 0)
        {
            c += 10;
            r = 1;
        }
        else r = 0;
        a[i] = '0' + c;
    }
    int i = 0;
    while (i + 1 < a.size() && a[i] == '0') ++ i;
    a = a.substr (i, a.size() - i);
    return a;
}

void enter()
{
    string s, t;
    cin >> s >> t;
    string S, T;
    S.push_back('0');
    for (int i = 0; i <= 3000; ++ i)
    T.push_back('9');
    for (int i = 0; i < s.size(); ++ i)
    {
        char c = s.back();
        s.pop_back();
        s = c + s;
        if (s[0] != '0')
        S = max (S, s);
    }
    for (int i = 0; i < t.size(); ++ i)
    {
        char c = t.back();
        t.pop_back();
        t = c + t;
        if (t[0] != '0')
        T = min (T, t);
    }
    if (T < S || T == S)
    cout << S - T;
    else
    cout << "-" << T - S;
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
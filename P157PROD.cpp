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
    string s;
    cin >> s;
    for (char c = '0'; c <= '9'; ++ c)
    {
        string s1 = s;
        for (char& d : s1) 
        if (d == '?')
        d = c;
        int j = 0;
        int Ok = - 1;
        vector<string> v;
        for (int i = 0; i < s1.size(); ++ i)
        if (!isdigit (s1[i]) && s1[i] != '-')
        {
            if (s1[i] == '+') Ok = 0;
            if (s1[i] == '-') Ok = 1;
            if (s1[i] == '*') Ok = 2;
            if (s1[i] == '/') Ok = 3;
            v.emplace_back(s1.substr (j, i - j));
            j = i + 1;
        }
        v.emplace_back(s1.substr (j, s.size() - j));
        bool ok = 1;
        vector<int> l;
        for (auto s : v)
        {
            int d = 0, r = 1;
            for (char c : s)
            {
                if (c == '-') 
                {
                    r = - r;
                    continue;
                }
                d = d * 10 + (c - '0');
            }
            int D = d;
            string s1;
            while (d)
            {
                s1.push_back((char)('0' + d % 10));
                d /= 10;
            }
            reverse (s1.begin (), s1.end());
            if (r < 0)
            s1 = '-' + s1;
            d = D;
            d *= r;
            if (s != s1) ok = 0;
            l.emplace_back(d);
        }
        if (!ok) continue;
        if (l.size() != 3) continue;
        if (Ok == - 1) continue;
        bool sol = 0;
        if (Ok == 0 && l[0] + l[1] == l[2]) sol = 1;
        if (Ok == 1 && l[0] - l[1] == l[2]) sol = 1;
        if (Ok == 2 && l[0] * l[1] == l[2]) sol = 1;
        if (sol)
        {
            cout << c << "\n";
            return;
        }
    }
    cout << - 1 << "\n";
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
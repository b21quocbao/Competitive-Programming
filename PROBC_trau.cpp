#include <bits/stdc++.h>

#define int long long 
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1000000;

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

void ax (string s, string& s1)
{
    int x = 0;
    char c1;
    for (char c : s)
    {
        if (isalpha(c)) 
        {
            for (int i = 0; i < x; ++ i)
            s1.push_back(c1);
            x = 0;
            c1 = c;
        }
        else
        x = x * 10 + (c - '0');
    }
    for (int i = 0; i < x; ++ i)
    s1.push_back(c1);
}

void wr (string s)
{
    if (s.empty()) return;
    int j = 0;
    for (int i = 0; i < s.size(); ++ i)
    if (s[i] != s[i - 1])
    {
        if (i)
        cout << s[i - 1] << i - j;
        j = i;
    }
    cout << s.back() << s.size() - j;
}

void enter()
{
    string c;
    if (!(cin >> c)) exit (0);
    cout << c << ": ";
    string s1, s2;
    cin >> s1;
    string a, b;
    if (c[1] == '1')
    {
        cin >> s2;
        ax (s1, a);
        ax (s2, b);
        string s;
        c = a + b;
        wr (c);
    } 
    else if (c[1] == '2')
    {
        int p, c;
        cin >> p >> c;
        -- p;
        ax (s1, a);
        a.erase (p, c);
        wr (a);
    }
    else if (c[1] == '3')
    {
        int p, c;
        cin >> p >> c;
        -- p;
        ax (s1, a);
        wr (a.substr (p, c));
    }
    else
    {
        int p;
        cin >> s2 >> p;
        -- p;
        ax (s1, a);
        ax (s2, b);
        a.insert (p, b);
        wr (a);
    }
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int32_t main()
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
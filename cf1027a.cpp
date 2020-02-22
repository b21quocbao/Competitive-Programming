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

void ch (char& c, int j)
{
    if (c == 'z' && j == 1) 
    {
        c = 'a';
        return;
    }
    if (c == 'a' && j == - 1) 
    {
        c = 'z';
        return;
    }
    c = c + j;
}

void enter()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool Sol = 1;
    for (int i = 0; i < s.size(); ++ i)
    {
        bool ok = 0;
        for (int j = - 1; j <= 1; j += 2)
        for (int k = - 1; k <= 1; k += 2)
        {
            char c1 = s[i], c2 = s[s.size() - 1 - i];
            ch (s[i], j); 
            ch (s[s.size() - 1 - i], k);
            if (s[i] == s[s.size() - 1 - i]) ok = 1;
            s[i] = c1;
            s[s.size() - 1 - i] = c2;
        }
        if (!ok) Sol = 0;
    }
    if (Sol)
    {
        cout << "YES";
    }
    else cout << "NO";
    cout << "\n";
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
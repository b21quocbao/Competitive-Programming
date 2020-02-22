#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TEMPLATE"

using namespace std;

const int mn = 5 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int z[mn];

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
    getline (cin, s);
    int n = s.size();
    int l = - 1, r = - 1;
    for (int i = 0; i < n; ++ i)
    {
        if (i > r)
        {
            while (z[i] < i && s[i + z[i]] == s[z[i]])
            ++ z[i];
        }
        else 
        {
            z[i] = min (z[i - l], r - i + 1);
            while (z[i] < i && s[i + z[i]] == s[z[i]])
            ++ z[i];
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
        // cerr << z[i] << "\n";
    }
    int cur = 0;
    int sol = 1;
    priority_queue<pair<int, int> > qu;
    for (int i = 1; i < n; ++ i)
    {
        qu.emplace(i, i + z[i] - 1);
        while (qu.size() && qu.top().second < i) qu.pop();
        while (qu.size() && qu.top().second - qu.top().first + 1 < sol)
        qu.pop();
        if (qu.size())
        sol = max (sol, i - qu.top().first + 1);
        else
        sol = i + 1;
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
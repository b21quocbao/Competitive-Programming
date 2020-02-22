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

int mi[mn], d[mn][30];

void enter()
{
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    s = ' ' + s;
    vector<pair<int, int> > v[30];
    for (int i = 0; i <= n; ++ i)
    for (char c = 'a'; c <= 'z'; ++ c)
    {
        if (i)
        d[i][c - 'a'] = d[i - 1][c - 'a'] + (c == s[i] ? 1 : 0);
        v[c - 'a'].emplace_back(2 * d[i][c - 'a'] - i, i);
    }
    mi[0] = n;
    int sol = 0;
    for (int i = 0; i <= 'z' - 'a'; ++ i)
    {
        sort (v[i].begin(), v[i].end());
        for (int j = 0; j < v[i].size(); ++ j)
        if (j)
        mi[j] = min (mi[j - 1], v[i][j].second);
        for (auto x : v[i])
        {
            int k = upper_bound(v[i].begin(), v[i].end(), make_pair (x.first + 1, n + 1)) - v[i].begin() - 1;
            if (k != - 1)
            sol = max (sol, x.second - mi[k]);
        }
    }
    cout << sol << "\n";
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
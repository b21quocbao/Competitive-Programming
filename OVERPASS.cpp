#include <bits/stdc++.h>

#define fn "test"
#define fn1 "OVERPASS"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[mn][2];
vector<pair<int, int> > e[mn][2], e1[mn][2];

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
    string s;
    cin >> n;
    cin.ignore();
    getline (cin, s);
    s = ' ' + s;
    for (int i = 1; i <= n; ++ i)
    for (int ok = 0; ok <= 1; ++ ok)
    e[i][ok].emplace_back(i, ok ^ 1);
    for (int i = 1; i <= n; ++ i)
    for (int ok = 0; ok <= 1; ++ ok)
    {
        if ((s[i] == 'B' || s[i] == 'L') && !ok) e[i][ok].emplace_back(i + 1, ok);
        else if ((s[i] == 'B' || s[i] == 'R') && ok) e[i][ok].emplace_back(i + 1, ok);
        else e1[i][ok].emplace_back(i + 1, ok);
    }
    e[n + 1][0].emplace_back(n + 1, 1);
    deque<pair<int, int> > qu;
    qu.emplace_back (1, 0);
    d[1][0] = 1;
    while (qu.size())
    {
        int u = qu.front().first;
        bool ok = qu.front().second;
        qu.pop_front();
        if (u == n + 1 && ok == 1)
        { 
            cout << d[u][ok] - 1;
            return;
        }
        for (auto i : e1[u][ok])
        if (!d[i.first][i.second] || d[u][ok] < d[i.first][i.second])
        {
            d[i.first][i.second] = d[u][ok];
            qu.emplace_front (i.first, i.second);
        }
        for (auto i : e[u][ok])
        if (!d[i.first][i.second] || d[u][ok] + 1 < d[i.first][i.second])
        {
            d[i.first][i.second] = d[u][ok] + 1;
            qu.emplace_back (i.first, i.second);
        }
    }
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
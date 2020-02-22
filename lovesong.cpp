#include <bits/stdc++.h>

#define fn "test"
#define fn1 "lovesong"

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
    int m, n;
    map<int, vector<int> > e, e1;
    map<int, int> cn,cn1;
    priority_queue<pair<int, int> > qu, qu1;
    cin >> m >> n;
    vector<pair<int, int> > sol; 
    for (int i = 1; i <= m; ++ i)
    {
        int x;
        cin >> x;
        e[x].emplace_back(i);
    }
    for (auto i : e)
    qu.emplace (i.second.size(), i.first);
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        cin >> x;
        e1[x].emplace_back(i);
    }
    for (auto i : e1)
    qu1.emplace (i.second.size(), i.first);
    while (1)
    {
        if (qu.empty()) break;
        int x = qu.top().second;
        qu.pop();
        int y = qu1.top().second;
        qu1.pop();
        if (x == y && qu1.empty() && qu.empty()) break;
        if (x != y)
        {
            sol.emplace_back (e[x].back(), e1[y].back());
            e[x].pop_back();
            e1[y].pop_back();
        }
        else if (qu1.size())
        {
            int Y = qu1.top().second;
            qu1.pop();
            sol.emplace_back (e[x].back(), e1[Y].back());
            e[x].pop_back();
            e1[Y].pop_back();
            if (e1[Y].size())
            qu1.emplace (e1[Y].size(), Y);
        }
        else 
        {
            int X = qu.top().second;
            qu.pop();
            sol.emplace_back (e[X].back(), e1[y].back());
            e[X].pop_back();
            e1[y].pop_back();
            if (e[X].size())
            qu.emplace (e[X].size(), X);
        }
        if (e[x].size())
        qu.emplace (e[x].size(), x);
        if (e1[y].size())
        qu1.emplace (e1[y].size(), y);
    }
    cout << sol.size() << "\n";
    for (auto x : sol)
    cout << x.second << " " << x.first << "\n";
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
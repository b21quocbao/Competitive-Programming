#include <bits/stdc++.h>
#define int long long

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

vector<int> e[mn];
bool t[mn];

void enter()
{
    int n;
    cin >> n;
    bool ok = 0;
    for (int i = 0; i < n; ++ i)
    {
        int x, s;
        cin >> x >> s;
        if (x == 1) 
        {
            ok = 1;
            t[i] = 1;
        }
        e[i].reserve(s);
        for (int j = 0; j < s; ++ j)
        {
            int x;
            cin >> x;
            e[i].emplace_back(x);
        }
    }
    if (ok)
    {
        int l = 0;
        map<int, int> cn;
        set<int> cn1;
        for (int i = 0; i < n; ++ i)
        if (t[i])
        {
            ++ l;
            for (int j : e[i])
            ++ cn[j];
        }
        for (auto u : cn)
        if (u.second == l) 
        cn1.emplace(u.first);
        for (int i = 0; i < n; ++ i)
        if (!t[i])
        {
            for (int j : e[i])
            cn1.erase(j);
        }
        cout << cn1.size();
        return;
    }
    set<int> mu;
    for (int i = 0; i < n; ++ i)
    for (int j : e[i])
    mu.emplace (j);
    cout << (long long)(1e18) - (long long)mu.size();
}

void solve()
{
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline (cin, s);
    int i, j;
    for (i = 0, j = 1; (i < n && j < n);)
    {
        int u = i, v = j;
        while (s[u] == s[v]) u = (u + 1) % n, v = (v + 1) % n;
        if (j == n) break;
        if (s[j] < s[i]) i = j;

    }
}

void print_result()
{

}

main()
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
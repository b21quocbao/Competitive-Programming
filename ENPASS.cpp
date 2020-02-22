#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ENPASS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[20], s[mn];

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

inline int mo (int x)
{
    if (x >= mod) x -= mod;
    return x;
}

void enter()
{
    int n;
    cin >> n;
    vector<pair<string, int> > v;
    for (int i = 0; i < n; ++ i)
    {
        string s;
        cin >> s;
        for (int j = 1; j < (1 << (int)s.size()); ++ j)
        {
            string s1;
            for (int k = 0; k < s.size(); ++ k)
            if ((j >> k) & 1) 
            s1.push_back(s[k]);
            v.push_back({s1, i + 1});
        }
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    d[0] = 1;
    s[0] = 1;
    int j = 0;
    for (int i = 1; i <= v.size(); ++ i)
    if ((i == v.size()) || (v[i].first != v[i - 1].first))
    {
        for (int k = j; k < i; ++ k)
        d[v[k].second] = mo (d[v[k].second] + s[v[k].second - 1]);
        for (int k = j; k < i; ++ k)
        s[v[k].second] = mo (s[v[k].second] + d[v[k].second]);
        for (int k = j; k < i; ++ k)
        d[v[k].second] = 0;
        j = i;
    }
    cout << s[n];
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
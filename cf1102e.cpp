//clone
#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 998244353;
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

int po (const int& x)
{
    if (!x) return 1;
    long long x1 = po (x >> 1);
    x1 = (x1 * x1) % mod;
    return (x & 1 ? (x1 * 2) % mod : x1);
}

void enter()
{
    int n;
    cin >> n;
    vector<pair<int, int> > V;
    for (int i = 1; i <= n; ++ i)
    {
        int x;
        cin >> x;
        V.emplace_back(x, i);
    }
    sort (V.begin(), V.end());
    vector<pair<int, int> > v;
    int cur = - 1, l, r;
    for (int i = 0; i < V.size(); ++ i)
    {
        if (V[i].first != cur)
        {
            if (cur != - 1)
            v.emplace_back(l, r);
            cur = V[i].first;
            l = V[i].second;
        }
        r = V[i].second;
    }
    v.emplace_back (l, r);
    sort (v.begin(), v.end());
    long long sol = 1;
    cur = 1;
    for (const auto& x : v)
    {
        if (x.first >= cur)
        sol *= po (x.first - cur);
        sol %= mod;
        cur = max (cur, x.second);
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
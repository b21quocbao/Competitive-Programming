#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 5 * (int)(1e5) + 10;
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

int a[mn], b[mn];
bool ok[mn];
vector<int> e[mn];
int cn[mn];

void enter()
{
    int n;
    cin >> n;
    vector<int> v;
    -- n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        v.emplace_back(a[i]);
    }
    bool Ok = 0;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> b[i];
        if (b[i] < a[i]) Ok = 1;
        v.emplace_back(b[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++ i)
    {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        ++ cn[a[i]];
        e[a[i]].emplace_back(i);
    }
    for (int i = 1; i <= n; ++ i)
    {
        b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
        ++ cn[b[i]];
        e[b[i]].emplace_back(i);
    }
    vector<int> V;
    for (int i = 0; i < v.size(); ++ i)
    if (cn[i] % 2) V.emplace_back(i);
    for (int i = 0; i < v.size(); ++ i)
    {
        sort (e[i].begin(), e[i].end());
        e[i].resize(unique(e[i].begin(), e[i].end()) - e[i].begin());
    }
    if (V.size() && V.size() != 2 || Ok)
    {
        cout << - 1;
        return;
    }
    int x;
    if (V.size()) x = V[0]; else x = 0;
    vector<int> sol;
    for (int i = 0; i <= n; ++ i)
    {
        cn[x] -= 2;
        cerr << v[x] << " ";
        sol.emplace_back(v[x]);
        if (i == n) break;
        while (e[x].size() && ok[e[x].back()]) e[x].pop_back();
        if (e[x].empty())
        {
            cout << - 1;
            return;
        }
        bool Ok = 0;
        vector<int> V;
        while (1) 
        {
            if (e[x].empty()) break;
            int r = e[x].back();
            if (x == a[r]) 
            {
                if (cn[b[r]] % 2 == 0) break;
            }
            else if (cn[a[r]] % 2 == 0) break;
            V.emplace_back(e[x].back());
            e[x].pop_back();
        }
        if (e[x].empty())
        {
            for (int i : V)
            e[x].emplace_back(i);
            V.clear();
        }
        while (e[x].size() && ok[e[x].back()]) e[x].pop_back();
        int j = e[x].back();
        if (a[j] == x) x = b[j]; else x = a[j];
        ok[j] = 1;
        for (int i : V)
        {
            e[x].emplace_back(i);
        }
    }
    for (int i : sol)
    cout << i << " ";
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
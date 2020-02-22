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
bool ok[mn];
int cv;
int l[mn], r[mn], w[mn], sc[mn];
int n, sol;
int S = 0;
list<int> v[mn];

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

inline void del (int re, int u)
{
    if (!u) return;
    if (ok[u]) return;
    ok[u] = 1;
    -- sc[re];
    del (re, l[u]); del (re, r[u]);
}

void F (int u)
{
    if (!u) return;
    F (l[u]); F (r[u]);
    sc[u] = sc[l[u]] + sc[r[u]] + 1;
    if (!l[u] && !r[u])
    {
        v[cv ++] = (list<int> (1, u));
    }
    if (!r[u] && l[u])
    {
        while (v[cv - 1].size() && w[v[cv - 1].back()] >= w[u]) 
        {
            del (u, v[cv - 1].back());
            v[cv - 1].pop_back();
        }
        v[cv - 1].emplace_back(u);
    }
    if (!l[u] && r[u])
    {
        while (v[cv - 1].size() && w[v[cv - 1].front()] <= w[u]) 
        {
            del (u, v[cv - 1].front());
            v[cv - 1].pop_front();
        }
        v[cv - 1].emplace_front(u);
    }
    if (l[u] && r[u])
    {
        while (v[cv - 1].size() && w[v[cv - 1].front()] <= w[u]) 
        {
            del (u, v[cv - 1].front());
            v[cv - 1].pop_front();
        }
        while (v[cv - 2].size() && w[v[cv - 2].back()] >= w[u]) 
        {
            del (u, v[cv - 2].back());
            v[cv - 2].pop_back();
        }
        v[cv - 2].emplace_back(u);
        v[cv - 2].splice(v[cv - 2].end(), v[cv - 1]);
        -- cv;
    }
    S = max (S, sc[u]);
}

void enter()
{
    read (n);
    sol = n;
    S = 0;
    for (int i = 1; i <= n; ++ i)
    {
        ok[i] = 0; sc[i] = 0;
        read (l[i]); read (r[i]); read (w[i]);
    }
    F (1);
    -- cv;
    cout << S << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
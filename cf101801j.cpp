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

long long ie[21 * mn];
int ne[21 * mn][2];
int cnt;

void Add (const int& x, const int& y)
{
    int cur = 1;
    int Y = abs (y);
    for (int i = 20; i >= 0; -- i)
    {
        int d1 = ((x >> i) & 1);
        int d2 = ((Y >> i) & 1);
        if (!d2)
        {
            if (!ne[cur][0]) ne[cur][0] = ++ cnt;
            if (!ne[cur][1]) ne[cur][1] = ++ cnt;
            ie[ne[cur][1 - d1]] += y;
            cur = ne[cur][d1];
        }
        else
        {
            if (!ne[cur][1 - d1]) ne[cur][1 - d1] = ++ cnt;
            cur = ne[cur][1 - d1];
        }
    }
}

void Del (const int& cur)
{
    if (!cur) return;
    ie[cur] = 0;
    Del (ne[cur][0]);
    Del (ne[cur][1]);
    ne[cur][0] = 0;
    ne[cur][1] = 0;
}

long long F (const int& x)
{
    int cur = 1;
    long long sol = 0;
    for (int i = 20; i >= 0; -- i)
    {
        if (!cur) break;
        sol += ie[cur];
        int d = ((x >> i) & 1);
        cur = ne[cur][d];
    }
    sol += ie[cur];
    return sol;
}

int l[mn], r[mn], n, a[mn];
vector<int> V[mn];

void enter()
{
    read (n);
    for (int i = 1; i <= n; ++ i)
    read (a[i]);
    vector<int> v;
    for (int i = 1; i <= n; ++ i)
    {
        while (v.size() && a[v.back()] < a[i]) v.pop_back();
        if (v.size())
        l[i] = v.back() + 1;
        else
        l[i] = 1;
        v.emplace_back(i);
    }
    v.clear();
    for (int i = n; i >= 1; -- i)
    {
        while (v.size() && a[v.back()] <= a[i]) v.pop_back();
        if (v.size())
        r[i] = v.back() - 1;
        else
        r[i] = n;
        v.emplace_back (i); 
    }
    long long Sol = 0;
    cnt = 1;
    for (int i = 1; i <= n + 1; ++ i)
    {
        for (const int& j : V[i])
        for (int k = l[j]; k <= j; ++ k)
        Add (a[k], - a[j]);
        V[i].clear();
        if (i == n + 1) continue;
        if (i - l[i] <= r[i] - i)
        {
            V[r[i] + 1].emplace_back (i);
            for (int j = l[i]; j <= i; ++ j)
            Add (a[j], a[i]);
        }
        Sol += F (a[i]);
    }
    for (int i = n; i >= 0; -- i)
    {
        for (const int& j : V[i])
        for (int k = j; k <= r[j]; ++ k)
        Add (a[k], - a[j]);
        V[i].clear();
        if (!i) continue;
        if (i - l[i] > r[i] - i)
        {
            V[l[i] - 1].emplace_back (i);
            for (int j = i; j <= r[i]; ++ j)
            Add (a[j], a[i]);
        }
        Sol += F (a[i]);
    }
    cout << Sol << "\n";
    Del (1);
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

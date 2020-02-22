#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TRITRIC"

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

void kt (pair<int, int> x1, pair<int, int> x2, pair<int, int> x3)
{
    set<int> mu;
    mu.insert (x1.second);
    mu.insert (x2.second);
    mu.insert (x3.second);
    if (mu.size() != 3) return;
    if (x1.first + x2.first <= x3.first) return;
    if (x3.first + x2.first <= x1.first) return;
    if (x1.first + x3.first <= x2.first) return;
    cout << x1.second << " " << x1.first << " ";
    cout << x2.second << " " << x2.first << " ";
    cout << x3.second << " " << x3.first;
    exit(0);
}

void enter()
{
    int c;
    read (c);
    vector<pair<int, int> > v, v1, v2;
    for (int i = 1; i <= c; ++ i)
    {
        int n, x;
        read (n);
        for (int j = 0; j < n; ++ j)
        {
            read (x);
            v.emplace_back(x, i);
        }
    }
    sort (v.begin(), v.end());
    int cn = 0;
    vector<pair<int, int> > a (2, make_pair(0, 0));
    auto b = a;
    auto d = a;
    for (int i = 0; i < v.size(); ++ i)
    {
        a = b;
        b = d;
        int j = i;
        ++ cn;
        while (j < v.size() && v[j].second == v[i].second) ++ j;
        d[0] = v[j - 1]; d[1] = v[i];
        if (cn >= 3)
        {
            for (int k1 = 0; k1 < 2; ++ k1)
            for (int k2 = 0; k2 < 2; ++ k2)
            for (int k3 = 0; k3 < 2; ++ k3)
            kt (a[k1], b[k2], d[k3]);
        }
        i = j - 1;
    }
    cout << - 1;
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
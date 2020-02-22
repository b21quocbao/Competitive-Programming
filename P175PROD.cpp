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

template <typename T>
class BIT 
{
    public:
    const T minT = 0;
    T MAX (const T& a, const T& b)
    {
        return a + b;
    }
    vector<T> bi;
    BIT (int n)
    {
        bi.resize(n + 2);
    }
    void udl (int u, T w)
    {
        for (; u < bi.size(); u += u & - u)
        bi[u] = MAX (bi[u], w);
    }
    int qun (int u)
    {
        T s = minT;
        for (; u >= 1; u -= u & - u)
        s = MAX (s, bi[u]);
        return s;
    }
    void udn (int u, T w)
    {
        for (; u >= 1; u -= u & - u)
        bi[u] = MAX (bi[u], w);
    }
    int qul (int u)
    {
        T s = minT;
        for (; u < bi.size(); u += u & - u)
        s = MAX (s, bi[u]);
        return s;
    }
};

void enter()
{
    int n;
    read (n);
    vector<int> v;
    vector<int> x (n), y (n), id (n), sol (n);
    for (int i = 0; i < n; ++ i)
    {
        read (x[i]); read (y[i]);
        v.emplace_back(x[i]);
        v.emplace_back(y[i]);
        id[i] = i;
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    sort (id.begin(), id.end(), [&](int i, int j)
         {
             return y[i] < y[j];
         });
    BIT<int> bit (v.size() + 1);
    for (const int& i : id)
    {
        x[i] = lower_bound(v.begin(), v.end(), x[i]) - v.begin() + 1;
        y[i] = lower_bound(v.begin(), v.end(), y[i]) - v.begin() + 1;
        sol[i] = bit.qul (x[i] + 1);
        bit.udn (x[i], 1);
    }
    for (const int& i : sol)
    {
        write (i);
        putchar('\n');
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
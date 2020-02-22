#include <bits/stdc++.h>

#define fn "test"
#define fn1 "TOWERS"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int id[mn];
pair<int, int> a[mn];
int l[mn];

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
    int n, k;
    read (n); read (k);
    int ma = - 1;
    for (int i = 1; i <= n; ++ i)
    {
        read (a[i].first);
        id[i] = i;
    }
    vector<int> t;
    for (int i = 1; i <= n; ++ i)
    {
        while (t.size() && a[t.back()].first < a[i].first)
        t.pop_back();
        if (t.size())
        l[i] = t.back();
        else
        l[i] = 0;
        t.emplace_back (i);
        a[i].second = 1;
    }
    sort (id + 1, id + n + 1, [](int i, int j)
         {
             return a[i].first < a[j].first;
         });
    for (int j = 1; j <= n; ++ j)
    {
        int i = id[j];
        if (l[i])
        a[l[i]].second = max (a[l[i]].second, a[i].second + 1);
    }
    sort (a, a + n + 1);
    for (int i = 1; i <= n; ++ i)
    a[i].second = max (a[i].second, a[i - 1].second);
    for (int i = 0; i < k; ++ i)
    {
        int h;
        read (h);
        cout << prev (lower_bound (a + 1, a + n + 1, make_pair (h, 0))) -> second << " ";
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
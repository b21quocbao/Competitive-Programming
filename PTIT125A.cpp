#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e4) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int m, n, a[mn], it[4 * mn];

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

void initit (int id, int l, int r)
{
    it[id] = 0;
    if (l == r) return;
    int m = (l + r) >> 1, i = (id * 2);
    initit (i, l, m);
    initit (i + 1, m + 1, r);
}

void ud (int id, int l, int r, int x)
{
    if (l > x || r < x) return;
    if (l == r) 
    {
        ++ it[id];
        return;
    }
    int m = (l + r) >> 1, i = id * 2;
    ud (i, l, m, x);
    ud (i + 1, m + 1, r, x);
    it[id] = it[i] + it[i + 1];
}

int qu (int id, int l, int r, int x)
{
    int m = (l + r) >> 1, i = id << 1;
    if (l == r) return l;
    if (it[i] >= x) return qu (i, l, m, x);
    return qu (i + 1, m + 1, r, x - it[i]);
}

void enter()
{
    cin >> m >> n;
    vector<int> v;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        v.emplace_back(a[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    m = v.size();
    cout << tt << " " << n / 2 + 1 << "\n";
    initit (1, 0, m);
    int cn = 0;
    for (int i = 0; i < n; ++ i)
    {
        int x = lower_bound (v.begin(), v.end(), a[i]) - v.begin();
        ud (1, 0, m - 1, x);
        if (i % 2 == 0)
        {
            if (++ cn == 11)
            {
                cn = 1;
                cout << "\n";
            }
            cout << v[qu (1, 0, m - 1, i / 2 + 1)] << " ";
        }
    }
    cout << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
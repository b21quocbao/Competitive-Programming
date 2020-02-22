#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
int a[1010][30];

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

#define vi pair<int, vector<int> > 

vi ch (int x)
{
    vi v;
    if (x < 0)
    {   
        v.first = - 1;
        x = - x;
    }
    else v.first = 1;
    if (!x)
    {
        v.second.emplace_back(x);
        return v;
    }
    while (x)
    {
        v.second.emplace_back(x % base);
        x /= base;
    }
    return v;
}

vi operator * (const vi& a, const vi& b)
{
    vi c;
    c.second.resize(a.second.size() + b.second.size());
    c.first = a.first * b.first;
    for (int i = 0; i < a.second.size(); ++ i)
    {
        long long r = 0;
        for (int j = 0; j < b.second.size() || r; ++ j)
        {
            r = r + c.second[i + j] + 1ll * a.second[i] * (j == b.second.size() ? 0 : b.second[j]);
            c.second[i + j] = r % base;
            r /= base;
        }
    }
    while (c.second.size() >= 2 && c.second.back() == 0)
    c.second.pop_back();
    if (c.second.size() == 1 && c.second[0] == 0)
    c.first = abs (c.first);
    return c;
}

bool operator >= (vi a, vi b)
{
    if (b.second.empty()) return 1;
    if (a.first != b.first) return (a.first > b.first);
    if (a.first == - 1) swap (a, b);
    if (a.second.size() != b.second.size()) return (a.second.size() > b.second.size());
    for (int i = a.second.size() - 1; i >= 0; -- i)
    if (a.second[i] != b.second[i])
    return (a.second[i] > b.second[i]);
    return 1;
}

void enter()
{
    int m, n;
    cin >> m >> n;
    if (!m && !n) exit(0);
    int soli;
    vi sol;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < m; ++ j)
    cin >> a[i][j];
    for (int i = 0; i < m; ++ i)
    {
        vi r;
        r.first = 1;
        r.second = vector<int> (1, 1);
        for (int j = 0; j < n; ++ j)
        r = r * ch (a[j][i]);
        if (r >= sol)
        {
            sol = r;
            soli = i + 1;
        }
    }
    cout << soli << "\n";
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
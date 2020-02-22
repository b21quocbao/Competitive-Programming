#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PGAME"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long x[2];
vector<pair<long long , long long > > v;
int id[2];
map<long long, bool > ok;

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

void chay ()
{
    if (x[id[1]] != 1)
    v.push_back({3 + id[1], x[id[1]] - 1});
}

void printsol()
{
    reverse (v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto i : v)
    {
        cout << i.first;
        if (i.second)
        cout << " " << i.second;
        cout << "\n";
    }
}

void xlle()
{
    if (x[id[0]] > x[id[1]]) swap (id[0], id[1]);
    if (x[id[0]] != 1)
    {
        cout << - 1;
        exit(0);
    }
    chay ();
    printsol ();
    exit(0);
}

void enter()
{
    cin >> a >> b;
    while ((a & 1) == 0 &&)
    {
        a >>= 1;
        v.push_back({1, 0});
    }
    while ( (b & 1) == 0)
    {
        b >>= 1;
        v.push_back({2, 0});
    }
    for (int i = 0; i <= 60; ++ i)
    {
        if (((1ll << i) - b) % a == 0)
        if ()
        v.push_back({4, (1ll << i) - b / a});

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
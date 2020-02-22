#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "TIGERSUGAR"

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

#define y1 __y1

int x1[mn], y1[mn], x2[mn], y2[mn];
vector<pair<int, int> > vx, vy;
int sol = 0, n;
vector<int> solx, soly;
int X, Y;

void process (vector<int>& solx, int& X)
{
    sort (vx.begin(), vx.end());
    int nx = 0, mx = 0, tx = 0, sx = 0;
    for (auto x : vx)
    if (x.second == 1)
    {
        ++ nx;
        tx += x.first;
    }
    int ma = LLONG_MAX;
    for (int i = 0; i < vx.size(); ++ i)
    {
        auto x = vx[i];
        if (x.second == 1)
        {
            -- nx;
            tx -= x.first;
        }
        else if (x.second == - 1)
        {
            ++ mx;
            sx += x.first - 1;
        }
        if (i == vx.size() - 1 || vx[i].first != vx[i + 1].first)
        {
            if (tx - nx * x.first + mx * x.first - sx >= ma) continue;
            ma = tx - nx * x.first + mx * x.first - sx;
            X = vx[i].first;
        }
    }
    solx.resize(n);
    for (int i = 0; i < n; ++ i)
    if (x2[i] <= X)
    solx[i] = x2[i];
    else if (x1[i] > X)
    solx[i] = x1[i];
    else 
    solx[i] = X;
    sol += ma;
}

void enter()
{
    read (n);
    for (int i = 0; i < n; ++ i)
    {
        read (x1[i]); read (y1[i]); read (x2[i]); read (y2[i]);
        if (x1[i] > x2[i]) swap (x1[i], x2[i]);
        if (y1[i] > y2[i]) swap (y1[i], y2[i]);
        vx.emplace_back(x1[i], 1);
        vx.emplace_back(x2[i] + 1, - 1);
        vy.emplace_back(y1[i], 1);
        vy.emplace_back(y2[i] + 1, - 1);
    }
    process(solx, X);
    swap (vx, vy);
    swap (x1, y1);
    swap (x2, y2);
    process(soly, Y);
    cout << sol << "\n";
    cout << X << " " << Y << "\n";
    for (int i = 0; i < n; ++ i)
    cout << solx[i] << " " << soly[i] << "\n";
}

void solve()
{

}

void print_result()
{

}

main()
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
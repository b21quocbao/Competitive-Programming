#include <bits/stdc++.h>

#define fn "test"
#define fn1 "RANKING"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int x[mm], y[mm];

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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> x[i] >> y[i];
    }
    #define eps 1e-6
    for (int i = 0; i < n; ++ i)
    {
        int sol = 0;
        vector<pair<double, bool>> v;
        int cn = 0; 
        int N = n;
        for (int j = 0; j < n; ++ j)
        if (j != i)
        {
            if (x[i] == x[j])
            {
                if (y[i] <= y[j])
                -- N;
                continue;
            }
            if (x[i] > x[j])
            v.emplace_back(1. * (y[i] - y[j]) / (x[i] - x[j]), 0);
            else
            {
                v.emplace_back(1. * (y[i] - y[j]) / (x[i] - x[j]), 1);
                ++ cn;
            }
        }
        sort (v.begin(), v.end());
        int sol1 = 0, sol2 = N - 1;
        for (auto d : v)
        {
            if (d.first > 0)
            {
                sol1 = max (sol1, cn);
                sol2 = min (sol2, cn);
            }
            if (d.second) -- cn;
            else ++ cn;
            if (d.first > 0)
            {
                sol1 = max (sol1, cn);
                sol2 = min (sol2, cn);
            }
        }
        sol1 = max (sol1, cn);
        sol2 = min (sol2, cn);
        cout << N - sol1 << " " << N - sol2 << "\n";
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
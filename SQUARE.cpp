#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SQUARE"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 2 * (int)(1e9) + 2;
const bool aNs = 0;

int tt, ntest = 1;
int x[mn], y[mn];

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

#define ii pair<int, int>  

struct cmp
{   
    inline long long operator () (const ii& a) const
    {
        return 1ll * a.first * base + a.second;
    }
};


void enter()
{
    int n;
    cin >> n;
    unordered_set<pair<int, int> , cmp> mu;
    for (int i = 0; i < n; ++ i)
    {
        cin >> x[i] >> y[i];
        mu.emplace (x[i], y[i]);
    }
    long long sol = 0;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < i; ++ j)
    {
        int a = x[j] - x[i], b = y[j] - y[i];
        int ok = 0;
        ok += (mu.count ({x[i] - b, y[i] + a}) && mu.count ({x[j] - b, y[j] + a}));
        ok += (mu.count ({x[i] + b, y[i] - a}) && mu.count ({x[j] + b, y[j] - a}));
        if (!ok) continue;
        sol = max (sol, llabs (1ll * a * a + 1ll * b * b));
    }
    cout << sol << "\n";
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
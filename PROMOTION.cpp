#include <bits/stdc++.h>

#define fn "test"
#define fn1 "PROMOTION"

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

void enter()
{
    int n, m;
    cin >> n >> m;
    vector<int> a (n + 1);
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    vector<int> u (m), v (m);
    vector<double> W (m), w (m);
    vector<double> d (n + 1);
    for (int i = 0; i < m; ++ i)
    cin >> u[i] >> v[i] >> W[i];
    double inf = 0, sup = 2000, sol;
    for (int i = 0; (i <= 30 && inf <= sup); ++ i)
    {
        double t = (inf + sup) / 2;
        for (int i = 0; i < m; ++ i)
        {
            w[i] = W[i] * t - a[u[i]];
        }
        fill (d.begin(), d.end(), 0);
        bool ok;
        for (int l = 0; l < n; ++ l)
        {
            ok = 0;
            for (int j = 0; j < m; ++ j)
            {
                if (d[u[j]] + w[j] < d[v[j]])
                {
                    d[v[j]] = d[u[j]] + w[j];
                    ok = 1;
                }
            }
        }
        if (ok)
        {
            inf = t;
            sol = t;
        }   
        else
        sup = t;
    }
    cout << fixed << setprecision(2) << sol;
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
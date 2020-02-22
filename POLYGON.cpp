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

pair<int, int> operator - (pair<int, int> x, pair<int, int> y)
{
    return {x.first - y.first, x.second - y.second};
}

long long operator * (pair<int, int> x, pair<int, int> y)
{
    return x.first * y.second - x.second * y.first;
}

pair<int, int> x[mn];
int id[mn];
int f[110][110];
int n;

int F (int i, int j)
{
    if (!i) return 1;
    if (f[i][j] != - 1) return f[i][j];
    f[i][j] = - 2;
    for (int k = i - 1; k >= 0; -- k)
    if ((x[id[i]] - x[id[k]]) * (x[id[j]] - x[id[i]]) > 0)
    if (F (k, i) != - 2)
    {
        f[i][j] = max (f[i][j], F (k, i) + 1);
        // cerr << (x[i] - x[k]) * (x[j] - x[i]) << " " << (x[j] - x[i]) * (x[i] - x[k]) << "\n";
    }
    return f[i][j];
}

void enter()
{
    cin >> n;
    if (n == 2)
    {
        cout << 3;
        return;
    }
    for (int i = 1; i <= n; ++ i)
    {
        cin >> x[i].first >> x[i].second;
        id[i] = i;
    }
    sort (id + 1, id + n + 1, [&](int i, int j)
         {
             return ((x[i] - x[0]) * (x[j] - x[0])) > 0;
         });
    int sol = 0;
    memset (f, - 1, sizeof (f));
    for (int i = 1; i <= n; ++ i)
    sol = max (sol, F (i, 0));
    cout << sol;
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
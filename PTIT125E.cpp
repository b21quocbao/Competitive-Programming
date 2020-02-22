#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 20 + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int x[mn], S[mn], f[mn][mm][mm];

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

bool F (int id, int a, int b)
{
    if (id < 0) return ((!a && !b) ? 1 : 0);
    if (a < 0 || b < 0 || S[id] - a - b < 0) return 0;
    if (f[id][a][b] != - 1) return f[id][a][b];
    bool ok1 = F (id - 1, a - x[id], b);
    bool ok2 = F (id - 1, a, b - x[id]);
    bool ok3 = F (id - 1, a, b);
    return f[id][a][b] = (ok1 | ok2 | ok3); 
}

void enter()
{
    int n, s = 0;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> x[i];
        S[i] = (!i ? 0 : S[i - 1]) + x[i];
        s += x[i];
    }
    memset (f, - 1, sizeof (f));
    for (int i = s / 3; i <= 1000; ++ i)
    for (int j = (s - i + 1) / 2; j <= i; ++ j)
    if (F (n - 1, i, j))
    {
        cout << i;
        return;
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
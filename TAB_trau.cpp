#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
int n, a[mm][mm], b[mm][mm], c[mm][mm];
int h[2 * mm + 3];
vector<pair<int, int> > v;

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

void chdc1()
{
    for (int i = 0; i < n; ++ i)
    a[i][i] = - a[i][i];
    v.emplace_back(3, 1);
}

void chdc2()
{
    for (int i = 0; i < n; ++ i)
    a[i][n - 1 - i] = - a[i][n - 1 - i];
    v.emplace_back(3, 2);
}

void chh (int i)
{
    for (int j = 0; j < n; ++ j)
    a[i][j] = - a[i][j];
    v.emplace_back(1, i + 1);
}

void chc (int j)
{
    for (int i = 0; i < n; ++ i)
    a[i][j] = - a[i][j];
    v.emplace_back(2, j + 1);
}

bool kt ()
{
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    if (a[i][j] != b[i][j]) return 0;
    return 1;
}

void init ()
{
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    a[i][j] = c[i][j];
    v.clear();
}

void attemp (int id)
{
    if (id == 2 * n + 2)
    {
        init();
        for (int i = 0; i < n; ++ i)
        if (h[i])
        chh (i);
        for (int j = 0; j < n; ++ j)
        if (h[n + j])
        chc (j);
        if (h[2 * n])
        chdc1();
        if (h[2 * n + 1])
        chdc2();
        if (kt ())
        {
            for (auto i : v)
            cout << i.first << " " << i.second << "\n";
            exit(0);
        }
        return;
    }
    for (int i = 0; i < 2; ++ i)
    {
        h[id] = i;
        attemp (id + 1);
    }
}

void enter()
{
    cin >> n;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        cin >> a[i][j];
        c[i][j] = a[i][j];
    }
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> b[i][j];
    attemp (0);
}

void solve()
{
    cout << - 1;
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
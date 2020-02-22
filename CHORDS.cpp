#include <bits/stdc++.h>

#define fn "test"
#define fn1 "CHORDS"

using namespace std;

const int mn = 2 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n;
pair<int, int> a[mn];
int f[mn][mn];
int tr[mn][mn];
int id[mn];

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

int F (int x, int y)
{
    if (x >= y) return 0;
    if (f[x][y] != - 1) return f[x][y];
    f[x][y] = 0;
    for (int j = 1; (j <= n && a[id[j]].first >= x); ++ j)
    {
        int i = id[j];
        if (a[i].second > y) continue;
        int r1 = F (x, a[i].first - 1);
        int r2 = F (a[i].first + 1, a[i].second - 1);
        int r3 = F (a[i].second + 1, y);
        if (r1 + r2 + r3 + 1 > f[x][y])
        {
            f[x][y] = r1 + r2 + r3 + 1;
            tr[x][y] = i;
        }
    }
    return f[x][y];
}

void Tr (int x, int y)
{
    if (x >= y) return;
    int i = tr[x][y];
    if (!i) return;
    cout << i << " ";
    Tr (x, a[i].first - 1);
    Tr (a[i].first + 1, a[i].second - 1);
    Tr (a[i].second + 1, y);
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second)
        swap (a[i].first, a[i].second);
        id[i] = i;
    }
    sort (id + 1, id + n + 1, [](int i, int j)
         {
             return a[i].first > a[j].first;
         });
    memset (f, - 1, sizeof (f));
    cout << F (1, 2 * n) << "\n";
    Tr (1, 2 * n);
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